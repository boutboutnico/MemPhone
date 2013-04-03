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
 * @file 	Finder.cpp
 * @brief	xx
 * @author	Boutboutnico
 * @date	3 avr. 2013
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include "finder.h"

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

void Finder::FindMatch(const vector<string>& v_dico, const set<string>& s_search, list<string>& l_match)
{
	vector<string>::size_type idx = 0;
//	uint32_t progression = 0, prog_old = 0;

	for(idx = 0; idx < v_dico.size(); idx++)
	{
//		progression = idx * 100 / v_dico.size();
//
//		if(progression != prog_old)
//		{
//			cout << progression << " ";
//			cout.flush();
//			prog_old = progression;
//
//			if(progression % 10 == 0) cout << endl;
//		}

		string string_format = FormatString(v_dico.at(idx));

		// Set
		set<string>::iterator it = s_search.find(string_format);
		if(it != s_search.end())
		{
//			cout << "Found : " << *it << " " << v_v_dico.at(idx) << endl;
			l_match.push_back(v_dico.at(idx));
		}
	}
}

/*****************************************************************************
 * PRIVATE IMPLEMENTATION
 *****************************************************************************/

string Finder::FormatString(const string s_in)
{
	string s_temp = s_in;

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

/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
