#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "tree_list_tpt.h"
#include <algorithm>
#include <cctype>

using namespace std;

tree<string> t;  //declare tree

//std::string text_line; //line to retrieve entire line of text from file
ifstream tree_file("morse-code.txt");

std::string _alpha;  //decode letter
std::string morse_overlay; //encode letter overlay
std::string encode_morse; //morse code symbol
int _index; //index to sort 
std::string blankSpace; // blank line

bool decoding; // bool to determine whether user wants to encode/decode
std::string user_string; // string that user wants to translate

  //temp string to later be casted
std::string str_index, str_alpha, str_morse_overlay;

//method to read in from a file and assemble the tree
void assemble_tree();

//method to ask whether you want to encode or decode
bool prompt_input_type();

//method to retrieve morse code from user
std::string get_user_morse();

//method to retrieve sentence from user
std::string get_user_sentence();

//method that takes in user's morse code and translates it
void handle_decoding(std::string s);

//method that takes in user's sentence and translates it
void handle_encoding(std::string s);


//
//MAIN PROGRAM BEGIN
//
int main(void)
{
	//read in file, build tree
	assemble_tree();
	
	//main program loop that handles user input and translation
	while(true){
		//get users input to choose whether to decode or encode
		decoding = prompt_input_type();

		//keep allowing user to decode
		if(decoding){
		
			//obtain user's morse code 
			user_string = get_user_morse();

			//decode it
			handle_decoding(user_string);
		}
		else if(!decoding){
		
			//obtain user's sentence 
			user_string = get_user_sentence();
			for (int i=0; i<user_string.length(); i++){
				if(!isalpha(user_string[i]) && user_string[i]!=char(32)){
					cout << "Invalid Input" << endl;
					break;
				}
				if(i==user_string.length()-1){
				//encode it
				handle_encoding(user_string);
				}
			}

			
		}
	}

#pragma region old_test_stuff
	
#pragma endregion old test stuff	
	system("pause");

}
//
//MAIN PROGRAM END
//







//method to read in from a file and assemble the tree
void assemble_tree(){
	if(tree_file.is_open()){
		while(tree_file.good()){

			//read in as strings
			getline(tree_file, str_index);
			getline(tree_file, _alpha);
			getline(tree_file, encode_morse);
			getline(tree_file, morse_overlay); 
			getline(tree_file, blankSpace); // handles blank lines

			//cast to other types
			_index = atoi(str_index.c_str());


			//insert into tree
			t.insert(_index, _alpha, encode_morse, morse_overlay);

			//output as reading in
			//cout << _index << endl;
			//cout << _alpha << endl;
			//cout << encode_morse << endl;
			//cout << morse_overlay << endl;
			//cout << "" << endl; //blank line
		}
		tree_file.close();
	}
	else{
		cout << "Unable to open file" << endl;
	}


	#pragma region temp_tree_testing
	
	#pragma endregion temp_tree_testing
}

//method to ask whether you want to encode or decode
bool prompt_input_type(){
	std::string answer;

	cout << "would you like to encode or decode?" << endl;
	getline(cin, answer);

	if(answer == "encode" || answer == "ENCODE" || answer == "e" || answer == "E"){
		return false;
	}
	else if(answer == "decode" || answer == "DECODE" || answer == "D" || answer == "d"){
		return true;
	}
	else{
		cout << "invalid input" << endl;
		prompt_input_type();
	}
}

//method to retrieve morse code from user
std::string get_user_morse(){
	std::string tmp_user_morse;

	cout << "" << endl;
	cout << "please enter morse code sentence with spaces in between each morse letter \n" <<
		"and two spaces in between each morse word." << endl;
	getline(cin, tmp_user_morse);

	cout << "" << endl;
	cout << "your morse code" << endl;
	cout << tmp_user_morse << endl;
	cout << "" << endl;

	return tmp_user_morse;
}

//method to retrieve sentence from user
std::string get_user_sentence(){
	std::string tmp_user_sentence;

	cout << "" << endl;
	cout << "please enter your sentence" << endl;
	getline(cin, tmp_user_sentence);
	cout << "" << endl;
// here
	transform (tmp_user_sentence.begin(), tmp_user_sentence.end(), tmp_user_sentence.begin(), ::toupper);
	cout << "your sentence:" << endl;
	cout << tmp_user_sentence << endl;
	cout << "" << endl;

	return tmp_user_sentence;
}

//method that takes in user's morse code and translates it
void handle_decoding(std::string s){
	std::string decoded_message;

	//call the decoding method
	decoded_message = t.decode(s);

	cout << "" << endl; 
	cout << "your translated sentence:" << endl;
	cout << decoded_message << endl;
	cout << "" << endl; 
}

//method that takes in user's sentence and translates it
void handle_encoding(std::string s){
	std::string encoded_message;

	//call the encoding method
	encoded_message = t.encode(s);

	cout << "" << endl; 
	cout << "your translated morse code:" << endl;
	cout << encoded_message << endl;
	cout << "" << endl; 
}
