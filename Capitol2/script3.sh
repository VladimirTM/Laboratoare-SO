#!/bin/bash
hour=$(date +%H)
if [ $hour -gt 6 ] && [ $hour -lt 12 ]
then salut="Buna dimineata"
elif [ $hour -ge 12 ] && [ $hour -lt 18 ]
then salut="Buna ziua"
elif [ $hour -ge 18 ] && [ $hour -lt 22 ]
then salut="Buna seara"
else salut="Noapte buna"
fi
username=$(whoami)
echo "$salut, $username!"
