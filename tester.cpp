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
	//cout << "TESTING BINARY SEARCH TREE METHODS" << endl;
	//tree<string> t;
	//tree<string> t2;
	//t2.insert("40");
	//t2.insert("50");
	//t2.insert("45");
	//t2.insert("60");
	//t2.insert("55");
	//t2.insert("47");
	//t2.insert("30");
	//t2.insert("35");
	//t2.insert("32");
	//
	//// test SMALLEST
	//cout << "\nTESTING SMALLEST METHOD" << endl;
	//
	//try {
	//	t.smallest();
	//	cout << "\tSMALLEST for empty tree does NOT throw domain error exception. (INCORRECT)" << endl;
	//}
	//catch (domain_error &de) {
	//	cout << "\tSMALLEST for empty tree throws domain error exception. (CORRECT)" << endl;
	//}
	//cout << "\tBuilding test tree." << endl;
	//
	//t2.pre_print();
	//cout << endl;
	//if (t2.smallest() == "30")
	//	cout << "\tSmallest element of tree == \"30\". (CORRECT)" << endl;
	//else
	//	cout << "\tSmallest element of tree != \"30\". (INCORRECT)" << endl;
	//
	//// test LARGEST
	//cout << "\nTESTING LARGEST METHOD" << endl;
	//
	//try {
	//	t.largest();
	//	cout << "\tLARGEST for empty tree does NOT throw domain error exception. (INCORRECT)" << endl;
	//}
	//catch (domain_error &de) {
	//	cout << "\tLARGEST for empty tree throws domain error exception. (CORRECT)" << endl;
	//}
	//cout << "\tBuilding test tree." << endl;
	//if (t2.largest() == "60")
	//	cout << "\tLargest element of tree == \"60\". (CORRECT)" << endl;
	//else
	//	cout << "\tLargest element of tree != \"60\". (INCORRECT)" << endl;
	//	
	//// test IN_SUM
	//cout << "\nTESTING IN_SUM METHOD" << endl;
	//
	//if (t.in_sum() == "")
	//	cout << "\tIn-order Sum of empty tree of strings is empty string. (CORRECT)" << endl;
	//else
	//	cout << "\tIn-order Sum of empty tree of strings is NOT empty string. (INCORRECT)" << endl;
	//cout << "\tBuilding test tree." << endl;
	//if (t2.in_sum() == "303235404547505560")
	//	cout << "\tIn-order Sum of tree of strings == \"303235404547505560\". (CORRECT)" << endl;
	//else
	//	cout << "\tIn-order Sum of tree of strings != \"303235404547505560\". (INCORRECT)" << endl;
	////cout << t2.in_sum() << endl;
	//
	//// test POST_SUM
	//cout << "\nTESTING POST_SUM METHOD" << endl;
	//
	//if (t.post_sum() == "")
	//	cout << "\tPost-order Sum of empty tree of strings is empty string. (CORRECT)" << endl;
	//else
	//	cout << "\tPost-order Sum of empty tree of strings is NOT empty string. (INCORRECT)" << endl;
	//cout << "\tBuilding test tree." << endl;
	//if (t2.post_sum() == "323530474555605040")
	//	cout << "\tPost-order Sum of tree of strings == \"323530474555605040\". (CORRECT)" << endl;
	//else
	//	cout << "\tPost-order Sum of tree of strings != \"323530474555605040\". (INCORRECT)" << endl;
	//
	///*t2.~tree();
	//try{
	//	t2.smallest();
	//}
	//catch (domain_error &de) {
	//	cout << "\tSMALLEST for empty tree throws domain error exception. (CORRECT)" << endl;
	//}*/

	//// test copy constructor
	//cout << "\nTESTING COPY CONSTRUCTOR" << endl;
	//tree<string> t3;
	//t3.insert("40");
	//t3.insert("50");
	//t3.insert("30");
	//
	//tree<string> t4 = t3;
	//t3.insert("20");
	//t4.insert("60");
	//if ((t3.smallest() == "20") && t3.contains("40") && t3.contains("30") && t3.contains("50") && !t3.contains("60") &&
	//	(t4.largest() == "60") && t4.contains("40") && t4.contains("30") && t4.contains("50") && !t4.contains("20"))
	//	cout << "Copy constructor corrrectly made tree t4 from tree t3. (CORRECT)" << endl;
	//else
	//	cout << "Copy constructor incorrrectly made tree t4 from tree t3. (INCORRECT)" << endl;
	//
	//// test assignment operator
	//cout << "\nTESTING ASSIGNMENT OPERATOR" << endl;
	//tree<string> t5;
	//t5.insert("40");
	//t5.insert("50");
	//t5.insert("30");
	//
	//tree<string> t6;
	//t6 = t5;
	//t5.insert("20");
	//t6.insert("60");
	//if ((t5.smallest() == "20") && t5.contains("40") && t5.contains("30") && t5.contains("50") && !t5.contains("60") &&
	//	(t6.largest() == "60") && t6.contains("40") && t6.contains("30") && t6.contains("50") && !t6.contains("20"))
	//	cout << "Copy constructor corrrectly made tree t3 from tree t. (CORRECT)" << endl;
	//else
	//	cout << "Copy constructor incorrrectly made tree t3 from tree t. (INCORRECT)" << endl;	
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
	//cout << "" << endl; //blank line
	//cout << "" << endl; //blank line
	//cout << "" << endl; //blank line
	//cout << "" << endl; //blank line
	////printing actual right side of tree
	//while(t.root != nullptr){
	//	cout << t.root->index << endl;
 //       cout << t.root->_alpha << endl;
 //       cout << t.root->encode_morse << endl;
 //       cout << t.root->morse_overlay << endl;

	//	t.root = t.root->right;
	//}

	//cout << "" << endl; //blank line
	//cout << "" << endl; //blank line
	//cout << "" << endl; //blank line
	//cout << "" << endl; //blank line
	////printing actual left side of tree
	//while(t.root != nullptr){
	//	cout << t.root->index << endl;
 //       cout << t.root->_alpha << endl;
 //       cout << t.root->encode_morse << endl;
 //       cout << t.root->morse_overlay << endl;

	//	t.root = t.root->left;
	//}
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
