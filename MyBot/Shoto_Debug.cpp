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
** File: Shoto_Debug.cpp
** Description: Bot custom code
** Copyright (c) 2023 raulmrio28-git and contributors.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Initial version
** ===========================================================================
*/

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include "Shoto_Debug.h"

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

#define  CONSTSTR_DEBUG     "[->DEBUG<-] "
#define  CONSTSTR_INFO      "[->INFO<-] "
#define  CONSTSTR_WARNING   "[->WARNING<-] "
#define  CONSTSTR_ERROR     "[->ERROR<-] "

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

char szBuffer[1024]; /* temp buffer */
time_t rawtime_T; /* time_t */
struct tm timeinfo_T; /* time struct */
char* pszBuffer; /* temp ptr buffer */

/*
**---------------------------------------------------------------------------
**  Function(internal use only) Declarations
**---------------------------------------------------------------------------
*/

/*
** ---------------------------------------------------------------------------
**
** Function:
**     pszGetDate()
**
** Description:
**     Get date of the system to a char string
**
** Input:
**     none
**
** Output:
**     Date during execution
**
** Return value:
**     pszBuffer
** 
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

char* pszGetDate()
{
	time(&rawtime_T);
	localtime_s(&timeinfo_T,&rawtime_T);
	pszBuffer = (char*)malloc(11);
	if (pszBuffer != NULL)
		sprintf_s(pszBuffer, _msize(pszBuffer), "%02d/%02d/%04d", timeinfo_T.tm_mday, timeinfo_T.tm_mon + 1, timeinfo_T.tm_year + 1900);
	return pszBuffer;
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     pszGetTime()
**
** Description:
**     Get time of the system to a char string
**
** Input:
**     none
**
** Output:
**     Time during execution
**
** Return value:
**     pszBuffer
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

char* pszGetTime()
{
	time(&rawtime_T);
	localtime_s(&timeinfo_T, &rawtime_T); 
	pszBuffer = (char*)malloc(9);
	if (pszBuffer != NULL)
		sprintf_s(pszBuffer, _msize(pszBuffer), "%02d:%02d:%02d", timeinfo_T.tm_hour, timeinfo_T.tm_min, timeinfo_T.tm_sec);
	return pszBuffer;
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     Shoto_Log()
**
** Description:
**     Debug logging
**
** Input:
**     nLevel - Type of information (LOG_TYPES_E)
**     pszFile - File (char*)
**     pszLine - Line (int)
**     pszFunction - Function (char*)
**     pszString - String (char*)
**     ...
**
** Output:
**     Debug information in stdout
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void Shoto_Log (LOG_TYPES_E nLevel, const char *pszFile, int nLine, const char *pszFunction, const char* pszString, ...)
{
	va_list argList;
	va_start(argList, pszString);
	vsprintf_s(szBuffer, sizeof(szBuffer), pszString, argList);
	va_end(argList);
	switch (nLevel)
	{
	case LOGLEVEL_DEBUG:
		printf(CONSTSTR_DEBUG"[%s-%s] FILE:%s LINE:%d %s->%s\n", pszGetDate(), pszGetTime(), pszFile, nLine, pszFunction, szBuffer);
		break; 
	case LOGLEVEL_INFO:
		printf(CONSTSTR_INFO"[%s-%s] FILE:%s LINE:%d %s->%s\n", pszGetDate(), pszGetTime(), pszFile, nLine, pszFunction, szBuffer);
		break; 
	case LOGLEVEL_WARN:
		printf(CONSTSTR_WARNING"[%s-%s] FILE:%s LINE:%d %s->%s\n", pszGetDate(), pszGetTime(), pszFile, nLine, pszFunction, szBuffer);
		break;
	case LOGLEVEL_ERROR:
		printf(CONSTSTR_ERROR"[%s-%s] FILE:%s LINE:%d %s->%s\n", pszGetDate(), pszGetTime(), pszFile, nLine, pszFunction, szBuffer);
		break;
	default:
		break;
	}
	free(pszBuffer);
	memset(szBuffer, sizeof(szBuffer), 0);
}