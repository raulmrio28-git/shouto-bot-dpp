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
#include "BotIncludes.h"
#include <dpp/dpp.h>
#include <string>
#include <vector>

int main()
{
    /* Create bot cluster */
    dpp::cluster bot(BOT_TOKEN);

    /* Output simple log messages to stdout */
    bot.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    bot.on_slashcommand([&](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            botSayPing(bot, event);
        }
        if (event.command.get_command_name() == "help") {
            botSayHelp(bot, event);
        }
        if (event.command.get_command_name() == "hello") {
            botSayHello(bot, event);
        }
        if (event.command.get_command_name() == "botinfo") {
            botSayBotInformation(bot, event);
        }
        if (event.command.get_command_name() == "serverinfo") {
            botSayServerInformation(bot, event);
        }
        });

    /* Register slash command here in on_ready */
    bot.on_ready([&bot](const dpp::ready_t& event) {
        BotLogger(LOGLEVEL_INFO, "Hello, Bot's ready!");
        // Set presence for the bot
    bot.start_timer([&](dpp::timer) {
            botSetStatusRandom(bot);
        }, 30);
        /* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
            bot.global_command_create(dpp::slashcommand("help", "Help on using this bot", bot.me.id));
            bot.global_command_create(dpp::slashcommand("hello", "Be greeted by TodorokiBot", bot.me.id));
            bot.global_command_create(dpp::slashcommand("botinfo", "Info about this bot", bot.me.id));
            bot.global_command_create(dpp::slashcommand("serverinfo", "Info about this server", bot.me.id));
        }
    });

    SetConsoleTitle(TEXT("Shoto Todoroki Bot ========= LOGGING! ========="));
    /* Start the bot */
    bot.start(dpp::st_wait);

    return 0;
}
