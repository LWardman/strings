#include <iostream>
#include <string>
#include "stringFuncs.h"


int main()
{
    std::string s1 = "A man, a plan, a canal: Panama";
    std::cout << stringFuncs::isPalindrome(s1) << std::endl;

    std::string s2 = "hello";
    std::cout << stringFuncs::reverseString(s2) << std::endl;

    std::string s3 = "maze";
    std::cout << stringFuncs::rotateString(s3) << std::endl;

    std::string s4 = "My name is";
    for (const string& word : stringFuncs::separateStringIntoWords(s4))
    {
        std::cout << word << std::endl;
    }

    std::string s5 = "hello there";
    std::cout << stringFuncs::capitalizeString(s5) << std::endl;

    std::string s6 = "what wonderful words";
    std::cout << stringFuncs::largestWordInString(s6) << std::endl;

    return 0;
}
