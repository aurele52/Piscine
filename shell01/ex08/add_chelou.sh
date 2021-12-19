nbr1=`echo $FT_NBR1 | sed 'y/\"?!/1234/' | tr "'" 0`
nbr2=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
nb110=`echo "ibase=5; $nbr1" | bc`
nb210=`echo "ibase=5; $nbr2" | bc`
resultat=$(expr $nb110 + $nb210 )
resultat=`echo "obase=13; $resultat" | bc`
echo $resultat | sed 'y/0123456789abc/gtaio luSnemf/'
