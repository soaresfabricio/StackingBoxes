# Box Stacking Problem


Solving and testing the Box Stacking Problem
code inspired by the solution discussed [here](http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem/).

### INPUT

* First line: The number of tests to execute;
* Next lines: Sets of boxes.

A Set of boxes has the following format:

* First line: The number of boxes on the set;
* Next lines: Three space-separated values representing each box from the set.

Example with ``1`` test and the set ``{ {1, 2, 3} , { 3, 4, 5 } }`` :

```
1
2
1 2 3
3 4 5
```

### OUTPUT

The number representing the maximum possible height of the stack made by the provided set of boxes.

### TESTING

To test everything, you'll need to run a :

	make test

``geraCasos.sh`` will, through a parameter ``N``, generate a set of ``N`` boxes containing random variables. Check the files ``casos.entrada`` for the input, and ``casos.resposta`` for the correct answers.

Example: 

	./geraCasos.sh 7

The script `testes.sh` receives the two files `casos.*` as inputs and tries to check for a possible processing timeout that surpasses 20 seconds, and also if the answers fit with the sets. To 

