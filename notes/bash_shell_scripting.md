# Bash Shell Scripting Reference #
Alexandra Steiner - March 2020

## Redirection ##
- `tree . > myfile.txt` Redirects standard output of the command `tree .` to `myfile.txt`. Overwrites all contents in `myfile.txt`
- `case -l < infile.in > outfile.out` Redirects standard input and output while overwriting
- `case -l < infile.in >> outfile.out` Redirects standard input and output and appends to specified output file
- `case -l < infile.in | less` Pipes standard output from `case -l < infile.in` to the standard input of `less`

## Variables ##
- Create a variable using the syntax `VAR=100`
- Access the value stored in the variable `VAR` using the syntax `echo $VAR`
- Local Variables:
    ```bash
    #!/bin/bash
    HELLO=Hello 
    function hello {
        local HELLO=World
        echo $HELLO
    }
    echo $HELLO
    hello
    echo $HELLO
    ```

## Conditionals ##
- Basic if then syntax
    ```bash
    if [expression]; then
        # Statements if expression is true (Evals to 0)
    fi
    ```
- If then else syntax
    ```bash
    if [expression]; then
        # Statements
    else if [expression]; then
        # Statements
    else
        # Statements
    fi
    ```
- [Link to gnu conditional statement specifications](https://www.gnu.org/software/bash/manual/html_node/Bash-Conditional-Expressions.html)

## Loops ##
- For Loop (very similar to python for loops)
    ```bash
    for i in `seq 1 10`; do
        echo $i
    done
    ```

- While Loop
    ```bash
    while [expression]; do
        # Statements
    done
    ```

## Functions ##
- Basic function syntax. Both are equivilent
    ```bash
    function myfunction {
        # Statements
    }
    newFunct () { # Prefered Method
        # Statements
    }

    myfunction
    newFunct
    ```

- Function arguments. Arguments are specified as `$<argument index>` where `$0` is the function name
    ```bash
    echoArg () {
        echo $1
    }
    echoArg "Hello"
    echoArg " World!"
    ```

- Preferred method for returning a value from a function
    ```bash
    my_function () {
        local func_result="some result"
        echo "$func_result"
    }

    func_result="$(my_function)"
    echo $func_result
    ```

## Misc ##
- The return value of a program can be accessed via the value of `$?`. `$?` contains the return value of the last run program 
- Arithmatic evaluation syntax: `echo $((1+1))`
- Reading user input:
    ```bash
    #!/bin/bash
    echo Please, enter your firstname and lastname
    read FN LN 
    echo "Hi! $LN, $FN !"
    ```
- Program arguments can be recieved by accessing the value of arguments in the same format as function arguments outside of a function (echo $1)




