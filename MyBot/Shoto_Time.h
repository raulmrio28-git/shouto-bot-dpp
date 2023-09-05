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
** File: Shoto_Time.h
** Description: TodorokiBot header
** Copyright (c) 2023 raulmrio28-git and contributors.
** Parts of this code are inspired by https://github.com/QuickNET-Tech/dstact.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 09/05/2023	raulmrio28-git	Initial version. Moves snowflake time code to
**								here
** ===========================================================================
*/

#ifndef _SHOTO_TIME_H_
#define _SHOTO_TIME_H_

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include <time.h> /* grabbing time */
#include <string> /* string */
#include <vector> /* vector */

/*
**-----------------------------------------------------------------------------
**  Type Definitions
**----------------------------------------------------------------------------
*/

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

/*
**-----------------------------------------------------------------------------
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
std::string szConvTime2String(time_t Time_T);

#endif /* _SNOWFLAKE_2_TIME_H_ */