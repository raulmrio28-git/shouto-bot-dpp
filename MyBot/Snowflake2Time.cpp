/*
** ===========================================================================
** File: Snowflake2Time.cpp
** Description: Converts Discord snowflake ID to time_t or string
** Copyright (c) 2023 raulmrio28-git and contriburors.
** Parts of this code are inspired by https://github.com/QuickNET-Tech/dstact.
** All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Initial version
** ===========================================================================
*/

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include "Snowflake2Time.h"

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

#define  DISCORD_EPOCH	1420070400000

/*
**----------------------------------------------------------------------------
**  Type Definitions
**----------------------------------------------------------------------------
*/

std::vector<std::string> vszSfMonths = { "Unknown",
										"January",
										"February",
										"March",
										"April",
										"May",
										"June",
										"August",
										"September",
										"October",
										"November",
										"December"
};

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

time_t snRawtime_T; /* time_t */
struct tm snTimeinfo_T; /* time struct */
std::string szTimeString; /* time string */

/*
**---------------------------------------------------------------------------
**  Function(internal use only) Declarations
**---------------------------------------------------------------------------
*/

/*
** ---------------------------------------------------------------------------
**
** Function:
**     ullSnowflake2Timestamp
**
** Description:
**     Convert a Discord snowflake ID to a time_t
**
** Input:
**     ullSnowflake - snowflake (unsigned long long)
**
** Output:
**     Discord snowflake ID to a time_t
**
** Return value:
**     (ullSnowflake>>22)+DISCORD_EPOCH /1000
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

time_t ullSnowflake2Timestamp(unsigned long long ullSnowflake)
{
	return (ullSnowflake >> 22) + DISCORD_EPOCH / 1000;
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     szConv2DigNoToString
**
** Description:
**     Convert a 2 digit number to string
**
** Input:
**     nNumber - number to be converted (int)
**
** Output:
**     Number as string
**
** Return value:
**     varies
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

std::string szConv2DigNoToString(int nNumber)
{
	if (nNumber <= 9)
		return "0" + std::to_string(nNumber);
	else
		return std::to_string(nNumber);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     szConvSfTime2String
**
** Description:
**     Convert a Discord snowflake ID to a time and date string
**
** Input:
**     ullSnowflake - snowflake (unsigned long long)
**     bIsSnowflake - true (if snowflake) or false (if converted from snowflake)
**
** Output:
**     Discord snowflake ID to a time and date string
**
** Return value:
**     szTimeString
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

std::string szConvSfTime2String(unsigned long long ullSnowflake, bool bIsSnowflake)
{
	if (bIsSnowflake == true)
		snRawtime_T = ullSnowflake2Timestamp(ullSnowflake);
	else
		snRawtime_T = ullSnowflake;
	localtime_s(&snTimeinfo_T, &snRawtime_T);
	szTimeString = std::to_string(snTimeinfo_T.tm_wday) + " " + vszSfMonths[snTimeinfo_T.tm_mon] + " " + std::to_string(snTimeinfo_T.tm_year + 1900) + ", " + szConv2DigNoToString(snTimeinfo_T.tm_hour) + ":" + szConv2DigNoToString(snTimeinfo_T.tm_min) + ":" + szConv2DigNoToString (snTimeinfo_T.tm_sec);
	return szTimeString;
}