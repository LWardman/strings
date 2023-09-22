
#include "stringFuncs.h"

#include <string>
#include <algorithm>

using std::string;

string stringFuncs::reverseString(const string& txt)
{
    string reversed(txt.size(), ' ');

    std::ranges::reverse_copy(txt.begin(), txt.end(), reversed.begin());

    return reversed;
}

bool stringFuncs::isPalindrome(const string& s)
{
    string inputCopy = s;

    std::ranges::remove_if(inputCopy.begin(), inputCopy.end(), ispunct); // Cleans up punctuation
    std::ranges::remove_if(inputCopy.begin(), inputCopy.end(), isspace); // Cleans up whitespace

    std::transform(inputCopy.begin(), inputCopy.end(), inputCopy.begin(),
                   [](unsigned char c){return std::tolower(c);});

    return inputCopy == reverseString(inputCopy);
}

string stringFuncs::rotateString(const string& txt)
{
    string inputCopy = txt;

    std::transform(inputCopy.begin(), inputCopy.end(), inputCopy.begin(),
                   [](unsigned char c){c++; if (c == '{') c = 'a'; return c;});

    return inputCopy;
}

std::vector<string> stringFuncs::separateStringIntoWords(const string& txt)
{
    std::vector<string> words;

    int start = 0;
    int end = 0;

    char space = ' ';

    while ((start = txt.find_first_not_of(space, end)) != string::npos)
    {
        end = txt.find(space, start);

        words.push_back(txt.substr(start, end - start));
    }

    return words;
}

string stringFuncs::capitalizeString(const string& txt)
{
    std::vector<string> splitString = separateStringIntoWords(txt);

    string capitalizedString;

    for (string word : splitString)
    {
        word[0] = std::toupper(word[0]);
        capitalizedString += word;
        capitalizedString += ' ';
    }

    capitalizedString.erase(capitalizedString.end() - 1, capitalizedString.end());

    return capitalizedString;
}

string stringFuncs::largestWordInString(const string& txt)
{
    std::vector<string> words = separateStringIntoWords(txt);

    std::ranges::sort(words.begin(), words.end(),
                      [](const string& lhs, const string& rhs)
                      {return lhs.size() > rhs.size();});

    return words[0];
}
