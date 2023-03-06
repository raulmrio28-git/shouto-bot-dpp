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
** File: Shoto_Information.cpp
** Description: Bot custom code
** Copyright (c) 2023 raulmrio28-git and contriburors.
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
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

#include "Shoto_Debug.h"
#include "Shoto_Information.h"
#include "Snowflake2Time.h"

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

std::vector<std::string> vszSiMonths = { "Unknown",
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

dpp::guild* guild; /* Server guild */
dpp::embed infoEmbed; /* embed */
time_t siRawtime_T; /* time_t */
struct tm siTimeinfo_T; /* time struct */

/*
**---------------------------------------------------------------------------
**  Function(internal use only) Declarations
**---------------------------------------------------------------------------
*/

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
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

std::string szConvTime2String(time_t ullTime)
{
	siRawtime_T = ullTime;
	localtime_s(&siTimeinfo_T, &siRawtime_T);
	return std::to_string(siTimeinfo_T.tm_wday) + " " + vszSiMonths[siTimeinfo_T.tm_mon] + " " + std::to_string(siTimeinfo_T.tm_year + 1900) + ", " + szConv2DigNoToString(siTimeinfo_T.tm_hour) + ":" + szConv2DigNoToString(siTimeinfo_T.tm_min) + ":" + szConv2DigNoToString(siTimeinfo_T.tm_sec);
	
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSayServerInformation()
**
** Description:
**     Makes the bot say an embed with info regarding the server
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**     event - Slash event (const dpp::slashcommand_t &)
**
** Output:
**     Server info as reply
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botSayServerInformation(dpp::cluster& bot, const dpp::slashcommand_t& event)
{
	guild = dpp::find_guild(event.command.guild_id);
	infoEmbed = dpp::embed();
	BotLogger(LOGLEVEL_DEBUG, "Server created on: %16x\n", guild->get_creation_time());
	infoEmbed.set_color(0xffa3d4)
		.set_title("Server Information")
		.set_thumbnail(guild->get_icon_url())
		.add_field("Server name", guild->name)
		.add_field("Created on", szConvSfTime2String(guild->get_creation_time(), false))
		.add_field("You joined on", szConvTime2String(event.command.member.joined_at))
		.add_field("Total members", std::to_string(guild->member_count))
		.set_footer(dpp::embed_footer().set_text(event.command.usr.username).set_icon(event.command.usr.get_avatar_url()))
		.set_timestamp(time(nullptr));
	BotLogger(LOGLEVEL_DEBUG, "Embed for serverinfo made, reply to user...");
	event.reply(
		dpp::message(event.command.channel_id, infoEmbed)
	);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSayBotInformation()
**
** Description:
**     Makes the bot say an embed with info regarding the bot
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**     event - Slash event (const dpp::slashcommand_t &)
**
** Output:
**     Bot info as reply
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botSayBotInformation(dpp::cluster& bot, const dpp::slashcommand_t& event)
{
	infoEmbed = dpp::embed();
	BotLogger(LOGLEVEL_DEBUG, "Bot created on: %16x\n", bot.me.get_creation_time());
	infoEmbed.set_color(0xa3fffa)
		.set_title("Bot Information")
		.set_thumbnail(bot.me.get_avatar_url())
		.add_field("Bot name", bot.me.username)
		.add_field("Created on", szConvSfTime2String(bot.me.get_creation_time(), false))
		.set_footer(dpp::embed_footer().set_text(event.command.usr.username).set_icon(event.command.usr.get_avatar_url()))
		.set_timestamp(time(nullptr));
	BotLogger(LOGLEVEL_DEBUG, "Embed for botinfo made, reply to user...");
	event.reply(
		dpp::message(event.command.channel_id, infoEmbed)
	);
}
