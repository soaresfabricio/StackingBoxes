#!/bin/bash

entrada="casos.entrada"
respostas="casos.respostas"

if [ -f $entrada ] ; then
    rm $entrada
fi

if [ -f $respostas ] ; then
    rm $respostas
fi

echo "1" >> casos.entrada
echo $1 >> casos.entrada

let "soma1 = 0"
let "soma2 = 0"
let "soma3 = 0"


for (( i = 0; i < $1; i++ )); do
  
  for (( j = 0; j < 3; j++ )); do

      _QUANTOS_ITENS=${RANDOM}
      let "_QUANTOS_ITENS %= 100"
      let "_QUANTOS_ITENS +=1"
      if [[ $j -eq 0 ]]; then
        let "soma1+=_QUANTOS_ITENS"
      fi
      if [[ $j -eq 1 ]]; then
        let "soma2+=_QUANTOS_ITENS"
      fi
      if [[ $j -eq 2 ]]; then
        let "soma3+=_QUANTOS_ITENS"
      fi
      echo -n "${_QUANTOS_ITENS} " >> casos.entrada
  done
  echo " " >> casos.entrada


done

  echo -n "$soma1" >> casos.respostas
  echo "" >> casos.respostas
  echo -n "$soma2" >> casos.respostas
  echo "" >> casos.respostas
  echo -n "$soma3" >> casos.respostas


# for (( j = 0; j < $1; j++ )); do
#   _NUM_ITENS=${RANDOM}
#   let "_NUM_ITENS %= 100"
#   let "_NUM_ITENS += 1"
#   echo "${_NUM_ITENS}"

#   _MAX_WEIGHT=${RANDOM}
#   let "_MAX_WEIGHT %= 100"
#   let "_MAX_WEIGHT += 1"
#   echo "${_MAX_WEIGHT}"

#   for (( i = 0; i < ${_NUM_ITENS}; i++ )); do
#     _value=${RANDOM}
#     let "_value %= 100"
#     let "_value += 1"
#     echo -n "${_value} "
#   done
#   echo

#   for (( i = 0; i < ${_NUM_ITENS}; i++ )); do
#     _weigth=${RANDOM}
#     let "_weigth %= 100"
#     let "_weigth += 1"
#     echo -n "${_weigth} "
#   done
#   echo

# done
