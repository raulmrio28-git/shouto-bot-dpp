/*
 * Copyright 2023 raulmrio28-git and contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 /*
 ** ===========================================================================
 ** File: Shoto_Fun.h
 ** Description: TodorokiBot header
 ** Copyright (c) 2023 raulmrio28-git and contributors.
 ** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
 ** Licensed under the Apache License, Version 2.0. All rights reserved.
 ** History:
 ** when			who				what, where, why
 ** MM-DD-YYYY- --------------- --------------------------------
 ** 03/08/2023	raulmrio28-git	finish MHA_CHARACTER_T
 ** 03/07/2023	raulmrio28-git	Initial version
 ** ===========================================================================
 */

#ifndef _SHOTO_FUN_H_
#define _SHOTO_FUN_H_
/* Important note, when entering Japanese input to a string, PLEASE place u8 before the opening bracket. */

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include <dpp/dpp.h> /* DPP stuff */
#include <string> /* std::string */
#include <vector> /* std::vector */

/*
**----------------------------------------------------------------------------
**  Type Definitions
**----------------------------------------------------------------------------
*/

/* Note: currently Class 1A is enum'd here... */

enum tagMHA_CHARACTER_E
{
	//Note: sorted by seat!!!
	CHAR_NONE = 0, 
	/* Class 1A */
	CHAR_AOYAMA,
	CHAR_ASHIDO,
	CHAR_ASUI,
	CHAR_TENYA,
	CHAR_OCHACO,
	CHAR_OJIRO,
	CHAR_DENKI,
	CHAR_EIJIRO,
	CHAR_KOJIKODA,
	CHAR_RIKIDO,
	CHAR_SHOJI,
	CHAR_KYOKA,
	CHAR_HANTA,
	CHAR_TOKOYAMI,
	CHAR_TODOROKI,
	CHAR_TORU,
	CHAR_BAKUGO,
	CHAR_IZUKU,
	CHAR_MINORU,
	CHAR_YAYOROZU
};
typedef enum tagMHA_CHARACTER_E  MHA_CHARACTER_E;
typedef struct tagMHA_CHARACTER_T  MHA_CHARACTER_T;

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

/*
**----------------------------------------------------------------------------
**  General Declarations
**----------------------------------------------------------------------------
*/

struct tagMHA_CHARACTER_T
{
	std::string szImgUrl;
	std::string szCharNameRoman;
	int nHexColor;
	std::string szCharNameJap;
	std::string szHeroName;
	int nDay;
	int nMonth;
	std::string szGender;
	std::string szHeight;
	std::string szBloodType;
	std::string szQuirk;
	std::string szBirthPlace;
	std::string szOccupation;
	int nSeatNo;
	std::string szLikes;
};

/*
**---------------------------------------------------------------------------
**  Function(external use only) Declarations
**---------------------------------------------------------------------------
*/
extern void botSayCharSheet(dpp::cluster& bot, const dpp::slashcommand_t& event, MHA_CHARACTER_E character);

#endif /* _SHOTO_FUN_H_ */