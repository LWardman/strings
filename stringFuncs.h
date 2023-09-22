
#ifndef STRINGS_STRINGFUNCS_H
#define STRINGS_STRINGFUNCS_H

#include <string>
#include <vector>

using std::string;

class stringFuncs {

public:

    static string reverseString(const string& txt);

    static bool isPalindrome(const string& s);


    /**
    * * Rotating a string means that each letter in the string gets sent to the next letter in the alphabet.
    *
    *  * For example. "abc" returns "bcd", "maze" returns "nbaf". Importantly, "z" rotates to "a".
    *
    * @param txt The string to be rotated.
    * @returns The rotated string.
    */
    static string rotateString(const string& txt);

    /**
    *  e.g "My name is" returns {"My", "name", "is"}.
    *
    * @param txt The (ideally multiple worded) string.
    * @return a vector of each individual word in the string.
    */
    static std::vector<string> separateStringIntoWords(const string& txt);

    /**
    * * This function capitalizes a string, which can be useful to transform a string into a more formal string.
    *
    * * Capitalizes ALL words in the sentence.
    *
    * * e.g "hello there" -> "Hello There"
    *
    * @param txt The sentence to capitalize.
    * @returns The capitalized version of the input string.
    */
    static string capitalizeString(const string& txt);

    /**
    * * Finds the longest word in a sentence (string).
    *
    * @param txt The input sentence to find the longest word in.
    * @returns The longest word in the sentence.
    */
    static string largestWordInString(const string& txt);

};

#endif //STRINGS_STRINGFUNCS_H
