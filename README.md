# SmartCalc v2.0 (Individual project)

## Score:
The final score is 113% (max for base and bonus part 1, bonus part 2 wasn't implemented).

The calc was developed with frontend on QT 6.5.2 (C++).

![calc](misc/calc.png)
![calc_credit](misc/calc_credit.png)

## Task

Implementation of an extended version of the standard calculator in C++ in the object-oriented programming paradigm using MVC pattern.

In addition to basic arithmetic operations such as add/subtract and multiply/divide, the calculator must have the ability to calculate arithmetic expressions by following the order, as well as some mathematical functions (sine, cosine, logarithm, etc.).

Besides calculating expressions, it should also support the use of the _x_ variable and the graphing of the corresponding function.

As for other improvements you can consider a credit and deposit calculator.


## Requirements

- The program must be developed in C++ language of C++17 standard
- Prepare full coverage of expression calculation modules with unit-tests using the GTest library
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests. Installation directory could be arbitrary
- Both integers and real numbers with a dot can be input into the program. You should provide the input of numbers in exponential notation
- The calculation must be done after you complete entering the calculating expression and press the `=` symbol.
- Calculating arbitrary bracketed arithmetic expressions in infix notation
- Calculate arbitrary bracketed arithmetic expressions in infix notation with substitution of the value of the variable _x_ as a number
- Plotting a graph of a function given by an expression in infix notation with the variable _x_ (with coordinate axes, mark of the used scale and an adaptive grid)
   - It is not necessary to provide the user with the ability to change the scale
- Domain and codomain of a function are limited to at least numbers from -1000000 to 1000000
   - To plot a graph of a function it is necessary to additionally specify the displayed domain and codomain
- Verifiable accuracy of the fractional part is at least to 7 decimal places
- Users must be able to enter up to 255 characters
- Bracketed arithmetic expressions in infix notation must support the following arithmetic operations and mathematical functions:
    - **Arithmetic operators**:
      ```
      Brackets (a + b)
      Addition a + b
      Subtraction a - b
      Multiplication a * b
      Division a / b
      Power a ^ b
      Modulus a mod b
      Unary plus +a
      Unary minus -a
      ```
    - **Functions**:
      ```
      Computes cosine cos(x)
      Computes sine sin(x)
      Computes tangent tan(x)
      Computes arc cosine acos(x)
      Computes arc sine asin(x)
      Computes arc tangent atan(x)
      Computes square root sqrt(x)
      Computes natural logarithm ln(x)
      Computes common logarithm log(x)
      ```

## Part 2. Bonus. Credit calculator

Provide a special mode "credit calculator" (you can take banki.ru and calcus.ru as an example):
- Input: total credit amount, term, interest rate, type (annuity, differentiated)
- Output: monthly payment, overpayment on credit, total payment


## Part 3. Bonus. Deposit calculator

Provide a special mode "deposit profitability calculator" (you can take banki.ru and calcus.ru as an example):
- Input: deposit amount, deposit term, interest rate, tax rate, periodicity of payments, capitalization of interest, replenishments list, partial withdrawals list
- Output: accrued interest, tax amount, deposit amount by the end of the term
