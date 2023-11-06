#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>

using std::string;

class Password
{
public:
  /*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
  */
  int count_leading_characters(string);
  /*The function that checks if there are upper case and lower case present within the password*/
  bool has_mixed_case(string);
};
#endif
