/*****************************************************

    Zack Garza
    CISP 400 - TTH 5:30 pm
    Programming Project 1 - STRING Implementation
    September 12, 2013

*****************************************************/

#ifndef MY_STRING_DEF
#define MY_STRING
#endif
const unsigned MAX_LENGTH = 10;

struct STRING
{
    unsigned len;
    char contents[MAX_LENGTH];
};
/**
    What constitutes a valid STRING?

    A valid STRING S is defined as a STRING for which the following conditions hold:
    - S is not null
    - Ample memory has been allocated for S,
    - Length(S) <= MAX_LENGTH
**/


/**********************************************/
// Pre:  s1 and s2 must be valid STRINGS
// Post: Compares s1 to s2 letter by letter. If, for all i < length,
//       s1[i] == s2[i], returns TRUE
                       // in              // in
bool STRcompare (const STRING& s1, const STRING& s2);
/**********************************************/



/**********************************************/
// Pre:  A and B are valid STRINGS
// Post: For i < length(B), A[i] == B[i]
//       Copies the contents of B into A, thus STRcompare(B,A) = TRUE
              // in           // in
void STRcopy(STRING& A, const STRING& B);
/**********************************************/



/**********************************************/
// Pre:  s is a valid STRING
// Post: Returns the number of letters contained in STRING s.
                      // in
unsigned STRlen(const STRING& s);
/**********************************************/



/**********************************************/
// Pre:  A and B are valid STRINGS containing characters from ASCII extended/ANSI set
// Post: After downcasing both strings,
//       For i < Length(A) and i < Length(B),
//       if STRcompare(A[i], B[i] = false
//          && A[i] < B[i], returns TRUE
//              (Thus STRING A comes before B alphabetically)
//          if A[i] > B[i], returns FALSE
//              (Thus STRING B comes before A alphabetically)
//       If, for all i, STRcompare(A[i], B[i]) == TRUE,
//          If Length(A) < Length(B), returns TRUE
//          If Length(A) > Length(B), returns FALSE
//
                         // in             // in
bool alpha_compare(const STRING& A, const STRING& B);
/**********************************************/



/**********************************************/
// Pre:  A and B are valid STRINGS, and Length(A) + Length(B) < MAX_LENGTH
// Post: While i < Length(B) && (i + Length(A)) < MAX_LENGTH,
//       A[i + Length(A)] = B[i]
//       B is appended to the end of A until Length(A) == MAX_LENGTH
            // out          // in
void STRcat(STRING& A, const STRING& B);
/**********************************************/



/**********************************************/
// Pre:
// Post:
//      Returns the index of the first occurence of c in s.
//      If the s does not contain c, returns -1
                         // in      // in
unsigned char_position(const STRING& s, char c);
/**********************************************/



/**********************************************/
// Pre:  0 < N <= Length(s)
// Post: Returns the N'th character in the contents of STRING s.
//       Indexing begins at 1, such that the first character is obtained when n = 1,
//       the second character at n = 2, etc.
//       If n > Length(s), returns -1
                        // in      // in
char num_position(const STRING& s, unsigned N);
/**********************************************/



/**********************************************/
// Pre:
// Post: For i < Length(s), prints s[i]
//          Displays s->contents to stdout
                      // in
void STRdisplay(const STRING& s);
/**********************************************/



/**********************************************/
// Pre:
// Post: For i < Length(cstr) - 1, str[i] == cstr[i]
//       Converts a string to a STRING, removes /0
               // out               // in
void STRassign(STRING& str, const char cstr[]);
/**********************************************/



/**********************************************/
// Pre: s is a valid STRING
// Post: s->contents == "" && s->len == 0
//      Converts s to an empty STRING such that isEmpty(s) == TRUE
                    // out
void create_empty_STR(STRING& s);
/**********************************************/





//               Helper Functions                   //
/****************************************************/

// Pre:  s is a valid STRING
// Post: If the first character in the contents of s is 0,
//       s is defined as an empty STRING and this returns TRUE
//
bool isEmpty(const STRING& s);
/**********************************************/

// Pre:
// Post: All uppercase letters in s are now lowercase.
//           //inout
void toLowerCase(STRING& s);
