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
		DICO_7_LETTERS = 0x07,
		DICO_8_LETTERS = 0x08,
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
	vector<string> v_dico_7;
	vector<string> v_dico_8;

	//--------------------------------------------------
	// Dictionary name file
	//--------------------------------------------------
	const string repository_name = "res/";
	const string filename_extension = ".txt";

	const string filename_dico_8 = "dico_8_fr";
	const string filename_dico_7 = "dico_7_fr";

};

#endif /* DICTIONARY_H_ */
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
