#!/bin/bash
# script to create python files

if [ $# -lt 1 ]
then
	read -r -p "Enter <file>.py: " file
else
	file=$1
fi

if [[ "${file}" != *".py" ]]
then
	echo "Provide a .py file"
	exit 1
elif [ ! -f "${file}" ]
then
	echo -e "#!/usr/bin/python3\n"> "${file}"; nvim "${file}"
else
	content=$(cat "$file")
	if [ -n "${content}" ]
	then
		echo "${file} is not empty"
		read -r -n1 -p "Do you want to open it? [Y/N]" option

		case $option in
			y | Y) nvim "${file}";;
			*) ;;
		esac
	fi
fi

# Change mode of file if it is not executable
if [ ! -x "${file}" ]
then
	chmod u+x "${file}"
fi

# Execute file
echo -e "\n"
read -r -n1 -p "Do you want to execute? [Y/N]" option

if [ "${option}" = "Y" ] || [ "${option}" = "y" ]
then
	echo
	echo "Executing file..."
	if python3 "${file}" 2> /dev/null
	then
		echo "Done!!"

	else
		echo "Execution failed"
	fi
else
	echo
fi

