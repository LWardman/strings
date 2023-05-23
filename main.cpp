#include <iostream>
#include <string>

using std::string;

bool isPalindrome(string s)
{
    for (int i = 0, len = s.size(); i < len; i++)
    {
        if (ispunct(s[i]) || isspace(s[i]))
        {
            s.erase(i--, 1);
            len = s.size();
        }
    }

    std::cout << s << std::endl;

    int frontIdx = 0;
    int backIdx = s.size() - 1;

    while (frontIdx < backIdx)
    {
        if (s[frontIdx] != s[backIdx])
        {
            return false;
        }
        frontIdx++;
        backIdx--;
    }
    return true;
}

/**
 * * A function to reverse a given string, meaning that the character at the final index now belongs to the end index.
 *
 * * Can be used as an alternative to isPalindrome by using if ( string1 == reverseString(string1)),
 *   however this will be case and whitespace sensitive, so more information on the string would be required.
 *
 * * Will be done by creating a temporary string and iterating over the string in reverse order, will make use of
 *   the push_back() function.
 *
 * @param txt The string that the function will reverse.
 * @returns txt in reverse order, eg: "hello" becomes "olleh".
 */
string reverseString(const string& txt)
{
    // Temporary string which will contain the reversed string.
    // We use a temp string because reversing in place will likely lead to loss of information.
    string reversed;

    // Iterating over the string, starting at the final element and working towards the first.
    for (int idx = txt.size() - 1; idx >= 0; idx--)
    {
        reversed.push_back(txt[idx]);
    }

    return reversed;
}

/**
 * * A function to rotate a string, meaning that each letter in the string gets sent to the next letter in the alphabet.
 *
 *  * For example. "abc" returns "bcd", "maze" returns "nbaf". Importantly, "z" rotates to "a"/
 *
 *  * Uses ASCII conversions to handle the rotation of each character.
 *
 * @param txt The string to be rotated.
 * @returns The rotated string.
 */
string rotateString(const string& txt)
{
    string rotatedString;

    for (char letter : txt)
    {
        char ch = letter + 1;

        if (ch == '{') // '{' comes after z.
        {
            ch = 'a';
        }

        rotatedString.push_back(ch);
    }

    return rotatedString;
}


int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    std::cout << isPalindrome(s1) << std::endl;

    string s2 = "hello";
    std::cout << reverseString(s2) << std::endl;

    string s3 = "maze";
    std::cout << rotateString(s3) << std::endl;

    return 0;
}
