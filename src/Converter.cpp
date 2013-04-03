//	 Start of the Copyright Notice
//	****************************************************************************
// 	* Copyright Itron SAS.                                                     *
//	* This computer program includes confidential proprietary information and  *
//	* is a trade secret of Itron. All use, disclosures and/or reproduction 	   *
//	* is prohibited unless authorized in writing.          					   *
//	* All Rights Reserved                                                      *
//	****************************************************************************
//	 End of the Copyright Notice

/*************************************************************************//**
 * @file 	Converter.cpp
 * @brief	xx
 * @author	Boutboutnico
 * @date	1 avr. 2013
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include "converter.h"

#include <cstdlib>
#include <iostream>

/*****************************************************************************
 * NAMESPACE
 *****************************************************************************/

/*****************************************************************************
 * GLOBALE VARIABLE
 *****************************************************************************/

/*****************************************************************************
 * PUBLIC IMPLEMENTATION
 *****************************************************************************/
void Converter::ToWords(const string& phone_number, set<string>& set_words)
{
	vector<int> v_digits;

	SplitPhoneNumber(phone_number, v_digits);

	int cpt = 0;
	string s_tmp;

	ToWordsRec(v_digits, cpt, s_tmp, set_words);

}
/*****************************************************************************
 * PRIVATE IMPLEMENTATION
 *****************************************************************************/

void Converter::ToWordsRec(
                           const vector<int>& v_in,
                           const unsigned int idx_digit,
                           string& s_result,
                           set<string>& set_words)
{
	//--------------------------------------------------
	// Exit recursive loop
	//--------------------------------------------------
	if(idx_digit >= v_in.size())
	{
		set_words.insert(s_result);
		return;
	}

	//--------------------------------------------------
	// Do next digit
	//--------------------------------------------------
	int current_digit = v_in.at(idx_digit);

	for(vector<char>::size_type i = 0; i < digit_to_letter.at(current_digit).size(); i++)
	{
		// Append current letter to existing result
		string s_copy = s_result;
		s_copy += digit_to_letter.at(current_digit).at(i);

		// Call next digit in phone number
		ToWordsRec(v_in, idx_digit + 1, s_copy, set_words);
	}
}

void Converter::SplitPhoneNumber(const string& phone_number, vector<int>& vector_digit)
{
	if(phone_number.size() != 8) cout << "ERROR : phone number size is != 8" << endl;

	for(uint8_t idx = 0; idx < phone_number.length(); idx++)
	{
		const char chara = phone_number.at(idx);
		vector_digit.push_back(atoi(&chara));
	}
}

/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
