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
** File: Shoto_Debug.h
** Description: Bot custom header
** Copyright (c) 2023 raulmrio28-git and contributors.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Initial version
** ===========================================================================
*/

#ifndef _SHOTO_DEBUG_H_
#define _SHOTO_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include <stdlib.h> /* malloc */
#include <stdio.h> /* sprintf */
#include <time.h> /* grabbing time */
#include <stdarg.h> /* vargs */
#include <string.h> /* memset */

/*
**----------------------------------------------------------------------------
**  Type Definitions
**----------------------------------------------------------------------------
*/

enum tagLOG_TYPES_E
{
	LOGLEVEL_CLOSE = 0, /* nothing */
	LOGLEVEL_DEBUG, /* debug */
	LOGLEVEL_WARN, /* warning */
	LOGLEVEL_INFO, /* information */
	LOGLEVEL_ERROR /* failure */
};
typedef enum tagLOG_TYPES_E  LOG_TYPES_E;

/*
**---------------------------------------------------------------------------
**  Function(external use only) Declarations
**---------------------------------------------------------------------------
*/

extern void Shoto_Log(LOG_TYPES_E nLevel, const char* pszFile, int nLine, const char* pszFunction, const char* pszString, ...);

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

#define BotLogger(level, msg, ...) Shoto_Log(level, __FILE__, __LINE__, __func__, msg, ##__VA_ARGS__)

/*
**----------------------------------------------------------------------------
**  General Declarations
**----------------------------------------------------------------------------
*/

#ifdef __cplusplus
}
#endif

#endif /* _SHOTO_INCLUDE_H_ */