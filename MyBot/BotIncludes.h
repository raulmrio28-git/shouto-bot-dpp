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
** File: BotIncludes.h
** Description: Bot includes
** Copyright (c) 2023 raulmrio28-git and contriburors. 
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
** All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/03/2023	raulmrio28-git	Initial version
** ===========================================================================
*/
#ifndef _BOT_INCLUDES_H_
#define _BOT_INCLUDES_H_

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/
#include "BotBuildChecks.h"
#include "Shoto_Include.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/
//To dev: replace the PLACE_YOUR_TOKEN_HERE in BOT_TOKEN with your bot's token
#define BOT_TOKEN "PLACE_YOUR_TOKEN_HERE"

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* _BOT_INCLUDES_H_ */
