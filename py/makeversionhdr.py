"""
Generate header file with macros defining MicroPython version info.

This script works with Python 2.6, 2.7, 3.3 and 3.4.
"""

from __future__ import print_function

import argparse
import sys
import os
import datetime
import subprocess


# The MicroPython repository tags a release commit as "vX.Y.Z", and the commit
# immediately following as "vX.(Y+1).Z-preview".
# This function will return:
#   "vX.Y.Z" -- building at the release commit
#   "vX.Y.Z-preview" -- building at the first commit in the next cycle
#   "vX.Y.Z-preview.N.gHASH" -- building at any subsequent commit in the cycle
#   "vX.Y.Z-preview.N.gHASH.dirty" -- building at any subsequent commit in the cycle
#                                     with local changes
def get_version_info_from_git(repo_path):
    # Python 2.6 doesn't have check_output, so check for that
    try:
        subprocess.check_output
    except AttributeError:
        return None

    # Note: git describe doesn't work if no tag is available
    try:
        git_tag = subprocess.check_output(
            ["git", "describe", "--tags", "--dirty", "--always", "--match", "v[1-9].*"],
            cwd=repo_path,
            stderr=subprocess.STDOUT,
            universal_newlines=True,
        ).strip()
        # Turn git-describe's output into semver compatible (dot-separated
        # identifiers inside the prerelease field).
        git_tag = git_tag.split("-", 1)
        if len(git_tag) == 1:
            return git_tag[0]
        else:
            return git_tag[0] + "-" + git_tag[1].replace("-", ".")
    except (subprocess.CalledProcessError, OSError):
        return None


def get_hash_from_git(repo_path):
    # Python 2.6 doesn't have check_output, so check for that.
    try:
        subprocess.check_output
    except AttributeError:
        return None

    try:
        return subprocess.check_output(
            ["git", "rev-parse", "--short", "HEAD"],
            cwd=repo_path,
            stderr=subprocess.STDOUT,
            universal_newlines=True,
        ).strip()
    except (subprocess.CalledProcessError, OSError):
        return None


# When building from a source tarball (or any situation where the git repo
# isn't available), this function will use the info in mpconfig.h as a
# fallback. The release commit sets MICROPY_VERSION_PRERELEASE to 0, and the
# commit immediately following increments MICROPY_VERSION_MINOR and sets
# MICROPY_VERSION_PRERELEASE back to 1.
# This function will return:
#    "vX.Y.Z" -- building at the release commit
#    "vX.Y.Z-preview" -- building at any other commit
def get_version_info_from_mpconfig(repo_path):
    print(
        "makeversionhdr.py: Warning: No git repo or tag info available, falling back to mpconfig.h version info.",
        file=sys.stderr,
    )

    with open(os.path.join(repo_path, "py", "mpconfig.h")) as f:
        for line in f:
            if line.startswith("#define MICROPY_VERSION_MAJOR "):
                ver_major = int(line.strip().split()[2])
            elif line.startswith("#define MICROPY_VERSION_MINOR "):
                ver_minor = int(line.strip().split()[2])
            elif line.startswith("#define MICROPY_VERSION_MICRO "):
                ver_micro = int(line.strip().split()[2])
            elif line.startswith("#define MICROPY_VERSION_PRERELEASE "):
                ver_prerelease = int(line.strip().split()[2])
                git_tag = "v%d.%d.%d%s" % (
                    ver_major,
                    ver_minor,
                    ver_micro,
                    "-preview" if ver_prerelease else "",
                )
                return git_tag
    return None


def make_version_header(repo_path, filename):
    git_tag = None
    git_hash = None
    if "MICROPY_GIT_TAG" in os.environ:
        git_tag = os.environ["MICROPY_GIT_TAG"]
        git_hash = os.environ.get("MICROPY_GIT_HASH")
    if git_tag is None:
        git_tag = get_version_info_from_git(repo_path)
        git_hash = get_hash_from_git(repo_path)
    if git_tag is None:
        git_tag = get_version_info_from_mpconfig(repo_path)

    if not git_tag:
        print("makeversionhdr.py: Error: No version information available.")
        sys.exit(1)

    build_date = datetime.date.today()
    if "SOURCE_DATE_EPOCH" in os.environ:
        build_date = datetime.datetime.utcfromtimestamp(
            int(os.environ["SOURCE_DATE_EPOCH"])
        ).date()

    # Generate the file with the git and version info
    # Note: MICROPY_GIT_HASH may be used by third-party code.
    file_data = """\
// This file was generated by py/makeversionhdr.py
#define MICROPY_GIT_TAG "%s"
#define MICROPY_GIT_HASH "%s"
#define MICROPY_BUILD_DATE "%s"
""" % (
        git_tag,
        git_hash or "<no hash>",
        build_date.strftime("%Y-%m-%d"),
    )

    # Check if the file contents changed from last time
    write_file = True
    if os.path.isfile(filename):
        with open(filename, "r") as f:
            existing_data = f.read()
        if existing_data == file_data:
            write_file = False

    # Only write the file if we need to
    if write_file:
        print("GEN %s" % filename)
        with open(filename, "w") as f:
            f.write(file_data)


def main():
    parser = argparse.ArgumentParser()
    # makeversionheader.py lives in repo/py, so default repo_path to the
    # parent of sys.argv[0]'s directory.
    parser.add_argument(
        "-r",
        "--repo-path",
        default=os.path.join(os.path.dirname(sys.argv[0]), ".."),
        help="path to MicroPython Git repo to query for version",
    )
    parser.add_argument("dest", nargs=1, help="output file path")
    args = parser.parse_args()

    make_version_header(args.repo_path, args.dest[0])


if __name__ == "__main__":
    main()
