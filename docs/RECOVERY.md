# Source code history recovery

This is the procedure I used to have the most updated and traceable history.

```bash
sudo apt update
sudo apt install -y wget unzip tar python2 cvs git

wget -O rocketworkbench.zip https://sourceforge.net/code-snapshots/cvs/r/ro/rocketworkbench.zip
wget -qO- https://github.com/mhagger/cvs2svn/releases/download/2.5.0/cvs2svn-2.5.0.tar.gz | tar -xz

unzip -q rocketworkbench.zip && rm rocketworkbench.zip
mv rocketworkbench rocketworkbench-cvs

python2 ./cvs2svn-2.5.0/cvs2git -q --blobfile=git-blob.dat --dumpfile=git-dump.dat rocketworkbench-cvs

mkdir rocketworkbench-git
cd rocketworkbench-git
git init
cat ../git-{blob,dump}.dat | git fast-import
rm ../git-{blob,dump}.dat
git reset --hard

git branch -m cvs2git

git checkout 885d7941f094508f6d79f7b26682ccab4cb10f07^

git checkout -b main

mkdir rocketworkbench
mkdir rocketworkbench/source
mkdir rocketworkbench/source/executables
mkdir rocketworkbench/source/libraries
mv data rocketworkbench
mv lib* rocketworkbench/source/libraries
mv {analyser,cpropep,cpropep-web,prop,rockflight} rocketworkbench/source/executables

git add data lib* analyser cpropep cpropep-web prop rockflight rocketworkbench

git commit -m "Moved some files for history reconstruction."

git cherry-pick -X theirs 885d7941f094508f6d79f7b26682ccab4cb10f07
git add rocketworkbench
git cherry-pick --continue --no-edit
git cherry-pick -X theirs d8b46c5601a3d9e5a0c59dd2484a2c4f8159421a^..cvs2git

mv rocketworkbench/* .
rmdir rocketworkbench
rm -r CVSROOT

git add * CVSROOT rocketworkbench

git commit -m "Removed CVSROOT and root rocketworkbench folder."
```
