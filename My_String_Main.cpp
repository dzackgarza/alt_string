/*****************************************************

    Zack Garza
    CISP 400 - TTH 5:30 pm
    Programming Project 1 - STRING Implementation
    September 12, 2013

*****************************************************/

#include <iostream>
#include "My_String.h"

using namespace std;

void test_STRcompare();
void test_STRcopy();
void test_STRlength();
void test_STRcat();
void test_char_position();
void test_num_position();
void test_STRdisplay();
void test_STRassign();
void test_create_empty_STR();
void test_downcase();
void test_alpha_compare();
void runtests();

int main()
{
    runtests();
    return 0;
}

void runtests ()
{
    test_char_position();
    test_num_position();
    test_STRcompare();
    test_STRcopy();
    test_STRlength();
    test_STRcat();
    test_downcase();
    test_alpha_compare();
}

void test_alpha_compare()
{
    cout << "\n********** Begin STRING Alpha Compare Test ******************\n";
    // Params
    char contents_A [] = "anterior";
    char contents_B [] = "ante";

    STRING *A = new STRING;
    STRING *B = new STRING;
    STRassign(*A, contents_A);
    STRassign(*B, contents_B);

    cout << "Contents of String A: '" << A->contents << "'.\n";
    cout << "Contents of String B: '" << B->contents << "'.\n";
    cout << "Does '" << A->contents << "' come before '" << B->contents << "' alphabetically? " << (alpha_compare(*A, *B) ? "True" : "False");

    cout << "\n********** End STRING Alpha Compare Test ******************\n";


}
void test_downcase()
{
    cout << "\n********** Begin STRING toLowerCase Test ******************\n";
    // Params
    char contents [] = "AaAaAaAaA";
    char lc_contents[] = "aaaaaaaaa";   // Manually insert correct lowercase equivalent.
    //

    STRING *s = new STRING;
    STRING *lc_s = new STRING;
    STRassign(*s, contents);
    STRassign(*lc_s, lc_contents);

    cout << "String contents before running toLowerCase: '" << s->contents << "'.\n";
    toLowerCase(*s);
    cout << "String contents after running toLowerCase: '" <<  s->contents << "'.\n";

    if (STRcompare(*s, *lc_s) == true) cout << "Test passed";
    else cout << "Test failed.";

    cout << "\n********** End STRING toLowerCase Test ******************\n";
}

void test_STRcat()
{
    cout << "\n********** Begin STRING Concatentation Test ******************\n";
    // Set paramters
    char contents_A [] = "aBcDe";
    char contents_B[] = "1234@";
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

void test_STRlength()
{
    cout << "\n********** Begin STRING Length Test ******************\n";
    // Set parameters
    char contents[] = "abcde";
    unsigned actual_length = 5; // Manually set the actual length of the string.
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

void test_STRcopy()
{
    cout << "\n********** Begin STRING Copy Test ******************\n";
    char str_contents[] = "123456789abcd";
    STRING *A = new STRING;
    STRING *B = new STRING;
    STRassign(*B, str_contents);
    STRcopy(*A, *B);

    cout << "String A is '" << A->contents << "'. \n";
    cout << "String B is '" << B->contents << "'. \n";
    cout << "The result of STRcompare is " << (STRcompare(*A, *B) ? "True" : "False") << ".";

    cout << "\n********** End STRING Copy Test ******************\n";
}

void test_char_position()
{
    cout << "\n********** Begin Character Position Test ******************\n";

    // Set Test Parameters Here
    char search_char = 'k';
    char str_contents[] = "abcdefghijkl";
    //

    STRING *my_string = new STRING;
    STRassign(*my_string, str_contents);
    cout << "Your string was '" << my_string->contents << "' and the character requested is '" << search_char << "'. \n";
    unsigned result = char_position(*my_string, search_char);
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

void test_num_position ()
{
    cout << "\n********** Begin Numeric Position Test ******************\n";
    // Set Test Parameters Here
    unsigned search_num =10;
    char str_contents[] = "abcdefghijkl";
    //

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

void test_STRcompare ()
{
    cout << "\n********** Begin STRING Compare Test ******************\n";
    // Set Test Parameters Here
    char s1_contents[] = "abcdefghijkl";
    char s2_contents[] = "abcdefghi";
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
