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
** File: Shoto_Base.h
** Description: TodorokiBot header
** Copyright (c) 2023 raulmrio28-git and contributors.
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Initial version
** ===========================================================================
*/

#ifndef _SHOTO_BASE_H_
#define _SHOTO_BASE_H_

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

void botSetStatusRandom(dpp::cluster& bot);
void botSayHelp(dpp::cluster& bot, const dpp::slashcommand_t& event);
void botSayPing(dpp::cluster& bot, const dpp::slashcommand_t& event);
void botSayHello(dpp::cluster& bot, const dpp::slashcommand_t& event);

#endif /* _SHOTO_BASE_H_ */