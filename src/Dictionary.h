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
 * @file 	Dictionary.h
 * @brief	xx
 * @author	Boutboutnico
 * @date	1 avr. 2013
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include <vector>
#include <string>
#include <array>

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
class Dictionary
{
public:
	//--------------------------------------------------
	// Public Enumeration
	//--------------------------------------------------
	typedef enum
	{
		DICO_4_LETTERS = 0x04,
		DICO_5_LETTERS = 0x05,
		DICO_6_LETTERS = 0x06,
		DICO_7_LETTERS = 0x07,
		DICO_8_LETTERS = 0x08,
		DICO_COUNT = 0x05,
		DICO_FIRST = DICO_4_LETTERS,
	} E8_Dico_Type;

public:
	const vector<string>& GetDico(const E8_Dico_Type e8_dico);

private:
	//--------------------------------------------------
	// Private Methods
	//--------------------------------------------------
	void ConstructDico(const E8_Dico_Type e8_dico);

	//--------------------------------------------------
	// Attributes
	//--------------------------------------------------
	std::array<vector<string>, DICO_COUNT> av_dico;

	//--------------------------------------------------
	// Dictionary name file
	//--------------------------------------------------
	const string repository_name = "res/";
	const string filename_extension = ".txt";

	const string filename_dico_4 = "dico_4_fr";
	const string filename_dico_5 = "dico_5_fr";
	const string filename_dico_6 = "dico_6_fr";
	const string filename_dico_7 = "dico_7_fr";
	const string filename_dico_8 = "dico_8_fr";

};

#endif /* DICTIONARY_H_ */
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
