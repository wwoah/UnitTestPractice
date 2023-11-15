#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string pass){
	bool lower = false;
	bool upper = false;

	for(int i = 0; i < pass.size();i++){
		for(int  j = 0; j < pass.size(); j++){
			if(pass[i] == toupper(pass[j])){
				upper = true;
			}
			else if (pass[i] == tolower(pass[j])){
				lower = true;
			}	
		}
	}

	return lower && upper;
}

Password::Password(){
	pass_history = {};		
}

 /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
void Password::set(string pass){
	bool conditions = true;
	int size = pass.length();

		if(size > 8)
			conditions = false;

		for(int i = 0; i < 2; i++){
			char temp = pass[i+1];
                	if(pass[i]==temp){
                        	conditions = false;
				break;
			}
			else if(i == 1){
				break;
			}
        	}

		for(int i = 0; i < pass_history.size(); i++){
			if(pass == pass_history[i])
				conditions = false;
				break;
		}

		if(!has_mixed_case(pass))
			conditions = false;
	
	if(conditions)
		pass_history.push_back(pass);
}

bool Password::authenticate(string){
	return false;
}
