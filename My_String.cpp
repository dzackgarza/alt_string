/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 1 - STRING Implementation
    September 12, 2013

*****************************************************/

#include <iostream>
#include "My_String.h"
using namespace std;

//               Main Functions                     //
/****************************************************/
bool STRcompare (const STRING& s1, const STRING& s2)
{
    if (STRlen(s1) != STRlen(s2)) return false;
    for (unsigned i = 0; i < STRlen(s1) && i < MAX_LENGTH; i++)
    // Note - may not need to compare to MAX_LENGTH. Delete for efficiency..?
    {
        if (s1.contents[i] != s2.contents[i]) return false;
    }
    return true;
}

void STRcopy(STRING& A, const STRING& B)
{
    unsigned i;
    for (i = 0; i < STRlen(B); i++)
    {
        A.contents[i] = B.contents[i];
    }
    setLen(A,i);
}

unsigned STRlen(const STRING& s)
{
    return s.len;
}

bool STRalpha_compare(STRING A, STRING B)
{
    toLowerCase(A);
    toLowerCase(B);

    for (unsigned i = 0; i < STRlen(A) && i < STRlen(B) ; i++)
    {
        if (A.contents[i] != B.contents[i])
        {
            if (A.contents[i] < B.contents[i]) return true;
            else if (A.contents[i] > B.contents[i]) return false;
        }
    }

    // Here it is known that the strings are identical up to the length of the shorter string.
    if (STRlen(A) < STRlen(B)) return true;
    else return false; // (STRlen(A) > STRlen(B))
}

void STRcat(STRING& A, const STRING& B)
{
    unsigned length_A = STRlen(A);
    unsigned i;
    for (i = 0; (length_A + i) < MAX_LENGTH && i < STRlen(B); i++)
    {
        A.contents[length_A + i] = B.contents[i];
    }
    setLen(A, length_A + i);
}

int char_position(const STRING& s, char c)
{
    for (unsigned i = 1; i <= STRlen(s); i++)
    {
        if (s.contents[i-1] == c) return i;
    }
    return -1;
}

char num_position(const STRING& s, unsigned n)
{
    if (n > STRlen(s) || n == 0) return -1;
    else return +s.contents[n-1];
}

void STRdisplay(const STRING& s)
{
    for (unsigned i = 0; i < STRlen(s); i++)
    {
        cout << s.contents[i];
    }
}

void STRassign(STRING& str, const char cstr[])
{
    unsigned i = 0;
    while (cstr[i] != '\0' && i < MAX_LENGTH)
    {
        str.contents[i] = cstr[i]; i++;
    }
    setLen(str, i);
}

void create_empty_STR(STRING& s)
{
    setLen(s, 0);
}


//               Helper Functions                   //
/****************************************************/
void setLen(STRING& s, unsigned length)
{
    s.len = length;
}
bool isEmpty(const STRING& s)
{
    return(s.contents[0] == 0);
}

void toLowerCase(STRING& s)
{
    for (unsigned i = 0; i < STRlen(s); i++)
    {
        if (s.contents[i] >= 'A' && s.contents[i] <= 'Z')
        {
            s.contents[i] |= 'a'-'A'; // 32 = 0010 0000; Equivalent to adding 32 to ASCII value by setting the 5th bit.
        }
    }
}

void toUpperCase(STRING& s)
{
    for (unsigned i = 0; i < STRlen(s); i++)
    {
        if (s.contents[i] >= 'a' && s.contents[i] <= 'z')
        {
            s.contents[i] &= ('A' - 'a' - 1);    // 223 = 1101 1111; Equivalent to subtracting 32 from ASCII value by clearing the 5th bit.
        }
    }
}

bool isEmpty(STRING& s)
{
    if (STRlen(s) == 0) return true;
    else return false;
}
