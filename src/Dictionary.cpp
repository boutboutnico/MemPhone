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
 * @file 	Dictionary.cpp
 * @brief	xx
 * @author	Boutboutnico
 * @date	1 avr. 2013
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

#include "dictionary.h"

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include <iostream>
#include <fstream>

/*****************************************************************************
 * PUBLIC IMPLEMENTATION
 *****************************************************************************/

const vector<string>& Dictionary::GetDico(const E8_Dico_Type e8_dico)
{
	string dico_filename = repository_name;
	vector<string>* current_dico;

	switch(e8_dico){
	case DICO_8_LETTERS:
		current_dico = &v_dico_8;
		break;

	default:
		cout << "Wrong dictionary type" << endl;
		break;
	}

	if(current_dico->empty() == false)
	{
		return *current_dico;
	}

	ConstructDico(e8_dico);
	return *current_dico;
}
/*****************************************************************************
 * PRIVATE IMPLEMENTATION
 *****************************************************************************/

void Dictionary::ConstructDico(const E8_Dico_Type e8_dico)
{
	string dico_filename = repository_name;
	vector<string>* current_dico;

	//--------------------------------------------------
	// Select Dictionary
	//--------------------------------------------------
	switch(e8_dico){
	case DICO_8_LETTERS:
		dico_filename.append(filename_dico_8);
		current_dico = &v_dico_8;
		break;

	default:
		cout << "Wrong dictionary type" << endl;
		break;
	}

	// Add extension to filename
	dico_filename.append(filename_extension);


	//--------------------------------------------------
	// Create dictionary from file
	//--------------------------------------------------
	ifstream dico_file(const_cast<char*>(dico_filename.c_str()));
	string line;

	if(dico_file.is_open())
	{
		while(dico_file.good())
		{
			getline(dico_file, line);
			current_dico->push_back(line);
		}
		dico_file.close();
	}
	else cout << "Unable to open file" << endl;
}
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
