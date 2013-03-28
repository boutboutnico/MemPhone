//============================================================================
// Name        : MemPhone.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// reading a text file
#include <iostream>
#include <fstream>
#include <string>

// vector
#include <vector>
#include <map>
#include <array>
#include <initializer_list>
#include <list>

using namespace std;

const vector<vector<char> > v_digit_to_letter { vector<char> { 'o' }, // 0
        vector<char> { 'i' }, // 1
        vector<char> { 'a', 'b', 'c' },	// 2
        vector<char> { 'd', 'e', 'f' },	// 3
        vector<char> { 'g', 'h', 'i' },	// 4
        vector<char> { 'j', 'k', 'l' },	// 5
        vector<char> { 'm', 'n', 'o' },	// 6
        vector<char> { 'p', 'q', 'r', 's' },	// 7
        vector<char> { 't', 'u', 'v' },	// 8
        vector<char> { 'w', 'x', 'y', 'z' },	// 9
};

void constructListRec(
                      const vector<int>& v_in,
                      const unsigned int idx_phone_number,
                      string& s_result,
                      list<string>& l_result)
{
	if(idx_phone_number >= v_in.size())
	{
		l_result.push_back(s_result);
		return;
	}

	int current_digit = v_in.at(idx_phone_number);

	for(uint32_t i = 0; i < v_digit_to_letter.at(current_digit).size(); i++)
	{
		// Append current letter to existing result
		string s_copy = s_result;
		s_copy += v_digit_to_letter.at(current_digit).at(i);

		// Call next digit in phone number
		constructListRec(v_in, idx_phone_number + 1, s_copy, l_result);
	}
}

int main()
{
	// http://www.liste-de-mots.com/mots-nombre-lettre/8/a/

	// Vector
	vector<string> v_dico_8;

//	vector<int> v_input { 6, 7, 9, 3, 7, 3, 9 };
//	vector<int> v_input { 6, 4, 4, 6, 6, 6, 6, 3 }; // Mignonne
//	vector<int> v_input { 3, 2, 1, 3, 8, 7, 2, 8 }; // Mathieu
	vector<int> v_input { 2, 9, 2, 4, 3, 8, 7, 9 }; //
//	vector<int> v_input { 3, 1, 7, 3, 3, 6, 8, 8 }; //
	list<string> l_output;

//	constructList(v_input, l_output);

	string s_result;
	int cpt = 0;
	constructListRec(v_input, cpt, s_result, l_output);

	//--------------------------------------------------
	// Display l_output
	//--------------------------------------------------
	cout << "Display l_output list :" << endl;
	for(list<string>::iterator it = l_output.begin(); it != l_output.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "l_output size : " << l_output.size() << endl;

	//--------------------------------------------------
	// Copy file in RAM
	//--------------------------------------------------
	string line;
	ifstream myfile("res/dico_a_8.txt");

	if(myfile.is_open())
	{
		while(myfile.good())
		{
			getline(myfile, line);
			v_dico_8.push_back(line);
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	//--------------------------------------------------
	// Find word
	//--------------------------------------------------
	vector<string>::size_type idx = 0;
	while(l_output.empty() == false)
	{
		string string = l_output.front();

		for(idx = 0; idx < v_dico_8.size(); idx++)
		{
			if(string == v_dico_8.at(idx))
			{
				cout << "Found : " << string << " " << v_dico_8.at(idx) << endl;
			}
		}
		l_output.pop_front();
	}

	//--------------------------------------------------
	// Display vector
	//--------------------------------------------------
//	for(idx = 0; idx < v_dico_8.size(); idx++)
//	{
//		cout << v_dico_8.at(idx) << endl;
//	}
//	cout << "v_dico_8 size : " << v_dico_8.size() << endl;

	//--------------------------------------------------
	// Exit
	//--------------------------------------------------
	// Debug
//	char X;
//	while(cin >> X && X != 'q')
//	{
//	};

	return 0;
}

//void constructListRec(const vector<int>& v_in, const unsigned int idx_phone_number, string& s_result, list<string>& l_result)
//{
//	static uint32_t cpt = 0;
////	cout << "ConstructListRec cpt : " << cpt++ << endl;
//
////	cout << "ui8_idx_phone_number : " << idx_phone_number << endl;
//	if(idx_phone_number >= v_in.size())
//	{
//		l_result.push_back(s_result);
////		cout << "Exit" << endl;
//		return;
//	}
//
//	int current_digit = v_in.at(idx_phone_number);
////	cout << "current_digit : " << current_digit << endl;
//
//	for(uint32_t i = 0; i < v_digit_to_letter.at(current_digit).size(); i++)
//	{
////		cout << "i : " << i << endl;
//
//		// Append current letter to existing result
//		string s_copy = s_result;
//		s_copy += v_digit_to_letter.at(current_digit).at(i);
////		cout << "s_result : " << s_result << endl;
//
//		// Call next digit in phone number
//		constructListRec(v_in, idx_phone_number + 1, s_copy, l_result);
//	}
//
////	cout << "End of construtListRec" << endl;
//}
