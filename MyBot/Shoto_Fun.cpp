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
** File: Shoto_Fun.cpp
** Description: Bot custom code
** Copyright (c) 2023 raulmrio28-git and contributors.
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY- --------------- --------------------------------
** 03/11/2023	raulmrio28-git	Initial version
** ===========================================================================
*/

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include "Shoto_Fun.h"
#include "Shoto_Debug.h"
#include "MhaCharacterInfo.h"

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

/*
**----------------------------------------------------------------------------
**  Type Definitions
**----------------------------------------------------------------------------
*/

/*
**---------------------------------------------------------------------------
**  Global variables
**---------------------------------------------------------------------------
*/

/*
**---------------------------------------------------------------------------
**  Internal variables
**---------------------------------------------------------------------------
*/

dpp::embed funEmbed; /* embed */
MHA_CHARACTER_T myCharacterInfo; /* bnha character info for /charsheet, used in Shoto_PrintCharSheet() */

/*
**---------------------------------------------------------------------------
**  Function(internal use only) Declarations
**---------------------------------------------------------------------------
*/

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botCharSheetInitCharacterInfo()
**
** Description:
**     Initializes myCharacterInfo values for Shoto_PrintCharSheet()
**
** Input:
**     nChar - character number (MHA_CHARACTER_E)
**
** Output:
**     Finished struct...
**
** Return value:
**     none yet
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/09/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botCharSheetInitCharacterInfo(MHA_CHARACTER_E nChar)
{
	switch (nChar)
	{
	case CHAR_AOYAMA:
		myCharacterInfo.szImgUrl = CHAR_AOYAMA_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_AOYAMA_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_AOYAMA_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_AOYAMA_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_AOYAMA_HERONAME;
		myCharacterInfo.nDay = CHAR_AOYAMA_DAY;
		myCharacterInfo.nMonth = CHAR_AOYAMA_MONTH;
		myCharacterInfo.szGender = CHAR_AOYAMA_GENDER;
		myCharacterInfo.szHeight = CHAR_AOYAMA_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_AOYAMA_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_AOYAMA_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_AOYAMA_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_AOYAMA_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_AOYAMA_SEATNO;
		myCharacterInfo.szLikes = CHAR_AOYAMA_LIKES;
		break;
	case CHAR_ASHIDO:
		myCharacterInfo.szImgUrl = CHAR_ASHIDO_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_ASHIDO_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_ASHIDO_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_ASHIDO_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_ASHIDO_HERONAME;
		myCharacterInfo.nDay = CHAR_ASHIDO_DAY;
		myCharacterInfo.nMonth = CHAR_ASHIDO_MONTH;
		myCharacterInfo.szGender = CHAR_ASHIDO_GENDER;
		myCharacterInfo.szHeight = CHAR_ASHIDO_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_ASHIDO_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_ASHIDO_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_ASHIDO_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_ASHIDO_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_ASHIDO_SEATNO;
		myCharacterInfo.szLikes = CHAR_ASHIDO_LIKES;
		break;
	case CHAR_ASUI:
		myCharacterInfo.szImgUrl = CHAR_ASUI_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_ASUI_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_ASUI_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_ASUI_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_ASUI_HERONAME;
		myCharacterInfo.nDay = CHAR_ASUI_DAY;
		myCharacterInfo.nMonth = CHAR_ASUI_MONTH;
		myCharacterInfo.szGender = CHAR_ASUI_GENDER;
		myCharacterInfo.szHeight = CHAR_ASUI_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_ASUI_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_ASUI_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_ASUI_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_ASUI_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_ASUI_SEATNO;
		myCharacterInfo.szLikes = CHAR_ASUI_LIKES;
		break;
	case CHAR_TENYA:
		myCharacterInfo.szImgUrl = CHAR_IDA_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_IDA_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_IDA_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_IDA_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_IDA_HERONAME;
		myCharacterInfo.nDay = CHAR_IDA_DAY;
		myCharacterInfo.nMonth = CHAR_IDA_MONTH;
		myCharacterInfo.szGender = CHAR_IDA_GENDER;
		myCharacterInfo.szHeight = CHAR_IDA_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_IDA_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_IDA_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_IDA_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_IDA_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_IDA_SEATNO;
		myCharacterInfo.szLikes = CHAR_IDA_LIKES;
		break;
	case CHAR_OCHACO:
		myCharacterInfo.szImgUrl = CHAR_OCHACO_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_OCHACO_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_OCHACO_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_OCHACO_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_OCHACO_HERONAME;
		myCharacterInfo.nDay = CHAR_OCHACO_DAY;
		myCharacterInfo.nMonth = CHAR_OCHACO_MONTH;
		myCharacterInfo.szGender = CHAR_OCHACO_GENDER;
		myCharacterInfo.szHeight = CHAR_OCHACO_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_OCHACO_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_OCHACO_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_OCHACO_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_OCHACO_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_OCHACO_SEATNO;
		myCharacterInfo.szLikes = CHAR_OCHACO_LIKES;
		break;
	case CHAR_OJIRO:
		myCharacterInfo.szImgUrl = CHAR_OJIRO_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_OJIRO_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_OJIRO_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_OJIRO_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_OJIRO_HERONAME;
		myCharacterInfo.nDay = CHAR_OJIRO_DAY;
		myCharacterInfo.nMonth = CHAR_OJIRO_MONTH;
		myCharacterInfo.szGender = CHAR_OJIRO_GENDER;
		myCharacterInfo.szHeight = CHAR_OJIRO_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_OJIRO_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_OJIRO_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_OJIRO_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_OJIRO_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_OJIRO_SEATNO;
		myCharacterInfo.szLikes = CHAR_OJIRO_LIKES;
		break;
	case CHAR_DENKI:
		myCharacterInfo.szImgUrl = CHAR_DENKI_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_DENKI_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_DENKI_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_DENKI_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_DENKI_HERONAME;
		myCharacterInfo.nDay = CHAR_DENKI_DAY;
		myCharacterInfo.nMonth = CHAR_DENKI_MONTH;
		myCharacterInfo.szGender = CHAR_DENKI_GENDER;
		myCharacterInfo.szHeight = CHAR_DENKI_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_DENKI_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_DENKI_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_DENKI_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_DENKI_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_DENKI_SEATNO;
		myCharacterInfo.szLikes = CHAR_DENKI_LIKES;
		break;
	case CHAR_EIJIRO:
		myCharacterInfo.szImgUrl = CHAR_EIJIRO_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_EIJIRO_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_EIJIRO_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_EIJIRO_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_EIJIRO_HERONAME;
		myCharacterInfo.nDay = CHAR_EIJIRO_DAY;
		myCharacterInfo.nMonth = CHAR_EIJIRO_MONTH;
		myCharacterInfo.szGender = CHAR_EIJIRO_GENDER;
		myCharacterInfo.szHeight = CHAR_EIJIRO_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_EIJIRO_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_EIJIRO_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_EIJIRO_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_EIJIRO_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_EIJIRO_SEATNO;
		myCharacterInfo.szLikes = CHAR_EIJIRO_LIKES;
		break;
	case CHAR_KOJIKODA:
		myCharacterInfo.szImgUrl = CHAR_KOJI_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_KOJI_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_KOJI_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_KOJI_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_KOJI_HERONAME;
		myCharacterInfo.nDay = CHAR_KOJI_DAY;
		myCharacterInfo.nMonth = CHAR_KOJI_MONTH;
		myCharacterInfo.szGender = CHAR_KOJI_GENDER;
		myCharacterInfo.szHeight = CHAR_KOJI_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_KOJI_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_KOJI_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_KOJI_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_KOJI_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_KOJI_SEATNO;
		myCharacterInfo.szLikes = CHAR_KOJI_LIKES;
		break;
	case CHAR_RIKIDO:
		myCharacterInfo.szImgUrl = CHAR_RIKIDO_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_RIKIDO_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_RIKIDO_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_RIKIDO_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_RIKIDO_HERONAME;
		myCharacterInfo.nDay = CHAR_RIKIDO_DAY;
		myCharacterInfo.nMonth = CHAR_RIKIDO_MONTH;
		myCharacterInfo.szGender = CHAR_RIKIDO_GENDER;
		myCharacterInfo.szHeight = CHAR_RIKIDO_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_RIKIDO_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_RIKIDO_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_RIKIDO_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_RIKIDO_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_RIKIDO_SEATNO;
		myCharacterInfo.szLikes = CHAR_RIKIDO_LIKES;
		break;
	case CHAR_SHOJI:
		myCharacterInfo.szImgUrl = CHAR_SHOJI_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_SHOJI_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_SHOJI_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_SHOJI_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_SHOJI_HERONAME;
		myCharacterInfo.nDay = CHAR_SHOJI_DAY;
		myCharacterInfo.nMonth = CHAR_SHOJI_MONTH;
		myCharacterInfo.szGender = CHAR_SHOJI_GENDER;
		myCharacterInfo.szHeight = CHAR_SHOJI_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_SHOJI_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_SHOJI_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_SHOJI_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_SHOJI_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_SHOJI_SEATNO;
		myCharacterInfo.szLikes = CHAR_SHOJI_LIKES;
		break;
	case CHAR_KYOKA:
		myCharacterInfo.szImgUrl = CHAR_KYOKA_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_KYOKA_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_KYOKA_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_KYOKA_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_KYOKA_HERONAME;
		myCharacterInfo.nDay = CHAR_KYOKA_DAY;
		myCharacterInfo.nMonth = CHAR_KYOKA_MONTH;
		myCharacterInfo.szGender = CHAR_KYOKA_GENDER;
		myCharacterInfo.szHeight = CHAR_KYOKA_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_KYOKA_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_KYOKA_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_KYOKA_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_KYOKA_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_KYOKA_SEATNO;
		myCharacterInfo.szLikes = CHAR_KYOKA_LIKES;
		break;
	case CHAR_HANTA:
		myCharacterInfo.szImgUrl = CHAR_HANTA_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_HANTA_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_HANTA_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_HANTA_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_HANTA_HERONAME;
		myCharacterInfo.nDay = CHAR_HANTA_DAY;
		myCharacterInfo.nMonth = CHAR_HANTA_MONTH;
		myCharacterInfo.szGender = CHAR_HANTA_GENDER;
		myCharacterInfo.szHeight = CHAR_HANTA_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_HANTA_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_HANTA_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_HANTA_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_HANTA_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_HANTA_SEATNO;
		myCharacterInfo.szLikes = CHAR_HANTA_LIKES;
		break;
	case CHAR_TOKOYAMI:
		myCharacterInfo.szImgUrl = CHAR_TOKOYAMI_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_TOKOYAMI_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_TOKOYAMI_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_TOKOYAMI_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_TOKOYAMI_HERONAME;
		myCharacterInfo.nDay = CHAR_TOKOYAMI_DAY;
		myCharacterInfo.nMonth = CHAR_TOKOYAMI_MONTH;
		myCharacterInfo.szGender = CHAR_TOKOYAMI_GENDER;
		myCharacterInfo.szHeight = CHAR_TOKOYAMI_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_TOKOYAMI_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_TOKOYAMI_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_TOKOYAMI_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_TOKOYAMI_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_TOKOYAMI_SEATNO;
		myCharacterInfo.szLikes = CHAR_TOKOYAMI_LIKES;
		break;
	case CHAR_TODOROKI:
		myCharacterInfo.szImgUrl = CHAR_TODOROKI_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_TODOROKI_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_TODOROKI_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_TODOROKI_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_TODOROKI_HERONAME;
		myCharacterInfo.nDay = CHAR_TODOROKI_DAY;
		myCharacterInfo.nMonth = CHAR_TODOROKI_MONTH;
		myCharacterInfo.szGender = CHAR_TODOROKI_GENDER;
		myCharacterInfo.szHeight = CHAR_TODOROKI_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_TODOROKI_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_TODOROKI_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_TODOROKI_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_TODOROKI_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_TODOROKI_SEATNO;
		myCharacterInfo.szLikes = CHAR_TODOROKI_LIKES;
		break;
	case CHAR_TORU:
		myCharacterInfo.szImgUrl = CHAR_HAGAKURE_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_HAGAKURE_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_HAGAKURE_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_HAGAKURE_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_HAGAKURE_HERONAME;
		myCharacterInfo.nDay = CHAR_HAGAKURE_DAY;
		myCharacterInfo.nMonth = CHAR_HAGAKURE_MONTH;
		myCharacterInfo.szGender = CHAR_HAGAKURE_GENDER;
		myCharacterInfo.szHeight = CHAR_HAGAKURE_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_HAGAKURE_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_HAGAKURE_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_HAGAKURE_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_HAGAKURE_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_HAGAKURE_SEATNO;
		myCharacterInfo.szLikes = CHAR_HAGAKURE_LIKES;
		break;
	case CHAR_BAKUGO:
		myCharacterInfo.szImgUrl = CHAR_BAKUGO_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_BAKUGO_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_BAKUGO_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_BAKUGO_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_BAKUGO_HERONAME;
		myCharacterInfo.nDay = CHAR_BAKUGO_DAY;
		myCharacterInfo.nMonth = CHAR_BAKUGO_MONTH;
		myCharacterInfo.szGender = CHAR_BAKUGO_GENDER;
		myCharacterInfo.szHeight = CHAR_BAKUGO_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_BAKUGO_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_BAKUGO_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_BAKUGO_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_BAKUGO_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_BAKUGO_SEATNO;
		myCharacterInfo.szLikes = CHAR_BAKUGO_LIKES;
		break;
	case CHAR_IZUKU:
		myCharacterInfo.szImgUrl = CHAR_IZUKU_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_IZUKU_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_IZUKU_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_IZUKU_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_IZUKU_HERONAME;
		myCharacterInfo.nDay = CHAR_IZUKU_DAY;
		myCharacterInfo.nMonth = CHAR_IZUKU_MONTH;
		myCharacterInfo.szGender = CHAR_IZUKU_GENDER;
		myCharacterInfo.szHeight = CHAR_IZUKU_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_IZUKU_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_IZUKU_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_IZUKU_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_IZUKU_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_IZUKU_SEATNO;
		myCharacterInfo.szLikes = CHAR_IZUKU_LIKES;
		break;
	case CHAR_MINORU:
		myCharacterInfo.szImgUrl = CHAR_MINORU_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_MINORU_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_MINORU_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_MINORU_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_MINORU_HERONAME;
		myCharacterInfo.nDay = CHAR_MINORU_DAY;
		myCharacterInfo.nMonth = CHAR_MINORU_MONTH;
		myCharacterInfo.szGender = CHAR_MINORU_GENDER;
		myCharacterInfo.szHeight = CHAR_MINORU_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_MINORU_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_MINORU_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_MINORU_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_MINORU_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_MINORU_SEATNO;
		myCharacterInfo.szLikes = CHAR_MINORU_LIKES;
		break;
	case CHAR_YAYOROZU:
		myCharacterInfo.szImgUrl = CHAR_YAYOROZU_IMGURL;
		myCharacterInfo.szCharNameRoman = CHAR_YAYOROZU_CHARNAME;
		myCharacterInfo.nHexColor = CHAR_YAYOROZU_HEXCOLOR;
		myCharacterInfo.szCharNameJap = CHAR_YAYOROZU_JAPNAME;
		myCharacterInfo.szHeroName = CHAR_YAYOROZU_HERONAME;
		myCharacterInfo.nDay = CHAR_YAYOROZU_DAY;
		myCharacterInfo.nMonth = CHAR_YAYOROZU_MONTH;
		myCharacterInfo.szGender = CHAR_YAYOROZU_GENDER;
		myCharacterInfo.szHeight = CHAR_YAYOROZU_HEIGHT;
		myCharacterInfo.szBloodType = CHAR_YAYOROZU_BLOODTYPE;
		myCharacterInfo.szQuirk = CHAR_YAYOROZU_QUIRK;
		myCharacterInfo.szBirthPlace = CHAR_YAYOROZU_BIRTHPLACE;
		myCharacterInfo.szOccupation = CHAR_YAYOROZU_OCCUP;
		myCharacterInfo.nSeatNo = CHAR_YAYOROZU_SEATNO;
		myCharacterInfo.szLikes = CHAR_YAYOROZU_LIKES;
		break;
	}
	BotLogger(LOGLEVEL_DEBUG, "myCharacterInfo 0x%08x is set!!", &myCharacterInfo);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSayCharSheet()
**
** Description:
**     Makes the bot say charsheet info
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**     event - Slash event (const dpp::slashcommand_t &)
**	   character - Character (MHA_CHARACTER_E)
**
** Output:
**     Char sheet as reply
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/11/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botSayCharSheet(dpp::cluster& bot, const dpp::slashcommand_t& event, MHA_CHARACTER_E character)
{
	funEmbed = dpp::embed();
	// Init myCharacterInfo...
	botCharSheetInitCharacterInfo(character);
	// Making embed for replying message
	funEmbed.set_color(myCharacterInfo.nHexColor)
		.set_title(myCharacterInfo.szCharNameRoman + " (" + myCharacterInfo.szCharNameJap + ")")
		.set_thumbnail(myCharacterInfo.szImgUrl)
		.add_field("Hero Name", myCharacterInfo.szHeroName)
		.add_field("Date of birth (mm/dd)", std::to_string(myCharacterInfo.nMonth) + "/" + std::to_string(myCharacterInfo.nDay))
		.add_field("Gender", myCharacterInfo.szGender)
		.add_field("Height", myCharacterInfo.szHeight)
		.add_field("Blood type", myCharacterInfo.szBloodType)
		.add_field("Quirk", myCharacterInfo.szQuirk)
		.add_field("Birth place", myCharacterInfo.szBirthPlace)
		.add_field("Occupation", myCharacterInfo.szOccupation)
		.add_field("Seat no.", std::to_string(myCharacterInfo.nSeatNo))
		.add_field("Likes", myCharacterInfo.szLikes)
		.set_footer(dpp::embed_footer().set_text(event.command.usr.username).set_icon(event.command.usr.get_avatar_url()))
		.set_timestamp(time(nullptr));
	BotLogger(LOGLEVEL_DEBUG, "Embed for help made, reply to user...");
	event.reply(
		dpp::message(event.command.channel_id, funEmbed)
	);
}