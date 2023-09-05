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
** File: Shoto_Time.cpp
** Description: Bot custom code
** Copyright (c) 2023 raulmrio28-git and contributors.
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
** Parts of this code are inspired by https://github.com/QuickNET-Tech/dstact.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 09/05/2023	raulmrio28-git	Initial version. Moves snowflake time code to
**								here
** ===========================================================================
*/

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include "Shoto_Time.h"

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

std::vector<std::string> vszMonths = { "Unknown",
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

time_t Rawtime_T; /* time_t */
struct tm Timeinfo_T; /* time struct */
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
** 09/05/2023	raulmrio28-git	Initial version. Moves snowflake time code to
**								here
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
** 09/05/2023	raulmrio28-git	Initial version. Moves snowflake time code to
**								here
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
**     szConvTime2String
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
** 09/05/2023	raulmrio28-git	Initial version. Moves snowflake time code to
**								here
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

std::string szConvSfTime2String(unsigned long long ullSnowflake, bool bIsSnowflake)
{
	if (bIsSnowflake == true)
		Rawtime_T = ullSnowflake2Timestamp(ullSnowflake);
	else
		Rawtime_T = ullSnowflake;
	localtime_s(&Timeinfo_T, &Rawtime_T);
	return std::to_string(Timeinfo_T.tm_wday) + " " + vszMonths[Timeinfo_T.tm_mon] + " " + std::to_string(Timeinfo_T.tm_year + 1900) + ", " + szConv2DigNoToString(Timeinfo_T.tm_hour) + ":" + szConv2DigNoToString(Timeinfo_T.tm_min) + ":" + szConv2DigNoToString(Timeinfo_T.tm_sec);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     szConvTime2String
**
** Description:
**     Convert a time_t to a time and date string
**
** Input:
**     ullTime - the time (time_t)
**
** Output:
**     time_t to a time and date string
**
** Return value:
**     szTimeString
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 09/05/2023	raulmrio28-git	Initial version. Moves Information time code
**								to here
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

std::string szConvTime2String(time_t Time_T)
{
	Rawtime_T = Time_T;
	localtime_s(&Timeinfo_T, &Rawtime_T);
	return std::to_string(Timeinfo_T.tm_wday) + " " + vszMonths[Timeinfo_T.tm_mon] + " " + std::to_string(Timeinfo_T.tm_year + 1900) + ", " + szConv2DigNoToString(Timeinfo_T.tm_hour) + ":" + szConv2DigNoToString(Timeinfo_T.tm_min) + ":" + szConv2DigNoToString(Timeinfo_T.tm_sec);
}