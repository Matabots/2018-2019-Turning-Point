#sh Update_Index.sh
cd 2018-2019-Turning-Point/
#following line is a command to write a list of folders in a directory
#Source: https://perishablepress.com/list-files-folders-recursively-terminal/
ls -R | grep ":$" | sed -e 's/:$//' -e 's/[^-][^\/]*\//--/g' -e 's/^/ /' -e 's/-/|/' > /Users/pablolepe/Documents/College/CSUN/Clubs/Vex\ Robotics/Programming/2018-2019/Code/Repo_Index.txt
cd ..
python transpose_Index.py
