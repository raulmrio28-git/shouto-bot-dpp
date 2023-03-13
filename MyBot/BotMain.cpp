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
#include <locale>
#include <algorithm>
using namespace std;

// templated version of my_equal so it could work with both char and wchar_t
template<typename charT>
struct my_equal {
    my_equal(const std::locale& loc) : loc_(loc) {}
    bool operator()(charT ch1, charT ch2) {
        return std::toupper(ch1, loc_) == std::toupper(ch2, loc_);
    }
private:
    const std::locale& loc_;
};

// find substring (case insensitive)
template<typename T>
int ci_find_substr(const T& str1, const T& str2, const std::locale& loc = std::locale())
{
    typename T::const_iterator it = std::search(str1.begin(), str1.end(),
        str2.begin(), str2.end(), my_equal<typename T::value_type>(loc));
    if (it != str1.end()) return it - str1.begin();
    else return -1; // not found
}

int main()
{
    /* Create bot cluster */
    dpp::cluster bot(BOT_TOKEN);

    /* Output simple log messages to stdout */
    bot.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    bot.on_slashcommand([&](const dpp::slashcommand_t& event) {
        dpp::interaction interaction = event.command;
        dpp::command_interaction cmd_data = interaction.get_command_interaction();
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
        if (interaction.get_command_name() == "charsheet") {
            std::string szMyVal = cmd_data.get_value<std::string>(0);
            if (ci_find_substr(szMyVal, (std::string)"deku") != -1 || ci_find_substr(szMyVal, (std::string)"izuku") != -1 || ci_find_substr(szMyVal, (std::string)"midoriya") != -1 || ci_find_substr(szMyVal, (std::string)"quirkle") != -1)
                botSayCharSheet(bot, event, CHAR_IZUKU);
            else if (ci_find_substr(szMyVal, (std::string)"baku") != -1 || ci_find_substr(szMyVal, (std::string)"katsu") != -1 || ci_find_substr(szMyVal, (std::string)"explo") != -1 || ci_find_substr(szMyVal, (std::string)"kaachan") != -1 || ci_find_substr(szMyVal, (std::string)"dyna") != -1)
                botSayCharSheet(bot, event, CHAR_BAKUGO);
            else if (ci_find_substr(szMyVal, (std::string)"todo") != -1 || ci_find_substr(szMyVal, (std::string)"shoto") != -1 || ci_find_substr(szMyVal, (std::string)"cold") != -1 || ci_find_substr(szMyVal, (std::string)"icy") != -1 || ci_find_substr(szMyVal, (std::string)"hot") != -1)
                botSayCharSheet(bot, event, CHAR_TODOROKI);
            else if (ci_find_substr(szMyVal, (std::string)"aoya") != -1 || ci_find_substr(szMyVal, (std::string)"yuga") != -1 || ci_find_substr(szMyVal, (std::string)"shin") != -1 || ci_find_substr(szMyVal, (std::string)"navel") != -1)
                botSayCharSheet(bot, event, CHAR_AOYAMA);
            else if (ci_find_substr(szMyVal, (std::string)"mina") != -1 || ci_find_substr(szMyVal, (std::string)"ashid") != -1 || ci_find_substr(szMyVal, (std::string)"pinky") != -1 || ci_find_substr(szMyVal, (std::string)"acid") != -1)
                botSayCharSheet(bot, event, CHAR_ASHIDO);
            else if (ci_find_substr(szMyVal, (std::string)"asui") != -1 || ci_find_substr(szMyVal, (std::string)"tsuyu") != -1 || ci_find_substr(szMyVal, (std::string)"froppy") != -1 || ci_find_substr(szMyVal, (std::string)"frog") != -1)
                botSayCharSheet(bot, event, CHAR_ASUI);
            else if (ci_find_substr(szMyVal, (std::string)"ida") != -1 || ci_find_substr(szMyVal, (std::string)"tenya") != -1 || ci_find_substr(szMyVal, (std::string)"ingen") != -1 || ci_find_substr(szMyVal, (std::string)"engin") != -1)
                botSayCharSheet(bot, event, CHAR_TENYA);
            else if (ci_find_substr(szMyVal, (std::string)"uraraka") != -1 || ci_find_substr(szMyVal, (std::string)"ochak") != -1 || ci_find_substr(szMyVal, (std::string)"uravi") != -1 || ci_find_substr(szMyVal, (std::string)"zero") != -1)
                botSayCharSheet(bot, event, CHAR_OCHACO);
            else if (ci_find_substr(szMyVal, (std::string)"mashirao") != -1 || ci_find_substr(szMyVal, (std::string)"ojir") != -1 || ci_find_substr(szMyVal, (std::string)"tail") != -1)
                botSayCharSheet(bot, event, CHAR_OJIRO);
            else if (ci_find_substr(szMyVal, (std::string)"kaminari") != -1 || ci_find_substr(szMyVal, (std::string)"denki") != -1 || ci_find_substr(szMyVal, (std::string)"electric") != -1 || ci_find_substr(szMyVal, (std::string)"charge") != -1)
                botSayCharSheet(bot, event, CHAR_DENKI);
            else if (ci_find_substr(szMyVal, (std::string)"eiji") != -1 || ci_find_substr(szMyVal, (std::string)"kiri") != -1 || ci_find_substr(szMyVal, (std::string)"harden") != -1)
                botSayCharSheet(bot, event, CHAR_EIJIRO);
            else if (ci_find_substr(szMyVal, (std::string)"koji") != -1 || ci_find_substr(szMyVal, (std::string)"koda") != -1 || ci_find_substr(szMyVal, (std::string)"anima") != -1 || ci_find_substr(szMyVal, (std::string)"anivo") != -1)
                botSayCharSheet(bot, event, CHAR_KOJIKODA);
            else if (ci_find_substr(szMyVal, (std::string)"sato") != -1 || ci_find_substr(szMyVal, (std::string)"rikid") != -1 || ci_find_substr(szMyVal, (std::string)"sugar") != -1)
                botSayCharSheet(bot, event, CHAR_RIKIDO);
            else if (ci_find_substr(szMyVal, (std::string)"shoj") != -1 || ci_find_substr(szMyVal, (std::string)"mezo") != -1 || ci_find_substr(szMyVal, (std::string)"tentac") != -1 || ci_find_substr(szMyVal, (std::string)"dupli") != -1)
                botSayCharSheet(bot, event, CHAR_SHOJI);
            else if (ci_find_substr(szMyVal, (std::string)"kyoka") != -1 || ci_find_substr(szMyVal, (std::string)"jiro") != -1 || ci_find_substr(szMyVal, (std::string)"earph") != -1 || ci_find_substr(szMyVal, (std::string)"jack") != -1)
                botSayCharSheet(bot, event, CHAR_KYOKA);
            else if (ci_find_substr(szMyVal, (std::string)"hant") != -1 || ci_find_substr(szMyVal, (std::string)"sero") != -1 || ci_find_substr(szMyVal, (std::string)"tape") != -1 || ci_find_substr(szMyVal, (std::string)"cello") != -1)
                botSayCharSheet(bot, event, CHAR_HANTA);
            else if (ci_find_substr(szMyVal, (std::string)"fumi") != -1 || ci_find_substr(szMyVal, (std::string)"tokoya") != -1 || ci_find_substr(szMyVal, (std::string)"tsukuy") != -1 || ci_find_substr(szMyVal, (std::string)"shado") != -1)
                botSayCharSheet(bot, event, CHAR_TOKOYAMI);
            else if (ci_find_substr(szMyVal, (std::string)"toru") != -1 || ci_find_substr(szMyVal, (std::string)"hagaku") != -1 || ci_find_substr(szMyVal, (std::string)"invisib") != -1)
                botSayCharSheet(bot, event, CHAR_TORU);
            else if (ci_find_substr(szMyVal, (std::string)"minet") != -1 || ci_find_substr(szMyVal, (std::string)"minoru") != -1 || ci_find_substr(szMyVal, (std::string)"pop") != -1 || ci_find_substr(szMyVal, (std::string)"grape") != -1)
                botSayCharSheet(bot, event, CHAR_MINORU);
            else if (ci_find_substr(szMyVal, (std::string)"momo") != -1 || ci_find_substr(szMyVal, (std::string)"yaoyo") != -1 || ci_find_substr(szMyVal, (std::string)"creati") != -1)
                botSayCharSheet(bot, event, CHAR_YAYOROZU);
            else
                event.reply("IDK what you typed...\nIt might not be available or it doesn't belong here!");
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
            dpp::slashcommand charsheet("charsheet", "Get information of a BNHA/MHA character (UA Class 1-A ONLY!)", bot.me.id);
            charsheet.add_option(
                dpp::command_option(dpp::co_string, "name", "Name of character", false)
            );
            bot.global_command_create(charsheet);
        }
    });

    SetConsoleTitle(TEXT("Shoto Todoroki Bot ========= LOGGING! ========="));
    /* Start the bot */
    bot.start(dpp::st_wait);

    return 0;
}
