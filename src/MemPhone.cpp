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
#include "Finder.h"

/*****************************************************************************
 * NAMESPACE
 *****************************************************************************/
using namespace std;

/*****************************************************************************
 * MAIN
 *****************************************************************************/

void DisplayList(const list<string>& l_to_display, const string& s_title);
void DisplayVector(const vector<string>& v_to_display, const string& s_title);

int main()
{
//	string phone_number = "33368337"; // édentées
//	string phone_number = "66646667"; // nominons
	string phone_number = "22288837";  // abattues
//	string phone_number = "77997401"; // Pierre
//	string phone_number = "07261634"; // Audrey
//	string phone_number = "26390119"; // Marius
//	string phone_number = "32138728"; // Mathieu
//	string phone_number = "29243879"; // Manu
//	string phone_number = "71719963"; // Franck
//	string phone_number = "31733688"; // Marie ade
//	string phone_number = "07494858"; // Youyou

	set<string> s_gen_8;
	set<string> s_gen_7_0;
	set<string> s_gen_7_1;

	Converter converter;
	converter.ToWords(phone_number, 0, 8, s_gen_8);
	converter.ToWords(phone_number, 0, 7, s_gen_7_0);
	converter.ToWords(phone_number, 1, 7, s_gen_7_1);

	//--------------------------------------------------
	// Get Dictionary
	//--------------------------------------------------
	Dictionary dico;
	const vector<string>& dico_7 = dico.GetDico(Dictionary::DICO_7_LETTERS);
	const vector<string>& dico_8 = dico.GetDico(Dictionary::DICO_8_LETTERS);

//	DisplayVector(dico_8, "Dictionary 8 letters");

	//--------------------------------------------------
	// Find word
	//--------------------------------------------------
	list<string> list_match;

	Finder finder;
	finder.FindMatch(dico_8, s_gen_8, list_match);
	finder.FindMatch(dico_7, s_gen_7_0, list_match);
	finder.FindMatch(dico_7, s_gen_7_1, list_match);

	//--------------------------------------------------
	// Display result
	//--------------------------------------------------
	DisplayList(list_match, "\nMatch list");

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

