//============================================================================
// Name        : MemPhone.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
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
#include <set>

#include "Dictionary.h"
#include "Converter.h"

/*****************************************************************************
 * NAMESPACE
 *****************************************************************************/
using namespace std;

/*****************************************************************************
 * MAIN
 *****************************************************************************/



void DisplayList(const list<string>& l_to_display, const string& s_title);
void DisplayVector(const vector<string>& v_to_display, const string& s_title);

//void constructListRec(
//                      const vector<int>& v_in,
//                      const unsigned int idx_phone_number,
//                      string& s_result,
//                      list<string>& l_result)
//{
//	if(idx_phone_number >= v_in.size())
//	{
//		l_result.push_back(s_result);
//		return;
//	}
//
//	int current_digit = v_in.at(idx_phone_number);
//
//	for(uint32_t i = 0; i < v_digit_to_letter.at(current_digit).size(); i++)
//	{
//		// Append current letter to existing result
//		string s_copy = s_result;
//		s_copy += v_digit_to_letter.at(current_digit).at(i);
//
//		// Call next digit in phone number
//		constructListRec(v_in, idx_phone_number + 1, s_copy, l_result);
//	}
//}

string FormatString(const string s_in)
{
	string s_temp = s_in;

	const map<char, char> m_character = { { 'à', 'a' }, //
	        { 'â', 'a' }, //
	        { 'ç', 'c' }, //
	        { 'é', 'e' }, //
	        { 'è', 'e' }, //
	        { 'ê', 'e' }, //
	        { 'î', 'i' }, //
	        { 'û', 'u' }, //
	        { 'ù', 'u' }, //
	        { 'ü', 'u' }, //
	        { 'ô', 'o' }, //
	        };

	for(auto it = m_character.cbegin(); it != m_character.cend(); ++it)
	{
		size_t found_pos = s_temp.find(it->first);

		// Find something
		if(found_pos != string::npos)
		{
			s_temp.replace(found_pos, 1, &it->second, 1);

			// Reset iterator to search again the same character
			it--;

//			cout << "s_in : " << s_in << endl;
//			cout << "s_temp : " << s_temp << endl;
//			cout << "pos : " << found_pos << endl;
		}
	}

	return s_temp;
}

int main()
{
//	string phone_number = "33368337"; // édentées
//	string phone_number = "66646667"; // nominons
//	string phone_number = "77997401"; // Pierre
//	string phone_number = "07261634"; // Audrey
//	string phone_number = "26390119"; // Marius
//	string phone_number = "32138728"; // Mathieu
//	string phone_number = "29243879"; // Manu
//	string phone_number = "71719963"; // Franck
//	string phone_number = "31733688"; // Marie ade
	string phone_number = "07494858"; // Youyou

	set<string> set_generated;
	Converter converter;
	converter.ToWords(phone_number, set_generated);

	//--------------------------------------------------
	// Get Dictionary
	//--------------------------------------------------
	Dictionary dico;
	const vector<string>& dico_8 = dico.GetDico(Dictionary::DICO_8_LETTERS);

//	DisplayVector(dico_8, "Dictionary 8 letters");

	//--------------------------------------------------
	// Find word
	//--------------------------------------------------
	list<string> list_match;
	vector<string>::size_type idx = 0;
	uint32_t progression = 0, prog_old = 0;

	for(idx = 0; idx < dico_8.size(); idx++)
	{
		progression = idx * 100 / dico_8.size();

		if(progression != prog_old)
		{
			cout << progression << endl;
			prog_old = progression;
		}

		string string_format = FormatString(dico_8.at(idx));

		// Set
		set<string>::iterator it = set_generated.find(string_format);
		if(it != set_generated.end())
		{
//			cout << "Found : " << *it << " " << v_dico_8.at(idx) << endl;
			list_match.push_back(dico_8.at(idx));
		}

		// List
//		for(list<string>::iterator it = l_generated.begin(); it != l_generated.end(); it++)
//		{
//			if(*it == string_format)
//			{
//				cout << "Found : " << *it << " " << v_dico_8.at(idx) << endl;
//			}
//		}
	}

	//--------------------------------------------------
	// Display result
	//--------------------------------------------------
	DisplayList(list_match, "Match list");

	cout << "EXIT" << endl;
	return 0;
}

/**
 *
 * @param i_list
 */
void DisplayList(const list<string>& l_to_display, const string& s_title)
{
	cout << s_title << " : " << endl;

	for(auto it = l_to_display.begin(); it != l_to_display.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Size : " << l_to_display.size() << endl;
}

void DisplayVector(const vector<string>& v_to_display, const string& s_title)
{
	cout << s_title << " : " << endl;

	vector<string>::size_type idx = 0;
	for(idx = 0; idx < v_to_display.size(); idx++)
	{
		cout << v_to_display.at(idx) << endl;
	}
	cout << "Size : " << v_to_display.size() << endl;
}

