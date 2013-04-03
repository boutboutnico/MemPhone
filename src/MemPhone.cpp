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
	const vector<string> v_phone_number = { //
	        "33368337", // édentées
	                "66646667", // nominons
	                "22288837",  // abattues
	                "77997401", // Pierre
	                "07261634", // Audrey
	                "26390119", // Marius
	                "32138728", // Mathieu
	                "29243879", // Manu
	                "71719963", // Franck
	                "31733688", // Marie ade
	                "07494858", // Youyou 10
	                "23522009", // Quentin
	                "87270186",	// Steph
	                "64443826",	// Ludo
	                "18688249", // Fx
	                "45269471", // Benoit
	                "11076175", // Marc
	                "42620824", // Annabelle
	                "64124466", // Yann
	                "77298608", // Marion
	                "83439326",	// Sylvain
	        };

	//--------------------------------------------------
	// Get Dictionary
	//--------------------------------------------------
	Dictionary dico;
	const vector<string>& dico_4 = dico.GetDico(Dictionary::DICO_4_LETTERS);
	const vector<string>& dico_5 = dico.GetDico(Dictionary::DICO_5_LETTERS);
	const vector<string>& dico_6 = dico.GetDico(Dictionary::DICO_6_LETTERS);
	const vector<string>& dico_7 = dico.GetDico(Dictionary::DICO_7_LETTERS);
	const vector<string>& dico_8 = dico.GetDico(Dictionary::DICO_8_LETTERS);

	Converter converter;
	Finder finder;
	const uint16_t word_size_max = 8;
	const uint16_t word_size_min = 4;

	vector<string>::size_type i_phone_number;
	for(i_phone_number = 0; i_phone_number < v_phone_number.size(); i_phone_number++)
	{
		cout << "----- i_phone_number : " << i_phone_number << " -----" << endl;

		for(uint16_t i_word_size = word_size_max; i_word_size >= word_size_min; i_word_size--)
		{
			for(uint16_t i_start_index = 0; i_start_index <= word_size_max - i_word_size; i_start_index++)
			{
				//--------------------------------------------------
				// Convert to words
				//--------------------------------------------------
				set<string> s_gen;
				converter.ToWords(v_phone_number.at(i_phone_number), i_start_index, i_word_size, s_gen);

				//--------------------------------------------------
				// Find word
				//--------------------------------------------------
				list<string> list_match;

				if(i_word_size == 8)
				{
					finder.FindMatch(dico_8, s_gen, list_match);
				}
				else if(i_word_size == 7)
				{
					finder.FindMatch(dico_7, s_gen, list_match);
				}
				else if(i_word_size == 6)
				{
					finder.FindMatch(dico_6, s_gen, list_match);
				}
				else if(i_word_size == 5)
				{
					finder.FindMatch(dico_5, s_gen, list_match);
				}
				else if(i_word_size == 4)
				{
					finder.FindMatch(dico_4, s_gen, list_match);
				}
				else
				{
					cout << "No Dico found to match this word size : " << i_word_size << endl;
				}

				//--------------------------------------------------
				// Display result
				//--------------------------------------------------
				if(list_match.size() > 0) DisplayList(list_match, "\nMatch list");
			}
		}
	}

	cout << "EXIT" << endl;
	return 0;
}

/**
 *
 * @param i_list
 */
void DisplayList(const list<string>& l_to_display, const string& s_title)
{
	cout << s_title << "[" << l_to_display.size() << "] : " << endl;

	for(auto it = l_to_display.begin(); it != l_to_display.end(); it++)
	{
		cout << *it << endl;
	}
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

