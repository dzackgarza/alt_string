/*****************************************************

    Zack Garza
    CISP 400 - TTH 5:30 pm
    Programming Project 1 - STRING Implementation
    September 12, 2013

*****************************************************/

#include <iostream>
#include "My_String.h"

using namespace std;

void runtests();

// Primary Functions (1 - 10)
void test_STRcompare (char s1_contents[], char s2_contents[]);
void test_STRcopy(char str_contents[]);
void test_STRlength(char contents[], unsigned actual_length);
void test_alpha_compare(char contents_A[], char contents_B[]);
void test_STRcat(char contents_A[], char contents_B[]);
void test_char_position(char str_contents[], char search_char);
void test_num_position (char str_contents[], unsigned search_num);
void test_STRdisplay(char s[]);   //
void test_STRassign(char s[]);          //
void test_create_empty_STR();

// Helper Functions
void test_case(char contents[], char lc_contents[]);
void test_downcase(char[]);
void test_upcase(char[]);

int main()
{
    runtests();
    return 0;
}

void runtests ()
{
    unsigned choice;
    cout << "Project 1: Modularization\n" << "Test Driver\n";
    while (choice != 0)
    {
        cout
        << "*******************************\n"
        << "1 - Compare\n"
        << "2 - Copy\n"
        << "3 - Length\n"
        << "4 - Compare Alphabetically\n"
        << "5 - Concatentation\n"
        << "6 - Character Position\n"
        << "7 - Numeric Position\n"
        << "8 - Display\n"
        << "9 - Assign\n"
        << "10 - Create Empty\n\n"
        << "0 - Exit Test Program\n"
        << "*******************************\n"
        << "Choose a test: ";

        cin >> choice;
        switch(choice)
        {
            case 1:     // Compare
                char s1[MAX_LENGTH];
                char s2[MAX_LENGTH];
                cout << "Enter two strings to compare.\n";
                cout << "String One:";
                cin >> s1;
                cout << "String Two:";
                cin >> s2;
                test_STRcompare(s1, s2);
                break;
            case 2:     // Copy
                char copy_string[MAX_LENGTH];
                cout << "Enter c-style string to be converted to STRING.";
                cin >> copy_string;
                test_STRcopy(copy_string);
                break;
            case 3:     // Length
                char length_string[MAX_LENGTH];
                unsigned actual_length;
                cout << "Enter test string:";
                cin >> length_string;
                cout << "How many characters are in this string?";
                cin >> actual_length;
                test_STRlength(length_string, actual_length);
                break;
            case 4:     // Alpha
                char alpha_s1[MAX_LENGTH];
                char alpha_s2[MAX_LENGTH];
                cout << "Enter two strings to compare.\n";
                cout << "String One:";
                cin >> alpha_s1;
                cout << "String Two:";
                cin >> alpha_s2;
                test_alpha_compare(alpha_s1, alpha_s2);
                break;
            case 5:     // Concat
                char A[MAX_LENGTH];
                char B[MAX_LENGTH];
                cout << "Enter first string.";
                cin >> A;
                cout << "Enter string to be concatenated onto first string.";
                cin >> B;
                test_STRcat(A,B);
                break;
            case 6:     // Char position
                char string[MAX_LENGTH];
                char search_char;
                cout << "Enter test string:"; // Attempt to overflow this
                cin >> string;
                cout << "Enter character to search for:";
                cin >> search_char;
                test_char_position(string, search_char);
                break;
            case 7:     // Num position
                char num_string[MAX_LENGTH];
                unsigned index;
                cout << "Enter test string:";
                cin >> num_string;
                cout << "Enter the number of the character to find.";
                cin >> index;
                test_num_position(num_string, index);
                break;
            case 8:     // Display
                char display_s[MAX_LENGTH];
                cout << "Enter string to be displayed:";
                cin >> display_s;
                test_STRdisplay(display_s);
                break;
            case 9:     // Assign
                char assign_s[MAX_LENGTH];
                cout << "Enter a standard C string to be assigned to a STRING.";
                cin >> assign_s;
                test_STRassign(assign_s);
                break;
            case 10:    // Create Empty
                cout << "Creating an empty STRING..";
                test_create_empty_STR();
                break;
            case 11:
                char downcase_s[MAX_LENGTH];
                cout << "Enter string to be downcased:";
                cin >> downcase_s;
                test_downcase(downcase_s);
            case 12:
                char upcase_s[MAX_LENGTH];
                cout << "Enter string to be upcased:";
                cin >> upcase_s;
                test_upcase(upcase_s);
                break;
            case 0:
                cout << "Exiting..";
                break;
            default:
                cout << "Invalid choice.";
                break;
            }
        cout << "\n\n";
        }
}
void test_create_empty_STR()
{

}

void test_STRassign(char s[])
{

}

void test_STRdisplay(char s[])
{

}

void test_downcase(char s[])
{

}

void test_upcase(char s[])
{

}
void test_alpha_compare(char contents_A[], char contents_B[])
{
    cout << "\n********** Begin STRING Alpha Compare Test ******************\n";
    // Params
    //char contents_A [] = "Anterior";
    //char contents_B [] = "ante";

    STRING *A = new STRING;
    STRING *B = new STRING;
    STRassign(*A, contents_A);
    STRassign(*B, contents_B);

    cout << "Contents of String A: '" << A->contents << "'.\n";
    cout << "Contents of String B: '" << B->contents << "'.\n";
    cout << "Does '" << A->contents << "' come before '" << B->contents << "' alphabetically?\nSTRalpha_compare says: " << (STRalpha_compare(*A, *B) ? "True" : "False");

    cout << "\n********** End STRING Alpha Compare Test ******************\n";
}

