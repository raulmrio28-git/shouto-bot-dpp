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
** File: Shoto_Base.cpp
** Description: Bot custom code
** Copyright (c) 2023 raulmrio28-git and contributors.
** D++ bot library: Copyright 2021 Craig Edwards and D++ contributors.
** Licensed under the Apache License, Version 2.0. All rights reserved.
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	Some changes in some bot commands
** 03/04/2023	raulmrio28-git	Initial version
** ===========================================================================
*/

/*
**----------------------------------------------------------------------------
**  Includes
**----------------------------------------------------------------------------
*/

#include "Shoto_Debug.h"
#include "Shoto_Base.h"

/*
**----------------------------------------------------------------------------
**  Definitions
**----------------------------------------------------------------------------
*/

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

std::vector<std::string> vszStatuses = { "with cold soba. | use /help",
										"Dabi, since he's a Todoroki",
										"with your cute face | use /help",
										"with my cyberpunk outfit /j  | use /help",
										"huwi ringtones | use /help",
										"IS BRAIZ???? | use /help",
										"with a phone with vizzz ui | use /help",
										"MHA: The Strongest Hero",
										"theses trollfeeds | use /help",
										"Untung pakai Flexi",
										"Lemon Mobiles: TOMORROW has CHANGED"
										};

/*
**---------------------------------------------------------------------------
**  Internal variables
**---------------------------------------------------------------------------
*/

std::string szMyStatus; /* status */
dpp::embed baseEmbed; /* embed */
float nPingTime;

/*
**---------------------------------------------------------------------------
**  Function(internal use only) Declarations
**---------------------------------------------------------------------------
*/

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSetStatusRandom()
**
** Description:
**     Set bot status to something random
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**
** Output:
**     Set status into the bot cluster
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

void botSetStatusRandom(dpp::cluster& bot)
{
	szMyStatus = vszStatuses[rand() % vszStatuses.size()];
	BotLogger(LOGLEVEL_DEBUG, "Setting status to \"%s\"", szMyStatus.c_str());
	bot.set_presence(
		dpp::presence::presence(dpp::presence_status::ps_idle, dpp::activity_type::at_game, szMyStatus)
	);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSayHelp()
**
** Description:
**     Makes the bot say the help message
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**     event - Slash event (const dpp::slashcommand_t &)
**
** Output:
**     Help message as reply
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/05/2023	raulmrio28-git	newline after commands and add info
** 03/04/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botSayHelp(dpp::cluster& bot, const dpp::slashcommand_t& event)
{
	baseEmbed = dpp::embed();

	// Making embed for replying message
	baseEmbed.set_color(0x70c168)
		.set_title("Help")
		.add_field("Basic", "`/help` - Show usage of this bot\n`/ping` - Ping time of this bot during execution of this command\n`/hello` - Be greeted by TodorokiBot")
		.add_field("Fun", "`/slurp`\n`/handcrusher`\n`/selfie`\n`/punkboy`\n`/perfectboy`\n`/rowdyboy`\n`/garbageboy`\n`/fight`\n`/shotoball`\n`/flip`\n`/owo`\n`/bonk`")
		/* sadly no calc command unless we know how to calculate n numbers in C++ easily or find a C++ equivalent of math.eval() */
		.add_field("Information", "`/botinfo` - Info about this bot\n`/serverinfo` - Info about this server")
		.add_field("Mod Stuff (requires moderation perms)", "`/kick user:<user name and tag>` - Kick user\n`/ban user:<user name and tag>` - Ban user\n`/report user:<user name and tag>` - Report a user\n")
		.add_field("Character Sheets", "`/charsheet name:<name of character>` (Currently only works for class 1-A)")
		.set_footer(dpp::embed_footer().set_text(event.command.usr.username).set_icon(event.command.usr.get_avatar_url()))
		.set_timestamp(time(nullptr));
	BotLogger(LOGLEVEL_DEBUG, "Embed for help made, reply to user...");
	event.reply(
		dpp::message(event.command.channel_id, baseEmbed).set_flags(dpp::m_ephemeral)
	);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSayPing()
**
** Description:
**     Makes the bot say ping time
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**     event - Slash event (const dpp::slashcommand_t &)
**
** Output:
**     Ping time message as reply
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Use + to add string instead of making one with them added
** 03/04/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botSayPing(dpp::cluster& bot, const dpp::slashcommand_t& event)
{
	nPingTime = (bot.rest_ping + bot.get_shard(0)->websocket_ping);
	baseEmbed = dpp::embed();
	BotLogger(LOGLEVEL_INFO, "Ping time: %f seconds", nPingTime);
	// Making embed for replying message
	baseEmbed.set_color(0x70c168)
		.set_title("Pong!")
		.add_field("Ping time:", std::to_string(nPingTime * 1000) + "ms")
		.set_footer(dpp::embed_footer().set_text(event.command.usr.username).set_icon(event.command.usr.get_avatar_url()))
		.set_timestamp(time(nullptr));
	BotLogger(LOGLEVEL_DEBUG, "Embed for ping made, reply to user...");
	event.reply(
		dpp::message(event.command.channel_id, baseEmbed)
	);
}

/*
** ---------------------------------------------------------------------------
**
** Function:
**     botSayHello()
**
** Description:
**     Makes the bot say hello to the user
**
** Input:
**     bot - Bot cluster (dpp::cluster &)
**     event - Slash event (const dpp::slashcommand_t &)
**
** Output:
**     Hello message as reply
**
** Return value:
**     none
**
** History:
** when			who				what, where, why
** MM-DD-YYYY-- --------------- --------------------------------
** 03/04/2023	raulmrio28-git	Use + to add string instead of making one with them added
** 03/04/2023	raulmrio28-git	Initial version
** ---------------------------------------------------------------------------
*/

void botSayHello(dpp::cluster& bot, const dpp::slashcommand_t& event)
{
	BotLogger(LOGLEVEL_DEBUG, "Saying hello to %s", event.command.usr.username.c_str());
	event.reply("Hello, " + event.command.usr.username);
}