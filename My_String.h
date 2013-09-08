/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 1 - STRING Implementation
    September 12, 2013

*****************************************************/

#ifndef MY_STRING_DEF
#define MY_STRING
#endif
const unsigned MAX_LENGTH = 0;

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
// Post: Compares s1 to s2 letter by letter.
//       If, for all i < STRlen(s1) and i < STRlen(s2),
//       s1[i] == s2[i], returns TRUE.
//       Also, guarantees STRlen(s1) == STRlen(s2).
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
// Post: Returns the number of characters contained in STRING s.
//
//       STRINGs are counted per character, starting at one.
//       That is, a STRING's length does not reflect the indices
//       of corresponding character positions.
//       Thus, the length of a STRING directly reflects
//       how many characters it contains.
                      // in
unsigned STRlen(const STRING& s);
/**********************************************/



/**********************************************/
// Pre:  A and B are valid STRINGS containing characters from ASCII extended/ANSI set
// Post: After downcasing both strings,
//       For i < Length(A) and i < Length(B),
//       if A[i] != B[i],
//          && A[i] < B[i], returns TRUE
//              (Thus STRING A comes before B alphabetically)
//          if A[i] > B[i], returns FALSE
//              (Thus STRING B comes before A alphabetically)
//       If, for all i, STRcompare(A[i], B[i]) == TRUE,
//          If Length(A) < Length(B), returns TRUE
//          If Length(A) > Length(B), returns FALSE
//
//       Thus if A comes before B alphabetically, returns TRUE.
//       In any other case, returns FALSE.
                         // in             // in
bool STRalpha_compare(STRING A, STRING B);
/**********************************************/



/**********************************************/
// Pre:  A and B are valid STRINGS, and Length(A) + Length(B) < MAX_LENGTH
// Post: While i < Length(B) && (i + Length(A)) < MAX_LENGTH,
//       A[Length(A) + i] = B[i]
//       B is appended to the end of A until Length(A) == MAX_LENGTH
//
//       A now contains its original contents, plus as much
//       of the contents from B as possible (as per the restrictions
//       set by MAX_LENGTH)
            // out          // in
void STRcat(STRING& A, const STRING& B);
/**********************************************/



/**********************************************/
// Pre: s is a valid STRING, and c is a valid character
// Post: Returns the index of the first occurence of c in the STRING s.
//       Only searches the first MAX_LENGTH characters,
//       If the s does not contain c, returns -1
                         // in      // in
int char_position(const STRING& s, char c);
/**********************************************/



/**********************************************/
// Pre:  s is a valid STRING, and 0 < N <= Length(s).
// Post: Returns the N'th character in the contents of STRING s.
//       Indexing begins at 1, such that the first character is obtained when n = 1,
//       the second character at n = 2, etc.
//       If N > Length(s), behavior is undefined. Returns -1
                        // in      // in
char num_position(const STRING& s, unsigned N);
/**********************************************/



/**********************************************/
// Pre:  s is a valid STRING, containing displayable characters.
// Post: For i < STRlen(s), s[i] is displayed to stdout.
                      // in
void STRdisplay(const STRING& s);
/**********************************************/



/**********************************************/
// Pre:  cstr is a well defined string, as per the standard library,
//       that is null terminated (with '\0' specifically) and str is
//       a valid STRING.
//       For expected behavior, cstr should also contain < MAX_LENGTH characters.
// Post: For i < the length of cstr, str[i] == cstr[i]
//       Converts a string to a STRING, character by character, until
//       str reaches MAX_LENGTH in size.
//       Also removes the null terminator ('/0').
               // out               // in
void STRassign(STRING& str, const char cstr[]);
/**********************************************/



/**********************************************/
// Pre:  s is a valid STRING
// Post: Converts s to an empty STRING such that isEmpty(s) == TRUE,
//       STRlen(s) == 0, and STRdisplay(s) = ''.
                    // out
void create_empty_STR(STRING& s);
/**********************************************/





//               Helper Functions                   //
/****************************************************/

/**********************************************/
// Pre:  s is a valid STRING
// Post: An empty string is defined such that its length is zero.
//       That is, if STRlen(s0) == 0, we say that it is empty and
//       STRdisplay(s) == ''.
//                 //in
bool isEmpty(const STRING& s);
/**********************************************/


/**********************************************/
// Pre:  s is a valid string that contains alphabetic characters from the standard ASCII set.
// Post: All uppercase letters in s are now lowercase. Symbols are not changed.
//               //inout
void toLowerCase(STRING& s);
/**********************************************/

/**********************************************/
// Pre:  s is a valid string that contains characters in the standard ASCII alphabet.
// Post: All lowercase characters in s will be converted to uppercase characters. Symbols remain unchanged.
//                //inout
void toUpperCase(STRING& s);
/**********************************************/

/**********************************************/
// Pre:  s is a valid string, and length <= MAX_LENGTH.
//       Warning! For internal use only. Setting length manually without filling the string's
//       contents can have unforeseen consequences.
// Post: STRlen(s) == length. Does not guarantee the contents are valid or meaningful.
//           //inout            //in
void setLen(STRING& s, unsigned length);
/**********************************************/
