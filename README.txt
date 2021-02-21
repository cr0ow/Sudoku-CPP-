Please notice that generator is a bit diffrent than the one in full-game version,
(only arguments given to fuctions differ)


 --GENERATOR ONLY--

In function sudoku:
 - tab2 - matrix which player fills, initialized with '0' in each cell

In function insertion:
 - x - first coordinate of the matrix
 - y - second coordinate of the matrix
 - start - a randomly-generated digit to insert first, increments by 1 for each iteration
 - tab1 - matrix with solution

 --FULL GAME--

In function map:
 - dif - number of digits revealed at start of the game, depends on difficulty

In function game:
 - mis - number of acceptable mistakes, default value is 3, can be changed in custom game 
 - hin - number of avaible hints, default value is 1, can be changed in custom game

In function insertion: (look above, at generator-only version)

In function end:
 - err - number of mistakes made in last game with which game recognizes if player won or lost