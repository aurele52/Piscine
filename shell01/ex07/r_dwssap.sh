cat /etc/passwd | cut -d: -f1 | sed '/^#/d' | sed -n 'n;p' | rev | sort -rd | sed -n $FT_LINE1','$FT_LINE2'p' | tr '\n' ' ' | sed "s/ /, /g" | sed "s/, $/./g"
