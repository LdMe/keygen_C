#!/bin/bash
filename="test.desktop"
description="test application"
version="1.0"
executable="test"

if [ $# -ge 1 ];
then
	filename="$1.desktop"
	executable=$1
fi
if [ $# -ge 2 ];
then
	version=$2
fi
if [ $# -ge 3 ];
then
	description=$3
fi
if [ $# -ge 4 ];
then
	
	if [[ $4 == "sh" ]];
	then
		path=$(pwd)
		executable=$executable.sh
		cp "./source/$executable" "./bin/"
		sed -i "s#path\=#path\=$path#" "./bin/$executable"
	fi
fi
path=$(pwd)
#This step is to avoid possible errors because of spaces in directory names 
path=$(echo "$path" | sed -e 's/[[:space:]]/\\ /g')
path_ex="$path/bin/$executable"
path_uninstall="$path/uninstall.sh"
line="Exec=gnome-terminal -e \"${path_ex@Q}\""
icon="Icon=$path/icon/icon.png"
# .desktop file with some metadata
touch $filename
echo "[Desktop Entry]" > $filename
echo "Encoding=UTF-8" >> $filename
echo "Type=Application" >> $filename
echo "Version=$version" >> $filename
echo "Name=$description" >> $filename
echo $line >> $filename
echo "Terminal=true" >> $filename
echo $icon >> $filename
echo "alias $1=${path_ex@Q}" >> ~/.bash_aliases
echo "alias $1_uninstall=${path_uninstall@Q}" >> ~/.bash_aliases