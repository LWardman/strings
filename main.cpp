#include <iostream>
#include <string>
#include <algorithm>

using std::string;


string reverseString(const string& txt)
{
    string reversed(txt.size(), ' ');

    std::ranges::reverse_copy(txt.begin(), txt.end(), reversed.begin());

    return reversed;
}

bool isPalindrome(const string& s)
{
    string inputCopy = s;

    std::ranges::remove_if(inputCopy.begin(), inputCopy.end(), ispunct); // Cleans up punctuation
    std::ranges::remove_if(inputCopy.begin(), inputCopy.end(), isspace); // Cleans up whitespace

    std::transform(inputCopy.begin(), inputCopy.end(), inputCopy.begin(),
                   [](unsigned char c){return std::tolower(c);});

    return inputCopy == reverseString(inputCopy);
}

/**
 * * Rotating a string means that each letter in the string gets sent to the next letter in the alphabet.
 *
 *  * For example. "abc" returns "bcd", "maze" returns "nbaf". Importantly, "z" rotates to "a".
 *
 *  * Uses ASCII conversions to handle the rotation of each character.
 *
 * @param txt The string to be rotated.
 * @returns The rotated string.
 */
string rotateString(const string& txt)
{
    string inputCopy = txt;

    std::transform(inputCopy.begin(), inputCopy.end(), inputCopy.begin(),
                   [](unsigned char c){c++; if (c == '{') c = 'a'; return c;});

    return inputCopy;
}

/**
 * * This function capitalizes a string, which can be useful to transform a string into a more formal string.
 *   Note that this capitalizes ALL words in the sentence. Requires that only single spaces are used between words.
 *
 * * This will be done by comparing ASCII values and doing a conversion if a letter falls into a certain ASCII range.
 *
 * * e.g "hello there" -> "Hello There"
 *
 * @param txt The sentence to capitalize.
 * @returns The capitalized version of the input string.
 */
string capitalizeString(const string& txt)
{
    string capitalString;

    bool bFollowsWhiteSpace = true;

    int ASCII_CONVERTER = -32;      // takes a lower case letter to its capital version.

    int a = 97;                     // ASCII value of 'a' is 97.
    int z = 122;                    // ASCII value of 'z' is 122.

    for (char letter : txt)
    {
        if (bFollowsWhiteSpace)
        {
            if (a <= letter <= z)
            {
                capitalString.push_back(letter + ASCII_CONVERTER);
            }
            else
            {
                capitalString.push_back(letter);
            }

            bFollowsWhiteSpace = false;
        }
        else
        {
            if (letter == ' ')
            {
                bFollowsWhiteSpace = true;
            }
            capitalString.push_back(letter);
        }
    }
    return capitalString;
}

/**
 * * Finds the longest word in a sentence (string). Accepts one word inputs, but will return the same input.
 *
 * * Finds the longest word by iterating through the letters in the string.
 *   If the current char is a whitespace, it checks to see if the word prior to the whitespace is longer than the
 *   current longest word. Then it empties the current word to keep track of the next word.
 *
 * * To get value from this function the user should input a sentence with whitespaces.
 *
 * @param txt The input sentence to find the longest word in.
 * @returns The longest word in the sentence.
 */
string largestWordInString(string txt)
{
    string largestWord;
    string currWord;

    for (char letter : txt)
    {
        if (letter == ' ')
        {
            if (currWord.size() > largestWord.size())
            {
                largestWord = currWord;
            }
            currWord.clear();
        }
        else
        {
            currWord.push_back(letter);
        }
    }

    if (largestWord.empty())
    {
        largestWord = currWord;
    }

    return largestWord;
}


int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    std::cout << isPalindrome(s1) << std::endl;

    string s2 = "hello";
    std::cout << reverseString(s2) << std::endl;

    string s3 = "maze";
    std::cout << rotateString(s3) << std::endl;

    string s4 = "hello there";
    std::cout << capitalizeString(s4) << std::endl;

    string s5 = "what wonderful words";
    std::cout << largestWordInString(s5) << std::endl;

    return 0;
}
