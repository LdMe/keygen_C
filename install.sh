#!/bin/bash
app_name="keygen"
version="1.1"
description="Keygen for terminal"
#first uninstall previous versions
./uninstall.sh 0
echo -e "previous versions uninstalled\n"
#then compile to get the binaries
./compile.sh $app_name
echo -e "executable file compiled\n"
#create desktop icon and alias for terminal 
#            		app name - version - description for icon
./create_desktop.sh $app_name  $version   "$description" sh
#move the .desktop file to your user's application directory to make it visible in your applications menu
mv $app_name.desktop ~/.local/share/applications/$app_name.desktop
echo -e ".desktop file created at ~/.local/share/applications/$app_name.desktop\n"
echo -e "alias created in ~/.bash_aliases\n"
echo -e "restart terminal or type 'bash' to enable the alias '$app_name'\n"
echo -e "to uninstall it, type '"$app_name"_uninstall' or run uninstall.sh "