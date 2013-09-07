/*****************************************************

    Zack Garza
    CISP 400 - TTH 5:30 pm
    Programming Project 1 - STRING Implementation
    September 12, 2013

*****************************************************/

#include <iostream>
#include "My_String.h"
using namespace std;

bool STRcompare (const STRING& s1, const STRING& s2)
{
    if (STRlen(s1) != STRlen(s2)) return false;
    for (int i = 0; i < STRlen(s1) && i < MAX_LENGTH; i++)
    {
        if (s1.contents[i] != s2.contents[i]) return false;
    }
    return true;
}

void STRcopy(STRING& A, const STRING& B)
{
    int i = 0;
    for (; i < B.len; i++)
    {
        A.contents[i] = B.contents[i];
    }
    A.len = i;
}

unsigned STRlen(const STRING& s)
{
    return s.len;
}

bool alpha_compare(STRING A, STRING B)
{
    toLowerCase(A); toLowerCase(B);
    for (int i = 0; i < A.len && i < B.len; i++)
    {
        if (A.contents[i] != B.contents[i])
        {
            if (A.contents[i] < B.contents[i]) return true;
            else if (A.contents[i] > B.contents[i]) return false;
        }
    }
    if (STRlen(A) < STRlen(B)) return true;
    else if (STRlen(A) > STRlen(B)) return false;
}

void STRcat(STRING& A, const STRING& B)
{
    unsigned length_A = STRlen(A);
    int i = 0;
    for (; (length_A + i) < MAX_LENGTH && i < STRlen(B); i++)
    {
        A.contents[length_A + i] = B.contents[i];
    }
    A.len = length_A + i;
}

unsigned char_position(const STRING& s, char c)
{
    for (int i = 1; i <= s.len; i++)
    {
        if (s.contents[i-1] == c) return i;
    }
    return -1;
}

char num_position(const STRING& s, unsigned n)
{
    if (n > s.len || n == 0) return -1;
    else return +s.contents[n-1];
}

void STRdisplay(const STRING& s)
{
    for (int i = 0; i < s.len; i++)
    {
        cout << s.contents[i];
    }
}

void STRassign(STRING& str, const char cstr[])
{
    int i = 0;
    while (cstr[i] != '\0' && i < MAX_LENGTH)
    {
        str.contents[i] = cstr[i]; i++;
    }
    str.len = i;
}

void create_empty_STR(STRING& s)
{
    s.contents[0] = 0;
    s.len = 0;
}


//               Helper Functions                   //
/****************************************************/
bool isEmpty(const STRING& s)
{
    return(s.contents[0] == 0);
}

void toLowerCase(STRING& s)
{
    for (int i = 0; i < s.len; i++)
    {
        s.contents[i] |= 32; // 32 = 0010 0000; Equivalent to adding 32 to ASCII value by setting the 5th bit.
    }
}

void toUpperCase(STRING& s)
{
    for (int i = 0; i < s.len; i++)
    {
        s.contents[i] &= 223;    // 223 = 1101 1111; Equivalent to subtracting 32 from ASCII value by clearing the 5th bit.
    }
}
