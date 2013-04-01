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
 * @file 	Converter.h
 * @brief	xx
 * @author	Boutboutnico
 * @date	1 avr. 2013
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

#ifndef CONVERTER_H_
#define CONVERTER_H_

/*****************************************************************************
 * DEFINITION
 *****************************************************************************/

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include <set>
#include <vector>

#include <string>

/*****************************************************************************
 * NAMESPACE
 *****************************************************************************/
using namespace std;

/*****************************************************************************
 * CLASS
 *****************************************************************************/
/**
 * @class 	xx
 * @brief	xx
 * @author	Boutboutnico
 * @date	1 avr. 2013
 */
class Converter
{
public:
	void ToWords(const string& phone_number, set<string>& set_words);

private:
	void ToWordsRec(
	                const vector<int>& v_in,
	                const unsigned int idx_digit,
	                string& s_result,
	                set<string>& set_words);

	void SplitPhoneNumber(const string& phone_number, vector<int>& vector_digit);

	//--------------------------------------------------
	// Conversion table
	//--------------------------------------------------
	const vector<vector<char> > digit_to_letter { vector<char> { 'o' }, // 0
	        vector<char> { 'i', 'l' }, // 1
	        vector<char> { 'a', 'b', 'c' },	// 2
	        vector<char> { 'd', 'e', 'f' },	// 3
	        vector<char> { 'g', 'h', 'i' },	// 4
	        vector<char> { 'j', 'k', 'l' },	// 5
	        vector<char> { 'm', 'n', 'o' },	// 6
	        vector<char> { 'p', 'q', 'r', 's' },	// 7
	        vector<char> { 't', 'u', 'v' },	// 8
	        vector<char> { 'w', 'x', 'y', 'z' },	// 9
	};
};

#endif /* CONVERTER_H_ */
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
