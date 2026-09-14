# proxychains -q git push
# git describe | xargs git tag
# git describe | xargs proxychains -q git push origin 
git fetch upsteam --tags
git push
git push origin --tags
git describe | xargs git tag
git describe | xargs git push origin 