void test_case(char contents[], char lc_contents[])
{
    cout << "\n********** Begin STRING toLowerCase Test ******************\n";
    // Params
    //char contents [] = "dDdDdDdDd";
    //char lc_contents[] = "ddddddddd";   // Manually insert correct lowercase equivalent.
    //

    STRING *s = new STRING;
    STRING *lc_s = new STRING;
    STRassign(*s, contents);
    STRassign(*lc_s, lc_contents);

    cout << "String contents before running toLowerCase: '" << s->contents << "'.\n";
    toUpperCase(*s);
    cout << "String contents after running toUpperCase: '" <<  s->contents << "'.\n";
    toLowerCase(*s);
    cout << "String contents after running toLowerCase: '" <<  s->contents << "'.\n";

    if (STRcompare(*s, *lc_s) == true) cout << "Test passed";
    else cout << "Test failed.";

    cout << "\n********** End STRING toLowerCase Test ******************\n";
}

void test_STRcat(char contents_A[], char contents_B[])
{
    cout << "\n********** Begin STRING Concatentation Test ******************\n";
    // Set paramters
    //char contents_A [] = "aBcDe";
    //char contents_B[] = "1234@";
    //

    STRING *A = new STRING;
    STRING *B = new STRING;
    STRassign(*A, contents_A);
    STRassign(*B, contents_B);
    cout << "String A is '" << A->contents << "'. \n";
    cout << "String B is '" << B->contents << "'. \n";
    STRcat(*A, *B);
    cout << "As a result of STRcat, string A now holds: '" << A->contents << "'.\n";

    cout << "\n********** END STRING Concatentation Test ******************\n";
}

void test_STRlength(char contents[], unsigned actual_length)
{
    cout << "\n********** Begin STRING Length Test ******************\n";
    // Set parameters
    //char contents[] = "abcde";
    //unsigned actual_length = 5; // Manually set the actual length of the string.
    //

    STRING *s = new STRING;
    STRassign(*s, contents);
    cout << "The STRING '" << s->contents << "' has a given length of " << actual_length << " characters.\n";
    cout << "STRlen reports the length as " << STRlen(*s) << ".\n";

    if (STRlen(*s) != actual_length)
    {
        cout << "Results differ. Test failed";
    }
    else
    {
        cout << "Results identical. Test passed.";
    }

    cout << "\n********** End STRING Length Test ******************\n";
}

void test_STRcopy(char str_contents[])
{
    cout << "\n********** Begin STRING Copy Test ******************\n";
    //char str_contents[] = "123456789abcd";
    STRING *A = new STRING;
    STRING *B = new STRING;
    STRassign(*B, str_contents);
    STRcopy(*A, *B);

    cout << "String A is '" << A->contents << "'. \n";
    cout << "String B is '" << B->contents << "'. \n";
    cout << "The result of STRcompare is " << (STRcompare(*A, *B) ? "True" : "False") << ".";

    cout << "\n********** End STRING Copy Test ******************\n";
}

void test_char_position(char str_contents[], char search_char)
{
    cout << "\n********** Begin Character Position Test ******************\n";

    // Set Test Parameters Here
    //char search_char = 'k';
    //char str_contents[] = "abcdefghijkl";
    //

    STRING *my_string = new STRING;
    STRassign(*my_string, str_contents);
    cout << "Your string was '" << my_string->contents << "' and the character requested is '" << search_char << "'. \n";
    int result = char_position(*my_string, search_char);
    if (result == -1)
    {
        cout << "Character '" << search_char << "' not found in string. \n";
    }
    else
    {
        cout << search_char << " found at position " << result << " in string '" << my_string->contents << "'.\n";
    }
    cout << "********** End Character Position Test ******************\n";
}

void test_num_position (char str_contents[], unsigned search_num)
{
    cout << "\n********** Begin Numeric Position Test ******************\n";
    // Set Test Parameters Here
    //unsigned search_num =10;
    //char str_contents[] = "abcdefghijkl";


    STRING *my_string = new STRING;
    STRassign(*my_string, str_contents);
    cout << "Your string was '" << my_string->contents << "' and the position requested is " << search_num << ". \n";
    char result = num_position(*my_string, search_num);
    if (result == -1)
    {
        cout << search_num << " is not a valid position, the string is only " << my_string->len << " letters long. \n";
    }
    else
    {
        cout << "The character at position " << search_num << " of " << my_string->contents << " is " << result << ". \n";
    }
    cout << "********** End Numeric Position Test ******************\n";
}

void test_STRcompare (char s1_contents[], char s2_contents[])
{
    cout << "\n********** Begin STRING Compare Test ******************\n";
    // Set Test Parameters Here
    //char s1_contents[] = "abcdefghijkl";
    //char s2_contents[] = "abcdefghi";
    //

    STRING *s1 = new STRING;
    STRING *s2 = new STRING;
    STRassign(*s1, s1_contents);
    STRassign(*s2, s2_contents);
    bool result = STRcompare(*s1, *s2);

    if (result)
    {
        cout << "The strings '" << s1->contents << "' and '" << s2->contents << "' are identical. \n";
    }
    else
    {
        cout << "The strings '" << s1->contents << "' and '" << s2->contents << "' are not identical. \n";
    }

    cout << "********** End STRING Compare Test ******************\n";
}
