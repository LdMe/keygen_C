#!/bin/bash

path=
#This step is to avoid possible errors because of spaces in directory names 
path_clean=$(echo "$path" | sed -e 's/[[:space:]]/\\ /g')
path_ex="$path_clean/bin/keygen"
seed=1
length=0
type="c" # classic
args=("$@")
len=$(($# - 1))
word=""
key=""
for (( i = 0; i < $#; i++ )); do
    arg=${args[$i]}
    if [ "$arg" == "-h" ] || [ "$arg" == "--help" ]; then
        printf "\nusage of the keygen:\n\n"
        printf "keygen [options] [public_key] [private_key]\n\n"
        printf "DESCRIPTION\n\n"
        printf "\tKey generator that doesn't save your keys.\n\tUseful to secure different accounts\n\twithout having to remember all the passwords.\n"
        printf "\tThe created password will be copied to your clipboard\n"
        printf "\nARGUMENTS\n\n"
        printf "\tif necessary arguments missing, they will be requested later\n\n"
        printf "\t-t, --type: password type \n"
        printf "\t\tc:   (default) classic, old algorithm without seed and no modifiable size\n"
        printf "\t\tn:   numeric, only numbers will appear in the password\n"
        printf "\t\tan:  alphanumeric, only alphanumeric characters\n"
        printf "\t\tans: alphanumeric + symbols, it adds symbols,\n\t\t     necessary for some passwords\n"
        printf "\t-l, --length: password length\n"
        printf "\t              number bigger than 3, not functional in classic\n"
        printf "\t-s, --seed: password seed\n"
        printf "\t            different seeds will give different passwords, not functional in classic\n"
        printf "\tpublic_key:  may be a specific word referencing the account it is going to be used for,\n"
        printf "\t             it can contain any character in ascii\n"
        printf "\tprivate_key: word or phrase you should keep secret,\n"
        printf "\t             it can contain any character in ascii\n"
        printf "\n\tif only one key present, it will be interpreted as public key,\n"
        printf "\tnote the importance, as the public key will be visible in terminal\n"
        printf "\nEXAMPLE\n\n"
        printf "keygen -t an -s 10 -l 20 public_key private_key\n\n"
        printf "gwSlAak60usEsKEmg000\n\n"
        exit 1
    fi
    if [ "$arg" == "-s" ] || [ "$arg" == "--seed" ]; then
        if [ $i -lt $len ]; then
            position=$(($i + 1))
            seed=${args[$position]}
            i=$(($i + 1))
        fi
    elif [ "$arg" == "-l" ] || [ "$arg" == "--length" ]; then
        if [ $i -lt $len ]; then
            position=$(($i + 1))
            length=${args[$position]}
            i=$(($i + 1))
        fi
    elif [ "$arg" == "-t" ] || [ "$arg" == "--type" ]; then
        if [ $i -lt $len ]; then
            position=$(($i + 1))
            type=${args[$position]}
            i=$(($i + 1))
        fi
    else
        if [[ $word == "" ]]; then
            word=${args[$i]}
        else
            key=${args[$i]}
        fi

    fi


done
if [[ $# == 0 ]]; then
    echo "Type: c, n, an, ans [c]"
    read type
    type=${type:-"c"}
    if [[ $type != "c" ]]; then
        echo "Length [8]"
        read length
        length=${length:-8}
        echo "seed [1]"
        read seed
        seed=${seed:-1}
    fi
fi
if [[ $word == "" ]]; then
    echo "Public password:"
    read word
fi
if [[ $key == "" ]]; then
    echo "Private password:"
    read -s key
fi
$path_ex $word $key $type $length $seed | xsel -i --clipboard
exit 0
