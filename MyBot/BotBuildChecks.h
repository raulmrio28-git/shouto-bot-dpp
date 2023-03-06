/************************************************************************************
 *
 * D++, A Lightweight C++ library for Discord
 *
 * Copyright 2021 Craig Edwards and D++ contributors
 * (https://github.com/brainboxdotcc/DPP/graphs/contributors)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ************************************************************************************/
/*
** ===========================================================================
** File: BotBuildChecks.h
** Description: Bot build checks
** Copyright (c) 2023 raulmrio28-git and contriburors.
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
** All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 01/07/2023	raulmrio28-git	Initial version
** ===========================================================================
*/
#ifndef _BOT_BUILD_CHECKS_H_
#define _BOT_BUILD_CHECKS_H_

/* Some user friendly sanity checks to cut down on silly support issues */

#if !defined(_MSC_VER) || (_MSC_VER < 1929)
	#error "This template is only for Microsoft Visual C++ 2019 and later. To build a D++ bot in Visual Studio Code, or on any other platform or compiler please use https://github.com/brainboxdotcc/templatebot"
#endif

#if (!defined(_MSVC_LANG) || _MSVC_LANG < 201703L)
	#error "D++ bots require C++17 or later. Please enable C++17 under project properties."
#endif

#if !defined(DPP_WIN_TEMPLATE) && !defined(DPP_CI)
	#error "You must compile this template using its .sln file. You cannot just double click the .cpp file and compile it on its own. Ensure you checked out the full source code of the template!"
#endif

#endif /* _BOT_BUILD_CHECKS_H_ */