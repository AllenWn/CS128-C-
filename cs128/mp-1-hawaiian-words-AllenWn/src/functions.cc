#include "functions.hpp"

#include <iostream>
#include <vector>
#include <cctype>
 
#include <string>
#include<map>

/**
 * TODO: Implement this function
 * @param word word to change to lowercase
 * @return result of changing every character in word to lowercase
 */
std::string StringToLower(const std::string& word) {
  std::string str;
  for (char c : word) {
    // c = std::tolower(static_cast<unsigned char>(c)); // 使用tolower转换每个字符
    str += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    //putchar (tolower(c));
    //str += c;
  }
  std::cout << "Input to StringToLower() : " << str << std::endl;
  return str;
}

/**
 * TODO: Implement this function
 * @param v1 first character in potential vowel group
 * @param v2 second character in potential vowel group
 * @return true if v1 and v2 form a valid vowel group
 */
bool IsVowelGroup(const char& v1, const char& v2) {
  std::vector<std::string> vowel_group {"ai", "ae", "ao", "au", "ei", "eu", "iu", "oi", "ou", "ui"};
  std::string str;
  str += v1;
  str += v2;
  if (std::find(vowel_group.begin(), vowel_group.end(), str) == vowel_group.end()) {
    return false;
  }
  std::cout << "Input to IsVowelGroup() : \"" << v1 << "\" \"" << v2 << "\""
            << std::endl;
  return true;
}

/**
 * TODO: Complete this function
 * @param v potential vowel character
 * @return true if v is a vowel
 */
bool IsVowel(const char& v) {
  std::vector<char> vowel {'a', 'e', 'i', 'o', 'u'};
  if (std::find(vowel.begin(), vowel.end(), v) == vowel.end()) {
    return false;
  }
  std::cout << "Input to IsVowel() : \"" << v << "\"" << std::endl;
  return true;
}

/**
 * TODO: Complete this function
 * @param c potential consonant character
 * @return true if c is a consonant
 */
bool IsConsonant(const char& c) {
  std::vector<char> consonants{'p', 'k', 'h', 'l', 'm', 'n', 'w'};
  if (std::find(consonants.begin(), consonants.end(), c) == consonants.end()) {
    return false;
  }
  std::cout << "Input to IsConsonant() : \"" << c << "\"" << std::endl;
  return true;
}

/**
 * TODO: Implement this function
 * @param c character to check validity of
 * @return true if input c is a valid character in the Hawaiian language, false
 * otherwise
 */
bool IsValidCharacter(const char& c) {
  std::vector<char> val_char {'a', 'e', 'i', 'o', 'u', 'p', 'k', 'h', 'l', 'm', 'n', 'w', ' ', '\''};
  if (std::find(val_char.begin(), val_char.end(), c) == val_char.end()) {
    return false;
  }
  std::cout << "Input to IsValidCharacter() : \"" << c << "\"" << std::endl;
  return true;
}

/**
 * TODO: Implement this function
 * @param word word to check validity of
 * @return true if every character in word is a valid character in the Hawaiian
 * language, false otherwise
 */
bool IsValidWord(const std::string& word) {
  for (auto c : word) {
    if (!IsValidCharacter(c)) {
      return false;
    }
  }
  std::cout << "Input to IsValidWord() : " << word << std::endl;
  return true;
}

/**
 * TODO: Implement this function
 * @param c consonant to get pronunciation of
 * @param prev character before c, used for determining w translation
 *    set to null character as default if no value is passed in
 * @return pronunciation of the consonant c as a char
 */
char ConsonantPronunciation(const char& c, const char& prev) {
  if (c != 'w') {
    return c;
  } else {
    std::string str;
    str += prev;
    str += c;
    if (str == "aw") {
      return 'w';
    } else if (str == "iw" || str == "ew") {
      return 'v';
    } else {
      return 'w';
    }
  }
  std::cout << "Input to ConsonantPronunciation() : \"" << c << "\" \"" << prev
            << "\"" << std::endl;
  return '\0';
}

