#!/bin/bash

## Mac OS não vem com a maravilhosa função timeout() ##
## perl -e 'alarm shift @ARGV; exec @ARGV' 5 foo arg1 arg2

echo "Realizando testes..."

RESULTADO=$(timeout 20s ./boxstacking < $1)
## Obtém o resultado do último comando e verifica
## se o programa demorou mais que 30 segundos
if [[ $? -eq 30 ]]; then
	echo "ESTOUROU"
## Verifica se resultados batem
fi

while IFS='' read -r line || [[ -n "$line" ]]; do
    if [[ $RESULTADO > $line ]]; then
		echo "Numero se encontra no intervalo correto."
	fi
done < "$2"

# elif [[ $(diff <(echo "$RESULTADO") "$2") != "" ]]; then
# 	echo "INCORRETO"
# else
# 	echo "CORRETO"
# fi
