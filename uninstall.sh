#!/bin/bash
app_name=$(grep "app_name=" install.sh | sed -e 's/app_name=//' | sed  -e 's/\"//g' )
rm -rf bin
rm -f ~/.local/share/applications/$app_name.desktop
sed -i "/$app_name/d" ~/.bash_aliases
sudo apt purge xsel
if [[ $# -lt 1 ]]; then
	echo "$app_name uninstalled succesfully"
fi