/**
 * TODO: Implement this function
 * @param v1 first vowel in a vowel grouping
 * @param v2 second vowel in a vowel grouping
 * @return the pronunciation of the vowel grouping made up of v1 and v2
 * as a string
 */
std::string VowelGroupPronunciation(const char& v1, const char& v2) {
  std::string str;
  str += v1;
  str += v2;
  std::map<std::string, std::string> vowel_group = {
        {"ai", "eye"},
        {"ae", "eye"},
        {"ao", "ow"},
        {"au", "ow"},
        {"ei", "ay"},
        {"eu", "eh-oo"},
        {"iu", "ew"},
        {"oi", "oy"},
        {"ou", "ow"},
        {"ui", "ooey"}
    };
  std::cout << "Input to VowelGroupPronunciation() : \"" << v1 << "\" \"" << v2
            << "\"" << std::endl;
  return vowel_group[str];
}

/**
 * TODO: Implement this function
 * @param v single vowel to get pronunciation of
 * @return the pronunciation of v as a string
 */
std::string SingleVowelPronunciation(const char& v) {
  std::map<char, std::string> single_vowel{
    {'a', "ah"},
    {'e', "eh"},
    {'i', "ee"},
    {'o', "oh"},
    {'u', "oo"}
  };
  std::cout << "Input to SingleVowelPronunciation() : \"" << v << "\""
            << std::endl;
  return single_vowel[v];
}

/**
 * TODO: Implement this function
 * @param prev first character in set of three passed to function
 * @param curr second character in set of three passed to function
 * @param next third character in set of three passed to function
 * @return pronunciation of curr using next and prev as needed to determine
 * result
 */
std::string ProcessCharacter(const char& prev,
                             const char& curr,
                             const char& next) {
  if (IsVowelGroup(curr, next)) {
    return VowelGroupPronunciation(curr, next);
  } else if (IsVowel(curr)) {
    return SingleVowelPronunciation(curr);
  } else if (IsConsonant(curr)) { 
    std::string constr;
    constr += ConsonantPronunciation(curr, prev);
    return constr;
  }
  std::string str;
  str += curr;
  std::cout << "Input to ProcessCharacter() : \"" << prev << "\" \"" << curr
            << "\" \"" << next << "\"" << std::endl;
  return str;
}

/**
 * TODO: Implement this function
 * @param word string to get pronunciation of
 * @return pronunciation of word
 */
std::string Pronunciation(const std::string& word) {
  std::string str = " ";
  str += word;
  str += " ";
  std::string result;
  for (size_t i = 1; i < str.size() - 1; ++i) {
    char prev = str[i - 1];
    char curr = str[i];
    char next = str[i + 1];
    result += ProcessCharacter(prev, curr, next);
    if (IsVowelGroup(curr, next) || IsVowel(curr)) {
      result += '-';
    }
    if (IsVowelGroup(curr, next)) {
      i++;
    }
  }
  if (result[result.size() - 1] == '-') {
    result.pop_back();
  }
  for (size_t i = 1; i < result.size(); ++i) {
    if ((result.at(i - 1) == '-' && result.at(i) == ' ') || (result.at(i - 1) == '-' && result.at(i) == '\'')) {
      result.erase(i - 1, 1);
    }
  }
  std::cout << "Input to Pronunciation() : " << word << std::endl;
  return result;
}

/**
 * TODO: Implement this function
 * @param hawaiian_word word to get pronunciation of
 * @return the pronunciation of hawaiian_word as a string if valid
 *  and throws an invalid_argument error if not valid
 */
std::string GetPronunciation(const std::string& hawaiian_word) {
  std::string word_low = StringToLower(hawaiian_word);
  if (!IsValidWord(word_low)) {
    throw std::invalid_argument("not a valid word");
  } 
  std::cout << "Input to GetPronunciation() : " << hawaiian_word << std::endl;
  return Pronunciation(word_low);
}