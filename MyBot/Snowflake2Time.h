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

#ifndef _SNOWFLAKE_2_TIME_H_
#define _SNOWFLAKE_2_TIME_H_

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include <time.h> /* grabbing time */
#include <string> /* string */
#include <vector> /* vector */

/*
**----------------------------------------------------------------------------
**  Type Definitions
**----------------------------------------------------------------------------
*/

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

/*
**---------------------------------------------------------------------------
**  Function(external use only) Declarations
**---------------------------------------------------------------------------
*/

std::string szConv2DigNoToString(int nNumber);
std::string szConvSfTime2String(unsigned long long ullSnowflake, bool bIsSnowflake);

#endif /* _SNOWFLAKE_2_TIME_H_ */