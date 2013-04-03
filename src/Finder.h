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
 * @file 	Finder.h
 * @brief	xx
 * @author	Boutboutnico
 * @date	3 avr. 2013
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

#ifndef FINDER_H_
#define FINDER_H_

/*****************************************************************************
 * DEFINITION
 *****************************************************************************/
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/

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
 * @date	3 avr. 2013
 */
class Finder
{
public:
	void FindMatch(const vector<string>& v_dico, const set<string>& s_search, list<string>& l_match);

private:
	string FormatString(const string s_in);

	//--------------------------------------------------
	// Conversion table
	//--------------------------------------------------
	const map<char, char> m_character = { //
	        { 'à', 'a' }, //
	                { 'â', 'a' }, //
	                { 'ç', 'c' }, //
	                { 'é', 'e' }, //
	                { 'è', 'e' }, //
	                { 'ê', 'e' }, //
	                { 'î', 'i' }, //
	                { 'ï', 'i' }, //
	                { 'û', 'u' }, //
	                { 'ù', 'u' }, //
	                { 'ü', 'u' }, //
	                { 'ô', 'o' }, //
	        };

};

#endif /* FINDER_H_ */
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
