alt_string
==========

An implementation of String that foregoes the null terminator in favor of manually tracking length.

======================================================================================================

CISP 430 Data Structures Fall 2013
Project 1: Modularization
 2013 David E. Fox

An important aspect of software development is modularization. When projects
become large it is impossible for any one person or group of people to comprehend it in its
entirety. In order to accomplish large projects, they are broken down into smaller pieces
and then these are broken down even more, until sub-problems are small enough that they
can be solved easily. As each of these sub-problems is solved, they are set aside in units
that are called modules. If carefully constructed, these modules can be reused in other
projects without need of further work.

It is generally accepted, that modules should be separated into two parts, the
interface between the user of the module and the developer, this interface is called the
specification. The second part is the problem solution and is called the implementation.
It is important that the user is given all of the information needed to use the module in the
specifications. However, the specifications should not contain any more information than
is needed. This process of information hiding serves two main purposes. First, it allows
the user to concentrate on the larger problem without becoming bogged down in the
details of the module. Second, it allows the module developer to change the
implementation without concern for assumptions that the user may have made about the
underlying structure of the module.

For this project, you will develop a module that will provide the user with several
functions for dealing with strings. You should attempt to make each of these functions as
efficient as possible. As you may recall, in C a string is a built-in array of type char with the
last character in the string the null character '\0'. However, we will create our own
implementation of a string as follows. Our STRING type will be implemented using a
struct with two data members, an unsigned int and a statically allocated array of
char that will hold MAX_STRING characters. MAX_STRING will be a constant defined in
the specification (.h) file. The unsigned int will keep track of how many characters in
the array of char are part of our STRING, that is, the number of valid characters in the
MAX_STRING character array.

The MAX_STRING-character array MUST NOT be null-terminated.

======================================================================================================

You will provide the following functions for STRING manipulation:


1
STRING compare. This function will take two STRING arguments and return a
Boolean (bool), true if they are exactly the same, character-by-character, and
false otherwise. Remember that any character after the number of characters
specified in the unsigned int is not valid. This function will be case sensitive,
that is, “A” != “a”

2
STRING copy. This function will take two STRING arguments, A and B. It will put a
copy of string B into string A.

3
STRING length. This function will take one STRING as an argument and will return
the number of characters in the STRING (only those that are valid).

4
Compare alphabetically. This function takes two STRING arguments, A and B. If A
comes before B alphabetically, it function returns true, otherwise it returns false.

5
STRING concatenation. This function will take two STRING arguments, A and B. It
will combine them such that string B is appended to the end of A. For example,
given A = "abcd" and B = "efgh", the function will change A so that it now
contains "abcdefgh". STRING B will be unchanged by the function.

6
Character position. This function takes a STRING and a character as arguments. It
returns the position in the STRING of the first occurrence of the character. If the
string does not contain the character, it returns -1.

7
Numeric position. This function takes a STRING and an integer n as arguments. It
returns the character at the nth position in the string. If n is larger than the length
of the string the function should return -1.

8
Display STRING. This function takes a STRING as argument and displays that
string to standard out.

9
Assign a STRING. This function takes a STRING argument and a null-terminated C
string and assigns the C string to the STRING.

10
Create an empty STRING. This function takes a STRING as an argument and
converts it into the empty string.You will write a complete specification for this module in the form of a header file.

======================================================================================================

These specifications should include, a function prototype, precise pre and post-conditions
for each function. The user of the module should be able to know exactly why and when a
true or false is returned and be given an exact definition of the set of data for which
each function is defined. Careful consideration should be given to how parameters are
passed. Parameters should be passed so that the function cannot alter parameters that
need not be altered (const).

You will be required to include comments stating if a parameter is, /*in*/,
/*out*/, or /*inout*/.

You will implement the module and provide a test driver in separate files. The test
driver should ask the tester to choose one of the above functions and then prompt for
appropriate input. After the function has completed its task, the results should be
displayed; this includes appropriate error messages. You need not perform error tests on
the test driver input, however, you may need to do various error testing in the functions.

You must use iostream for all input and output.

Note: the final project will consist of three files, the module specification (header) file, the
module implementation file, and the file that contains the test driver (function main). These
files will be named:
My_String.h
My_String.cpp
My_String_Main.cpp

You MUST NOT use any C/C++ built-in string manipulation functions in your
implementation! However, you are to use your own functions in the implementation of
other parts, for example, you must use your function that returns the length of a string in
your function that compares the length of two strings.

You MUST NOT use any literal values that correspond to ASCII values. For instance, if
you decide that you need to know the ASCII value for the character 'A', just use the
character 'A'; DO NOT use the number 65d.
