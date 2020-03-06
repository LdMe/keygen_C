#!/bin/bash

path=/home/dlm/EPITECH/installer
#This step is to avoid possible errors because of spaces in directory names 
path_clean=$(echo "$path" | sed -e 's/[[:space:]]/\\ /g')
path_ex="$path_clean/bin/keygen"
if [ $# -lt 1 ]
then
    echo "Public password:"
    read public_key
    echo "Private password:"
    
    read -s private_key
    # I changed xclip for xsel, as it was not working if the shell was not interactive
    $path_ex $public_key $private_key | xsel -i --clipboard
    exit 0
fi
if [ $# -lt 2 ]
then
    echo "Private password:"
    read -s key
    $path_ex $1 $key | xclip -sel clip
    exit 0
fi

exit 1
