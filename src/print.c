#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/physic.h"
#include "../headers/talk.h"
#include "../headers/talkbis.h"

void print_player(WINDOW *cam, trainer *player)
{

    if (player->is_on_water == 1)
    {
        wattron(cam, COLOR_PAIR(1));
        mvwprintw(cam, ((63 - 2) / 2), ((236 - 2) / 2) + 3, "_");
        mvwprintw(cam, ((63 - 2) / 2) + 1, ((236 - 2) / 2) + 2, "'_'");
        mvwprintw(cam, ((63 - 2) / 2) + 2, ((236 - 2) / 2) + 1, "/| |\\");
        mvwprintw(cam, ((63 - 2) / 2) + 3, (236 - 2) / 2, "' |_| '");
        mvwprintw(cam, ((63 - 2) / 2) + 4, ((236 - 2) / 2) + 2, "|");
        mvwprintw(cam, ((63 - 2) / 2) + 4, ((236 - 2) / 2) + 4, "|");
        mvwprintw(cam, ((63 - 2) / 2) + 5, ((236 - 2) / 2) + 1, "-----");
        wattroff(cam, COLOR_PAIR(1));
    }
    else
    {
        wattron(cam, COLOR_PAIR(1));
        mvwprintw(cam, ((63 - 2) / 2), ((236 - 2) / 2) + 3, "_");
        mvwprintw(cam, ((63 - 2) / 2) + 1, ((236 - 2) / 2) + 2, "'_'");
        mvwprintw(cam, ((63 - 2) / 2) + 2, ((236 - 2) / 2) + 1, "/| |\\");
        mvwprintw(cam, ((63 - 2) / 2) + 3, (236 - 2) / 2, "'");
        mvwprintw(cam, ((63 - 2) / 2) + 3, ((236 - 2) / 2) + 2, "|_|");
        mvwprintw(cam, ((63 - 2) / 2) + 3, ((236 - 2) / 2) + 6, "'");
        mvwprintw(cam, ((63 - 2) / 2) + 4, ((236 - 2) / 2) + 2, "|");
        mvwprintw(cam, ((63 - 2) / 2) + 4, ((236 - 2) / 2) + 4, "|");
        mvwprintw(cam, ((63 - 2) / 2) + 5, ((236 - 2) / 2) + 2, "-");
        mvwprintw(cam, ((63 - 2) / 2) + 5, ((236 - 2) / 2) + 4, "-");
        wattroff(cam, COLOR_PAIR(1));
    }
}

void chargement(int time)
{
    WINDOW *pikachu_screen = newwin(62, 235, 0, 0);
    WINDOW *blackscreen = newwin(62, 235, 0, 0);
    FILE *f = NULL;
    int sec = 0, count_points = 0, frame_number;

    f = fopen("ressources/pikachu_frames", "r");
    if (f == NULL)
    {
        printw("ouverture du fichier ratée");
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(71);
    }

    while (sec != 6)
    {
        char ligne[101];
        int ligne_limite;

        for (frame_number = 1; frame_number <= 4; frame_number++)
        {
            switch (frame_number)
            {
            case 1:
                ligne_limite = 34;
                break;
            case 2:
                ligne_limite = 29; /*ligne_limite=nombre de lignes de l'image*/
                break;
            case 3:
                ligne_limite = 30;
                break;
            case 4:
                ligne_limite = 34;
                break;
            default:
                break;
            }

            // wattron(pikachu_screen,COLOR_PAIR(3));
            int j = 15;
            for (int i = 0; i < ligne_limite; i++)
            {
                fgets(ligne, 100, f);
                mvwprintw(pikachu_screen, j, 60, "%s", ligne);
                j++;
            }
            // wattroff(pikachu_screen,COLOR_PAIR(3));

            // 4 affichages = 1sec
            if (count_points < 4)
            {
                mvwprintw(pikachu_screen, 15, 160, "    __                    ___                   ");
                mvwprintw(pikachu_screen, 15 + 1, 160, "   / /   ____  ____ _____/ (_)___  ____ _       ");
                mvwprintw(pikachu_screen, 15 + 2, 160, "  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/       ");
                mvwprintw(pikachu_screen, 15 + 3, 160, " / /___/ /_/ / /_/ / /_/ / / / / / /_/ /  _ ");
                mvwprintw(pikachu_screen, 15 + 4, 160, "/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__, /  (_)");
                mvwprintw(pikachu_screen, 15 + 5, 160, "                                /____/          ");
            }

            else if (count_points < 8)
            {
                mvwprintw(pikachu_screen, 15, 160, "    __                    ___                   ");
                mvwprintw(pikachu_screen, 15 + 1, 160, "   / /   ____  ____ _____/ (_)___  ____ _       ");
                mvwprintw(pikachu_screen, 15 + 2, 160, "  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/       ");
                mvwprintw(pikachu_screen, 15 + 3, 160, " / /___/ /_/ / /_/ / /_/ / / / / / /_/ /  _ _");
                mvwprintw(pikachu_screen, 15 + 4, 160, "/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__, /  (_|_)");
                mvwprintw(pikachu_screen, 15 + 5, 160, "                                /____/          ");
            }

            else if (count_points < 12)
            {
                mvwprintw(pikachu_screen, 15, 160, "    __                    ___                   ");
                mvwprintw(pikachu_screen, 15 + 1, 160, "   / /   ____  ____ _____/ (_)___  ____ _       ");
                mvwprintw(pikachu_screen, 15 + 2, 160, "  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/       ");
                mvwprintw(pikachu_screen, 15 + 3, 160, " / /___/ /_/ / /_/ / /_/ / / / / / /_/ /  _ _ _ ");
                mvwprintw(pikachu_screen, 15 + 4, 160, "/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__, /  (_|_|_)");
                mvwprintw(pikachu_screen, 15 + 5, 160, "                                /____/          ");
            }

            wrefresh(pikachu_screen);
            wclear(pikachu_screen);

            usleep(68000);
        }

        if (count_points == 11)
        {
            count_points = 0;
            sec += 6;
        }
        else
        {
            count_points++;
        }
        rewind(f);
    }

    fclose(f);
    wclear(blackscreen);
    wrefresh(blackscreen);

    if (delwin(pikachu_screen) == ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(72);
    }
    if (delwin(blackscreen) == ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(73);
    }
    int ch;
    while ((ch = getch()) != ERR)
    {
    }
}

void print_poke(WINDOW *win, pokemon poke, int x, int y, int FRONT0_BACK1)
{

    if (FRONT0_BACK1 == 0) // FRONT
    {
        switch (poke.art_front)
        {
        case CHARMANDER:
            mvwprintw(win, x, y, " $$$              ");
            mvwprintw(win, x + 1, y, " $$$$$##          ");
            mvwprintw(win, x + 2, y, "*$$$$$,*          ");
            mvwprintw(win, x + 3, y, "#,$$$. (        # ");
            mvwprintw(win, x + 4, y, "   ###(#$      ###");
            mvwprintw(win, x + 5, y, "$$#@@@@$$$$(   &&(");
            mvwprintw(win, x + 6, y, "   @@@&@$$      $ ");
            mvwprintw(win, x + 7, y, " &$&&&&&&$$#(((#  ");
            mvwprintw(win, x + 8, y, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(win, x, y, "    .&$$$$#            ");
            mvwprintw(win, x + 1, y, "   *$$$$ ,#((        ");
            mvwprintw(win, x + 2, y, "   ( (((.*((*        ");
            mvwprintw(win, x + 3, y, "    $$((((,((        ");
            mvwprintw(win, x + 4, y, ",$$#&&$..$$#((#      ");
            mvwprintw(win, x + 5, y, "   &&&.&*((#$((      ");
            mvwprintw(win, x + 6, y, "   $&&&&&#$$$/ ###(((");
            mvwprintw(win, x + 7, y, "  $#((###$$$$((((((( ");
            mvwprintw(win, x + 8, y, "          ((((      ");
            break;

        case BULBASAUR:
            mvwprintw(win, x, y, "          $$########(     ");
            mvwprintw(win, x + 1, y, "   $#   .(## $######(/  ");
            mvwprintw(win, x + 2, y, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(win, x + 3, y, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(win, x + 4, y, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(win, x + 5, y, "(.#$$$$######(((((((((/ ");
            mvwprintw(win, x + 6, y, "   #/((((((,($#$$##//(( ");
            mvwprintw(win, x + 7, y, "   (((#( ((((.$$#(((((( ");
            mvwprintw(win, x + 8, y, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(win, x, y, "   .");
            mvwprintw(win, x + 1, y, " #@.     ./,**");
            mvwprintw(win, x + 2, y, " .$@@@$#&$#     .&/ ");
            mvwprintw(win, x + 3, y, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(win, x + 4, y, " #$$//$$($..#$$&&&* ");
            mvwprintw(win, x + 5, y, "  &&$$$#$&&  *#");
            mvwprintw(win, x + 6, y, " /&(&&/&&#&.((,");
            mvwprintw(win, x + 7, y, "(&$$&&&$&&$$.,");
            mvwprintw(win, x + 8, y, " /$#(//$$$$/");
            mvwprintw(win, x + 9, y, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(win, x, y, "    ,           #            ");
            mvwprintw(win, x + 1, y, "  .(  (       (***#,       ");
            mvwprintw(win, x + 2, y, "/*####,      ..***///*#    ");
            mvwprintw(win, x + 3, y, "*,###(//   #.**/**,/////., ");
            mvwprintw(win, x + 4, y, "** . **/##..**///**/  * /* ");
            mvwprintw(win, x + 5, y, "     ##/$$#,#        ((   /");
            mvwprintw(win, x + 6, y, "  /# &@@@@@./.       **&*  ");
            mvwprintw(win, x + 7, y, "    //@@@@@##.#      #.    ");
            mvwprintw(win, x + 8, y, "   ((/ ###(//#//////(      ");
            mvwprintw(win, x + 9, y, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(win, x, y, "         ####$*/#           ");
            mvwprintw(win, x + 1, y, "(&&&  ###########@$  *#  @");
            mvwprintw(win, x + 2, y, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(win, x + 3, y, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(win, x + 4, y, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(win, x + 5, y, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(win, x + 6, y, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(win, x + 7, y, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(win, x + 8, y, "     .,(/// $$#$.(####$   ");
            mvwprintw(win, x + 9, y, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(win, x, y, "           $$       $         ");
            mvwprintw(win, x + 1, y, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(win, x + 2, y, "   ((. $***.******.**(***(  ");
            mvwprintw(win, x + 3, y, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(win, x + 4, y, "    #(($(@$$($$$($((@(      ");
            mvwprintw(win, x + 5, y, " (,(((($(((((,,(((((((((,,,@");
            mvwprintw(win, x + 6, y, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(win, x + 7, y, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(win, x + 8, y, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(win, x + 9, y, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(win, x, y, "    $             ");
            mvwprintw(win, x + 1, y, "   &&& &        ");
            mvwprintw(win, x + 2, y, "     &&& $.     ");
            mvwprintw(win, x + 3, y, ".       *   &   ");
            mvwprintw(win, x + 4, y, "(*.*,. &&     * ");
            mvwprintw(win, x + 5, y, ".$$$$&#        ,");
            mvwprintw(win, x + 6, y, ".&*&&&$$        ");
            mvwprintw(win, x + 7, y, " &@@@@$&$      ,");
            mvwprintw(win, x + 8, y, " ($$@@&$$.**.   ");
            mvwprintw(win, x + 9, y, ".,.   .**      ");
            break;

        case NOPOKEMON:
            mvwprintw(win, x, y, "                              ");
            mvwprintw(win, x + 1, y, "                            ");
            mvwprintw(win, x + 2, y, "                            ");
            mvwprintw(win, x + 3, y, "                            ");
            mvwprintw(win, x + 4, y, "                            ");
            mvwprintw(win, x + 5, y, "                            ");
            mvwprintw(win, x + 6, y, "                            ");
            mvwprintw(win, x + 7, y, "                            ");
            mvwprintw(win, x + 8, y, "                            ");
            mvwprintw(win, x + 9, y, "                            ");
            break;

        default:
            break;
        }
    }

    if (FRONT0_BACK1 == 1) // BEHIND
    {
        switch (poke.art_front)
        {
        case CHARMANDER:
            mvwprintw(win, x, y, "      ../.*           ,,,,      ");
            mvwprintw(win, x + 1, y, "  ./**/*         **,,,,***(   ");
            mvwprintw(win, x + 2, y, "(//**(*         ,*********#@  ");
            mvwprintw(win, x + 3, y, ".(/(/**(        (*********(/, ");
            mvwprintw(win, x + 4, y, "./**/(**       ./********(##& ");
            mvwprintw(win, x + 5, y, "   #(@       .(,,*****(#@.    ");
            mvwprintw(win, x + 6, y, "  ***#    ,/*********,*/.    ");
            mvwprintw(win, x + 7, y, "  (**/    *(/***//((/*#(/(@   ");
            mvwprintw(win, x + 8, y, "  *.*/(#* ##(((((((,,.@ .,(   ");
            break;

        case SQUIRTLE:
            mvwprintw(win, x, y, "              .*...,//../.");
            mvwprintw(win, x + 1, y, "            ,/../////////#");
            mvwprintw(win, x + 2, y, "            &///////////##/");
            mvwprintw(win, x + 3, y, "          ,   ,,@///////*,*");
            mvwprintw(win, x + 4, y, "       ,/*(/((((((,*(////@.");
            mvwprintw(win, x + 5, y, "     *##/((#/(((((@@,(//(@#/*");
            mvwprintw(win, x + 6, y, "     ##(((((((#(((@,(//////*/");
            mvwprintw(win, x + 7, y, "     @#((((((@((((#,@&@&*");
            mvwprintw(win, x + 8, y, "  /((##(&##(((#((((/(/*");
            mvwprintw(win, x + 9, y, "(**/(@#/@#(((((((&,&@(");
            mvwprintw(win, x + 10, y, "#//////@//@*((,,@////#/");
            break;

        case BULBASAUR:
            mvwprintw(win, x, y, "         (//#(...,/,*/(......,/*,,( ");
            mvwprintw(win, x + 1, y, "     ,*/(((#/*///*///(/***/#(*****/(");
            mvwprintw(win, x + 2, y, "    ,/*//***//************(/*****/(,@,");
            mvwprintw(win, x + 3, y, "   (****/***********//******(*****/,/#");
            mvwprintw(win, x + 4, y, " /*****/****,.,,,,****//**//@@******//@");
            mvwprintw(win, x + 5, y, "*/****//**,,,,*********/(/(##/***//#/. ");
            mvwprintw(win, x + 6, y, "*/***//************////(@#@@**/#@**(*");
            mvwprintw(win, x + 7, y, "  *@(//(/////*/*////((#&#(***//#@((/@*");
            mvwprintw(win, x + 8, y, "      /###@@@@@@##(//////(##(////(&#(,");
            break;

        case PIKACHU:
            mvwprintw(win, x, y, "               ..      ");
            mvwprintw(win, x + 1, y, "    .         ..(    ");
            mvwprintw(win, x + 2, y, " .    .@@&,    @@&   ");
            mvwprintw(win, x + 3, y, "/@@@@.    /@@@@@@@*  ");
            mvwprintw(win, x + 4, y, ".@@@@@@@ *@@@@@@@@@/ ");
            mvwprintw(win, x + 5, y, "     ,@@@,**(@@@@@@  ");
            mvwprintw(win, x + 6, y, "     @@@***(@@@@@@@@/");
            mvwprintw(win, x + 7, y, "      **@@@@@@@@@    ");
            mvwprintw(win, x + 8, y, "      (@@@@@@@@@@/   ");
            break;

        case CHARIZARD:
            mvwprintw(win, x, y, "        ,((/           @(,      ");
            mvwprintw(win, x + 1, y, "   /(((///$        ,(#        ");
            mvwprintw(win, x + 2, y, "  (#////,         /(/* ((*    ");
            mvwprintw(win, x + 3, y, " .(/////*        ,((**///((,  ");
            mvwprintw(win, x + 4, y, " ((///////    ,,#(//*,/////// ");
            mvwprintw(win, x + 5, y, "$( ,/&./////##//((** @//// /(/");
            mvwprintw(win, x + 6, y, "/((   *(//((((//(,(*  @// ,   ");
            mvwprintw(win, x + 7, y, "/(   //////////(//,           ");
            mvwprintw(win, x + 8, y, "    #//////////(,//,((/,*   ");
            break;

        case BLASTOISE:
            mvwprintw(win, x, y, "            /@**(***//     ");
            mvwprintw(win, x + 1, y, "            @*/,@(,,,,     ");
            mvwprintw(win, x + 2, y, "   ,.@   ***,,*/&*(.,.       ");
            mvwprintw(win, x + 3, y, "    //*****///**/$@/,  ..&   ");
            mvwprintw(win, x + 4, y, "   #//*////(((((/#/(../**&   ");
            mvwprintw(win, x + 5, y, "  ((//((((((##(####  ///**** ");
            mvwprintw(win, x + 6, y, "  ((((((#((#((((((...@//////@");
            mvwprintw(win, x + 7, y, "  (#####((##((((#.,.,,       ");
            mvwprintw(win, x + 8, y, "**(#####(##(((  . /***       ");
            break;

        case VENUSAUR:
            mvwprintw(win, x, y, "      /,//((&*((**(////       ");
            mvwprintw(win, x + 1, y, " $(,*/$*.,**&/.,,**&(./(    ");
            mvwprintw(win, x + 2, y, " $##///.,@$($($&&((/($#(##  ");
            mvwprintw(win, x + 3, y, "(**$&@@($(@&@@(#$(&@$*(/((  ");
            mvwprintw(win, x + 4, y, "@ $@,,(#,((((&##@$(/$&$,*,#(");
            mvwprintw(win, x + 5, y, "##$#/,,,(,##########$#$#(//$");
            mvwprintw(win, x + 6, y, "$##################/(/#####(");
            mvwprintw(win, x + 7, y, "####$$########$###$###,###, ");
            mvwprintw(win, x + 8, y, "  (((( /(    .$####(/       ");
            break;

        case RAICHU:
            mvwprintw(win, x, y, "         $#$$$$*   ");
            mvwprintw(win, x + 1, y, "     $    ($(     ");
            mvwprintw(win, x + 2, y, "   /   ,,       / ");
            mvwprintw(win, x + 3, y, " *   ..,,,&&$$//* ");
            mvwprintw(win, x + 4, y, "*        $$$##(/  ");
            mvwprintw(win, x + 5, y, "        (//*/(/*  ");
            mvwprintw(win, x + 6, y, ",      (/(//*(/*/*");
            mvwprintw(win, x + 7, y, " ,    $#*(((#((/  ");
            mvwprintw(win, x + 8, y, "       $/    (,.  ");
            break;

        case NOPOKEMON:
            mvwprintw(win, x, y, "                                          ");
            mvwprintw(win, x + 1, y, "                                        ");
            mvwprintw(win, x + 2, y, "                                        ");
            mvwprintw(win, x + 3, y, "                                        ");
            mvwprintw(win, x + 4, y, "                                        ");
            mvwprintw(win, x + 5, y, "                                        ");
            mvwprintw(win, x + 6, y, "                                        ");
            mvwprintw(win, x + 7, y, "                                        ");
            mvwprintw(win, x + 8, y, "                                        ");
            mvwprintw(win, x + 9, y, "                                        ");
            mvwprintw(win, x + 10, y, "                                        ");
            break;

        default:
            break;
        }
    }
}

void print_house(WINDOW *house_map, int x, int y)
{

    mvwprintw(house_map, 3, 20, " _______");
    mvwprintw(house_map, 3 + 1, 20, "|_______|");
    mvwprintw(house_map, 3 + 2, 20, "|       |");
    mvwprintw(house_map, 3 + 3, 20, "|]      |");
    mvwprintw(house_map, 3 + 4, 20, "|_______|");
    mvwprintw(house_map, 3 + 5, 20, "|]      |");
    mvwprintw(house_map, 3 + 6, 20, "|       |");
    mvwprintw(house_map, 3 + 7, 20, "|_______|");

    mvwprintw(house_map, 6, 3, " __=||=________ ");
    mvwprintw(house_map, 6 + 1, 3, "|,--''-- |     |");
    mvwprintw(house_map, 6 + 2, 3, "||______||     |");
    mvwprintw(house_map, 6 + 3, 3, "|________|_____|");
    mvwprintw(house_map, 6 + 4, 3, " |____________|");

    mvwprintw(house_map, 5, 45, " ________ ");
    mvwprintw(house_map, 5 + 1, 45, "|(_)++(_)|");
    mvwprintw(house_map, 5 + 2, 45, "|________|");
    mvwprintw(house_map, 5 + 3, 45, "|.------.|");
    mvwprintw(house_map, 5 + 4, 45, "||     o||");
    mvwprintw(house_map, 5 + 5, 45, "|`------'|");

    mvwprintw(house_map, 7, 29, " _ ");
    mvwprintw(house_map, 7 + 1, 29, "| |");
    mvwprintw(house_map, 7 + 2, 29, "|-|");
    mvwprintw(house_map, 7 + 3, 29, "|_|");

    mvwprintw(house_map, 4, 70, "     __________");
    mvwprintw(house_map, 4 + 1, 70, "   _/__________\\_");
    mvwprintw(house_map, 4 + 2, 70, "  | ,----------. |");
    mvwprintw(house_map, 4 + 3, 70, "  | |  ...     | |");
    mvwprintw(house_map, 4 + 4, 70, " _| | :-o-:    | |_____");
    mvwprintw(house_map, 4 + 5, 70, "| | |  '''     | |   __|");
    mvwprintw(house_map, 4 + 6, 70, "| | `----------' |  /~/|");
    mvwprintw(house_map, 4 + 7, 70, "|  ~~~~~~~~~~~~~~  /_/ |");
    mvwprintw(house_map, 4 + 8, 70, "|______________________|");
    mvwprintw(house_map, 4 + 9, 70, " |____________________|");

    mvwprintw(house_map, 17, 70, "   ___________________   ");
    mvwprintw(house_map, 17 + 1, 70, " _|                   |_ ");
    mvwprintw(house_map, 17 + 2, 70, "||                     ||");
    mvwprintw(house_map, 17 + 3, 70, "||                     ||");
    mvwprintw(house_map, 17 + 4, 70, "||_____________________||");
    mvwprintw(house_map, 17 + 5, 70, "    o               o    ");

    mvwprintw(house_map, 3, 125, "                  .'");
    mvwprintw(house_map, 3 + 1, 125, "               .'   ____ ");
    mvwprintw(house_map, 3 + 2, 125, "            .'   _,|     ");
    mvwprintw(house_map, 3 + 3, 125, "         .'   _,| ||     ");
    mvwprintw(house_map, 3 + 4, 125, "      .'   _,| || ||____ ");
    mvwprintw(house_map, 3 + 5, 125, "   .'   _,| || ||_|'    ");
    mvwprintw(house_map, 3 + 6, 125, "     _,| || ||_|'       ");
    mvwprintw(house_map, 3 + 7, 125, "  _,| || ||_|'          ");
    mvwprintw(house_map, 3 + 8, 125, " | || ||_|'             ");
    mvwprintw(house_map, 3 + 9, 125, " | ||_|'                ");
    mvwprintw(house_map, 3 + 10, 125, " |_|'___________________");

    mvwprintw(house_map, 29, 10, "   ____________  ");
    mvwprintw(house_map, 29 + 1, 10, " /'            '\\");
    mvwprintw(house_map, 29 + 2, 10, "|                | ");
    mvwprintw(house_map, 29 + 3, 10, "|                | ");
    mvwprintw(house_map, 29 + 4, 10, " \\,____________,/ ");

    mvwprintw(house_map, 34, 13, " ___ ");
    mvwprintw(house_map, 34 + 1, 13, "|___|");

    mvwprintw(house_map, 34, 20, " ___ ");
    mvwprintw(house_map, 34 + 1, 20, "|___|");

    mvwprintw(house_map, 27, 13, " ___ ");
    mvwprintw(house_map, 27 + 1, 13, "|___|");

    mvwprintw(house_map, 27, 20, " ___ ");
    mvwprintw(house_map, 27 + 1, 20, "|___|");

    mvwprintw(house_map, 35, 120, " _____________ ");
    mvwprintw(house_map, 35 + 1, 120, "|             |");
    mvwprintw(house_map, 35 + 2, 120, "|   WELCOME   |");
    mvwprintw(house_map, 35 + 3, 120, "|             |");
    mvwprintw(house_map, 35 + 4, 120, "               ");

    wattron(house_map, COLOR_PAIR(2));
    mvwprintw(house_map, 18 - 1, 3, "MOM");
    mvwprintw(house_map, 18, 3, ".,_  ");
    mvwprintw(house_map, 18 + 1, 3, "/'_' ");
    mvwprintw(house_map, 18 + 2, 3, " \\|\\");
    mvwprintw(house_map, 18 + 3, 3, "  | ");
    mvwprintw(house_map, 18 + 4, 3, "  -' ");
    wattroff(house_map, COLOR_PAIR(2));

    wattron(house_map, COLOR_PAIR(1));
    mvwprintw(house_map, x, y + 2, "_");
    mvwprintw(house_map, x + 1, y + 1, "'_'");
    mvwprintw(house_map, x + 2, y, "/| |\\");
    mvwprintw(house_map, x + 3, y + 1, "|-|");
    mvwprintw(house_map, x + 4, y + 1, "- -");
    wattroff(house_map, COLOR_PAIR(1));
}

void print_lab(WINDOW *lab_map, int x, int y)
{

    mvwprintw(lab_map, 4, 3, " _________");
    mvwprintw(lab_map, 4 + 1, 3, "|_________|");
    mvwprintw(lab_map, 4 + 2, 3, "| |_^-^_| |");
    mvwprintw(lab_map, 4 + 3, 3, "|  _____  |");
    mvwprintw(lab_map, 4 + 4, 3, "| | + = | |");
    mvwprintw(lab_map, 4 + 5, 3, "| |_+_=_| |");
    mvwprintw(lab_map, 4 + 6, 3, "|_________|");

    mvwprintw(lab_map, 4 + 1, 16, " _________");
    mvwprintw(lab_map, 4 + 2, 16, "|_________|");
    mvwprintw(lab_map, 4 + 3, 16, "| |_^o^_| |");
    mvwprintw(lab_map, 4 + 4, 16, "|  _____  |");
    mvwprintw(lab_map, 4 + 5, 16, "| |_*_*_| |");
    mvwprintw(lab_map, 4 + 6, 16, "|_________|");

    wattron(lab_map, COLOR_PAIR(BLUE));
    mvwprintw(lab_map, 3 - 1, 35, "   [PC]");
    wattroff(lab_map, COLOR_PAIR(BLUE));
    mvwprintw(lab_map, 3, 35, "   _____");
    mvwprintw(lab_map, 3 + 1, 35, "  |_____|   ___");
    mvwprintw(lab_map, 3 + 2, 35, "  |     |  |___|");
    mvwprintw(lab_map, 3 + 3, 35, " _|_____|__|===|__");
    mvwprintw(lab_map, 3 + 4, 35, "| __|_|__  |===|  |");
    mvwprintw(lab_map, 3 + 5, 35, "|  |ooo| O |_-_|  |");
    mvwprintw(lab_map, 3 + 6, 35, "|_________________|");
    mvwprintw(lab_map, 3 + 7, 35, "|_|          |_+_|");

    mvwprintw(lab_map, 0 + 1, 70, " ___|__|___");
    mvwprintw(lab_map, 0 + 2, 70, "| WELCOME  | ");
    mvwprintw(lab_map, 0 + 3, 70, "| TO  THE  |");
    mvwprintw(lab_map, 0 + 4, 70, "|LABORATORY|");
    mvwprintw(lab_map, 0 + 5, 70, "|__________|");

    mvwprintw(lab_map, 3 + 1, 120, " ________________________");
    mvwprintw(lab_map, 3 + 2, 120, "|________________________|");
    mvwprintw(lab_map, 3 + 3, 120, "| __     __   ____   ___ |");
    mvwprintw(lab_map, 3 + 4, 120, "||==|__ |--|_|=||=|_|=*=||");
    mvwprintw(lab_map, 3 + 5, 120, "||__|__||__|_|_||_|_|___||");
    mvwprintw(lab_map, 3 + 6, 120, "|________________________|");
    mvwprintw(lab_map, 3 + 7, 120, "|________________________|");
    mvwprintw(lab_map, 3 + 7, 120, "|_|  |_|          |_|  |_|");

    mvwprintw(lab_map, 31 + 1, 3, " ________________________");
    mvwprintw(lab_map, 31 + 2, 3, "|________________________|");
    mvwprintw(lab_map, 31 + 3, 3, "|                        |");
    mvwprintw(lab_map, 31 + 4, 3, "|                        |");
    mvwprintw(lab_map, 31 + 5, 3, "|                        |");
    mvwprintw(lab_map, 31 + 6, 3, "|________________________|");
    mvwprintw(lab_map, 31 + 7, 3, "|________________________|");
    mvwprintw(lab_map, 31 + 7, 3, "|_|  |_|          |_|  |_|");

    mvwprintw(lab_map, 31 + 1, 35, " _________________");
    mvwprintw(lab_map, 31 + 2, 35, "|_________________|");
    mvwprintw(lab_map, 31 + 3, 35, "|                 |");
    mvwprintw(lab_map, 31 + 4, 35, "|                 |");
    mvwprintw(lab_map, 31 + 5, 35, "|                 |");
    mvwprintw(lab_map, 31 + 6, 35, "|_________________|");
    mvwprintw(lab_map, 31 + 7, 35, "|_________________|");
    mvwprintw(lab_map, 31 + 7, 35, "|_|             |_|");

    mvwprintw(lab_map, 31 + 1, 95, " _________________");
    mvwprintw(lab_map, 31 + 2, 95, "|_________________|");
    mvwprintw(lab_map, 31 + 3, 95, "|                 |");
    mvwprintw(lab_map, 31 + 4, 95, "|                 |");
    mvwprintw(lab_map, 31 + 5, 95, "|                 |");
    mvwprintw(lab_map, 31 + 6, 95, "|_________________|");
    mvwprintw(lab_map, 31 + 7, 95, "|_________________|");
    mvwprintw(lab_map, 31 + 7, 95, "|_|             |_|");

    mvwprintw(lab_map, 31 + 1, 120, " ________________________");
    mvwprintw(lab_map, 31 + 2, 120, "|________________________|");
    mvwprintw(lab_map, 31 + 3, 120, "|                        |");
    mvwprintw(lab_map, 31 + 4, 120, "|                        |");
    mvwprintw(lab_map, 31 + 5, 120, "|                        |");
    mvwprintw(lab_map, 31 + 6, 120, "|________________________|");
    mvwprintw(lab_map, 31 + 7, 120, "|________________________|");
    mvwprintw(lab_map, 31 + 7, 120, "|_|  |_|          |_|  |_|");

    mvwprintw(lab_map, 15 + 1, 12, "                    ");
    mvwprintw(lab_map, 15 + 2, 12, "    _____");
    mvwprintw(lab_map, 15 + 3, 12, "   /  _  \\");
    mvwprintw(lab_map, 15 + 4, 12, "   | (_) |");
    mvwprintw(lab_map, 15 + 5, 12, "   \\_____/");
    mvwprintw(lab_map, 15 + 6, 12, " __|_____|__");
    mvwprintw(lab_map, 15 + 7, 12, "|___________|");
    mvwprintw(lab_map, 15 + 7, 12, " |_||_++_|_|");

    mvwprintw(lab_map, 19, 106, "   _________________  ");
    mvwprintw(lab_map, 19 + 1, 106, " /' ...   ...   ... '\\");
    mvwprintw(lab_map, 19 + 2, 106, "|  :-o-: :-o-: :-o-:  | ");
    mvwprintw(lab_map, 19 + 3, 106, "|   '''   '''   '''   | ");
    mvwprintw(lab_map, 19 + 4, 106, " \\,_________________,/ ");
    mvwprintw(lab_map, 19 + 5, 106, "   '                '    ");

    mvwprintw(lab_map, 35, 68, " _____________ ");
    mvwprintw(lab_map, 35 + 1, 68, "|             |");
    mvwprintw(lab_map, 35 + 2, 68, "|   WELCOME   |");
    mvwprintw(lab_map, 35 + 3, 68, "|             |");
    mvwprintw(lab_map, 35 + 4, 68, "               ");

    wattron(lab_map, COLOR_PAIR(BLUE));
    mvwprintw(lab_map, 6 - 1, 100 - 2, "Professor");
    mvwprintw(lab_map, 6, 100 + 2, "-");
    mvwprintw(lab_map, 6 + 1, 100 + 1, "'~'");
    mvwprintw(lab_map, 6 + 2, 100, "/|+|\\");
    mvwprintw(lab_map, 6 + 3, 100 + 1, "|-|");
    mvwprintw(lab_map, 6 + 4, 100 + 1, "- -");
    wattroff(lab_map, COLOR_PAIR(BLUE));

    wattron(lab_map, COLOR_PAIR(RED));
    mvwprintw(lab_map, x, y + 2, "_");
    mvwprintw(lab_map, x + 1, y + 1, "'_'");
    mvwprintw(lab_map, x + 2, y, "/| |\\");
    mvwprintw(lab_map, x + 3, y + 1, "|-|");
    mvwprintw(lab_map, x + 4, y + 1, "- -");
    wattroff(lab_map, COLOR_PAIR(RED));
}

void print_league(WINDOW *league_map, int x, int y, trainer champion)
{

    mvwprintw(league_map, 39, 70 - 2, " ");
    mvwprintw(league_map, 39, 70 - 1, " ");
    mvwprintw(league_map, 39, 70, " ");
    mvwprintw(league_map, 39, 70 + 1, " ");
    mvwprintw(league_map, 39, 70 + 2, " ");
    mvwprintw(league_map, 39, 70 + 3, " ");
    mvwprintw(league_map, 39, 70 + 4, " ");
    mvwprintw(league_map, 39, 70 + 5, " ");
    mvwprintw(league_map, 39, 70 + 6, " ");
    mvwprintw(league_map, 39, 70 + 7, " ");
    mvwprintw(league_map, 39, 70 + 8, " ");
    mvwprintw(league_map, 39, 70 + 9, " ");

    mvwprintw(league_map, 3, 1, "       _________       ");
    mvwprintw(league_map, 3 + 1, 1, "------|   .-.   |------");
    mvwprintw(league_map, 3 + 2, 1, "______|  (-o-)  |______");
    mvwprintw(league_map, 3 + 3, 1, "      |___'-'___|      ");

    mvwprintw(league_map, 3, 24, "       _________    ");
    mvwprintw(league_map, 3 + 1, 24, "------|   .-.   |---");
    mvwprintw(league_map, 3 + 2, 24, "______|  (-o-)  |___");
    mvwprintw(league_map, 3 + 3, 24, "      |___'-'___|   ");

    mvwprintw(league_map, 3, 44, "       _________       ");
    mvwprintw(league_map, 3 + 1, 44, "------|   .-.   |------");
    mvwprintw(league_map, 3 + 2, 44, "______|  (-o-)  |______");
    mvwprintw(league_map, 3 + 3, 44, "      |___'-'___|      ");

    mvwprintw(league_map, 1, 67, "     ______         ");
    mvwprintw(league_map, 1 + 1, 67, "  ,-' |__| `-.      ");
    mvwprintw(league_map, 1 + 2, 67, " / __________ \\    ");
    mvwprintw(league_map, 1 + 3, 67, "| |    ||    | |");
    mvwprintw(league_map, 1 + 4, 67, ") |   =||=   | (");
    mvwprintw(league_map, 1 + 5, 67, "| | =  ||  = | |");
    mvwprintw(league_map, 1 + 6, 67, "| | =  ||  = | |");
    mvwprintw(league_map, 1 + 7, 67, "| |   =||=   | |");
    mvwprintw(league_map, 1 + 8, 67, ") |    ||    | (");
    mvwprintw(league_map, 1 + 9, 67, "|_|_;-------;|_|");

    mvwprintw(league_map, 3, 83, "       _________     ");
    mvwprintw(league_map, 3 + 1, 83, "------|   .-.   |----");
    mvwprintw(league_map, 3 + 2, 83, "______|  (-o-)  |____");
    mvwprintw(league_map, 3 + 3, 83, "      |___'-'___|    ");

    mvwprintw(league_map, 3, 104, "       _________       ");
    mvwprintw(league_map, 3 + 1, 104, "------|   .-.   |------");
    mvwprintw(league_map, 3 + 2, 104, "______|  (-o-)  |______");
    mvwprintw(league_map, 3 + 3, 104, "      |___'-'___|      ");

    mvwprintw(league_map, 3, 127, "       _________     ");
    mvwprintw(league_map, 3 + 1, 127, "------|   .-.   |-----");
    mvwprintw(league_map, 3 + 2, 127, "______|  (-o-)  |_____");
    mvwprintw(league_map, 3 + 3, 127, "      |___'-'___|     ");

    //

    mvwprintw(league_map, 20, 66, "     .-'"
                                  "'-.");
    mvwprintw(league_map, 20 + 1, 66, "  .'        '.");
    mvwprintw(league_map, 20 + 2, 66, " /    .--.    \\");
    mvwprintw(league_map, 20 + 3, 66, ";____/    \\____;");
    mvwprintw(league_map, 20 + 4, 66, ";----\\    /----;");
    mvwprintw(league_map, 20 + 5, 66, " \\    '--'    /");
    mvwprintw(league_map, 20 + 6, 66, "  '.        .'");
    mvwprintw(league_map, 20 + 7, 66, "    '-....-'");

    mvwprintw(league_map, 23, 50, "________________;");
    mvwprintw(league_map, 24, 50, "----------------;");
    mvwprintw(league_map, 23, 81, ";________________");
    mvwprintw(league_map, 24, 81, ";----------------");

    mvwprintw(league_map, 11, 22, " __________ ");
    mvwprintw(league_map, 11 + 1, 22, "|__________|");
    mvwprintw(league_map, 11 + 2, 22, "  ||||||||  ");
    mvwprintw(league_map, 11 + 3, 22, "  ||||||||  ");
    mvwprintw(league_map, 11 + 4, 22, "  ||||||||  ");
    mvwprintw(league_map, 11 + 5, 22, "  ||||||||  ");
    mvwprintw(league_map, 11 + 6, 22, " -||||||||-  ");
    mvwprintw(league_map, 11 + 7, 22, "|__________|");

    mvwprintw(league_map, 23, 50, "________________;");
    mvwprintw(league_map, 23 + 1, 50, "----------------;");
    mvwprintw(league_map, 23, 50, "________________;");
    mvwprintw(league_map, 23 + 1, 50, "----------------;");
    mvwprintw(league_map, 23, 50, "________________;");
    mvwprintw(league_map, 23 + 1, 50, "----------------;");

    mvwprintw(league_map, 28, 22, " __________ ");
    mvwprintw(league_map, 28 + 1, 22, "|__________|");
    mvwprintw(league_map, 28 + 2, 22, "  ||||||||  ");
    mvwprintw(league_map, 28 + 3, 22, "  ||||||||  ");
    mvwprintw(league_map, 28 + 4, 22, "  ||||||||  ");
    mvwprintw(league_map, 28 + 5, 22, "  ||||||||  ");
    mvwprintw(league_map, 28 + 6, 22, " -||||||||-  ");
    mvwprintw(league_map, 28 + 7, 22, "|__________|");

    mvwprintw(league_map, 20, 22, "     )    ");
    mvwprintw(league_map, 20 + 1, 22, "    ) \\  ");
    mvwprintw(league_map, 20 + 2, 22, "   / ) (  ");
    mvwprintw(league_map, 20 + 3, 22, " --\\(_)/--");
    mvwprintw(league_map, 20 + 4, 22, "|_________|");

    mvwprintw(league_map, 11, 110, " __________ ");
    mvwprintw(league_map, 11 + 1, 110, "|__________|");
    mvwprintw(league_map, 11 + 2, 110, "  ||||||||  ");
    mvwprintw(league_map, 11 + 3, 110, "  ||||||||  ");
    mvwprintw(league_map, 11 + 4, 110, "  ||||||||  ");
    mvwprintw(league_map, 11 + 5, 110, "  ||||||||  ");
    mvwprintw(league_map, 11 + 6, 110, " -||||||||-  ");
    mvwprintw(league_map, 11 + 7, 110, "|__________|");

    mvwprintw(league_map, 20, 110, "     )    ");
    mvwprintw(league_map, 20 + 1, 110, "    ) \\  ");
    mvwprintw(league_map, 20 + 2, 110, "   / ) (  ");
    mvwprintw(league_map, 20 + 3, 110, " --\\(_)/--");
    mvwprintw(league_map, 20 + 4, 110, "|_________|");

    mvwprintw(league_map, 28, 110, " __________ ");
    mvwprintw(league_map, 28 + 1, 110, "|__________|");
    mvwprintw(league_map, 28 + 2, 110, "  ||||||||  ");
    mvwprintw(league_map, 28 + 3, 110, "  ||||||||  ");
    mvwprintw(league_map, 28 + 4, 110, "  ||||||||  ");
    mvwprintw(league_map, 28 + 5, 110, "  ||||||||  ");
    mvwprintw(league_map, 28 + 6, 110, " -||||||||-  ");
    mvwprintw(league_map, 28 + 7, 110, "|__________|");

    if (champion.art == CHAMPIONBLUE)
    {
        wattron(league_map, COLOR_PAIR(BLUE));
        mvwprintw(league_map, 13, 65 - 14, "Blue, Champion");
        mvwprintw(league_map, 13 + 1, 65 - 13, "of the league");
        mvwprintw(league_map, 13, 65 + 2, "-");
        mvwprintw(league_map, 13 + 1, 65 + 1, "'~'");
        mvwprintw(league_map, 13 + 2, 65, "/| |\\");
        mvwprintw(league_map, 13 + 3, 65 + 1, "|-|");
        mvwprintw(league_map, 13 + 4, 65 + 1, "- -");
        wattroff(league_map, COLOR_PAIR(BLUE));
    }

    else if (champion.art == CHAMPIONYELLOW)
    {
        wattron(league_map, COLOR_PAIR(YELLOW));
        mvwprintw(league_map, 13, 65 - 15, "Yellow, Champion");
        mvwprintw(league_map, 13 + 1, 65 - 14, "of the league");
        mvwprintw(league_map, 13, 65 + 2, "-");
        mvwprintw(league_map, 13 + 1, 65 + 1, "'~'");
        mvwprintw(league_map, 13 + 2, 65, "/| |\\");
        mvwprintw(league_map, 13 + 3, 65 + 1, "|-|");
        mvwprintw(league_map, 13 + 4, 65 + 1, "- -");
        wattroff(league_map, COLOR_PAIR(YELLOW));
    }

    else if (champion.art == CHAMPIONRED)
    {
        wattron(league_map, COLOR_PAIR(RED));
        mvwprintw(league_map, 13, 65 - 14, "Red, Champion");
        mvwprintw(league_map, 13 + 1, 65 - 13, "of the league");
        mvwprintw(league_map, 13, 65 + 2, "-");
        mvwprintw(league_map, 13 + 1, 65 + 1, "'~'");
        mvwprintw(league_map, 13 + 2, 65, "/| |\\");
        mvwprintw(league_map, 13 + 3, 65 + 1, "|-|");
        mvwprintw(league_map, 13 + 4, 65 + 1, "- -");
        wattroff(league_map, COLOR_PAIR(RED));
    }

    wattron(league_map, COLOR_PAIR(1));
    mvwprintw(league_map, x, y + 2, "_");
    mvwprintw(league_map, x + 1, y + 1, "'_'");
    mvwprintw(league_map, x + 2, y, "/| |\\");
    mvwprintw(league_map, x + 3, y + 1, "|-|");
    mvwprintw(league_map, x + 4, y + 1, "- -");
    wattroff(league_map, COLOR_PAIR(1));
}
void print_forest(WINDOW *forest_map, int x, int y)
{

    mvwprintw(forest_map, 1, 1, "     __-__");
    mvwprintw(forest_map, 1 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 1, "     |  |");
    mvwprintw(forest_map, 1 + 7, 1, "    //__\\\\");

    mvwprintw(forest_map, 1, 16, "     __-__");
    mvwprintw(forest_map, 1 + 1, 16, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 16, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 16, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 16, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 16, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 16, "     |  |");
    mvwprintw(forest_map, 1 + 7, 16, "    //__\\\\");

    mvwprintw(forest_map, 1, 31, "     __-__");
    mvwprintw(forest_map, 1 + 1, 31, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 31, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 31, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 31, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 31, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 31, "     |  |");
    mvwprintw(forest_map, 1 + 7, 31, "    //__\\\\");

    mvwprintw(forest_map, 1, 46, "     __-__");
    mvwprintw(forest_map, 1 + 1, 46, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 46, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 46, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 46, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 46, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 46, "     |  |");
    mvwprintw(forest_map, 1 + 7, 46, "    //__\\\\");

    mvwprintw(forest_map, 1, 61, "     __-__");
    mvwprintw(forest_map, 1 + 1, 61, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 61, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 61, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 61, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 61, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 61, "     |  |");
    mvwprintw(forest_map, 1 + 7, 61, "    //__\\\\");

    mvwprintw(forest_map, 1, 76, "     __-__");
    mvwprintw(forest_map, 1 + 1, 76, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 76, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 76, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 76, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 76, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 76, "     |  |");
    mvwprintw(forest_map, 1 + 7, 76, "    //__\\\\");

    mvwprintw(forest_map, 1, 91, "     __-__");
    mvwprintw(forest_map, 1 + 1, 91, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 91, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 91, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 91, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 91, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 91, "     |  |");
    mvwprintw(forest_map, 1 + 7, 91, "    //__\\\\");

    mvwprintw(forest_map, 1, 106, "     __-__");
    mvwprintw(forest_map, 1 + 1, 106, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 106, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 106, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 106, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 106, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 106, "     |  |");
    mvwprintw(forest_map, 1 + 7, 106, "    //__\\\\");

    mvwprintw(forest_map, 1, 121, "     __-__");
    mvwprintw(forest_map, 1 + 1, 121, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 121, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 121, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 121, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 121, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 121, "     |  |");
    mvwprintw(forest_map, 1 + 7, 121, "    //__\\\\");

    mvwprintw(forest_map, 1, 136, "     __-__");
    mvwprintw(forest_map, 1 + 1, 136, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 136, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 136, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 136, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 136, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 136, "     |  |");
    mvwprintw(forest_map, 1 + 7, 136, "    //__\\\\");

    mvwprintw(forest_map, 1, 151, "     __-__");
    mvwprintw(forest_map, 1 + 1, 151, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 151, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 151, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 151, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 151, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 151, "     |  |");
    mvwprintw(forest_map, 1 + 7, 151, "    //__\\\\");

    mvwprintw(forest_map, 1, 166, "     __-__");
    mvwprintw(forest_map, 1 + 1, 166, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 166, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 166, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 166, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 166, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 166, "     |  |");
    mvwprintw(forest_map, 1 + 7, 166, "    //__\\\\");

    mvwprintw(forest_map, 1, 181, "     __-__");
    mvwprintw(forest_map, 1 + 1, 181, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 181, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 181, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 181, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 181, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 181, "     |  |");
    mvwprintw(forest_map, 1 + 7, 181, "    //__\\\\");

    mvwprintw(forest_map, 1, 196, "     __-__");
    mvwprintw(forest_map, 1 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 1 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 1 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 1 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 1 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 1 + 6, 196, "     |  |");
    mvwprintw(forest_map, 1 + 7, 196, "    //__\\\\");

    // ARBRE DE GAUCHE

    mvwprintw(forest_map, 24, 1, "     __-__");
    mvwprintw(forest_map, 24 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 24 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 24 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 24 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 24 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 24 + 6, 1, "     |  |");
    mvwprintw(forest_map, 24 + 7, 1, "    //__\\\\");

    mvwprintw(forest_map, 30, 1, "     __-__");
    mvwprintw(forest_map, 30 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 30 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 30 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 30 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 30 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 30 + 6, 1, "     |  |");
    mvwprintw(forest_map, 30 + 7, 1, "    //__\\\\");

    mvwprintw(forest_map, 36, 1, "     __-__");
    mvwprintw(forest_map, 36 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 36 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 36 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 36 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 36 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 36 + 6, 1, "     |  |");
    mvwprintw(forest_map, 36 + 7, 1, "    //__\\\\");

    mvwprintw(forest_map, 42, 1, "     __-__");
    mvwprintw(forest_map, 42 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 42 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 42 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 42 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 42 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 42 + 6, 1, "     |  |");
    mvwprintw(forest_map, 42 + 7, 1, "    //__\\\\");

    mvwprintw(forest_map, 48, 1, "     __-__");
    mvwprintw(forest_map, 48 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 48 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 48 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 48 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 48 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 48 + 6, 1, "     |  |");
    mvwprintw(forest_map, 48 + 7, 1, "    //__\\\\");

    mvwprintw(forest_map, 54, 1, "     __-__");
    mvwprintw(forest_map, 54 + 1, 1, "   /~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 1, " /~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 1, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 1, " \\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 1, "    \\\\  //");
    mvwprintw(forest_map, 54 + 6, 1, "     |  |");
    mvwprintw(forest_map, 54 + 7, 1, "    //__\\\\");

    // ARBRE DE DROITE

    mvwprintw(forest_map, 6, 196, "     __-__");
    mvwprintw(forest_map, 6 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 6 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 6 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 6 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 6 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 6 + 6, 196, "     |  |");
    mvwprintw(forest_map, 6 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 12, 196, "     __-__");
    mvwprintw(forest_map, 12 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 12 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 12 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 12 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 12 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 12 + 6, 196, "     |  |");
    mvwprintw(forest_map, 12 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 18, 196, "     __-__");
    mvwprintw(forest_map, 18 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 18 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 18 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 18 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 18 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 18 + 6, 196, "     |  |");
    mvwprintw(forest_map, 18 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 24, 196, "     __-__");
    mvwprintw(forest_map, 24 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 24 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 24 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 24 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 24 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 24 + 6, 196, "     |  |");
    mvwprintw(forest_map, 24 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 30, 196, "     __-__");
    mvwprintw(forest_map, 30 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 30 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 30 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 30 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 30 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 30 + 6, 196, "     |  |");
    mvwprintw(forest_map, 30 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 36, 196, "     __-__");
    mvwprintw(forest_map, 36 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 36 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 36 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 36 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 36 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 36 + 6, 196, "     |  |");
    mvwprintw(forest_map, 36 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 42, 196, "     __-__");
    mvwprintw(forest_map, 42 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 42 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 42 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 42 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 42 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 42 + 6, 196, "     |  |");
    mvwprintw(forest_map, 42 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 48, 196, "     __-__");
    mvwprintw(forest_map, 48 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 48 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 48 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 48 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 48 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 48 + 6, 196, "     |  |");
    mvwprintw(forest_map, 48 + 7, 196, "    //__\\\\");

    mvwprintw(forest_map, 54, 196, "     __-__");
    mvwprintw(forest_map, 54 + 1, 196, "   /~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 196, " /~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 196, " \\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 196, "    \\\\  //");
    mvwprintw(forest_map, 54 + 6, 196, "     |  |");
    mvwprintw(forest_map, 54 + 7, 196, "    //__\\\\");

    // Intérieur foret
    // TRONC HAUT GAUCHE

    mvwprintw(forest_map, 6, 46, "     __-__");
    mvwprintw(forest_map, 6 + 1, 46, "   /~~ o~~\\");
    mvwprintw(forest_map, 6 + 2, 46, " /~~o     ~~\\");
    mvwprintw(forest_map, 6 + 3, 46, "{ ~~      o~~}");
    mvwprintw(forest_map, 6 + 4, 46, " \\ _-     -_/");
    mvwprintw(forest_map, 6 + 5, 46, "    \\\\  //");
    mvwprintw(forest_map, 6 + 6, 46, "     |  |");
    mvwprintw(forest_map, 6 + 7, 46, "    //__\\\\");

    mvwprintw(forest_map, 12, 46, "     __-__");
    mvwprintw(forest_map, 12 + 1, 46, "   /~~ o~~\\");
    mvwprintw(forest_map, 12 + 2, 46, " /~~o     ~~\\");
    mvwprintw(forest_map, 12 + 3, 46, "{ ~~      o~~}");
    mvwprintw(forest_map, 12 + 4, 46, " \\ _-     -_/");
    mvwprintw(forest_map, 12 + 5, 46, "    \\\\  //");
    mvwprintw(forest_map, 12 + 6, 46, "     |  |");
    mvwprintw(forest_map, 12 + 7, 46, "    //__\\\\");

    mvwprintw(forest_map, 18, 46, "     __-__");
    mvwprintw(forest_map, 18 + 1, 46, "   /~~ o~~\\");
    mvwprintw(forest_map, 18 + 2, 46, " /~~o     ~~\\");
    mvwprintw(forest_map, 18 + 3, 46, "{ ~~      o~~}");
    mvwprintw(forest_map, 18 + 4, 46, " \\ _-     -_/");
    mvwprintw(forest_map, 18 + 5, 46, "    \\\\  //");
    mvwprintw(forest_map, 18 + 6, 46, "     |  |");
    mvwprintw(forest_map, 18 + 7, 46, "    //__\\\\");

    mvwprintw(forest_map, 24, 46, "     __-__");
    mvwprintw(forest_map, 24 + 1, 46, "   /~~ o~~\\");
    mvwprintw(forest_map, 24 + 2, 46, " /~~o     ~~\\");
    mvwprintw(forest_map, 24 + 3, 46, "{ ~~      o~~}");
    mvwprintw(forest_map, 24 + 4, 46, " \\ _-     -_/");
    mvwprintw(forest_map, 24 + 5, 46, "    \\\\  //");
    mvwprintw(forest_map, 24 + 6, 46, "     |  |");
    mvwprintw(forest_map, 24 + 7, 46, "    //__\\\\");

    // TRONC BAS GAUCHE

    mvwprintw(forest_map, 36, 91, "     __-__");
    mvwprintw(forest_map, 36 + 1, 91, "   /~~ o~~\\");
    mvwprintw(forest_map, 36 + 2, 91, " /~~o     ~~\\");
    mvwprintw(forest_map, 36 + 3, 91, "{ ~~      o~~}");
    mvwprintw(forest_map, 36 + 4, 91, " \\ _-     -_/");
    mvwprintw(forest_map, 36 + 5, 91, "    \\\\  //");
    mvwprintw(forest_map, 36 + 6, 91, "     |  |");
    mvwprintw(forest_map, 36 + 7, 91, "    //__\\\\");

    mvwprintw(forest_map, 42, 91, "     __-__");
    mvwprintw(forest_map, 42 + 1, 91, "   /~~ o~~\\");
    mvwprintw(forest_map, 42 + 2, 91, " /~~o     ~~\\");
    mvwprintw(forest_map, 42 + 3, 91, "{ ~~      o~~}");
    mvwprintw(forest_map, 42 + 4, 91, " \\ _-     -_/");
    mvwprintw(forest_map, 42 + 5, 91, "    \\\\  //");
    mvwprintw(forest_map, 42 + 6, 91, "     |  |");
    mvwprintw(forest_map, 42 + 7, 91, "    //__\\\\");

    mvwprintw(forest_map, 48, 91, "     __-__");
    mvwprintw(forest_map, 48 + 1, 91, "   /~~ o~~\\");
    mvwprintw(forest_map, 48 + 2, 91, " /~~o     ~~\\");
    mvwprintw(forest_map, 48 + 3, 91, "{ ~~      o~~}");
    mvwprintw(forest_map, 48 + 4, 91, " \\ _-     -_/");
    mvwprintw(forest_map, 48 + 5, 91, "    \\\\  //");
    mvwprintw(forest_map, 48 + 6, 91, "     |  |");
    mvwprintw(forest_map, 48 + 7, 91, "    //__\\\\");

    mvwprintw(forest_map, 54, 91, "     __-__");
    mvwprintw(forest_map, 54 + 1, 91, "   /~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 91, " /~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 91, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 91, " \\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 91, "    \\\\  //");
    mvwprintw(forest_map, 54 + 6, 91, "     |  |");
    mvwprintw(forest_map, 54 + 7, 91, "    //__\\\\");

    // TRONC HAUT DROIT

    mvwprintw(forest_map, 6, 136, "     __-__");
    mvwprintw(forest_map, 6 + 1, 136, "   /~~ o~~\\");
    mvwprintw(forest_map, 6 + 2, 136, " /~~o     ~~\\");
    mvwprintw(forest_map, 6 + 3, 136, "{ ~~      o~~}");
    mvwprintw(forest_map, 6 + 4, 136, " \\ _-     -_/");
    mvwprintw(forest_map, 6 + 5, 136, "    \\\\  //");
    mvwprintw(forest_map, 6 + 6, 136, "     |  |");
    mvwprintw(forest_map, 6 + 7, 136, "    //__\\\\");

    mvwprintw(forest_map, 12, 136, "     __-__");
    mvwprintw(forest_map, 12 + 1, 136, "   /~~ o~~\\");
    mvwprintw(forest_map, 12 + 2, 136, " /~~o     ~~\\");
    mvwprintw(forest_map, 12 + 3, 136, "{ ~~      o~~}");
    mvwprintw(forest_map, 12 + 4, 136, " \\ _-     -_/");
    mvwprintw(forest_map, 12 + 5, 136, "    \\\\  //");
    mvwprintw(forest_map, 12 + 6, 136, "     |  |");
    mvwprintw(forest_map, 12 + 7, 136, "    //__\\\\");

    mvwprintw(forest_map, 18, 136, "     __-__");
    mvwprintw(forest_map, 18 + 1, 136, "   /~~ o~~\\");
    mvwprintw(forest_map, 18 + 2, 136, " /~~o     ~~\\");
    mvwprintw(forest_map, 18 + 3, 136, "{ ~~      o~~}");
    mvwprintw(forest_map, 18 + 4, 136, " \\ _-     -_/");
    mvwprintw(forest_map, 18 + 5, 136, "    \\\\  //");
    mvwprintw(forest_map, 18 + 6, 136, "     |  |");
    mvwprintw(forest_map, 18 + 7, 136, "    //__\\\\");

    mvwprintw(forest_map, 24, 136, "     __-__");
    mvwprintw(forest_map, 24 + 1, 136, "   /~~ o~~\\");
    mvwprintw(forest_map, 24 + 2, 136, " /~~o     ~~\\");
    mvwprintw(forest_map, 24 + 3, 136, "{ ~~      o~~}");
    mvwprintw(forest_map, 24 + 4, 136, " \\ _-     -_/");
    mvwprintw(forest_map, 24 + 5, 136, "    \\\\  //");
    mvwprintw(forest_map, 24 + 6, 136, "     |  |");
    mvwprintw(forest_map, 24 + 7, 136, "    //__\\\\");

    // HERBE

    mvwprintw(forest_map, 12, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 1, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 2, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 3, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 4, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 5, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 6, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 7, 21, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 45, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 1, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 2, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 3, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 4, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 5, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 6, 21, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 7, 21, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 45, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 1, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 2, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 3, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 4, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 5, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 6, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 7, 67, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 12, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 1, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 2, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 3, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 4, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 5, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 6, 67, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 7, 67, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 12, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 1, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 2, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 3, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 4, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 5, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 6, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 7, 87, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 12, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 1, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 2, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 3, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 4, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 5, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 6, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 7, 109, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 45, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 1, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 2, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 3, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 4, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 5, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 6, 109, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 7, 109, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 45, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 1, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 2, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 3, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 4, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 5, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 6, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 7, 129, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 12, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 1, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 2, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 3, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 4, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 5, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 6, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 12 + 7, 165, "@@@@@@@@@@@@@@@@@@@@");

    mvwprintw(forest_map, 45, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 1, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 2, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 3, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 4, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 5, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 6, 165, "@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(forest_map, 45 + 7, 165, "@@@@@@@@@@@@@@@@@@@@");

    wattron(forest_map, COLOR_PAIR(1));
    mvwprintw(forest_map, x - 4, y + 2, "_");
    mvwprintw(forest_map, x - 3, y + 1, "'_'");
    mvwprintw(forest_map, x - 2, y, "/| |\\");
    mvwprintw(forest_map, x - 1, y + 1, "|-|");
    mvwprintw(forest_map, x, y + 1, "- -");
    wattroff(forest_map, COLOR_PAIR(1));

    // ARBRE DU BAS

    mvwprintw(forest_map, 54, 16 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 16 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 16 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 16, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 16 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 16 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 16 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 16 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 31 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 31 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 31 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 31, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 31 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 31 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 31 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 31 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 46 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 46 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 46 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 46, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 46 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 46 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 46 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 46 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 61 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 61 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 61 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 61, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 61 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 61 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 61 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 61 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 76 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 76 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 76 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 76, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 76 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 76 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 76 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 76 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 91 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 91 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 91 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 91, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 91 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 91 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 91 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 91 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 106 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 106 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 106 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 106, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 106 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 106 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 106 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 106 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 121 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 121 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 121 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 121, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 121 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 121 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 121 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 121 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 136 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 136 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 136 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 136, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 136 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 136 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 136 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 136 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 151 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 151 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 151 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 151, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 151 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 151 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 151 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 151 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 166 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 166 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 166 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 166, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 166 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 166 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 166 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 166 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 181 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 181 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 181 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 181, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 181 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 181 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 181 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 181 + 4, "//__\\\\");

    mvwprintw(forest_map, 54, 196 + 5, "__-__");
    mvwprintw(forest_map, 54 + 1, 196 + 3, "/~~ o~~\\");
    mvwprintw(forest_map, 54 + 2, 196 + 1, "/~~o     ~~\\");
    mvwprintw(forest_map, 54 + 3, 196, "{ ~~      o~~}");
    mvwprintw(forest_map, 54 + 4, 196 + 1, "\\ _-     -_/");
    mvwprintw(forest_map, 54 + 5, 196 + 4, "\\\\  //");
    mvwprintw(forest_map, 54 + 6, 196 + 5, "|  |");
    mvwprintw(forest_map, 54 + 7, 196 + 4, "//__\\\\");
}
void print_shop(WINDOW *shop_map, int x, int y)
{

    mvwprintw(shop_map, 2, 13, "   ___       __         ______           ");
    mvwprintw(shop_map, 2 + 1, 13, "  / _ \\___  / /_____   / __/ /  ___  ___ ");
    mvwprintw(shop_map, 2 + 2, 13, " / ___/ _ \\/  '_/ -_) _\\ \\/ _ \\/ _ \\/ _ \\");
    mvwprintw(shop_map, 2 + 3, 13, "/_/   \\___/_/\\_\\\\__/ /___/_//_/\\___/ .__/");
    mvwprintw(shop_map, 2 + 4, 13, "                                  /_/    ");

    mvwprintw(shop_map, 1, 130, " ____________ ");
    mvwprintw(shop_map, 1 + 1, 130, "|            |");
    mvwprintw(shop_map, 1 + 2, 130, "|     .-.    |");
    mvwprintw(shop_map, 1 + 3, 130, "|    |-o-|   |");
    mvwprintw(shop_map, 1 + 4, 130, "|     '-'    |");
    mvwprintw(shop_map, 1 + 5, 130, "|            |");
    mvwprintw(shop_map, 1 + 6, 130, "|____________|");

    mvwprintw(shop_map, 1, 100, " ____________ ");
    mvwprintw(shop_map, 1 + 1, 100, "|            |");
    mvwprintw(shop_map, 1 + 2, 100, "|     .-.    |");
    mvwprintw(shop_map, 1 + 3, 100, "|    |-o-|   |");
    mvwprintw(shop_map, 1 + 4, 100, "|     '-'    |");
    mvwprintw(shop_map, 1 + 5, 100, "|            |");
    mvwprintw(shop_map, 1 + 6, 100, "|____________|");

    mvwprintw(shop_map, 1, 70, " ____________ ");
    mvwprintw(shop_map, 1 + 1, 70, "|            |");
    mvwprintw(shop_map, 1 + 2, 70, "|     .-.    |");
    mvwprintw(shop_map, 1 + 3, 70, "|    |-o-|   |");
    mvwprintw(shop_map, 1 + 4, 70, "|     '-'    |");
    mvwprintw(shop_map, 1 + 5, 70, "|            |");
    mvwprintw(shop_map, 1 + 6, 70, "|____________|");

    mvwprintw(shop_map, 12, 90, " __-__ ");
    mvwprintw(shop_map, 12 + 1, 90, "[]| |[]");
    mvwprintw(shop_map, 12 + 2, 90, "[]| |[]");
    mvwprintw(shop_map, 12 + 3, 90, "[]| |[]");
    mvwprintw(shop_map, 12 + 4, 90, "[]| |[]");
    mvwprintw(shop_map, 12 + 5, 90, "[]| |[]");
    mvwprintw(shop_map, 12 + 6, 90, "[]|-|[]");
    mvwprintw(shop_map, 12 + 7, 90, "|_____|");

    mvwprintw(shop_map, 23, 90, " __-__ ");
    mvwprintw(shop_map, 23 + 1, 90, "[]| |[]");
    mvwprintw(shop_map, 23 + 2, 90, "[]| |[]");
    mvwprintw(shop_map, 23 + 3, 90, "[]| |[]");
    mvwprintw(shop_map, 23 + 4, 90, "[]| |[]");
    mvwprintw(shop_map, 23 + 5, 90, "[]| |[]");
    mvwprintw(shop_map, 23 + 6, 90, "[]|-|[]");
    mvwprintw(shop_map, 23 + 7, 90, "|_____|");

    mvwprintw(shop_map, 12, 110, " __-__ ");
    mvwprintw(shop_map, 12 + 1, 110, "[]| |[]");
    mvwprintw(shop_map, 12 + 2, 110, "[]| |[]");
    mvwprintw(shop_map, 12 + 3, 110, "[]| |[]");
    mvwprintw(shop_map, 12 + 4, 110, "[]| |[]");
    mvwprintw(shop_map, 12 + 5, 110, "[]| |[]");
    mvwprintw(shop_map, 12 + 6, 110, "[]|-|[]");
    mvwprintw(shop_map, 12 + 7, 110, "|_____|");

    mvwprintw(shop_map, 23, 110, " __-__ ");
    mvwprintw(shop_map, 23 + 1, 110, "[]| |[]");
    mvwprintw(shop_map, 23 + 2, 110, "[]| |[]");
    mvwprintw(shop_map, 23 + 3, 110, "[]| |[]");
    mvwprintw(shop_map, 23 + 4, 110, "[]| |[]");
    mvwprintw(shop_map, 23 + 5, 110, "[]| |[]");
    mvwprintw(shop_map, 23 + 6, 110, "[]|-|[]");
    mvwprintw(shop_map, 23 + 7, 110, "|_____|");

    mvwprintw(shop_map, 23, 144, " _-_");
    mvwprintw(shop_map, 23 + 1, 144, "[]| |");
    mvwprintw(shop_map, 23 + 2, 144, "[]| |");
    mvwprintw(shop_map, 23 + 3, 144, "[]| |");
    mvwprintw(shop_map, 23 + 4, 144, "[]| |");
    mvwprintw(shop_map, 23 + 5, 144, "[]| |");
    mvwprintw(shop_map, 23 + 6, 144, "[]|-|");
    mvwprintw(shop_map, 23 + 7, 144, "|____");

    mvwprintw(shop_map, 12, 144, " _-_");
    mvwprintw(shop_map, 12 + 1, 144, "[]| |");
    mvwprintw(shop_map, 12 + 2, 144, "[]| |");
    mvwprintw(shop_map, 12 + 3, 144, "[]| |");
    mvwprintw(shop_map, 12 + 4, 144, "[]| |");
    mvwprintw(shop_map, 12 + 5, 144, "[]| |");
    mvwprintw(shop_map, 12 + 6, 144, "[]|-|");
    mvwprintw(shop_map, 12 + 7, 144, "|____");

    mvwprintw(shop_map, 17 - 7, 1, "                                                            |    |");
    mvwprintw(shop_map, 17 - 6, 1, "                                                    |\\ ___  | _/||");
    mvwprintw(shop_map, 17 - 5, 1, "                                                    | |   | ||_|/|");
    mvwprintw(shop_map, 17 - 4, 1, "                                                     \\|___| |    |");
    mvwprintw(shop_map, 17 - 3, 1, "                               [$]                     `  ` |    |");
    mvwprintw(shop_map, 17 - 2, 1, "                                                            |    |");
    mvwprintw(shop_map, 17 - 1, 1, "                                                            |    |");
    mvwprintw(shop_map, 17, 1, "____________________________________________________________|    |");
    mvwprintw(shop_map, 17 + 1, 1, "                                                                 |");
    mvwprintw(shop_map, 17 + 2, 1, "_________________________________________________________________|");
    mvwprintw(shop_map, 17 + 3, 1, "                                                                 |");
    mvwprintw(shop_map, 17 + 4, 1, "_________________________________________________________________|");

    wattron(shop_map, COLOR_PAIR(2));
    mvwprintw(shop_map, 15, 31, "  _");
    mvwprintw(shop_map, 16, 31, " '_'");
    mvwprintw(shop_map, 17, 31, "/|_|\\");
    wattroff(shop_map, COLOR_PAIR(2));

    mvwprintw(shop_map, 35, 120, " _____________ ");
    mvwprintw(shop_map, 35 + 1, 120, "|             |");
    mvwprintw(shop_map, 35 + 2, 120, "|   WELCOME   |");
    mvwprintw(shop_map, 35 + 3, 120, "|             |");
    mvwprintw(shop_map, 35 + 4, 120, "               ");

    wattron(shop_map, COLOR_PAIR(1));
    mvwprintw(shop_map, x, y + 2, "_");
    mvwprintw(shop_map, x + 1, y + 1, "'_'");
    mvwprintw(shop_map, x + 2, y, "/| |\\");
    mvwprintw(shop_map, x + 3, y + 1, "|-|");
    mvwprintw(shop_map, x + 4, y + 1, "- -");
    wattroff(shop_map, COLOR_PAIR(1));
}

void print_flowers(WINDOW *road, int flowerx1, int flowerx2, int flowerx3, int flowerx4, int flowerx5, int flowerx6, int flowerx7, int flowerx8, int flowerx9, int flowerx10, int flowery1, int flowery2, int flowery3, int flowery4, int flowery5, int flowery6, int flowery7, int flowery8, int flowery9, int flowery10)
{
    if (flowerx1 == 0)
    {
        mvwprintw(road, flowerx1 - 1, flowery1, "  ");
        mvwprintw(road, flowerx1, flowery1, "   ");
    }
    else
    {
        mvwprintw(road, flowerx1 - 1, flowery1, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx1, flowery1, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx2 == 0)
    {
        mvwprintw(road, flowerx2 - 1, flowery2, "  ");
        mvwprintw(road, flowerx2, flowery2, "   ");
    }
    else
    {
        mvwprintw(road, flowerx2 - 1, flowery2, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx2, flowery2, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx3 == 0)
    {
        mvwprintw(road, flowerx3 - 1, flowery3, "  ");
        mvwprintw(road, flowerx3, flowery3, "   ");
    }
    else
    {
        mvwprintw(road, flowerx3 - 1, flowery3, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx3, flowery3, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx4 == 0)
    {
        mvwprintw(road, flowerx4 - 1, flowery4, "  ");
        mvwprintw(road, flowerx4, flowery4, "   ");
    }
    else
    {
        mvwprintw(road, flowerx4 - 1, flowery4, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx4, flowery4, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx5 == 0)
    {
        mvwprintw(road, flowerx5 - 1, flowery5, "  ");
        mvwprintw(road, flowerx5, flowery5, "   ");
    }
    else
    {
        mvwprintw(road, flowerx5 - 1, flowery5, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx5, flowery5, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx6 == 0)
    {
        mvwprintw(road, flowerx6 - 1, flowery6, "  ");
        mvwprintw(road, flowerx6, flowery6, "   ");
    }
    else
    {
        mvwprintw(road, flowerx6 - 1, flowery6, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx6, flowery6, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx7 == 0)
    {
        mvwprintw(road, flowerx7 - 1, flowery7, "  ");
        mvwprintw(road, flowerx7, flowery7, "   ");
    }
    else
    {
        mvwprintw(road, flowerx7 - 1, flowery7, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx7, flowery7, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx8 == 0)
    {
        mvwprintw(road, flowerx8 - 1, flowery8, "  ");
        mvwprintw(road, flowerx8, flowery8, "   ");
    }
    else
    {
        mvwprintw(road, flowerx8 - 1, flowery8, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx8, flowery8, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx9 == 0)
    {
        mvwprintw(road, flowerx9 - 1, flowery9, "  ");
        mvwprintw(road, flowerx9, flowery9, "   ");
    }
    else
    {
        mvwprintw(road, flowerx9 - 1, flowery9, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx9, flowery9, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }

    if (flowerx10 == 0)
    {
        mvwprintw(road, flowerx10 - 1, flowery10, "  ");
        mvwprintw(road, flowerx10, flowery10, "   ");
    }
    else
    {
        mvwprintw(road, flowerx10 - 1, flowery10, " #");
        wattron(road, COLOR_PAIR(GREEN));
        mvwprintw(road, flowerx10, flowery10, "\\|/");
        wattroff(road, COLOR_PAIR(GREEN));
    }
}

void print_roadto_league(WINDOW *road)
{

    mvwprintw(road, 30, 148, "      ________________________________________________________________________ ");
    mvwprintw(road, 30 + 1, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 2, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 3, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 4, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 5, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 6, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 7, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 8, 148, "     |                                                                        |");
    mvwprintw(road, 30 + 9, 148, "     |________________________________________________________________________|");
    mvwprintw(road, 30 + 10, 148, "      |    __    __    __               _____               __     __    __  |");
    mvwprintw(road, 30 + 11, 148, "      |   |  |  |  |  |  |             / ___ \\             |  |   |  |  |  | |");
    mvwprintw(road, 30 + 12, 148, "      |   |__|  |__|  |__|            / /   \\ \\            |__|   |__|  |__| |");
    mvwprintw(road, 30 + 13, 148, "      |                            ___|_|___|_|___                           |");
    mvwprintw(road, 30 + 14, 148, "      |     League                |   |___,___|   |                          |");
    mvwprintw(road, 30 + 15, 148, "      |      Pokemon              /  ,/   |   \\,  \\                          |");
    mvwprintw(road, 30 + 16, 148, "      |                           |  |    |    |  |                          |");
    mvwprintw(road, 30 + 17, 148, "      |___________________________|--|    |    |--|__________________________|");

    mvwprintw(road, 36, 118, "          &&& &&  & &&");
    mvwprintw(road, 36 + 1, 118, "      && &\\/&\\|& ()|/ @, &&");
    mvwprintw(road, 36 + 2, 118, "      &\\/(/&/&||/& /_/)_&/_&");
    mvwprintw(road, 36 + 3, 118, "   &() &\\/&|()|/&\\/ '@' & ()");
    mvwprintw(road, 36 + 4, 118, "  &_\\_&&_\\ |& |&&/&__@_/_& &&");
    mvwprintw(road, 36 + 5, 118, "&&   && & &| &| /& & @ ()& /&&");
    mvwprintw(road, 36 + 6, 118, " ()&_---()&\\&\\|&&-&&--@---()~");
    mvwprintw(road, 36 + 7, 118, "     &&     \\|||");
    mvwprintw(road, 36 + 8, 118, "             |||");
    mvwprintw(road, 36 + 9, 118, "             |||");
    mvwprintw(road, 36 + 10, 118, "             |||");
    mvwprintw(road, 36 + 11, 118, "        ,-=-~  .-^-_");

    mvwprintw(road, 36, 230, "          &&& &&  & &&");
    mvwprintw(road, 36 + 1, 230, "      && &\\/&\\|& ()|/ @, &&");
    mvwprintw(road, 36 + 2, 230, "      &\\/(/&/&||/& /_/)_&/_&");
    mvwprintw(road, 36 + 3, 230, "   &() &\\/&|()|/&\\/ '@' & ()");
    mvwprintw(road, 36 + 4, 230, "  &_\\_&&_\\ |& |&&/&__@_/_& &&");
    mvwprintw(road, 36 + 5, 230, "&&   && & &| &| /& & @ ()& /&&");
    mvwprintw(road, 36 + 6, 230, " ()&_---()&\\&\\|&&-&&--@---()~");
    mvwprintw(road, 36 + 7, 230, "     &&     \\|||");
    mvwprintw(road, 36 + 8, 230, "             |||");
    mvwprintw(road, 36 + 9, 230, "             |||");
    mvwprintw(road, 36 + 10, 230, "             |||");
    mvwprintw(road, 36 + 11, 230, "        ,-=-~  .-^-_");

    mvwprintw(road, 85, 116, " "); // cassure gauche
    mvwprintw(road, 85 + 1, 116, " ");
    mvwprintw(road, 85 + 2, 116, " ");
    mvwprintw(road, 85 + 3, 116, " ");
    mvwprintw(road, 85 + 4, 116, " ");
    mvwprintw(road, 85 + 5, 116, " ");
    mvwprintw(road, 85 + 6, 116, " ");
    mvwprintw(road, 85 + 7, 116, " ");
    mvwprintw(road, 85 + 8, 116, " ");
    mvwprintw(road, 85 + 9, 116, " ");
    mvwprintw(road, 85 + 10, 116, " ");
    mvwprintw(road, 85 + 11, 116, " ");
    mvwprintw(road, 85 + 12, 116, " ");
    mvwprintw(road, 85 + 13, 116, " ");
    mvwprintw(road, 85 + 14, 116, " ");
    mvwprintw(road, 85 + 15, 116, " ");
    mvwprintw(road, 85 + 16, 116, " ");
    mvwprintw(road, 85 + 17, 116, " ");
    mvwprintw(road, 85 + 18, 116, " ");
    mvwprintw(road, 85 + 19, 116, " ");
    mvwprintw(road, 85 + 20, 116, " ");
    mvwprintw(road, 85 + 21, 116, " ");
    mvwprintw(road, 85 + 22, 116, " ");
    mvwprintw(road, 85 + 23, 116, " ");
    mvwprintw(road, 85 + 24, 116, " ");

    mvwprintw(road, 85, 265, " "); // cassure gauche
    mvwprintw(road, 85 + 1, 265, " ");
    mvwprintw(road, 85 + 2, 265, " ");
    mvwprintw(road, 85 + 3, 265, " ");
    mvwprintw(road, 85 + 4, 265, " ");
    mvwprintw(road, 85 + 5, 265, " ");
    mvwprintw(road, 85 + 6, 265, " ");
    mvwprintw(road, 85 + 7, 265, " ");
    mvwprintw(road, 85 + 8, 265, " ");
    mvwprintw(road, 85 + 9, 265, " ");
    mvwprintw(road, 85 + 10, 265, " ");
    mvwprintw(road, 85 + 11, 265, " ");
    mvwprintw(road, 85 + 12, 265, " ");
    mvwprintw(road, 85 + 13, 265, " ");
    mvwprintw(road, 85 + 14, 265, " ");
    mvwprintw(road, 85 + 15, 265, " ");
    mvwprintw(road, 85 + 16, 265, " ");
    mvwprintw(road, 85 + 17, 265, " ");
    mvwprintw(road, 85 + 18, 265, " ");
    mvwprintw(road, 85 + 19, 265, " ");
    mvwprintw(road, 85 + 20, 265, " ");
    mvwprintw(road, 85 + 21, 265, " ");
    mvwprintw(road, 85 + 22, 265, " ");
    mvwprintw(road, 85 + 23, 265, " ");
    mvwprintw(road, 85 + 24, 265, " ");

    mvwprintw(road, 139, 183, "|"); // exit zone
    mvwprintw(road, 139, 183 + 1, " ");
    mvwprintw(road, 139, 183 + 2, " ");
    mvwprintw(road, 139, 183 + 3, " ");
    mvwprintw(road, 139, 183 + 4, " ");
    mvwprintw(road, 139, 183 + 5, " ");
    mvwprintw(road, 139, 183 + 6, " ");
    mvwprintw(road, 139, 183 + 7, " ");
    mvwprintw(road, 139, 183 + 8, " ");
    mvwprintw(road, 139, 183 + 9, " ");
    mvwprintw(road, 139, 183 + 10, " ");
    mvwprintw(road, 139, 183 + 11, " ");
    mvwprintw(road, 139, 183 + 12, " ");
    mvwprintw(road, 139, 183 + 13, " ");
    mvwprintw(road, 139, 183 + 14, "|");

    mvwprintw(road, 140, 177, "EXIT");

    wattron(road, COLOR_PAIR(4));
    for (int j = 0; j <= 200; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i <= 115; i += 2) // eau a gauche
            {
                mvwprintw(road, j, i, "~");
            }
        }

        else
        {
            for (int i = 1; i <= 115; i += 2) // eau a gauche
            {
                mvwprintw(road, j, i, "~");
            }
        }
    }

    for (int j = 0; j <= 200; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 266; i <= 400; i += 2) // eau a gauche
            {
                mvwprintw(road, j, i, "~");
            }
        }

        else
        {
            for (int i = 267; i <= 400; i += 2) // eau a gauche
            {
                mvwprintw(road, j, i, "~");
            }
        }
    }

    for (int j = 0; j <= 28; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 116; i <= 266; i += 2) // eau en haut
            {
                mvwprintw(road, j, i, "~");
            }
        }

        else
        {
            for (int i = 115; i <= 267; i += 2) // eau en haut
            {
                mvwprintw(road, j, i, "~");
            }
        }
    }

    for (int j = 149; j <= 200; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 116; i <= 266; i += 2) // eau en bas
            {
                mvwprintw(road, j, i, "~");
            }
        }

        else
        {
            for (int i = 115; i <= 267; i += 2) // eau en bas
            {
                mvwprintw(road, j, i, "~");
            }
        }
    }

    for (int j = 85; j <= 109; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 116; i <= 266; i += 2) // eau cassure
            {
                mvwprintw(road, j, i, "~");
            }
        }

        else
        {
            for (int i = 115; i <= 267; i += 2) // eau cassure
            {
                mvwprintw(road, j, i, "~");
            }
        }
    }
    wattroff(road, COLOR_PAIR(4));
}

void jauges_refresh(WINDOW *match, WINDOW *jauge_player, WINDOW *jauge_champion, pokemon player_poke, pokemon champion_poke)
{

    mvwprintw(match, 24, 110, "     ");
    mvwprintw(match, 8, 21, "     ");
    mvwprintw(match, 24, 110, "%.0f/%.0f", player_poke.pv, player_poke.pv_save);
    mvwprintw(match, 8, 21, "%.0f/%.0f", champion_poke.pv, champion_poke.pv_save);
    int array_pv_player = (player_poke.pv / player_poke.pv_save) * 20;
    int array_pv_champion = (champion_poke.pv / champion_poke.pv_save) * 20;
    if (array_pv_champion > 0)
    {
        mvwprintw(jauge_champion, 1, 1, "                   ");
        for (int i = 1; i < array_pv_champion; i++)
        {
            mvwprintw(jauge_champion, 1, i, "#");
        }
    }
    if (array_pv_player > 0)
    {
        mvwprintw(jauge_player, 1, 1, "                   ");
        for (int i = 1; i < array_pv_player; i++)
        {
            mvwprintw(jauge_player, 1, i, "#");
        }
    }
    wrefresh(match);
    box(jauge_champion, 0, 0);
    box(jauge_player, 0, 0);
    wrefresh(jauge_champion);
    wrefresh(jauge_player);
}

void print_match(WINDOW *match, WINDOW *jauge_champion, WINDOW *jauge_player, pokemon player_poke, pokemon champion_poke, int x, int y)
{

    mvwprintw(match, 30, 90, " ___ ___ ___ _  _ _____");
    mvwprintw(match, 30 + 1, 90, "| __|_ _/ __| || |_   _|");
    mvwprintw(match, 30 + 2, 90, "| _| | | (_ | __ | | |  ");
    mvwprintw(match, 30 + 3, 90, "|_| |___\\___|_||_| |_|  ");

    mvwprintw(match, 30, 130, " ___   _   ___ ");
    mvwprintw(match, 30 + 1, 130, "| _ ) /_\\ / __|");
    mvwprintw(match, 30 + 2, 130, "| _ \\/ _ \\ (_ |");
    mvwprintw(match, 30 + 3, 130, "|___/_/ \\_\\___|");

    mvwprintw(match, 36, 113, " ___ _   _ _  _ ");
    mvwprintw(match, 36 + 1, 113, "| _ \\ | | | \\| |");
    mvwprintw(match, 36 + 2, 113, "|   / |_| | .` |");
    mvwprintw(match, 36 + 3, 113, "|_|_\\\\___/|_|\\_|");

    mvwprintw(match, x, y, ">");

    mvwprintw(match, 20, 100, "      ______________________________________");
    mvwprintw(match, 20 + 1, 100, "     /                                     /");
    mvwprintw(match, 20 + 2, 100, "    /                                     /");
    mvwprintw(match, 20 + 3, 100, "   /                                     /");
    mvwprintw(match, 20 + 4, 100, "  /                                     /");
    mvwprintw(match, 20 + 5, 100, " /                                     /");
    mvwprintw(match, 20 + 6, 100, "<_____________________________________/");

    mvwprintw(match, 22, 107, "%s", player_poke.name);
    mvwprintw(match, 22, 132, "lvl %d", player_poke.lvl);

    mvwprintw(match, 4, 10, "______________________________________");
    mvwprintw(match, 4 + 1, 10, "\\                                     \\");
    mvwprintw(match, 4 + 2, 10, " \\                                     \\");
    mvwprintw(match, 4 + 3, 10, "  \\                                     \\");
    mvwprintw(match, 4 + 4, 10, "   \\                                     \\");
    mvwprintw(match, 4 + 5, 10, "    \\                                     \\");
    mvwprintw(match, 4 + 6, 10, "     \\_____________________________________>");

    mvwprintw(match, 6, 14, "%s", champion_poke.name);
    mvwprintw(match, 6, 40, "lvl %d", champion_poke.lvl);

    print_poke(match, player_poke, 17, 10, 1);
    print_poke(match, champion_poke, 6, 110, 0);

    mvwprintw(match, 24, 105, "HP");
    mvwprintw(match, 8, 16, "HP");

    jauges_refresh(match, jauge_player, jauge_champion, player_poke, champion_poke);
}

void print_menu(WINDOW *win, int x, int y)
{

    mvwprintw(win, 2, 236 / 10, "88b           d88  88888888888  888b      88  88        88");
    mvwprintw(win, 3, 236 / 10, "888b         d888  88           8888b     88  88        88");
    mvwprintw(win, 4, 236 / 10, "88`8b       d8'88  88           88 `8b    88  88        88");
    mvwprintw(win, 5, 236 / 10, "88 `8b     d8' 88  88aaaaa      88  `8b   88  88        88");
    mvwprintw(win, 6, 236 / 10, "88  `8b   d8'  88  88           88   `8b  88  88        88");
    mvwprintw(win, 7, 236 / 10, "88   `8b d8'   88  88           88    `8b 88  88        88");
    mvwprintw(win, 8, 236 / 10, "88    `888'    88  88           88     `8888  88a.    .a8P");
    mvwprintw(win, 9, 236 / 10, "88     `8'     88  88888888888  88      `888   '88888888'");

    mvwprintw(win, 13, 236 / 15, "__   _____  _   _ ____    _____ _____    _    __  __ ");
    mvwprintw(win, 13 + 1, 236 / 15, "\\ \\ / / _ \\| | | |  _ \\  |_   _| ____|  / \\  |  \\/  |");
    mvwprintw(win, 13 + 2, 236 / 15, " \\ V / | | | | | | |_) |   | | |  _|   / _ \\ | |\\/| |");
    mvwprintw(win, 13 + 3, 236 / 15, "  | || |_| | |_| |  _ /    | | | |___ / ___ \\| |  | |");
    mvwprintw(win, 13 + 4, 236 / 15, "  |_| '___/ '___/|_| '_\\   |_| |_____/_/   \\_\\_|  |_|");

    mvwprintw(win, 22, 236 / 15, " ____    ___     _______ ");
    mvwprintw(win, 22 + 1, 236 / 15, "/ ___|  / \\ \\   / / ____|");
    mvwprintw(win, 22 + 2, 236 / 15, "'___ ' / _ \\ \\ / /|  _|  ");
    mvwprintw(win, 22 + 3, 236 / 15, " ___) / ___ \\ V / | |___ ");
    mvwprintw(win, 22 + 4, 236 / 15, "|____/_/   '_\\_/  |_____|");

    mvwprintw(win, 31, 236 / 15, "  ___  _   _ ___ _____   _____ _   _ _____    ____    _    __  __ _____ ");
    mvwprintw(win, 31 + 1, 236 / 15, " / _ \\| | | |_ _|_   _| |_   _| | | | ____|  / ___|  / \\  |  \\/  | ____|");
    mvwprintw(win, 31 + 2, 236 / 15, "| | | | | | || |  | |     | | | |_| |  _|   | |  _  / _ \\ | |\\/| |  _|  ");
    mvwprintw(win, 31 + 3, 236 / 15, "| |_| | |_| || |  | |     | | |  _  | |___  | |_| |/ ___ \\| |  | | |___ ");
    mvwprintw(win, 31 + 4, 236 / 15, " \\__\\__\\___/|___| |_|     |_| |_| |_|_____|  \\____/_/   \\_\\_|  |_|_____|");

    mvwprintw(win, x, y, "    .");
    mvwprintw(win, x + 1, y, "  .;;............");
    mvwprintw(win, x + 2, y, ".;;;;::::::::::::");
    mvwprintw(win, x + 3, y, " ':;;::::::::::::");
    mvwprintw(win, x + 4, y, "   ':");
}

void print_inventory(WINDOW *sac, trainer *player, int x, int y)
{
    int i;

    for (i = 0; i < 27; i++)
    {
        mvwprintw(sac, 1 + i, (236 / 1.5) / 2, "|"); // colonne du droite
    }

    for (i = 0; i < 27; i++)
    {
        mvwprintw(sac, 1 + i, (236 / 1.5) / 4, "|"); // colonne de gauche
    }

    for (i = 0; i < 116; i++)
    {
        mvwprintw(sac, (63 / 1.5) / 3, 1 + i, "_"); // ligne
    }

    mvwprintw(sac, x, y, "  ,");
    mvwprintw(sac, x + 1, y, ".:::.");

    mvwprintw(sac, 2, 28, "%s", player->inventory[POKEBALLS].name);
    mvwprintw(sac, 2, 68, "%s", player->inventory[POTIONS].name);
    mvwprintw(sac, 2, 108, "%s", player->inventory[CANDYS].name);

    mvwprintw(sac, 2, 4, "       ,,,,,,,,,     ");
    mvwprintw(sac, 2 + 1, 4, "     @((((((((((((&     ");
    mvwprintw(sac, 2 + 2, 4, "  &      ((((((((((((&  ");
    mvwprintw(sac, 2 + 3, 4, " ((    ((((((###&(((((( ");
    mvwprintw(sac, 2 + 4, 4, "(((((((&####    &&#(((((");
    mvwprintw(sac, 2 + 5, 4, "############&&   #######");
    mvwprintw(sac, 2 + 6, 4, "*****        &##        ");
    mvwprintw(sac, 2 + 7, 4, " *****               *   ");
    mvwprintw(sac, 2 + 8, 4, "   ******          **   ");
    mvwprintw(sac, 2 + 9, 4, "      ************     ");
    mvwprintw(sac, 3, 33, "x%d", player->inventory[POKEBALLS].quant);

    mvwprintw(sac, 1, 44, "     @@@@@@@@@@(     ");
    mvwprintw(sac, 1 + 1, 44, "    *@@@@@@@####&&   ");
    mvwprintw(sac, 1 + 2, 44, "    @@@( &@######.   ");
    mvwprintw(sac, 1 + 3, 44, "    &#@#*,###//##.   ");
    mvwprintw(sac, 1 + 4, 44, "     ##&&###///##    ");
    mvwprintw(sac, 1 + 5, 44, "     ##&&,/////##    ");
    mvwprintw(sac, 1 + 6, 44, "    ###(((/(((((##   ");
    mvwprintw(sac, 1 + 7, 44, " ####(((((/#(#(//##  ");
    mvwprintw(sac, 1 + 8, 44, "##((##(#((/#(/(///((.");
    mvwprintw(sac, 1 + 9, 44, "#((//(((((/(//*//*/##");
    mvwprintw(sac, 1 + 10, 44, "   #(#//(#/////#( ");
    mvwprintw(sac, 3, 73, "x%d", player->inventory[POTIONS].quant);

    mvwprintw(sac, 3, 84, "              ..");
    mvwprintw(sac, 3 + 1, 84, "             \\@(");
    mvwprintw(sac, 3 + 2, 84, "       .((((,,//##(/");
    mvwprintw(sac, 3 + 3, 84, "     *@&*####(/.,,, ");
    mvwprintw(sac, 3 + 4, 84, "     (#(#####(/.");
    mvwprintw(sac, 3 + 5, 84, ",(((((/,(((((*, ");
    mvwprintw(sac, 3 + 6, 84, "  **,//*        ");
    mvwprintw(sac, 3 + 7, 84, "   **,,.        ");
    mvwprintw(sac, 3, 113, "x%d", player->inventory[CANDYS].quant);

    mvwprintw(sac, 16, 28, "%s", player->inventory[SLOT4].name);
    mvwprintw(sac, 16, 68, "%s", player->inventory[SLOT5].name);
    mvwprintw(sac, 16, 108, "%s", player->inventory[SLOT6].name);

    if (player->inventory[3].type == SURF || player->inventory[3].type == ROAR || player->inventory[3].type == LEER)
    {
        mvwprintw(sac, 16, 5, "     (@@@@@&&@@(       ");
        mvwprintw(sac, 16 + 1, 5, "  &/(($$$$$&@@@@@&&    ");
        mvwprintw(sac, 16 + 2, 5, " $##(/(#$$$&@@@&$$$$   ");
        mvwprintw(sac, 16 + 3, 5, "$$$$$$#((...$$$$$$$$$  ");
        mvwprintw(sac, 16 + 4, 5, "########*   *######((  ");
        mvwprintw(sac, 16 + 5, 5, "&$$$$$$&@&#(((##$$$$&  ");
        mvwprintw(sac, 16 + 6, 5, " &##$&@@@&###(//(##&   ");
        mvwprintw(sac, 16 + 7, 5, "   &@@@@&$#####(/&     ");
        mvwprintw(sac, 16 + 8, 5, "        &&&&&          ");
        mvwprintw(sac, 17, 30, "x%d", player->inventory[SLOT4].quant);
    }

    if (player->inventory[4].type == SURF || player->inventory[4].type == ROAR || player->inventory[4].type == LEER)
    {
        mvwprintw(sac, 16, 45, "     (@@@@@&&@@(       ");
        mvwprintw(sac, 16 + 1, 45, "  &/(($$$$$&@@@@@&&    ");
        mvwprintw(sac, 16 + 2, 45, " $##(/(#$$$&@@@&$$$$   ");
        mvwprintw(sac, 16 + 3, 45, "$$$$$$#((...$$$$$$$$$  ");
        mvwprintw(sac, 16 + 4, 45, "########*   *######((  ");
        mvwprintw(sac, 16 + 5, 45, "&$$$$$$&@&#(((##$$$$&  ");
        mvwprintw(sac, 16 + 6, 45, " &##$&@@@&###(//(##&   ");
        mvwprintw(sac, 16 + 7, 45, "   &@@@@&$#####(/&     ");
        mvwprintw(sac, 16 + 8, 45, "        &&&&&          ");
        mvwprintw(sac, 17, 70, "x%d", player->inventory[SLOT5].quant);
    }

    if (player->inventory[5].type == SURF || player->inventory[5].type == ROAR || player->inventory[5].type == LEER)
    {
        mvwprintw(sac, 16, 84, "     (@@@@@&&@@(       ");
        mvwprintw(sac, 16 + 1, 84, "  &/(($$$$$&@@@@@&&    ");
        mvwprintw(sac, 16 + 2, 84, " $##(/(#$$$&@@@&$$$$   ");
        mvwprintw(sac, 16 + 3, 84, "$$$$$$#((...$$$$$$$$$  ");
        mvwprintw(sac, 16 + 4, 84, "########*   *######((  ");
        mvwprintw(sac, 16 + 5, 84, "&$$$$$$&@&#(((##$$$$&  ");
        mvwprintw(sac, 16 + 6, 84, " &##$&@@@&###(//(##&   ");
        mvwprintw(sac, 16 + 7, 84, "   &@@@@&$#####(/&     ");
        mvwprintw(sac, 16 + 8, 84, "        &&&&&          ");
        mvwprintw(sac, 17, 110, "x%d", player->inventory[SLOT6].quant);
    }

    if (player->inventory[3].type == FLOWER)
    {
        mvwprintw(sac, 16, 13, "   _ _");
        mvwprintw(sac, 16 + 1, 13, " _{ ' }_");
        mvwprintw(sac, 16 + 2, 13, "{ `.!.` }");
        mvwprintw(sac, 16 + 3, 13, "',_/Y\\_,'");
        mvwprintw(sac, 16 + 4, 13, "  {_,_}");
        mvwprintw(sac, 16 + 5, 13, "    |");
        mvwprintw(sac, 16 + 6, 13, "  (\\|");
        mvwprintw(sac, 16 + 7, 13, "   \\| /)");
        mvwprintw(sac, 16 + 8, 13, "    |//");
        mvwprintw(sac, 17, 30, "x%d", player->inventory[SLOT4].quant);
    }

    if (player->inventory[4].type == FLOWER)
    {
        mvwprintw(sac, 16, 53, "   _ _");
        mvwprintw(sac, 16 + 1, 53, " _{ ' }_");
        mvwprintw(sac, 16 + 2, 53, "{ `.!.` }");
        mvwprintw(sac, 16 + 3, 53, "',_/Y\\_,'");
        mvwprintw(sac, 16 + 4, 53, "  {_,_}");
        mvwprintw(sac, 16 + 5, 53, "    |");
        mvwprintw(sac, 16 + 6, 53, "  (\\|");
        mvwprintw(sac, 16 + 7, 53, "   \\| /)");
        mvwprintw(sac, 16 + 8, 53, "    |//");
        mvwprintw(sac, 17, 70, "x%d", player->inventory[SLOT5].quant);
    }

    if (player->inventory[5].type == FLOWER)
    {
        mvwprintw(sac, 16, 92, "   _ _");
        mvwprintw(sac, 16 + 1, 92, " _{ ' }_");
        mvwprintw(sac, 16 + 2, 92, "{ `.!.` }");
        mvwprintw(sac, 16 + 3, 92, "',_/Y\\_,'");
        mvwprintw(sac, 16 + 4, 92, "  {_,_}");
        mvwprintw(sac, 16 + 5, 92, "    |");
        mvwprintw(sac, 16 + 6, 92, "  (\\|");
        mvwprintw(sac, 16 + 7, 92, "   \\| /)");
        mvwprintw(sac, 16 + 8, 92, "    |//");
        mvwprintw(sac, 17, 110, "x%d", player->inventory[SLOT6].quant);
    }
}

void print_art_box(WINDOW *box, trainer player, int whatpoke)
{

    switch (whatpoke)
    {
    case 1:
        switch (player.poke1.art_box)
        {
        case CHARMANDER:
            mvwprintw(box, 6, 4, "   $$$               ");
            mvwprintw(box, 6 + 1, 4, " $$$$$##          ");
            mvwprintw(box, 6 + 2, 4, "*$$$$$,*          ");
            mvwprintw(box, 6 + 3, 4, "#,$$$. (        # ");
            mvwprintw(box, 6 + 4, 4, "   ###(#$      ###");
            mvwprintw(box, 6 + 5, 4, "$$#@@@@$$$$(   &&(");
            mvwprintw(box, 6 + 6, 4, "   @@@&@$$      $ ");
            mvwprintw(box, 6 + 7, 4, " &$&&&&&&$$#(((#  ");
            mvwprintw(box, 6 + 8, 4, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(box, 6, 3, "    .&$$$$#              ");
            mvwprintw(box, 6 + 1, 3, "   *$$$$ ,#((        ");
            mvwprintw(box, 6 + 2, 3, "   ( (((.*((*        ");
            mvwprintw(box, 6 + 3, 3, "    $$((((,((        ");
            mvwprintw(box, 6 + 4, 3, ",$$#&&$..$$#((#      ");
            mvwprintw(box, 6 + 5, 3, "   &&&.&*((#$((      ");
            mvwprintw(box, 6 + 6, 3, "   $&&&&&#$$$/ ###(((");
            mvwprintw(box, 6 + 7, 3, "  $#((###$$$$((((((( ");
            mvwprintw(box, 6 + 8, 3, "          ((((       ");
            break;

        case BULBASAUR:
            mvwprintw(box, 6, 2, "           $$########(    ");
            mvwprintw(box, 6 + 1, 2, "   $#   .(## $######(/  ");
            mvwprintw(box, 6 + 2, 2, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(box, 6 + 3, 2, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(box, 6 + 4, 2, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(box, 6 + 5, 2, "(.#$$$$######(((((((((/ ");
            mvwprintw(box, 6 + 6, 2, "   #/((((((,($#$$##//(( ");
            mvwprintw(box, 6 + 7, 2, "   (((#( ((((.$$#(((((( ");
            mvwprintw(box, 6 + 8, 2, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(box, 6, 3, "   .");
            mvwprintw(box, 6 + 1, 3, " #@.     ./,**");
            mvwprintw(box, 6 + 2, 3, " .$@@@$#&$#     .&/ ");
            mvwprintw(box, 6 + 3, 3, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(box, 6 + 4, 3, " #$$//$$($..#$$&&&* ");
            mvwprintw(box, 6 + 5, 3, "  &&$$$#$&&  *#");
            mvwprintw(box, 6 + 6, 3, " /&(&&/&&#&.((,");
            mvwprintw(box, 6 + 7, 3, "(&$$&&&$&&$$.,");
            mvwprintw(box, 6 + 8, 3, " /$#(//$$$$/");
            mvwprintw(box, 6 + 9, 3, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(box, 6, 3, "    ,           #            ");
            mvwprintw(box, 6 + 1, 3, "  .(  (       (***#,       ");
            mvwprintw(box, 6 + 2, 3, "/*####,      ..***///*#    ");
            mvwprintw(box, 6 + 3, 3, "*,###(//   #.**/**,/////., ");
            mvwprintw(box, 6 + 4, 3, "** . **/##..**///**/  * /* ");
            mvwprintw(box, 6 + 5, 3, "     ##/$$#,#        ((   /");
            mvwprintw(box, 6 + 6, 3, "  /# &@@@@@./.       **&*  ");
            mvwprintw(box, 6 + 7, 3, "    //@@@@@##.#      #.    ");
            mvwprintw(box, 6 + 8, 3, "   ((/ ###(//#//////(      ");
            mvwprintw(box, 6 + 9, 3, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(box, 6, 3, "         ####$*/#           ");
            mvwprintw(box, 6 + 1, 3, "(&&&  ###########@$  *#  @");
            mvwprintw(box, 6 + 2, 3, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(box, 6 + 3, 3, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(box, 6 + 4, 3, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(box, 6 + 5, 3, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(box, 6 + 6, 3, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(box, 6 + 7, 3, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(box, 6 + 8, 3, "     .,(/// $$#$.(####$   ");
            mvwprintw(box, 6 + 9, 3, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(box, 6, 1, "           $$       $         ");
            mvwprintw(box, 6 + 1, 1, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(box, 6 + 2, 1, "   ((. $***.******.**(***(  ");
            mvwprintw(box, 6 + 3, 1, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(box, 6 + 4, 1, "    #(($(@$$($$$($((@(      ");
            mvwprintw(box, 6 + 5, 1, " (,(((($(((((,,(((((((((,,,");
            mvwprintw(box, 6 + 6, 1, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(box, 6 + 7, 1, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(box, 6 + 8, 1, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(box, 6 + 9, 1, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(box, 6, 5, "    $             ");
            mvwprintw(box, 6 + 1, 5, "   &&& &        ");
            mvwprintw(box, 6 + 2, 5, "     &&& $.     ");
            mvwprintw(box, 6 + 3, 5, ".       *   &   ");
            mvwprintw(box, 6 + 4, 5, "(*.*,. &&     * ");
            mvwprintw(box, 6 + 5, 5, ".$$$$&#        ,");
            mvwprintw(box, 6 + 6, 5, ".&*&&&$$        ");
            mvwprintw(box, 6 + 7, 5, " &@@@@$&$      ,");
            mvwprintw(box, 6 + 8, 5, " ($$@@&$$.**.   ");
            mvwprintw(box, 6 + 9, 5, ".,.   .**      ");
            break;

        default:
            break;
        }
        break;

    case 2:
        switch (player.poke2.art_box)
        {
        case CHARMANDER:
            mvwprintw(box, 6, 4, "   $$$          ");
            mvwprintw(box, 6 + 1, 4, " $$$$$##          ");
            mvwprintw(box, 6 + 2, 4, "*$$$$$,*          ");
            mvwprintw(box, 6 + 3, 4, "#,$$$. (        # ");
            mvwprintw(box, 6 + 4, 4, "   ###(#$      ###");
            mvwprintw(box, 6 + 5, 4, "$$#@@@@$$$$(   &&(");
            mvwprintw(box, 6 + 6, 4, "   @@@&@$$      $ ");
            mvwprintw(box, 6 + 7, 4, " &$&&&&&&$$#(((#  ");
            mvwprintw(box, 6 + 8, 4, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(box, 6, 3, "    .&$$$$#          ");
            mvwprintw(box, 6 + 1, 3, "   *$$$$ ,#((        ");
            mvwprintw(box, 6 + 2, 3, "   ( (((.*((*        ");
            mvwprintw(box, 6 + 3, 3, "    $$((((,((        ");
            mvwprintw(box, 6 + 4, 3, ",$$#&&$..$$#((#      ");
            mvwprintw(box, 6 + 5, 3, "   &&&.&*((#$((      ");
            mvwprintw(box, 6 + 6, 3, "   $&&&&&#$$$/ ###(((");
            mvwprintw(box, 6 + 7, 3, "  $#((###$$$$((((((( ");
            mvwprintw(box, 6 + 8, 3, "          ((((       ");
            break;

        case BULBASAUR:
            mvwprintw(box, 6, 2, "           $$########(  ");
            mvwprintw(box, 6 + 1, 2, "   $#   .(## $######(/  ");
            mvwprintw(box, 6 + 2, 2, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(box, 6 + 3, 2, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(box, 6 + 4, 2, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(box, 6 + 5, 2, "(.#$$$$######(((((((((/ ");
            mvwprintw(box, 6 + 6, 2, "   #/((((((,($#$$##//(( ");
            mvwprintw(box, 6 + 7, 2, "   (((#( ((((.$$#(((((( ");
            mvwprintw(box, 6 + 8, 2, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(box, 6, 3, "   .");
            mvwprintw(box, 6 + 1, 3, " #@.     ./,**");
            mvwprintw(box, 6 + 2, 3, " .$@@@$#&$#     .&/ ");
            mvwprintw(box, 6 + 3, 3, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(box, 6 + 4, 3, " #$$//$$($..#$$&&&* ");
            mvwprintw(box, 6 + 5, 3, "  &&$$$#$&&  *#");
            mvwprintw(box, 6 + 6, 3, " /&(&&/&&#&.((,");
            mvwprintw(box, 6 + 7, 3, "(&$$&&&$&&$$.,");
            mvwprintw(box, 6 + 8, 3, " /$#(//$$$$/");
            mvwprintw(box, 6 + 9, 3, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(box, 6, 3, "    ,           #            ");
            mvwprintw(box, 6 + 1, 3, "  .(  (       (***#,       ");
            mvwprintw(box, 6 + 2, 3, "/*####,      ..***///*#    ");
            mvwprintw(box, 6 + 3, 3, "*,###(//   #.**/**,/////., ");
            mvwprintw(box, 6 + 4, 3, "** . **/##..**///**/  * /* ");
            mvwprintw(box, 6 + 5, 3, "     ##/$$#,#        ((   /");
            mvwprintw(box, 6 + 6, 3, "  /# &@@@@@./.       **&*  ");
            mvwprintw(box, 6 + 7, 3, "    //@@@@@##.#      #.    ");
            mvwprintw(box, 6 + 8, 3, "   ((/ ###(//#//////(      ");
            mvwprintw(box, 6 + 9, 3, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(box, 6, 3, "         ####$*/#           ");
            mvwprintw(box, 6 + 1, 3, "(&&&  ###########@$  *#  @");
            mvwprintw(box, 6 + 2, 3, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(box, 6 + 3, 3, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(box, 6 + 4, 3, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(box, 6 + 5, 3, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(box, 6 + 6, 3, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(box, 6 + 7, 3, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(box, 6 + 8, 3, "     .,(/// $$#$.(####$   ");
            mvwprintw(box, 6 + 9, 3, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(box, 6, 1, "           $$       $         ");
            mvwprintw(box, 6 + 1, 1, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(box, 6 + 2, 1, "   ((. $***.******.**(***(  ");
            mvwprintw(box, 6 + 3, 1, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(box, 6 + 4, 1, "    #(($(@$$($$$($((@(      ");
            mvwprintw(box, 6 + 5, 1, " (,(((($(((((,,(((((((((,,,@");
            mvwprintw(box, 6 + 6, 1, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(box, 6 + 7, 1, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(box, 6 + 8, 1, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(box, 6 + 9, 1, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(box, 6, 5, "    $             ");
            mvwprintw(box, 6 + 1, 5, "   &&& &        ");
            mvwprintw(box, 6 + 2, 5, "     &&& $.     ");
            mvwprintw(box, 6 + 3, 5, ".       *   &   ");
            mvwprintw(box, 6 + 4, 5, "(*.*,. &&     * ");
            mvwprintw(box, 6 + 5, 5, ".$$$$&#        ,");
            mvwprintw(box, 6 + 6, 5, ".&*&&&$$        ");
            mvwprintw(box, 6 + 7, 5, " &@@@@$&$      ,");
            mvwprintw(box, 6 + 8, 5, " ($$@@&$$.**.   ");
            mvwprintw(box, 6 + 9, 5, ".,.   .**      ");
            break;

        default:
            break;
        }
        break;

    case 3:
        switch (player.poke3.art_box)
        {
        case CHARMANDER:
            mvwprintw(box, 6, 4, "   $$$          ");
            mvwprintw(box, 6 + 1, 4, " $$$$$##          ");
            mvwprintw(box, 6 + 2, 4, "*$$$$$,*          ");
            mvwprintw(box, 6 + 3, 4, "#,$$$. (        # ");
            mvwprintw(box, 6 + 4, 4, "   ###(#$      ###");
            mvwprintw(box, 6 + 5, 4, "$$#@@@@$$$$(   &&(");
            mvwprintw(box, 6 + 6, 4, "   @@@&@$$      $ ");
            mvwprintw(box, 6 + 7, 4, " &$&&&&&&$$#(((#  ");
            mvwprintw(box, 6 + 8, 4, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(box, 6, 3, "    .&$$$$#          ");
            mvwprintw(box, 6 + 1, 3, "   *$$$$ ,#((        ");
            mvwprintw(box, 6 + 2, 3, "   ( (((.*((*        ");
            mvwprintw(box, 6 + 3, 3, "    $$((((,((        ");
            mvwprintw(box, 6 + 4, 3, ",$$#&&$..$$#((#      ");
            mvwprintw(box, 6 + 5, 3, "   &&&.&*((#$((      ");
            mvwprintw(box, 6 + 6, 3, "   $&&&&&#$$$/ ###(((");
            mvwprintw(box, 6 + 7, 3, "  $#((###$$$$((((((( ");
            mvwprintw(box, 6 + 8, 3, "          ((((       ");
            break;

        case BULBASAUR:
            mvwprintw(box, 6, 2, "           $$########(  ");
            mvwprintw(box, 6 + 1, 2, "   $#   .(## $######(/  ");
            mvwprintw(box, 6 + 2, 2, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(box, 6 + 3, 2, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(box, 6 + 4, 2, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(box, 6 + 5, 2, "(.#$$$$######(((((((((/ ");
            mvwprintw(box, 6 + 6, 2, "   #/((((((,($#$$##//(( ");
            mvwprintw(box, 6 + 7, 2, "   (((#( ((((.$$#(((((( ");
            mvwprintw(box, 6 + 8, 2, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(box, 6, 3, "   .");
            mvwprintw(box, 6 + 1, 3, " #@.     ./,**");
            mvwprintw(box, 6 + 2, 3, " .$@@@$#&$#     .&/ ");
            mvwprintw(box, 6 + 3, 3, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(box, 6 + 4, 3, " #$$//$$($..#$$&&&* ");
            mvwprintw(box, 6 + 5, 3, "  &&$$$#$&&  *#");
            mvwprintw(box, 6 + 6, 3, " /&(&&/&&#&.((,");
            mvwprintw(box, 6 + 7, 3, "(&$$&&&$&&$$.,");
            mvwprintw(box, 6 + 8, 3, " /$#(//$$$$/");
            mvwprintw(box, 6 + 9, 3, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(box, 6, 3, "    ,           #            ");
            mvwprintw(box, 6 + 1, 3, "  .(  (       (***#,       ");
            mvwprintw(box, 6 + 2, 3, "/*####,      ..***///*#    ");
            mvwprintw(box, 6 + 3, 3, "*,###(//   #.**/**,/////., ");
            mvwprintw(box, 6 + 4, 3, "** . **/##..**///**/  * /* ");
            mvwprintw(box, 6 + 5, 3, "     ##/$$#,#        ((   /");
            mvwprintw(box, 6 + 6, 3, "  /# &@@@@@./.       **&*  ");
            mvwprintw(box, 6 + 7, 3, "    //@@@@@##.#      #.    ");
            mvwprintw(box, 6 + 8, 3, "   ((/ ###(//#//////(      ");
            mvwprintw(box, 6 + 9, 3, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(box, 6, 3, "         ####$*/#           ");
            mvwprintw(box, 6 + 1, 3, "(&&&  ###########@$  *#  @");
            mvwprintw(box, 6 + 2, 3, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(box, 6 + 3, 3, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(box, 6 + 4, 3, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(box, 6 + 5, 3, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(box, 6 + 6, 3, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(box, 6 + 7, 3, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(box, 6 + 8, 3, "     .,(/// $$#$.(####$   ");
            mvwprintw(box, 6 + 9, 3, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(box, 6, 1, "           $$       $         ");
            mvwprintw(box, 6 + 1, 1, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(box, 6 + 2, 1, "   ((. $***.******.**(***(  ");
            mvwprintw(box, 6 + 3, 1, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(box, 6 + 4, 1, "    #(($(@$$($$$($((@(      ");
            mvwprintw(box, 6 + 5, 1, " (,(((($(((((,,(((((((((,,,@");
            mvwprintw(box, 6 + 6, 1, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(box, 6 + 7, 1, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(box, 6 + 8, 1, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(box, 6 + 9, 1, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(box, 6, 5, "    $             ");
            mvwprintw(box, 6 + 1, 5, "   &&& &        ");
            mvwprintw(box, 6 + 2, 5, "     &&& $.     ");
            mvwprintw(box, 6 + 3, 5, ".       *   &   ");
            mvwprintw(box, 6 + 4, 5, "(*.*,. &&     * ");
            mvwprintw(box, 6 + 5, 5, ".$$$$&#        ,");
            mvwprintw(box, 6 + 6, 5, ".&*&&&$$        ");
            mvwprintw(box, 6 + 7, 5, " &@@@@$&$      ,");
            mvwprintw(box, 6 + 8, 5, " ($$@@&$$.**.   ");
            mvwprintw(box, 6 + 9, 5, ".,.   .**      ");
            break;

        default:
            break;
        }
        break;

    case 4:
        switch (player.poke4.art_box)
        {
        case CHARMANDER:
            mvwprintw(box, 6, 4, "   $$$          ");
            mvwprintw(box, 6 + 1, 4, " $$$$$##          ");
            mvwprintw(box, 6 + 2, 4, "*$$$$$,*          ");
            mvwprintw(box, 6 + 3, 4, "#,$$$. (        # ");
            mvwprintw(box, 6 + 4, 4, "   ###(#$      ###");
            mvwprintw(box, 6 + 5, 4, "$$#@@@@$$$$(   &&(");
            mvwprintw(box, 6 + 6, 4, "   @@@&@$$      $ ");
            mvwprintw(box, 6 + 7, 4, " &$&&&&&&$$#(((#  ");
            mvwprintw(box, 6 + 8, 4, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(box, 6, 3, "    .&$$$$#          ");
            mvwprintw(box, 6 + 1, 3, "   *$$$$ ,#((        ");
            mvwprintw(box, 6 + 2, 3, "   ( (((.*((*        ");
            mvwprintw(box, 6 + 3, 3, "    $$((((,((        ");
            mvwprintw(box, 6 + 4, 3, ",$$#&&$..$$#((#      ");
            mvwprintw(box, 6 + 5, 3, "   &&&.&*((#$((      ");
            mvwprintw(box, 6 + 6, 3, "   $&&&&&#$$$/ ###(((");
            mvwprintw(box, 6 + 7, 3, "  $#((###$$$$((((((( ");
            mvwprintw(box, 6 + 8, 3, "          ((((       ");
            break;

        case BULBASAUR:
            mvwprintw(box, 6, 2, "           $$########(  ");
            mvwprintw(box, 6 + 1, 2, "   $#   .(## $######(/  ");
            mvwprintw(box, 6 + 2, 2, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(box, 6 + 3, 2, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(box, 6 + 4, 2, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(box, 6 + 5, 2, "(.#$$$$######(((((((((/ ");
            mvwprintw(box, 6 + 6, 2, "   #/((((((,($#$$##//(( ");
            mvwprintw(box, 6 + 7, 2, "   (((#( ((((.$$#(((((( ");
            mvwprintw(box, 6 + 8, 2, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(box, 6, 3, "   .");
            mvwprintw(box, 6 + 1, 3, " #@.     ./,**");
            mvwprintw(box, 6 + 2, 3, " .$@@@$#&$#     .&/ ");
            mvwprintw(box, 6 + 3, 3, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(box, 6 + 4, 3, " #$$//$$($..#$$&&&* ");
            mvwprintw(box, 6 + 5, 3, "  &&$$$#$&&  *#");
            mvwprintw(box, 6 + 6, 3, " /&(&&/&&#&.((,");
            mvwprintw(box, 6 + 7, 3, "(&$$&&&$&&$$.,");
            mvwprintw(box, 6 + 8, 3, " /$#(//$$$$/");
            mvwprintw(box, 6 + 9, 3, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(box, 6, 3, "    ,           #            ");
            mvwprintw(box, 6 + 1, 3, "  .(  (       (***#,       ");
            mvwprintw(box, 6 + 2, 3, "/*####,      ..***///*#    ");
            mvwprintw(box, 6 + 3, 3, "*,###(//   #.**/**,/////., ");
            mvwprintw(box, 6 + 4, 3, "** . **/##..**///**/  * /* ");
            mvwprintw(box, 6 + 5, 3, "     ##/$$#,#        ((   /");
            mvwprintw(box, 6 + 6, 3, "  /# &@@@@@./.       **&*  ");
            mvwprintw(box, 6 + 7, 3, "    //@@@@@##.#      #.    ");
            mvwprintw(box, 6 + 8, 3, "   ((/ ###(//#//////(      ");
            mvwprintw(box, 6 + 9, 3, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(box, 6, 3, "         ####$*/#           ");
            mvwprintw(box, 6 + 1, 3, "(&&&  ###########@$  *#  @");
            mvwprintw(box, 6 + 2, 3, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(box, 6 + 3, 3, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(box, 6 + 4, 3, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(box, 6 + 5, 3, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(box, 6 + 6, 3, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(box, 6 + 7, 3, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(box, 6 + 8, 3, "     .,(/// $$#$.(####$   ");
            mvwprintw(box, 6 + 9, 3, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(box, 6, 1, "           $$       $         ");
            mvwprintw(box, 6 + 1, 1, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(box, 6 + 2, 1, "   ((. $***.******.**(***(  ");
            mvwprintw(box, 6 + 3, 1, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(box, 6 + 4, 1, "    #(($(@$$($$$($((@(      ");
            mvwprintw(box, 6 + 5, 1, " (,(((($(((((,,(((((((((,,,@");
            mvwprintw(box, 6 + 6, 1, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(box, 6 + 7, 1, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(box, 6 + 8, 1, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(box, 6 + 9, 1, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(box, 6, 5, "    $             ");
            mvwprintw(box, 6 + 1, 5, "   &&& &        ");
            mvwprintw(box, 6 + 2, 5, "     &&& $.     ");
            mvwprintw(box, 6 + 3, 5, ".       *   &   ");
            mvwprintw(box, 6 + 4, 5, "(*.*,. &&     * ");
            mvwprintw(box, 6 + 5, 5, ".$$$$&#        ,");
            mvwprintw(box, 6 + 6, 5, ".&*&&&$$        ");
            mvwprintw(box, 6 + 7, 5, " &@@@@$&$      ,");
            mvwprintw(box, 6 + 8, 5, " ($$@@&$$.**.   ");
            mvwprintw(box, 6 + 9, 5, ".,.   .**      ");
            break;

        default:
            break;
        }
        break;

    case 5:
        switch (player.poke5.art_box)
        {
        case CHARMANDER:
            mvwprintw(box, 6, 4, "   $$$          ");
            mvwprintw(box, 6 + 1, 4, " $$$$$##          ");
            mvwprintw(box, 6 + 2, 4, "*$$$$$,*          ");
            mvwprintw(box, 6 + 3, 4, "#,$$$. (        # ");
            mvwprintw(box, 6 + 4, 4, "   ###(#$      ###");
            mvwprintw(box, 6 + 5, 4, "$$#@@@@$$$$(   &&(");
            mvwprintw(box, 6 + 6, 4, "   @@@&@$$      $ ");
            mvwprintw(box, 6 + 7, 4, " &$&&&&&&$$#(((#  ");
            mvwprintw(box, 6 + 8, 4, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(box, 6, 3, "    .&$$$$#          ");
            mvwprintw(box, 6 + 1, 3, "   *$$$$ ,#((        ");
            mvwprintw(box, 6 + 2, 3, "   ( (((.*((*        ");
            mvwprintw(box, 6 + 3, 3, "    $$((((,((        ");
            mvwprintw(box, 6 + 4, 3, ",$$#&&$..$$#((#      ");
            mvwprintw(box, 6 + 5, 3, "   &&&.&*((#$((      ");
            mvwprintw(box, 6 + 6, 3, "   $&&&&&#$$$/ ###(((");
            mvwprintw(box, 6 + 7, 3, "  $#((###$$$$((((((( ");
            mvwprintw(box, 6 + 8, 3, "          ((((       ");
            break;

        case BULBASAUR:
            mvwprintw(box, 6, 2, "           $$########(  ");
            mvwprintw(box, 6 + 1, 2, "   $#   .(## $######(/  ");
            mvwprintw(box, 6 + 2, 2, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(box, 6 + 3, 2, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(box, 6 + 4, 2, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(box, 6 + 5, 2, "(.#$$$$######(((((((((/ ");
            mvwprintw(box, 6 + 6, 2, "   #/((((((,($#$$##//(( ");
            mvwprintw(box, 6 + 7, 2, "   (((#( ((((.$$#(((((( ");
            mvwprintw(box, 6 + 8, 2, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(box, 6, 3, "   .");
            mvwprintw(box, 6 + 1, 3, " #@.     ./,**");
            mvwprintw(box, 6 + 2, 3, " .$@@@$#&$#     .&/ ");
            mvwprintw(box, 6 + 3, 3, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(box, 6 + 4, 3, " #$$//$$($..#$$&&&* ");
            mvwprintw(box, 6 + 5, 3, "  &&$$$#$&&  *#");
            mvwprintw(box, 6 + 6, 3, " /&(&&/&&#&.((,");
            mvwprintw(box, 6 + 7, 3, "(&$$&&&$&&$$.,");
            mvwprintw(box, 6 + 8, 3, " /$#(//$$$$/");
            mvwprintw(box, 6 + 9, 3, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(box, 6, 3, "    ,           #            ");
            mvwprintw(box, 6 + 1, 3, "  .(  (       (***#,       ");
            mvwprintw(box, 6 + 2, 3, "/*####,      ..***///*#    ");
            mvwprintw(box, 6 + 3, 3, "*,###(//   #.**/**,/////., ");
            mvwprintw(box, 6 + 4, 3, "** . **/##..**///**/  * /* ");
            mvwprintw(box, 6 + 5, 3, "     ##/$$#,#        ((   /");
            mvwprintw(box, 6 + 6, 3, "  /# &@@@@@./.       **&*  ");
            mvwprintw(box, 6 + 7, 3, "    //@@@@@##.#      #.    ");
            mvwprintw(box, 6 + 8, 3, "   ((/ ###(//#//////(      ");
            mvwprintw(box, 6 + 9, 3, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(box, 6, 3, "         ####$*/#           ");
            mvwprintw(box, 6 + 1, 3, "(&&&  ###########@$  *#  @");
            mvwprintw(box, 6 + 2, 3, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(box, 6 + 3, 3, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(box, 6 + 4, 3, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(box, 6 + 5, 3, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(box, 6 + 6, 3, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(box, 6 + 7, 3, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(box, 6 + 8, 3, "     .,(/// $$#$.(####$   ");
            mvwprintw(box, 6 + 9, 3, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(box, 6, 1, "           $$       $         ");
            mvwprintw(box, 6 + 1, 1, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(box, 6 + 2, 1, "   ((. $***.******.**(***(  ");
            mvwprintw(box, 6 + 3, 1, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(box, 6 + 4, 1, "    #(($(@$$($$$($((@(      ");
            mvwprintw(box, 6 + 5, 1, " (,(((($(((((,,(((((((((,,,@");
            mvwprintw(box, 6 + 6, 1, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(box, 6 + 7, 1, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(box, 6 + 8, 1, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(box, 6 + 9, 1, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(box, 6, 5, "    $             ");
            mvwprintw(box, 6 + 1, 5, "   &&& &        ");
            mvwprintw(box, 6 + 2, 5, "     &&& $.     ");
            mvwprintw(box, 6 + 3, 5, ".       *   &   ");
            mvwprintw(box, 6 + 4, 5, "(*.*,. &&     * ");
            mvwprintw(box, 6 + 5, 5, ".$$$$&#        ,");
            mvwprintw(box, 6 + 6, 5, ".&*&&&$$        ");
            mvwprintw(box, 6 + 7, 5, " &@@@@$&$      ,");
            mvwprintw(box, 6 + 8, 5, " ($$@@&$$.**.   ");
            mvwprintw(box, 6 + 9, 5, ".,.   .**      ");
            break;

        default:
            break;
        }
        break;

    case 6:
        switch (player.poke6.art_box)
        {
        case CHARMANDER:
            mvwprintw(box, 6, 4, "   $$$          ");
            mvwprintw(box, 6 + 1, 4, " $$$$$##          ");
            mvwprintw(box, 6 + 2, 4, "*$$$$$,*          ");
            mvwprintw(box, 6 + 3, 4, "#,$$$. (        # ");
            mvwprintw(box, 6 + 4, 4, "   ###(#$      ###");
            mvwprintw(box, 6 + 5, 4, "$$#@@@@$$$$(   &&(");
            mvwprintw(box, 6 + 6, 4, "   @@@&@$$      $ ");
            mvwprintw(box, 6 + 7, 4, " &$&&&&&&$$#(((#  ");
            mvwprintw(box, 6 + 8, 4, " ###     ###      ");
            break;

        case SQUIRTLE:
            mvwprintw(box, 6, 3, "    .&$$$$#          ");
            mvwprintw(box, 6 + 1, 3, "   *$$$$ ,#((        ");
            mvwprintw(box, 6 + 2, 3, "   ( (((.*((*        ");
            mvwprintw(box, 6 + 3, 3, "    $$((((,((        ");
            mvwprintw(box, 6 + 4, 3, ",$$#&&$..$$#((#      ");
            mvwprintw(box, 6 + 5, 3, "   &&&.&*((#$((      ");
            mvwprintw(box, 6 + 6, 3, "   $&&&&&#$$$/ ###(((");
            mvwprintw(box, 6 + 7, 3, "  $#((###$$$$((((((( ");
            mvwprintw(box, 6 + 8, 3, "          ((((       ");
            break;

        case BULBASAUR:
            mvwprintw(box, 6, 2, "           $$########(  ");
            mvwprintw(box, 6 + 1, 2, "   $#   .(## $######(/  ");
            mvwprintw(box, 6 + 2, 2, "  $$$(//$#$##$(((((((/( ");
            mvwprintw(box, 6 + 3, 2, "$,$##$$$$$&/$#(#((((((((");
            mvwprintw(box, 6 + 4, 2, "@/#$$$$#$@,@/((((//.((((");
            mvwprintw(box, 6 + 5, 2, "(.#$$$$######(((((((((/ ");
            mvwprintw(box, 6 + 6, 2, "   #/((((((,($#$$##//(( ");
            mvwprintw(box, 6 + 7, 2, "   (((#( ((((.$$#(((((( ");
            mvwprintw(box, 6 + 8, 2, "    & #    #$##   $&((  ");
            break;

        case PIKACHU:
            mvwprintw(box, 6, 3, "   .");
            mvwprintw(box, 6 + 1, 3, " #@.     ./,**");
            mvwprintw(box, 6 + 2, 3, " .$@@@$#&$#     .&/ ");
            mvwprintw(box, 6 + 3, 3, " ,#&&&&$(&,  .&&&&&*");
            mvwprintw(box, 6 + 4, 3, " #$$//$$($..#$$&&&* ");
            mvwprintw(box, 6 + 5, 3, "  &&$$$#$&&  *#");
            mvwprintw(box, 6 + 6, 3, " /&(&&/&&#&.((,");
            mvwprintw(box, 6 + 7, 3, "(&$$&&&$&&$$.,");
            mvwprintw(box, 6 + 8, 3, " /$#(//$$$$/");
            mvwprintw(box, 6 + 9, 3, "   ``   `` ");
            break;

        case CHARIZARD:
            mvwprintw(box, 6, 3, "    ,           #            ");
            mvwprintw(box, 6 + 1, 3, "  .(  (       (***#,       ");
            mvwprintw(box, 6 + 2, 3, "/*####,      ..***///*#    ");
            mvwprintw(box, 6 + 3, 3, "*,###(//   #.**/**,/////., ");
            mvwprintw(box, 6 + 4, 3, "** . **/##..**///**/  * /* ");
            mvwprintw(box, 6 + 5, 3, "     ##/$$#,#        ((   /");
            mvwprintw(box, 6 + 6, 3, "  /# &@@@@@./.       **&*  ");
            mvwprintw(box, 6 + 7, 3, "    //@@@@@##.#      #.    ");
            mvwprintw(box, 6 + 8, 3, "   ((/ ###(//#//////(      ");
            mvwprintw(box, 6 + 9, 3, "   ..//     /*/");
            break;

        case BLASTOISE:
            mvwprintw(box, 6, 3, "         ####$*/#           ");
            mvwprintw(box, 6 + 1, 3, "(&&&  ###########@$  *#  @");
            mvwprintw(box, 6 + 2, 3, "  ((,&@&&&&&@$&#.@@@.&((* ");
            mvwprintw(box, 6 + 3, 3, "   .# #/.#$$( #.,##$#@..* ");
            mvwprintw(box, 6 + 4, 3, "   .//.@&&&@@@@$####.@//  ");
            mvwprintw(box, 6 + 5, 3, "     /&&&&&@@@@/,   @@@(  ");
            mvwprintw(box, 6 + 6, 3, "       #&&&&&&&&&&&@(@@@  ");
            mvwprintw(box, 6 + 7, 3, "     /// ###$@&&@*$$$##$(*");
            mvwprintw(box, 6 + 8, 3, "     .,(/// $$#$.(####$   ");
            mvwprintw(box, 6 + 9, 3, "    .//*$#        //,#/@ ");
            break;

        case VENUSAUR:
            mvwprintw(box, 6, 1, "           $$       $         ");
            mvwprintw(box, 6 + 1, 1, "     .###$,,@.&/.$#$$,*     ");
            mvwprintw(box, 6 + 2, 1, "   ((. $***.******.**(***(  ");
            mvwprintw(box, 6 + 3, 1, "    @(*((* $$(($@*..((.,    ");
            mvwprintw(box, 6 + 4, 1, "    #(($(@$$($$$($((@(      ");
            mvwprintw(box, 6 + 5, 1, " (,(((($(((((,,(((((((((,,,@");
            mvwprintw(box, 6 + 6, 1, "   @(*$,,,,**((#$#####,@$$  ");
            mvwprintw(box, 6 + 7, 1, ",((**#*(*(((#*((((($/###//$ ");
            mvwprintw(box, 6 + 8, 1, "((**(***(((((##(((#$/#/@//$ ");
            mvwprintw(box, 6 + 9, 1, "((((#$(#((($#### $/#**** @@");
            break;

        case RAICHU:
            mvwprintw(box, 6, 5, "    $             ");
            mvwprintw(box, 6 + 1, 5, "   &&& &        ");
            mvwprintw(box, 6 + 2, 5, "     &&& $.     ");
            mvwprintw(box, 6 + 3, 5, ".       *   &   ");
            mvwprintw(box, 6 + 4, 5, "(*.*,. &&     * ");
            mvwprintw(box, 6 + 5, 5, ".$$$$&#        ,");
            mvwprintw(box, 6 + 6, 5, ".&*&&&$$        ");
            mvwprintw(box, 6 + 7, 5, " &@@@@$&$      ,");
            mvwprintw(box, 6 + 8, 5, " ($$@@&$$.**.   ");
            mvwprintw(box, 6 + 9, 5, ".,.   .**      ");
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}

void print_yourteam(WINDOW *box1, WINDOW *box2, WINDOW *box3, WINDOW *box4, WINDOW *box5, WINDOW *box6, trainer *player, int x, int y)
{
    int i;

    wclear(box1);
    wclear(box2);
    wclear(box3);
    wclear(box4);
    wclear(box5);
    wclear(box6);

    box(box1, 0, 0);
    box(box2, 0, 0);
    box(box3, 0, 0);
    box(box4, 0, 0);
    box(box5, 0, 0);
    box(box6, 0, 0);

    if (x == 1)
    {
        switch (y)
        {
        case 1:
            mvwprintw(box1, 17, 22, "  ,");
            mvwprintw(box1, 17 + 1, 22, ".:::.");
            break;

        case 2:
            mvwprintw(box2, 17, 22, "  ,");
            mvwprintw(box2, 17 + 1, 22, ".:::.");
            break;

        case 3:
            mvwprintw(box3, 17, 22, "  ,");
            mvwprintw(box3, 17 + 1, 22, ".:::.");
            break;

        default:
            break;
        }
    }

    if (x == 2)
    {
        switch (y)
        {
        case 1:
            mvwprintw(box4, 17, 22, "  ,");
            mvwprintw(box4, 17 + 1, 22, ".:::.");
            break;

        case 2:
            mvwprintw(box5, 17, 22, "  ,");
            mvwprintw(box5, 17 + 1, 22, ".:::.");
            break;

        case 3:
            mvwprintw(box6, 17, 22, "  ,");
            mvwprintw(box6, 17 + 1, 22, ".:::.");
            break;

        default:
            break;
        }
    }

    // box1
    print_art_box(box1, *player, 1);

    mvwprintw(box1, 3, 4, "%s", player->poke1.name);
    if (player->poke1.type != 0)
    {
        mvwprintw(box1, 3, 40, "lvl %d", player->poke1.lvl);
        mvwprintw(box1, 7, 30, "HP : %.1f/%.1f", player->poke1.pv, player->poke1.pv_save);
        mvwprintw(box1, 8, 30, "ATK : %.1f", player->poke1.atk);
        mvwprintw(box1, 9, 30, "DEF : %.1f", player->poke1.def * 100);
        mvwprintw(box1, 10, 30, "DODGE : %.1f", player->poke1.dodge);
        mvwprintw(box1, 12, 30, "UTILITARY : %s", player->poke1.CTutil->name);
        mvwprintw(box1, 13, 30, "STAT : %s", player->poke1.CTstat->name);
        mvwprintw(box1, 18, 31, "In your duel team");
    }

    // box2
    print_art_box(box2, *player, 2);

    mvwprintw(box2, 3, 4, "%s", player->poke2.name);
    if (player->poke2.type != 0)
    {
        mvwprintw(box2, 3, 40, "lvl %d", player->poke2.lvl);
        mvwprintw(box2, 7, 30, "HP : %.1f/%.1f", player->poke2.pv, player->poke2.pv_save);
        mvwprintw(box2, 8, 30, "ATK : %.1f", player->poke2.atk);
        mvwprintw(box2, 9, 30, "DEF : %.1f", player->poke2.def * 100);
        mvwprintw(box2, 10, 30, "DODGE : %.1f", player->poke2.dodge);
        mvwprintw(box2, 12, 30, "UTILITARY : %s", player->poke2.CTutil->name);
        mvwprintw(box2, 13, 30, "STAT : %s", player->poke2.CTstat->name);
        mvwprintw(box2, 18, 31, "In your duel team");
    }

    // box3
    print_art_box(box3, *player, 3);

    mvwprintw(box3, 3, 4, "%s", player->poke3.name);
    if (player->poke3.type != 0)
    {
        mvwprintw(box3, 3, 40, "lvl %d", player->poke3.lvl);
        mvwprintw(box3, 7, 30, "HP : %.1f/%.1f", player->poke3.pv, player->poke3.pv_save);
        mvwprintw(box3, 8, 30, "ATK : %.1f", player->poke3.atk);
        mvwprintw(box3, 9, 30, "DEF : %.1f", player->poke3.def * 100);
        mvwprintw(box3, 10, 30, "DODGE : %.1f", player->poke3.dodge);
        mvwprintw(box3, 12, 30, "UTILITARY : %s", player->poke3.CTutil->name);
        mvwprintw(box3, 13, 30, "STAT : %s", player->poke3.CTstat->name);
        mvwprintw(box3, 18, 31, "In your duel team");
    }

    // box4
    print_art_box(box4, *player, 4);

    mvwprintw(box4, 3, 4, "%s", player->poke4.name);
    if (player->poke4.type != 0)
    {
        mvwprintw(box4, 3, 40, "lvl %d", player->poke4.lvl);
        mvwprintw(box4, 7, 30, "HP : %.1f/%.1f", player->poke4.pv, player->poke4.pv_save);
        mvwprintw(box4, 8, 30, "ATK : %.1f", player->poke4.atk);
        mvwprintw(box4, 9, 30, "DEF : %.1f", player->poke4.def * 100);
        mvwprintw(box4, 10, 30, "DODGE : %.1f", player->poke4.dodge);
        mvwprintw(box4, 12, 30, "UTILITARY : %s", player->poke4.CTutil->name);
        mvwprintw(box4, 13, 30, "STAT : %s", player->poke4.CTstat->name);
    }

    // box5
    print_art_box(box5, *player, 5);

    mvwprintw(box5, 3, 4, "%s", player->poke5.name);
    if (player->poke5.type != 0)
    {
        mvwprintw(box5, 3, 40, "lvl %d", player->poke5.lvl);
        mvwprintw(box5, 7, 30, "HP : %.1f/%.1f", player->poke5.pv, player->poke5.pv_save);
        mvwprintw(box5, 8, 30, "ATK : %.1f", player->poke5.atk);
        mvwprintw(box5, 9, 30, "DEF : %.1f", player->poke5.def * 100);
        mvwprintw(box5, 10, 30, "DODGE : %.1f", player->poke5.dodge);
        mvwprintw(box5, 12, 30, "UTILITARY : %s", player->poke5.CTutil->name);
        mvwprintw(box5, 13, 30, "STAT : %s", player->poke5.CTstat->name);
    }

    // box6
    print_art_box(box6, *player, 6);

    mvwprintw(box6, 3, 4, "%s", player->poke6.name);
    if (player->poke6.type != 0)
    {
        mvwprintw(box6, 3, 40, "lvl %d", player->poke6.lvl);
        mvwprintw(box6, 7, 30, "HP : %.1f/%.1f", player->poke6.pv, player->poke6.pv_save);
        mvwprintw(box6, 8, 30, "ATK : %.1f", player->poke6.atk);
        mvwprintw(box6, 9, 30, "DEF : %.1f", player->poke6.def * 100);
        mvwprintw(box6, 10, 30, "DODGE : %.1f", player->poke6.dodge);
        mvwprintw(box6, 12, 30, "UTILITARY : %s", player->poke6.CTutil->name);
        mvwprintw(box6, 13, 30, "STAT : %s", player->poke6.CTstat->name);
    }

    wrefresh(box1);
    wrefresh(box2);
    wrefresh(box3);
    wrefresh(box4);
    wrefresh(box5);
    wrefresh(box6);
}

void print_main_menu(WINDOW *win, int x, int y)
{
    mvwprintw(win, 5, 55, " _       __________    __________  __  _________   __________     ______            ____  ____  __ __ ________  _______  _   __   __");
    mvwprintw(win, 5 + 1, 55, "| |     / / ____/ /   / ____/ __ \\/  |/  / ____/  /_  __/ __ \\   / ____/           / __ \\/ __ \\/ //_// ____/  |/  / __ \\/ | / /  / /");
    mvwprintw(win, 5 + 2, 55, "| | /| / / __/ / /   / /   / / / / /|_/ / __/      / / / / / /  / /      ______   / /_/ / / / / ,<  / __/ / /|_/ / / / /  |/ /  / / ");
    mvwprintw(win, 5 + 3, 55, "| |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___     / / / /_/ /  / /___   /_____/  / ____/ /_/ / /| |/ /___/ /  / / /_/ / /|  /  /_/  ");
    mvwprintw(win, 5 + 4, 55, "|__/|__/_____/_____/\\____/\\____/_/  /_/_____/    /_/  \\____/   \\____/           /_/    \\____/_/ |_/_____/_/  /_/\\____/_/ |_/  (_)   ");

    mvwprintw(win, 20, 130, "                         &&@&@#                                                                    ");
    mvwprintw(win, 20 + 1, 130, "                         &&&&@&..*.                                                                ");
    mvwprintw(win, 20 + 2, 130, "                          .@&@/....,,&                                                           ,(");
    mvwprintw(win, 20 + 3, 130, "                            #@*.........#                                               ,(.&@@&&@@ ");
    mvwprintw(win, 20 + 4, 130, "                              #..........,,/                                       ./......,@&@&.  ");
    mvwprintw(win, 20 + 5, 130, "                                ,,...........@                                 *,.........,(@&.    ");
    mvwprintw(win, 20 + 6, 130, "                                   #,..........#    ,#@(((((##*.            #,,..........,,&       ");
    mvwprintw(win, 20 + 7, 130, "           @..&                       &*.......,..,................,.@   @,,............(          ");
    mvwprintw(win, 20 + 8, 130, "         #,......,.(*                    ./,*,..........................,,..........,(             ");
    mvwprintw(win, 20 + 9, 130, "       #,...........,.../,                 ,,,............................,,..,,@                  ");
    mvwprintw(win, 20 + 10, 130, "      .,.................,,,,@            *,..,.,..,......................,./                      ");
    mvwprintw(win, 20 + 11, 130, "    #............................,/      #..,.(&@   #...............,........                      ");
    mvwprintw(win, 20 + 12, 130, "   ..,................................@  *..,.&&@&@&&.,............&  ,@&...,                      ");
    mvwprintw(win, 20 + 13, 130, " /.,............................,.,...,.#.,.,,..*@*,,....,.,,,..../&&@&&&,..,                      ");
    mvwprintw(win, 20 + 14, 130, "#,...........................#,,...,...(#(((((@.,..,,.,..,..........#&&(,...*                      ");
    mvwprintw(win, 20 + 15, 130, "   #************************(........,@#(((((((#......@@@&&&@&&&,..........,,                      ");
    mvwprintw(win, 20 + 16, 130, "            .#(**************#..........,(((((@.....,.########@#.....,#((((((*                     ");
    mvwprintw(win, 20 + 17, 130, "                      .##*****/...........,(.,.......,#//////(/.....,,(((((((.                     ");
    mvwprintw(win, 20 + 18, 130, "                               (,............*.........#*///(..........#(((@                       ");
    mvwprintw(win, 20 + 19, 130, "                              @*(...........,.*........,.*.,,.........,./                          ");
    mvwprintw(win, 20 + 20, 130, "                            *******,................................,/*                            ");
    mvwprintw(win, 20 + 21, 130, "                           ********#.................******,,.....,,,.,(                           ");
    mvwprintw(win, 20 + 22, 130, "                         @********(  .,...................,..,..,........                          ");
    mvwprintw(win, 20 + 23, 130, "                         .@***********#*#,.,.................,,.........@                          ");
    mvwprintw(win, 20 + 24, 130, "                               .#*****,.,....................,,.........*                          ");
    mvwprintw(win, 20 + 25, 130, "                                 (***@,.....................,#,.........#                          ");
    mvwprintw(win, 20 + 26, 130, "                               @###/&........................,........,,*                          ");
    mvwprintw(win, 20 + 27, 130, "                             (@#####,.....(/#*,.............,.........,((*                         ");
    mvwprintw(win, 20 + 28, 130, "                                 ,@#...,..,(#,,.,*...........,.....,.,/,..,@(,,@                   ");
    mvwprintw(win, 20 + 29, 130, "                                   ......./,**.,,...........,#.,,.,..(..,,/.***                    ");
    mvwprintw(win, 20 + 30, 130, "                                   .......******................,.*.,..../****/                    ");
    mvwprintw(win, 20 + 31, 130, "                                   /.....**#****@**,.,**********,,......*****,                     ");
    mvwprintw(win, 20 + 32, 130, "                                    #***************************************                       ");
    mvwprintw(win, 20 + 33, 130, "                                       @**********************************/                        ");
    mvwprintw(win, 20 + 34, 130, "                                              #*(                     *(                           ");

    mvwprintw(win, 28, 30, " ___           _                                         _             _                ");
    mvwprintw(win, 28 + 1, 30, "| _ ) ___ __ _(_)_ _    __ _   _ _  _____ __ __  __ _ __| |_ _____ _ _| |_ _  _ _ _ ___ ");
    mvwprintw(win, 28 + 2, 30, "| _ \\/ -_) _` | | ' \\  / _` | | ' \\/ -_) V  V / / _` / _` \\ V / -_) ' \\  _| || | '_/ -_)");
    mvwprintw(win, 28 + 3, 30, "|___/\\___\\__, |_|_||_| \\__,_| |_||_\\___|\\_/\\_/  \\__,_\\__,_|\\_/\\___|_||_\\__|\\_,_|_| \\___|");
    mvwprintw(win, 28 + 4, 30, "         |___/                                                                                         ");

    mvwprintw(win, 38, 30, " _                 _                                           _          ");
    mvwprintw(win, 38 + 1, 30, "| |   ___  __ _ __| |  __ _   _ __ _ _ ___  __ _ _ _ ___ _____(_)___ _ _  ");
    mvwprintw(win, 38 + 2, 30, "| |__/ _ \\/ _` / _` | / _` | | '_ \\ '_/ _ \\/ _` | '_/ -_|_-<_-< / _ \\ ' \\ ");
    mvwprintw(win, 38 + 3, 30, "|____\\___/\\__,_\\__,_| \\__,_| | .__/_| \\___/\\__, |_| \\___/__/__/_\\___/_||_|");
    mvwprintw(win, 38 + 4, 30, "                             |_|           |___/                          ");

    mvwprintw(win, x, y, "        :'");
    mvwprintw(win, x + 1, y, "::::::::;;:'");
    mvwprintw(win, x + 2, y, "::::::::;;;;.");
    mvwprintw(win, x + 3, y, "........;;.");
    mvwprintw(win, x + 4, y, "        .");
}

void create_map(WINDOW *map, trainer *player)
{

    // repérage : x_map = x_cadre + 29      y_map = y_cadre + 116

    mvwprintw(map, 32, 120, "        ________| |________");
    mvwprintw(map, 32 + 1, 120, "       /                  /\\");
    mvwprintw(map, 32 + 2, 120, "      /       ______     /  \\");
    mvwprintw(map, 32 + 3, 120, "     /       /\\    /    /    \\");
    mvwprintw(map, 32 + 4, 120, "    /       /  /__/    /      \\");
    mvwprintw(map, 32 + 5, 120, "   /        |[]| /    /        \\");
    mvwprintw(map, 32 + 6, 120, "  /         |__|/    /==========\\");
    mvwprintw(map, 32 + 7, 120, " /__________________/   HOME   I_\\");
    mvwprintw(map, 32 + 8, 120, "    I      _____         __    I");
    mvwprintw(map, 32 + 9, 120, "    I     |__|__|  ___  |[]|   I");
    mvwprintw(map, 32 + 10, 120, "    I     |__|__| |_1_| | -|   I"); // line = 9, col = 38  (+- 1)
    mvwprintw(map, 32 + 11, 120, "    I      XXXXX    |   |__|   I");
    mvwprintw(map, 32 + 12, 120, "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map, 34, 343, "                     ____");
    mvwprintw(map, 34 + 1, 343, "  ___________________|  |______");
    mvwprintw(map, 34 + 2, 343, " /     LAB                     \\ ");
    mvwprintw(map, 34 + 3, 343, "/_______________________________\\");
    mvwprintw(map, 34 + 4, 343, "  |||||||||||||||||||||||||||||");
    mvwprintw(map, 34 + 5, 343, "  ||___|___||||||||||||___|__||");
    mvwprintw(map, 34 + 6, 343, "  ||___|___||||||||||||___|__||");
    mvwprintw(map, 34 + 7, 343, "  |||||||||||||    ||||||||||||");
    mvwprintw(map, 34 + 8, 343, "  |||||||||||||   -||||||||||||"); // line = 9, col = 218  (+- 1)
    mvwprintw(map, 34 + 9, 343, "  |||||||||||||    ||||||||||||");
    mvwprintw(map, 34 + 10, 343, " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map, 74, 121, "  _____________________________ ");
    mvwprintw(map, 74 + 1, 121, " |                             |");
    mvwprintw(map, 74 + 2, 121, " |    SHOP  ________           |");
    mvwprintw(map, 74 + 3, 121, " |         | .''''. |          |");
    mvwprintw(map, 74 + 4, 121, " |_________| :-()-: |__________|");
    mvwprintw(map, 74 + 5, 121, "  | ______ | ',,,,' | _______ |");
    mvwprintw(map, 74 + 6, 121, "  ||  |   ||  ____  ||   |   ||");
    mvwprintw(map, 74 + 7, 121, "  ||--+---|| |    | ||---+---||");
    mvwprintw(map, 74 + 8, 121, "  ||__|___|| |   -| ||___|___||"); // line = 49, col = 38  (+- 1)
    mvwprintw(map, 74 + 9, 121, "  |________|_|____|_|_________|");
    mvwprintw(map, 74 + 10, 121, " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map, 104 - 3, 117, " ______________");
    mvwprintw(map, 104 - 2, 117, "|__THE_LEAGUE__|");
    mvwprintw(map, 104 - 1, 117, "        |  ");
    mvwprintw(map, 104, 115, "===");
    mvwprintw(map, 104 + 1, 116, " ");
    mvwprintw(map, 104 + 2, 116, " ");
    mvwprintw(map, 104 + 3, 116, " ");
    mvwprintw(map, 104 + 4, 116, " "); // line = 25, col = 256 (+- 1)
    mvwprintw(map, 104 + 5, 116, " ");
    mvwprintw(map, 104 + 6, 116, " ");
    mvwprintw(map, 104 + 7, 116, " ");
    mvwprintw(map, 104 + 8, 115, "===");

    if (player->is_rock_there == 0)
    {
        mvwprintw(map, 54 - 3, 365, " ______________");
        mvwprintw(map, 54 - 2, 365, "|__THE_FOREST__|");
        mvwprintw(map, 54 - 1, 365, "        |  ");
        mvwprintw(map, 54, 380, "===");
        mvwprintw(map, 54 + 1, 381, " ");
        mvwprintw(map, 54 + 2, 381, " ");
        mvwprintw(map, 54 + 3, 381, " ");
        mvwprintw(map, 54 + 4, 381, " "); // line = 25, col = 256 (+- 1)
        mvwprintw(map, 54 + 5, 381, " ");
        mvwprintw(map, 54 + 6, 381, " ");
        mvwprintw(map, 54 + 7, 381, " ");
        mvwprintw(map, 54 + 8, 380, "===");
    }
    else
    {
        mvwprintw(map, 54 - 3, 365, " ______________");
        mvwprintw(map, 54 - 2, 365, "|__THE_FOREST__|");
        mvwprintw(map, 54 - 1, 365, "        |  ");
        mvwprintw(map, 54, 380, "===");
        mvwprintw(map, 54 + 1, 372, "   (#$#####$$##/(  ");
        mvwprintw(map, 54 + 2, 372, "  ###($(((#$(((((( ");
        mvwprintw(map, 54 + 3, 372, "  /#$$$#(#($##((#(#");
        mvwprintw(map, 54 + 4, 372, " #####(#(#$##((((#("); // line = 25, col = 256 (+- 1)
        mvwprintw(map, 54 + 5, 372, " ($#((#(//(##,,.#  ");
        mvwprintw(map, 54 + 6, 372, "/(###$(###/(####(  ");
        mvwprintw(map, 54 + 7, 372, "#((###((((#(((($( ");
        mvwprintw(map, 54 + 8, 380, "===");
    }

    mvwprintw(map, 122, 120, "        ________| |________");
    mvwprintw(map, 122 + 1, 120, "       /                  /\\");
    mvwprintw(map, 122 + 2, 120, "      /       ______     /  \\");
    mvwprintw(map, 122 + 3, 120, "     /       /\\    /    /    \\");
    mvwprintw(map, 122 + 4, 120, "    /       /  /__/    /      \\");
    mvwprintw(map, 122 + 5, 120, "   /        |[]| /    /        \\");
    mvwprintw(map, 122 + 6, 120, "  /         |__|/    /==========\\");
    mvwprintw(map, 122 + 7, 120, " /__________________/          I_\\");
    mvwprintw(map, 122 + 8, 120, "    I      _____         __    I");
    mvwprintw(map, 122 + 9, 120, "    I     |__|__|  ___  |[]|   I");
    mvwprintw(map, 122 + 10, 120, "    I     |__|__| |_2_| | -|   I");
    mvwprintw(map, 122 + 11, 120, "    I      XXXXX    |   |__|   I");
    mvwprintw(map, 122 + 12, 120, "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                                  "~~~");

    mvwprintw(map, 122, 343, "       ________| |________");
    mvwprintw(map, 122 + 1, 343, "      /\\                  \\");
    mvwprintw(map, 122 + 2, 343, "     /  \\     ______       \\");
    mvwprintw(map, 122 + 3, 343, "    /    \\    \\    /\\       \\");
    mvwprintw(map, 122 + 4, 343, "   /      \\    \\__\\  \\       \\");
    mvwprintw(map, 122 + 5, 343, "  /        \\    \\ |[]|        \\");
    mvwprintw(map, 122 + 6, 343, " /==========\\    \\|__|         \\");
    mvwprintw(map, 122 + 7, 343, "/_I          \\__________________\\");
    mvwprintw(map, 122 + 8, 343, "  I    __         _____      I");
    mvwprintw(map, 122 + 9, 343, "  I   |[]|  ___  |__|__|     I");
    mvwprintw(map, 122 + 10, 343, "  I   |- | |_5_| |__|__|     I");
    mvwprintw(map, 122 + 11, 343, "  I   |__|   |    XXXXX      I");
    mvwprintw(map, 122 + 12, 343, " ~~~"
                                  "~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map, 72, 343, "       ________| |________");
    mvwprintw(map, 72 + 1, 343, "      /\\                  \\");
    mvwprintw(map, 72 + 2, 343, "     /  \\     ______       \\");
    mvwprintw(map, 72 + 3, 343, "    /    \\    \\    /\\       \\");
    mvwprintw(map, 72 + 4, 343, "   /      \\    \\__\\  \\       \\");
    mvwprintw(map, 72 + 5, 343, "  /        \\    \\ |[]|        \\");
    mvwprintw(map, 72 + 6, 343, " /==========\\    \\|__|         \\");
    mvwprintw(map, 72 + 7, 343, "/_I          \\__________________\\");
    mvwprintw(map, 72 + 8, 343, "  I    __         _____      I");
    mvwprintw(map, 72 + 9, 343, "  I   |[]|  ___  |__|__|     I");
    mvwprintw(map, 72 + 10, 343, "  I   |- | |_3_| |__|__|     I");
    mvwprintw(map, 72 + 11, 343, "  I   |__|   |    XXXXX      I");
    mvwprintw(map, 72 + 12, 343, " ~~~"
                                 "~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map, 97, 343, "       ________| |________");
    mvwprintw(map, 97 + 1, 343, "      /\\                  \\");
    mvwprintw(map, 97 + 2, 343, "     /  \\     ______       \\");
    mvwprintw(map, 97 + 3, 343, "    /    \\    \\    /\\       \\");
    mvwprintw(map, 97 + 4, 343, "   /      \\    \\__\\  \\       \\");
    mvwprintw(map, 97 + 5, 343, "  /        \\    \\ |[]|        \\");
    mvwprintw(map, 97 + 6, 343, " /==========\\    \\|__|         \\");
    mvwprintw(map, 97 + 7, 343, "/_I          \\__________________\\");
    mvwprintw(map, 97 + 8, 343, "  I    __         _____      I");
    mvwprintw(map, 97 + 9, 343, "  I   |[]|  ___  |__|__|     I");
    mvwprintw(map, 97 + 10, 343, "  I   |- | |_4_| |__|__|     I");
    mvwprintw(map, 97 + 11, 343, "  I   |__|   |    XXXXX      I");
    mvwprintw(map, 97 + 12, 343, " ~~~"
                                 "~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void breaktherock(WINDOW *map, WINDOW *cam, trainer *player)
{
    for (int i = 0; i < 4; i++)
    {
        mvwprintw(map, 54, 380, "===");
        mvwprintw(map, 54 + 1, 372, "   (#$#####$$##/(  ");
        mvwprintw(map, 54 + 2, 372, "  ###($(((#$(((((( ");
        mvwprintw(map, 54 + 3, 372, "  /#$$$#(#($##((#(#");
        mvwprintw(map, 54 + 4, 372, " #####(#(#$##((((#(");
        mvwprintw(map, 54 + 5, 372, " ($#((#(//(##,,.#  ");
        mvwprintw(map, 54 + 6, 372, "/(###$(###/(####(  ");
        mvwprintw(map, 54 + 7, 372, "#((###((((#(((($( ");
        mvwprintw(map, 54 + 8, 380, "===");
        wrefresh(cam);
        usleep(500000);

        mvwprintw(map, 54, 380, "===");
        mvwprintw(map, 54 + 1, 372, "                   ");
        mvwprintw(map, 54 + 2, 372, "                   ");
        mvwprintw(map, 54 + 3, 372, "                   ");
        mvwprintw(map, 54 + 4, 372, "                   ");
        mvwprintw(map, 54 + 5, 372, "                   ");
        mvwprintw(map, 54 + 6, 372, "                   ");
        mvwprintw(map, 54 + 7, 372, "                  ");
        mvwprintw(map, 54 + 8, 380, "===");
        wrefresh(cam);
        usleep(500000);
    }
    player->is_rock_there = 0; // FALSE
}

void print_load(WINDOW *win, FILE *save1r, FILE *save2r, FILE *save3r, FILE *save4r, FILE *save5r, int x)
{

    mvwprintw(win, 8, 150, "                        //*///***/,                  ");
    mvwprintw(win, 8 + 1, 150, "                     *///(//*////////                ");
    mvwprintw(win, 8 + 2, 150, "                    *(*//(*(/ .///(**.               ");
    mvwprintw(win, 8 + 3, 150, "                    *//*(//*... ////*(               ");
    mvwprintw(win, 8 + 4, 150, "                    /((/.$......#*((*/               ");
    mvwprintw(win, 8 + 5, 150, "                    ,**,.#......(..//.               ");
    mvwprintw(win, 8 + 6, 150, "                     /# ... ,..... #(                ");
    mvwprintw(win, 8 + 7, 150, "                     *#(......,...(#,                ");
    mvwprintw(win, 8 + 8, 150, "                    ,($#(#/. . *#((#/                ");
    mvwprintw(win, 8 + 9, 150, "                    ,*($(#,*,,*,(#(,#                ");
    mvwprintw(win, 8 + 10, 150, "                   .*,,....... ....* ,*              ");
    mvwprintw(win, 8 + 11, 150, "                 /((#  /,/(##(#((/,* .(((/.          ");
    mvwprintw(win, 8 + 12, 150, "               .//#((  ///((((//(((. .((((#          ");
    mvwprintw(win, 8 + 13, 150, "              ,(/((#(,,,,,*******,,,*,##(//          ");
    mvwprintw(win, 8 + 14, 150, "              $//((#                  .#(/((         ");
    mvwprintw(win, 8 + 15, 150, "            ////((#( .,,,,,,,,,,,,,,,, $((//.        ");
    mvwprintw(win, 8 + 16, 150, "           /((/(#( ,,,,,,,,,,,,,,,,,,,##(///(        ");
    mvwprintw(win, 8 + 17, 150, "          #(/(((#   ...,.,,,,,,,,,,.,  (#///(/       ");
    mvwprintw(win, 8 + 18, 150, "         ((//(((    ,                ,  #(///(,      ");
    mvwprintw(win, 8 + 19, 150, "       ,(/(/(/,     ,                .  *(///((      ");
    mvwprintw(win, 8 + 20, 150, "      //////(      ...,,   .,*/,   /...  ((//(//     ");
    mvwprintw(win, 8 + 21, 150, "     (/(/(((      /*                . ,.  (((/(/,    ");
    mvwprintw(win, 8 + 22, 150, "   ,*,(((//      /#                   .(.  ((//((    ");
    mvwprintw(win, 8 + 23, 150, "   ..((//       * ,                   . ,  ./((/,$   ");
    mvwprintw(win, 8 + 24, 150, "  ,. ,         .. ,                   ,. .  *(((/.   ");
    mvwprintw(win, 8 + 25, 150, " . ..,         .. ,                   *..*     , .,  ");
    mvwprintw(win, 8 + 26, 150, "**. ,.        , ( .                   *,  .    ...., ");
    mvwprintw(win, 8 + 27, 150, "**           ,., ...                  ., .,     /,/, ");
    mvwprintw(win, 8 + 28, 150, "            , ,,..,,                 *.,...*         ");
    mvwprintw(win, 8 + 29, 150, "           .../ ..*,                 *.., ,.         ");
    mvwprintw(win, 8 + 30, 150, "           ../. .* . .,,*,      .,,** ..*.*./        ");
    mvwprintw(win, 8 + 31, 150, "           .,, .,,...   ..*, ......*..  *..*..       ");
    mvwprintw(win, 8 + 32, 150, "         ..,* ../ ..... .*,,......., ....,./.,       ");
    mvwprintw(win, 8 + 33, 150, "        ,.,/.  ,,. .. .  *,*......,*. .. *. *.,      ");
    mvwprintw(win, 8 + 34, 150, "       ,..,...,/ ........,,.. .....,,... *../.,      ");
    mvwprintw(win, 8 + 35, 150, "      ,..,*.  ,... .. ../,*.. .....*, ... * ., ,     ");
    mvwprintw(win, 8 + 36, 150, "     ,  ./. ../.........*,* .......,, ..../../.,     ");
    mvwprintw(win, 8 + 37, 150, "         ....,,...... ..,,*....... /,........*, ,    ");
    mvwprintw(win, 8 + 38, 150, "          *,**..........,,,. ....../,,... ., .       ");
    mvwprintw(win, 8 + 39, 150, "              ,. ... . ,,,,. ..  ../,,....           ");
    mvwprintw(win, 8 + 40, 150, "                     . , ..*. ...*/                  ");
    mvwprintw(win, 8 + 41, 150, "                     ....,  ***,,/                   ");
    mvwprintw(win, 8 + 42, 150, "                      ....  ***,,.                   ");
    mvwprintw(win, 8 + 43, 150, "                      * .., ....*                    ");
    mvwprintw(win, 8 + 44, 150, "                      *...*,. ..                     ");
    mvwprintw(win, 8 + 45, 150, "                      /....,...*                     ");
    mvwprintw(win, 8 + 46, 150, "                      *. .*.. .*                     ");
    mvwprintw(win, 8 + 47, 150, "                     *..  * ....                     ");
    mvwprintw(win, 8 + 48, 150, "                      .(*,/.. ,.*                    ");
    mvwprintw(win, 8 + 49, 150, "                         .. .    ,                   ");
    mvwprintw(win, 8 + 50, 150, "                          .(/**//                    ");

    mvwprintw(win, 17, 40, "  ___ _                                                               _          ");
    mvwprintw(win, 17 + 1, 40, " / __| |_  ___  ___ ___ ___   __ _   _ __ _ _ ___  __ _ _ _ ___ _____(_)___ _ _  ");
    mvwprintw(win, 17 + 2, 40, "| (__| ' \\/ _ \\/ _ (_-</ -_) / _` | | '_ \\ '_/ _ \\/ _` | '_/ -_|_-<_-< / _ \\ ' \\ ");
    mvwprintw(win, 17 + 3, 40, " \\___|_||_\\___/\\___/__/\\___| \\__,_| | .__/_| \\___/\\__, |_| \\___/__/__/_\\___/_||_|");
    mvwprintw(win, 17 + 4, 40, "                                    |_|           |___/                         ");

    mvwprintw(win, 52, 20, "Press enter/e to load a save");
    mvwprintw(win, 54, 20, "Press x to remove a progression");

    mvwprintw(win, x, 68, ">");

    trainer temp1;
    trainer temp2;
    trainer temp3;
    trainer temp4;
    trainer temp5;

    fseek(save1r, 0, SEEK_END);
    fseek(save2r, 0, SEEK_END);
    fseek(save3r, 0, SEEK_END);
    fseek(save4r, 0, SEEK_END);
    fseek(save5r, 0, SEEK_END);

    int test1 = ftell(save1r);
    int test2 = ftell(save2r);
    int test3 = ftell(save3r);
    int test4 = ftell(save4r);
    int test5 = ftell(save5r);

    if (test1 == 0)
    {
        mvwprintw(win, 29, 70, "Emplacement 1");
    }
    else
    {
        rewind(save1r);
        fread(&temp1, sizeof(trainer), 1, save1r);
        mvwprintw(win, 29, 70, "%s lvl %d", temp1.name, temp1.lvl);
    }

    if (test2 == 0)
    {
        mvwprintw(win, 31, 70, "Emplacement 2");
    }
    else
    {
        rewind(save2r);
        fread(&temp2, sizeof(trainer), 1, save2r);
        mvwprintw(win, 31, 70, "%s lvl %d", temp2.name, temp2.lvl);
    }

    if (test3 == 0)
    {
        mvwprintw(win, 33, 70, "Emplacement 3");
    }
    else
    {
        rewind(save3r);
        fread(&temp3, sizeof(trainer), 1, save3r);
        mvwprintw(win, 33, 70, "%s lvl %d", temp3.name, temp3.lvl);
    }

    if (test4 == 0)
    {
        mvwprintw(win, 35, 70, "Emplacement 4");
    }
    else
    {
        rewind(save4r);
        fread(&temp4, sizeof(trainer), 1, save4r);
        mvwprintw(win, 35, 70, "%s lvl %d", temp4.name, temp4.lvl);
    }

    if (test5 == 0)
    {
        mvwprintw(win, 37, 70, "Emplacement 5");
    }
    else
    {
        rewind(save5r);
        fread(&temp5, sizeof(trainer), 1, save5r);
        mvwprintw(win, 37, 70, "%s lvl %d", temp5.name, temp5.lvl);
    }
}

void print_save(WINDOW *win, FILE *save1r, FILE *save2r, FILE *save3r, FILE *save4r, FILE *save5r, int x)
{

    mvwprintw(win, 2, 140, "                                      /&#                                      ");
    mvwprintw(win, 2 + 1, 140, "                                .(,.        .,(*                               ");
    mvwprintw(win, 2 + 2, 140, "                            $&        *$##(((##(  .(                           ");
    mvwprintw(win, 2 + 3, 140, "                         #((&       *$#$/$###((##,   ..                        ");
    mvwprintw(win, 2 + 4, 140, "                         $(((       ,$((#(//*(#(#,    /                        ");
    mvwprintw(win, 2 + 5, 140, "                         $#((          *#######,      .                        ");
    mvwprintw(win, 2 + 6, 140, "                         $#((    .,/((###(((((#$#(*  .                         ");
    mvwprintw(win, 2 + 7, 140, "                        ,&&&$$$(((((((((((((((((((((((#,                       ");
    mvwprintw(win, 2 + 8, 140, "                    ./#&$$$$$&#/#$&&&$((@&&&&&((&@&#$$$#(#                     ");
    mvwprintw(win, 2 + 9, 140, "                    *&$$$$$$$@,,,* #( *&/$&&(#(&/ $*#$$$$$                     ");
    mvwprintw(win, 2 + 10, 140, "                  ,&&&&&&&/(#,,,,  $@ .,*$,,,,.&$ *,@#&&&&                     ");
    mvwprintw(win, 2 + 11, 140, "                      ,@&&//$//*,,,(#.,,,,,,,,,@#.,,//&&@*                     ");
    mvwprintw(win, 2 + 12, 140, "                      ,@&&&&(///*(,##*,,,,,,(,/,$$*,@&@/                       ");
    mvwprintw(win, 2 + 13, 140, "                ,.  .$#.,/((&&&&(/,,,,,,*/(((/,,,,/.                           ");
    mvwprintw(win, 2 + 14, 140, "           **,,,*(,,,,,*$   .&$$&&$&(*,,,,,,,,,$                               ");
    mvwprintw(win, 2 + 15, 140, "           *,,,$$*,*$#*$&  &&&$$$$$$$##$&##&$$$##$                             ");
    mvwprintw(win, 2 + 16, 140, "          ,$$$$$$$$$$* ..$$$$#($@##&$$$$$(/#(#$$$$$                            ");
    mvwprintw(win, 2 + 17, 140, "        /*$$$$$$#((#$$$#$$$#*,#(#&&#(((#$$$##$$(($@($(                         ");
    mvwprintw(win, 2 + 18, 140, "        $/$$((/$(//##////(&/,,$(((#&@$(((((.,$((#@&(((#(*                      ");
    mvwprintw(win, 2 + 19, 140, "         (#,     ,.    .**$#(#$@#((((#&@@@/../$@&#(((($((*                     ");
    mvwprintw(win, 2 + 20, 140, "           ,/***,********&((((( $@$(((((((#$/#((((((($$((((                    ");
    mvwprintw(win, 2 + 21, 140, "              ,$(////((//($$$&,   ,&@$#((((#.*#(((($@$##(((/                   ");
    mvwprintw(win, 2 + 22, 140, "                /$$&$&$$&$$$#,.      .#@@&$#.,$$&@&, ($$(((($.                 ");
    mvwprintw(win, 2 + 23, 140, "                    /&$ (&@,,,             ,,,/      ,$#(((((($.               ");
    mvwprintw(win, 2 + 24, 140, "                        (,/,.              ,,,/      .$((((((##                ");
    mvwprintw(win, 2 + 25, 140, "                        *  ,       .       ,*,(       $$((#$////*   /####&     ");
    mvwprintw(win, 2 + 26, 140, "                        .  ,      #(#,     ,*,(...,&(,&#(/////,*#,#,,,#$####(  ");
    mvwprintw(win, 2 + 27, 140, "                        ,       /#($.      ,*,(     ###   (*,(,/(,,,,///$####$ ");
    mvwprintw(win, 2 + 28, 140, "                        /  ,  .$(#/        ,,.(      ##.   ,**,(,/*,#,,,*&####.");
    mvwprintw(win, 2 + 29, 140, "                        / ,  $((#.         ,,.(       #(,    **,,#*##,/(,,/&##(");
    mvwprintw(win, 2 + 30, 140, "                       *  #,#($.           *,.(        #(          ../(/#*,(*  ");
    mvwprintw(win, 2 + 31, 140, "                       . (                .(..(          (                     ");
    mvwprintw(win, 2 + 32, 140, "                       (  .,*//***//***,./.,##./         ,                     ");
    mvwprintw(win, 2 + 33, 140, "                       *..             ./.*#((#./       /                      ");
    mvwprintw(win, 2 + 34, 140, "                       .####$#######$$$$$$$##$##$$$$$$$#,                      ");
    mvwprintw(win, 2 + 35, 140, "                       $#$$###############$##$#########&$                      ");
    mvwprintw(win, 2 + 36, 140, "                      *$#################$$$&&$#########$/                     ");
    mvwprintw(win, 2 + 37, 140, "                     .##################&$$$$$$##########$                     ");
    mvwprintw(win, 2 + 38, 140, "                     @$################$$$$$$$$###########*                    ");
    mvwprintw(win, 2 + 39, 140, "                    *##########$$&&$$## /$$$$$$##$$&&$####$                    ");
    mvwprintw(win, 2 + 40, 140, "                   .$#&##############$   #$$$$&############*                   ");
    mvwprintw(win, 2 + 41, 140, "                   (#$###############,    &$$$$$############                   ");
    mvwprintw(win, 2 + 42, 140, "                  .$#$##############(     ,$$$#$###########$,                  ");
    mvwprintw(win, 2 + 43, 140, "                  (#$##############$       ($$##$###########/                  ");
    mvwprintw(win, 2 + 44, 140, "                 .$$&$#############,        &$##$###########$                  ");
    mvwprintw(win, 2 + 45, 140, "                 /#########$&$$$$$(         *####$$$$$$$$####,                 ");
    mvwprintw(win, 2 + 46, 140, "               ,$&#########$#####$           &########$#######                 ");
    mvwprintw(win, 2 + 47, 140, "              *#$$#######$#######*           ,#########&######*                ");
    mvwprintw(win, 2 + 48, 140, "              ###########&#####,               /###############             ");
    mvwprintw(win, 2 + 49, 140, "             ###########$#####$                .################              ");
    mvwprintw(win, 2 + 50, 140, "            &$$###############.                .#################              ");
    mvwprintw(win, 2 + 51, 140, "           $((((((#$&$$$$$&,                     ,$$$$$$$$$$$$$$$$,            ");
    mvwprintw(win, 2 + 52, 140, "         (&(((((((((((&$$$$*                     .$$$$$$$$$$((((((/            ");
    mvwprintw(win, 2 + 53, 140, "        (#$$$$##(((((#####$                        &&$$&&$&#((((((##           ");
    mvwprintw(win, 2 + 54, 140, "      *$##$$$$$####$$(###/                        .#####(((##(($$$#$$*         ");
    mvwprintw(win, 2 + 55, 140, "   /#((((((((((((($$(###&                           $####(($#$$$$##$#(((((($,  ");
    mvwprintw(win, 2 + 56, 140, "  #$#########$$((((#(###,                           $###$#(((((((($(((($######(");
    mvwprintw(win, 2 + 57, 140, ",(((#$$#####$$$#($#&($#*                            $#####((((((((##($$$$$$$$$$");
    mvwprintw(win, 2 + 58, 140, "/ (#(((((((((((((#$..,*                             /,,,,, *($##((($((((((((((#");

    mvwprintw(win, 17, 45, "  ___ _                                                  __ _ _     ");
    mvwprintw(win, 17 + 1, 45, " / __| |_  ___  ___ ___ ___   __ _   ___ __ ___ _____   / _(_) |___ ");
    mvwprintw(win, 17 + 2, 45, "| (__| ' \\/ _ \\/ _ (_-</ -_) / _` | (_-</ _` \\ V / -_) |  _| | / -_)");
    mvwprintw(win, 17 + 3, 45, " \\___|_||_\\___/\\___/__/\\___| \\__,_| /__/\\__,_|\\_/\\___| |_| |_|_\\___|");

    mvwprintw(win, 52, 20, "Press enter/e to save");
    mvwprintw(win, 54, 20, "Press x to remove a save");

    mvwprintw(win, x, 68, ">");

    trainer temp1;
    trainer temp2;
    trainer temp3;
    trainer temp4;
    trainer temp5;

    fseek(save1r, 0, SEEK_END);
    fseek(save2r, 0, SEEK_END);
    fseek(save3r, 0, SEEK_END);
    fseek(save4r, 0, SEEK_END);
    fseek(save5r, 0, SEEK_END);

    int test1 = ftell(save1r);
    int test2 = ftell(save2r);
    int test3 = ftell(save3r);
    int test4 = ftell(save4r);
    int test5 = ftell(save5r);

    if (test1 == 0)
    {
        mvwprintw(win, 29, 70, "Emplacement 1");
    }
    else
    {
        rewind(save1r);
        fread(&temp1, sizeof(trainer), 1, save1r);
        mvwprintw(win, 29, 70, "%s lvl %d", temp1.name, temp1.lvl);
    }

    if (test2 == 0)
    {
        mvwprintw(win, 31, 70, "Emplacement 2");
    }
    else
    {
        rewind(save2r);
        fread(&temp2, sizeof(trainer), 1, save2r);
        mvwprintw(win, 31, 70, "%s lvl %d", temp2.name, temp2.lvl);
    }

    if (test3 == 0)
    {
        mvwprintw(win, 33, 70, "Emplacement 3");
    }
    else
    {
        rewind(save3r);
        fread(&temp3, sizeof(trainer), 1, save3r);
        mvwprintw(win, 33, 70, "%s lvl %d", temp3.name, temp3.lvl);
    }

    if (test4 == 0)
    {
        mvwprintw(win, 35, 70, "Emplacement 4");
    }
    else
    {
        rewind(save4r);
        fread(&temp4, sizeof(trainer), 1, save4r);
        mvwprintw(win, 35, 70, "%s lvl %d", temp4.name, temp4.lvl);
    }

    if (test5 == 0)
    {
        mvwprintw(win, 37, 70, "Emplacement 5");
    }
    else
    {
        rewind(save5r);
        fread(&temp5, sizeof(trainer), 1, save5r);
        mvwprintw(win, 37, 70, "%s lvl %d", temp5.name, temp5.lvl);
    }
}

void print_newtrainer(WINDOW *chat)
{

    mvwprintw(chat, 2 + 1, 150, "                     .@@&@ #.&@#/,,,*,./@&                        ");
    mvwprintw(chat, 2 + 2, 150, "                #@@*&&&&&&&@@@@@@@@@@@@@&@,@@                     ");
    mvwprintw(chat, 2 + 3, 150, "            #/&&&&&&@&&&&&&&&&&@@@@@@@@@@@&&&*@                   ");
    mvwprintw(chat, 2 + 4, 150, "             (&@&&&&&&&&&&&&&&&&&@@@@@@@@@@@@&*                   ");
    mvwprintw(chat, 2 + 5, 150, "              &@&&&&&,@@@@@@&*&&@@/&&&&&&&(@@&*@                  ");
    mvwprintw(chat, 2 + 6, 150, "               @*&&&*@@@@@@@&&&&&&@&&&&&&&@@(/*@                  ");
    mvwprintw(chat, 2 + 7, 150, "                @#((*&/***.#&&&&&&&&#.,,,(&,((&                   ");
    mvwprintw(chat, 2 + 8, 150, "                @(&*/&&&*#,.,/&&&#*.*/&@@&&/*&(&                  ");
    mvwprintw(chat, 2 + 9, 150, "                (#*/@&&*@@.(@&&&&&&@@.@@/&&#*,&.@                 ");
    mvwprintw(chat, 2 + 10, 150, "                &,#*.&&&&@*#&&&&&&&&@/*&&&&./#*@                  ");
    mvwprintw(chat, 2 + 11, 150, "                  @,*(&&&&&&&&&@#&&&&&&&&&(#*&@                   ");
    mvwprintw(chat, 2 + 12, 150, "                     #&&&&@&&&&&&&&&&&(&&&*(                      ");
    mvwprintw(chat, 2 + 13, 150, "                      @,&&&&&&&&&&&&&&&&/&@                       ");
    mvwprintw(chat, 2 + 14, 150, "                        (&./&&&&&&&&&.(@                          ");
    mvwprintw(chat, 2 + 15, 150, "                 /@&#(@@@(**////////*,,((,,/&@                    ");
    mvwprintw(chat, 2 + 16, 150, "           .@&/#@@@#@@@@.((,,,,//,,,,,, //(.///#.@@               ");
    mvwprintw(chat, 2 + 17, 150, "        .&@&@@@@@@#@@@@*&*((,,,,.,,,,,.@&&@@*@@@@@@&,@.           ");
    mvwprintw(chat, 2 + 18, 150, "       @/&&&&&@@@@@@/&@*&&@(@#/*//(@(@@@.&,@@@&@@@(@@&.@          ");
    mvwprintw(chat, 2 + 19, 150, "      (#&@@@@&@@@@*@@&@####@&&,*,*@@@@@@&@&#&@@@@@&@@@@ @         ");
    mvwprintw(chat, 2 + 20, 150, "      @#@(@@####((((((((((((,&,##/@@@@@(@@@@**(/,@/@@@@@.@        ");
    mvwprintw(chat, 2 + 21, 150, "     @*@@/( .*(############(#@&&@@@@@@@,@@@*/*@((//@@@@@@##/      ");
    mvwprintw(chat, 2 + 22, 150, "     &@@@&,#################/.&&@@@@@@@*@@(@@@@,@#/@@@@@@@,@      ");
    mvwprintw(chat, 2 + 23, 150, "    @#@@@@#######(*#/*#@@@#@((/@@@@@@@@(@@@@@@@@@#(@@@@@@@#&      ");
    mvwprintw(chat, 2 + 24, 150, "  ,@/@&@@@@*,**###*//*#######(*@@@@@@@#&&@@@@@@&&//@@@@@@@@*@     ");
    mvwprintw(chat, 2 + 25, 150, " .#@@@@@@@@,##.###*,#@@#/,###((.@@@@@@/@((((//#&@@(@@@@@@&&&*@    ");
    mvwprintw(chat, 2 + 26, 150, " @(@@@@@@@,/(/&&&&&&&,*@###(##(,@@@@,@,*@@@@@@@@@@#@@@&&@&@@@@.   ");
    mvwprintw(chat, 2 + 27, 150, "@#@@@@@@@*/*(#@&&#@@&&&&&#(##,*, @@@/#.@@@@@@@@@@@@@@@@@(@@@@,@   ");
    mvwprintw(chat, 2 + 28, 150, "@*@@@@@@,/.###(#&&&&&&&&*/#(,//*,/@@@#.@@@@@@@@@@@&,@&&@@@@@@@@   ");
    mvwprintw(chat, 2 + 29, 150, "*@(@@@@@*//######,#(##### /////*,.#.,,,@@@@@@@@@&&@@(@@@@@@@@(&@  ");
    mvwprintw(chat, 2 + 30, 150, "  ##&@@@,///(###########....*////&(,**,@@@@@@@@@@@@@*@@@@@@,@*    ");
    mvwprintw(chat, 2 + 31, 150, "    *@/@@*(///((/(*/####/,,,,.,,.,*(/*,@@@@@@@@@@@@@@,@@,@*       ");
    mvwprintw(chat, 2 + 32, 150, "       &*#@@#.,#########.,,,,.,,.,/(,*.@@@@@@@@@@@@@@@@@          ");
    mvwprintw(chat, 2 + 33, 150, "      @.@@&@###@.#######.,*//.,,.//*(/,@@@@@@@&&&@@@@@&/&         ");
    mvwprintw(chat, 2 + 34, 150, "      @@@@@@@@@&*@#####@.*///,//*///// &@@@@@&#@@@@@@@@.@         ");
    mvwprintw(chat, 2 + 35, 150, "      @@@@@@@@@@@@@@@@&@,/*///*/,///// &@@@@@&/@@@@@@@@(@         ");
    mvwprintw(chat, 2 + 36, 150, "     @/@@@@@@@@#@@@@@@@@//////*/,///// &@@@@@@*@@@@@@@@@&         ");
    mvwprintw(chat, 2 + 37, 150, "     @(@@@@@@@@,@@@@@@@(//,,,,,,.///// @@@@@@@,@@@@@@@@&#@        ");
    mvwprintw(chat, 2 + 38, 150, "     @(@@@@@@@@@@@@@@@@,//*,,.,((.//// @@@@@@@*&@@@@@@@&*@        ");
    mvwprintw(chat, 2 + 39, 150, "     @&@@@@@@@&@@@@@@@@.///*,,.(((*/// @@@@@@@(&@@@@@@@@.@        ");
    mvwprintw(chat, 2 + 40, 150, "     @@@@@@&@(#@@@@@@@@,////,,*(((./// &@@@@@@@#@@##///#.@        ");
    mvwprintw(chat, 2 + 41, 150, "    *(@@@@@@@@@@@@@@@@@/////*,((((/*/,.&@@@@@@@@@@@@@@@@ @        ");
    mvwprintw(chat, 2 + 42, 150, "    #*@@@@@@@@@@@@@@@@#/////*.(((((,//,&@@@@@@@@@@@@@@@@ @        ");
    mvwprintw(chat, 2 + 43, 150, "    #*@@@@@@@@@@@@@@@@*/////**,**,,.//,&@@@@@@@@@@@@@@@@.@        ");
    mvwprintw(chat, 2 + 44, 150, "        @//**,...#@&@@./////*.@   *@*/*&@@@@&&@*...,,,,@          ");
    mvwprintw(chat, 2 + 45, 150, "        ///////////////////**.@    @,///****/////////*,@          ");
    mvwprintw(chat, 2 + 46, 150, "        /////.///////////***,.@    @*////////////////**&          ");
    mvwprintw(chat, 2 + 47, 150, "        ////*///////////****,*@    ,&*//////////////**,(&         ");
    mvwprintw(chat, 2 + 48, 150, "        @//,///////////*****,/@     @.///////////**,,,,,#@        ");
    mvwprintw(chat, 2 + 49, 150, "        @.((//////////******.&.     @*//////////*,,,,,,,**@       ");
    mvwprintw(chat, 2 + 50, 150, "       @*((//////////******,,/@      @,////////*,,,,,,,,,,@       ");
    mvwprintw(chat, 2 + 51, 150, "       @.,//*/////,***,*****,@.      @ *//////*.,/////.,,,@       ");
    mvwprintw(chat, 2 + 52, 150, "    /@.,#/////////*,**,.,,,.&,       @.,,/*,/,//////////, @       ");
    mvwprintw(chat, 2 + 53, 150, "   @./(#**/////////*.**,.,.(@         @(,/(/,*//////////.,,&      ");
    mvwprintw(chat, 2 + 54, 150, "   @.*/////((///////*,..@@              @,////((////////*,,,@     ");
    mvwprintw(chat, 2 + 55, 150, "    @.****,,......,*,.@                 @**,*,.,**////*....#*     ");
    mvwprintw(chat, 2 + 56, 150, "         @@&#/*..,@@                      /@&*.  ....  *@@        ");

    mvwprintw(chat, 15, 18, "__      ___         _   _                                                                  _            _                ___            ");
    mvwprintw(chat, 15 + 1, 18, "\\ \\    / / |_  __ _| |_( )___  _  _ ___ _  _ _ _   _ _  __ _ _ __  ___   _ _  _____ __ __ | |_ _ _ __ _(_)_ _  ___ _ _  |__ \\           ");
    mvwprintw(chat, 15 + 2, 18, " \\ \\/\\/ /| ' \\/ _` |  _|/(_-< | || / _ \\ || | '_| | ' \\/ _` | '  \\/ -_) | ' \\/ -_) V  V / |  _| '_/ _` | | ' \\/ -_) '_|   /_/  ");
    mvwprintw(chat, 15 + 3, 18, "  \\_/\\_/ |_||_\\__,_|\\__| /__/  \\_, \\___/\\_,_|_|   |_||_\\__,_|_|_|_\\___| |_||_\\___|\\_/\\_/   \\__|_| \\__,_|_|_||_\\___|_|    (_)            ");
    mvwprintw(chat, 15 + 4, 18, "                               |__/                                                                                                     ");
}

void print_get_firstpoke(WINDOW *win, int x, int y)
{

    // wattron(win,COLOR_PAIR(RED));
    mvwprintw(win, 15 - 1, 95, "          .(*,@°@,*#.                                         ");
    mvwprintw(win, 15, 95, "           #,,,,,,,,,,(/                                                ");
    mvwprintw(win, 15 + 1, 95, "        &,   ,,,,,,,,,,*/&                                    ");
    mvwprintw(win, 15 + 2, 95, "      *,,...,,,,,,,,,,,,*//                                   ");
    mvwprintw(win, 15 + 3, 95, "     @,,,,,,,,,,,,,,,,*#@(//                                  ");
    mvwprintw(win, 15 + 4, 95, "     @.,*,,,,,,,,,,,,*(  @@/#                                 ");
    mvwprintw(win, 15 + 5, 95, "     & /,,,,,,,,,,,,,,&@*@@#/                                 ");
    mvwprintw(win, 15 + 6, 95, "     #@@,,,,,,,,,,,,,,#@@&@(/(                                ");
    mvwprintw(win, 15 + 7, 95, "    #*&&,,,,,,,,,,,,,,,&/*////                                ");
    mvwprintw(win, 15 + 8, 95, "    *,,,,,,.,,,,,,,,,,,,//////                         .      ");
    mvwprintw(win, 15 + 9, 95, "    ///@,,,,,,,,,,,,*@&& @///(                        (/#     ");
    mvwprintw(win, 15 + 10, 95, "      (//(##(#(#(((/**/#////*                       / ((/*   ");
    mvwprintw(win, 15 + 11, 95, "         #///&*,.,,,,@/////#                       #.*/(/(   ");
    mvwprintw(win, 15 + 12, 95, "             &///(/////////*,/(                   ./*///.*/, ");
    mvwprintw(win, 15 + 13, 95, "       .@,,,,**/#.. .&///*,,,,,,,,,/(             //((/((.,. ");
    mvwprintw(win, 15 + 14, 95, " ,@,,,,,,,,,,@/        /,,,,,,,,,,,,,,,,/(&&     ../.*(/, ./ ");
    mvwprintw(win, 15 + 15, 95, "@,,,,,,,,,,,,@           &,,,,,,,,,,,,,(//*/    #... (.  ,/  ");
    mvwprintw(win, 15 + 16, 95, "  ,,,///////@              ,*(#///////&/          #.... .((  ");
    mvwprintw(win, 15 + 17, 95, "                            ,,,**/                 /..,,//(  ");
    mvwprintw(win, 15 + 18, 95, "                            .,,,,,*                   ,@     ");
    mvwprintw(win, 15 + 19, 95, "                             &,,,,,,@               ,*,@     ");
    mvwprintw(win, 15 + 20, 95, "           *                  (,,,,,,/             @//(      ");
    mvwprintw(win, 15 + 21, 95, "        #,,,,           .....,...,,,,,,/        @(///#,      ");
    mvwprintw(win, 15 + 22, 95, "      ,.  .,,*..      .   ..*...,,,,,,,/#((((((((((@.        ");
    mvwprintw(win, 15 + 23, 95, "      ...,,,////     .  .   *,,,,,,,,,*/((((((((((,          ");
    mvwprintw(win, 15 + 24, 95, "     .,**//////////#        ********/////((((&,,@            ");
    mvwprintw(win, 15 + 25, 95, "      &///////////@.       .(@@///////////*&.                ");
    mvwprintw(win, 15 + 26, 95, "    /,#/(///////*               #////////@                   ");
    mvwprintw(win, 15 + 27, 95, "  &(&  . .&                      &//////&@./                 ");
    mvwprintw(win, 15 + 28, 95, "                                  ,@  @&,.&                 ");
    wattroff(win, COLOR_PAIR(RED));

    // wattron(win,COLOR_PAIR(GREEN));
    mvwprintw(win, 20, 25, "                                          ,            ");
    mvwprintw(win, 20 + 1, 25, "                                         (*(&*(        ");
    mvwprintw(win, 20 + 2, 25, "                         ,#*****//***/////#**/@(@      ");
    mvwprintw(win, 20 + 3, 25, "                     &******//**/@(**********/((       ");
    mvwprintw(win, 20 + 4, 25, "       /#,         &((///***/#/********/*/**/(((#      ");
    mvwprintw(win, 20 + 5, 25, "     (****#,,,,,,,******@/,,,***//*/////***//(@(((     ");
    mvwprintw(win, 20 + 6, 25, "    /*(,,,,,,,,#####***********/(*///***//(((((((((    ");
    mvwprintw(win, 20 + 7, 25, "    **,,,,,((#####*************/((((((((((((((((((((   ");
    mvwprintw(win, 20 + 8, 25, "   (,,****@***(/****************//(((((((((((((((#(((( ");
    mvwprintw(win, 20 + 9, 25, "  ##.#***(/****,****(,**,&##@**//////@#(((((((((((((((@");
    mvwprintw(win, 20 + 10, 25, " ,@.#///*****###****,*(.((/.#@/(///@//(@(((((((((((((((");
    mvwprintw(win, 20 + 11, 25, " *,.#,/********@*****@..@#(.##/////(/(#####@((##((((((@");
    mvwprintw(win, 20 + 12, 25, " ***&(*,,************...,(((((//(/((//(@#####(@((((((( ");
    mvwprintw(win, 20 + 13, 25, " @((***,,*******************//#/////////(@@@@((/&((#@  ");
    mvwprintw(win, 20 + 14, 25, "   ,(/##@#/////////((#@@#*&//(///(//////////(////(     ");
    mvwprintw(win, 20 + 15, 25, "       &//((//////////&(((////&/*******/#/#***/////    ");
    mvwprintw(win, 20 + 16, 25, "       @***/(@(//(////(@#((((****@****//&*/((##//(((   ");
    mvwprintw(win, 20 + 17, 25, "       .*(((#///(#((((((((((**#@*#****///*#(##@//(//   ");
    mvwprintw(win, 20 + 18, 25, "        @(((@///////*##(((((//(******//@///((@(////#   ");
    mvwprintw(win, 20 + 19, 25, "         (**//////(     #(@####****//# /((//////((/    ");
    mvwprintw(win, 20 + 20, 25, "         .*.@/*//,        /*****///(     @(/#//(/#     ");
    mvwprintw(win, 20 + 21, 25, "                            ,./.@                      ");
    // wattroff(win,COLOR_PAIR(GREEN));

    // wattron(win,COLOR_PAIR(BLUE));
    mvwprintw(win, 21, 160, "                         .(*,,*#.");
    mvwprintw(win, 21 + 1, 160, "                     *,,,,,,,,,,.. .&");
    mvwprintw(win, 21 + 2, 160, "                   .*///,*.*.,,,,,,,,(,");
    mvwprintw(win, 21 + 3, 160, "                  ////**#@@@@,,,,,,,,,@");
    mvwprintw(win, 21 + 4, 160, "                  (///// (&@&,,,,,,,,,##");
    mvwprintw(win, 21 + 5, 160, "                  (//////,,,,,,,,,,,(,,./");
    mvwprintw(win, 21 + 6, 160, "                   //(///((///////(//(/(");
    mvwprintw(win, 21 + 7, 160, "                    (///(/////////////");
    mvwprintw(win, 21 + 8, 160, "                .//@*@##//////////@#/(*");
    mvwprintw(win, 21 + 9, 160, "                (@/@//*,,.,********...,,,,..&");
    mvwprintw(win, 21 + 10, 160, "               &//(///,,,,.,@*,..   #  /,,,,,,,*.,");
    mvwprintw(win, 21 + 11, 160, "              .**/,@//*,,,(,,,....     .@,,,,&#(( ");
    mvwprintw(win, 21 + 12, 160, "              &**/@.**/#(,//,,.......  .. .,,.");
    mvwprintw(win, 21 + 13, 160, "              (///( ,@*#/(/((..../.....,.");
    mvwprintw(win, 21 + 14, 160, ".. (*,,,,,,*   (((( ,#***,@,,.. .#...../*");
    mvwprintw(win, 21 + 15, 160, ".@//((/**,,,*( #((,#,,,,@**,.....#.....,,,");
    mvwprintw(win, 21 + 16, 160, " ///(/(//#/////(##*,,,,,,,@****,.(..,,(,...");
    mvwprintw(win, 21 + 17, 160, " @/(//////////////,,,,,,,,,&*/@****,@/*,,,.(");
    mvwprintw(win, 21 + 18, 160, "  ,/////((////////*,,,,.,,*#(/((.  (/////**(");
    mvwprintw(win, 21 + 19, 160, "      /#(///#@.  ///***/*(          //////**@,");
    mvwprintw(win, 21 + 20, 160, "                 //////(/                ,");
    mvwprintw(win, 21 + 21, 160, "                   .#");
    // wattroff(win,COLOR_PAIR(BLUE));

    mvwprintw(win, 7, 85, "  ___ _                                        _                        _ ");
    mvwprintw(win, 7 + 1, 85, " / __| |_  ___  ___ ___ ___   __ _   _ __  ___| |_____ _ __  ___ _ _   | |");
    mvwprintw(win, 7 + 2, 85, "| (__| ' \\/ _ \\/ _ (_-</ -_) / _` | | '_ \\/ _ \\ / / -_) '  \\/ _ \\ ' \\  |_|");
    mvwprintw(win, 7 + 3, 85, " \\___|_||_\\___/\\___/__/\\___| \\__,_| | .__/\\___/_\\_\\___|_|_|_\\___/_||_| (_)");
    mvwprintw(win, 7 + 4, 85, "                                    |_|                                   ");

    mvwprintw(win, x, y, "    .");
    mvwprintw(win, x + 1, y, "  .:;:.");
    mvwprintw(win, x + 2, y, ".:;;;;;:.");
    mvwprintw(win, x + 3, y, "  ;;;;;");
}

void print_computer_connect(WINDOW *pc, trainer *player)
{

    mvwprintw(pc, 6, 45, "   ___       __         _____                     __");
    mvwprintw(pc, 6 + 1, 45, "  / _ \\___  / /_____   / ___/__  __ _  ___  __ __/ /____ ____");
    mvwprintw(pc, 6 + 2, 45, " / ___/ _ \\/  '_/ -_) / /__/ _ \\/  ' \\/ _ \\/ // / __/ -_) __/");
    mvwprintw(pc, 6 + 3, 45, "/_/   \\___/_/\\_\\\\__/  \\___/\\___/_/_/_/ .__/\\_,_/\\__/\\__/_/");
    mvwprintw(pc, 6 + 4, 45, "                                    /_/");

    mvwprintw(pc, 12, 65, "       _.-;;-._ ");
    mvwprintw(pc, 12 + 1, 65, "'-..-'|   ||   |");
    mvwprintw(pc, 12 + 2, 65, "'-..-'|_.-;;-._|");
    mvwprintw(pc, 12 + 3, 65, "'-..-'|   ||   |");
    mvwprintw(pc, 12 + 4, 65, "'-..-'|_.-''-._|");

    mvwprintw(pc, 22, 110, "    @           ");
    mvwprintw(pc, 22 + 1, 110, "    @  @        ");
    mvwprintw(pc, 22 + 2, 110, "    @    @      ");
    mvwprintw(pc, 22 + 3, 110, "    @      @    ");
    mvwprintw(pc, 22 + 4, 110, "    @        (@ ");
    mvwprintw(pc, 22 + 5, 110, "    @      @/.  ");
    mvwprintw(pc, 22 + 6, 110, "    @    @  @   ");
    mvwprintw(pc, 22 + 7, 110, "      @   @  @  ");
    mvwprintw(pc, 22 + 8, 110, "           @  @ ");
    mvwprintw(pc, 22 + 9, 110, "            @ #@");

    mvwprintw(pc, 19, 37, "Login");
    mvwprintw(pc, 26, 35, "Password");
}

void print_evolution(WINDOW *evolve_win, pokemon poke, pokemon evolution)
{
    pokemon pokenull, charmander, bulbasaur, squirtle, pikachu, charizard, blastoise, venusaur, raichu;
    init_poke(&pokenull, &charmander, &bulbasaur, &squirtle, &pikachu, &charizard, &blastoise, &venusaur, &raichu);
    WINDOW *text = subwin(evolve_win, 20, 235, 63 - 21, 0);
    box(text, 0, 0);

    print_poke(evolve_win, poke, 20, 105, 0);
    wrefresh(evolve_win);
    write_flush(text, 9, 110, "What ?!");
    sleep(1);
    mvwprintw(text, 9, 110, "                        ");

    write_flush(text, 9, 103, "%s is evolving !", poke.name);
    for (int i = 0; i < 13; i++)
    {
        if (i <= 5)
        {
            print_poke(evolve_win, pokenull, 20, 105, 0);
            usleep(500000);
            print_poke(evolve_win, poke, 20, 105, 0);
            wrefresh(evolve_win);
            print_poke(evolve_win, pokenull, 20, 105, 0);
            usleep(500000);
            print_poke(evolve_win, evolution, 20, 105, 0);
            wrefresh(evolve_win);
        }
        else
        {
            print_poke(evolve_win, pokenull, 20, 105, 0);
            usleep(250000);
            print_poke(evolve_win, poke, 20, 105, 0);
            wrefresh(evolve_win);
            print_poke(evolve_win, pokenull, 20, 105, 0);
            usleep(250000);
            print_poke(evolve_win, evolution, 20, 105, 0);
            wrefresh(evolve_win);
        }
    }

    print_poke(evolve_win, evolution, 20, 105, 0);
    mvwprintw(text, 9, 112, "                           ");
    write_flush(text, 9, 103, "%s became a %s !", poke.name, evolution.name);

    wrefresh(evolve_win);

    sleep(5);

    if (delwin(text) == ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(74);
    }
}

void cinematique_rock(WINDOW *map, WINDOW *cam, trainer *player)
{

    wattron(map, COLOR_PAIR(BLUE));
    mvwprintw(map, 40, 358 - 2, "Professor");
    mvwprintw(map, 40 + 1, 358 + 2, "-");
    mvwprintw(map, 40 + 2, 358 + 1, "'~'");
    mvwprintw(map, 40 + 3, 358, "/|+|\\");
    mvwprintw(map, 40 + 4, 358 + 1, "|-|");
    mvwprintw(map, 40 + 5, 358 + 1, "- -");
    wattroff(map, COLOR_PAIR(BLUE));
    wrefresh(cam);
    usleep(750000);

    for (int i = 40; i <= 45; i++) // positionnement du prof
    {
        mvwprintw(map, i + 1, 358 + 2, " ");
        mvwprintw(map, i + 2, 358 + 1, "   ");
        mvwprintw(map, i + 3, 358, "     ");
        mvwprintw(map, i + 4, 358 + 1, "   ");
        mvwprintw(map, i + 5, 358 + 1, "   ");
        create_map(map, player);
        wattron(map, COLOR_PAIR(BLUE));
        mvwprintw(map, i + 1 + 1, 358 + 2, "-");
        mvwprintw(map, i + 1 + 2, 358 + 1, "'~'");
        mvwprintw(map, i + 1 + 3, 358, "/|+|\\");
        mvwprintw(map, i + 1 + 4, 358 + 1, "|-|");
        mvwprintw(map, i + 1 + 5, 358 + 1, "- -");
        wattroff(map, COLOR_PAIR(BLUE));
        wrefresh(cam);
        usleep(750000);
    }

    char talk1[100] = "Hey ";
    strcat(talk1, player->name);

    for (int i = 0; i < strlen(talk1); i++) // write flush modifié pour fonctionner avec la cam
    {
        mvwprintw(map, 47, 364 + i, "%c", talk1[i]);
        fflush(stdout);
        wrefresh(cam);
        usleep(50000);
    }
    sleep(2);
    for (int i = 0; i < strlen(talk1); i++) // delete
    {
        mvwprintw(map, 47, 364 + i, " ");
    }

    // pause

    for (int i = 0; i < strlen("I see you're struggling with this rock"); i++) // write flush modifié pour fonctionner avec la cam
    {
        mvwprintw(map, 47, 364 + i, "%c", "I see you're struggling with this rock"[i]);
        fflush(stdout);
        wrefresh(cam);
        usleep(50000);
    }
    sleep(2);
    for (int i = 0; i < strlen("I see you're struggling with this rock"); i++) // delete
    {
        mvwprintw(map, 47, 364 + i, " ");
    }

    // pause

    for (int i = 0; i < strlen("Your pokemons are here to help you"); i++) // write flush modifié pour fonctionner avec la cam
    {
        mvwprintw(map, 47, 364 + i, "%c", "Your pokemons are here to help you"[i]);
        fflush(stdout);
        wrefresh(cam);
        usleep(50000);
    }
    sleep(2);
    for (int i = 0; i < strlen("Your pokemons are here to help you"); i++) // delete
    {
        mvwprintw(map, 47, 364 + i, " ");
    }

    // pause

    char talk2[100] = "Try and ask for help to your ";
    if (player->poke1.type != NOPOKEMON)
    {
        strcat(talk2, player->poke1.name);
    }
    else if (player->poke2.type != NOPOKEMON)
    {
        strcat(talk2, player->poke2.name);
    }
    else if (player->poke3.type != NOPOKEMON)
    {
        strcat(talk2, player->poke3.name);
    }
    else if (player->poke4.type != NOPOKEMON)
    {
        strcat(talk2, player->poke4.name);
    }
    else if (player->poke5.type != NOPOKEMON)
    {
        strcat(talk2, player->poke5.name);
    }
    else if (player->poke6.type != NOPOKEMON)
    {
        strcat(talk2, player->poke6.name);
    }
    else
    {
        exit(76); // no pokemon in the pocket -> error not possible
    }

    for (int i = 0; i < strlen(talk2); i++) // write flush modifié pour fonctionner avec la cam
    {
        mvwprintw(map, 47, 364 + i, "%c", talk2[i]);
        fflush(stdout);
        wrefresh(cam);
        usleep(50000);
    }
    sleep(2);
    for (int i = 0; i < strlen(talk2); i++) // delete
    {
        mvwprintw(map, 47, 364 + i, " ");
    }

    // pause

    for (int i = 0; i < strlen("Press any key to break the rock"); i++) // write flush modifié pour fonctionner avec la cam
    {
        mvwprintw(map, 47, 364 + i, "%c", "Press any key to break the rock"[i]);
        fflush(stdout);
        wrefresh(cam);
        usleep(50000);
    }
    sleep(2);

    int ch;
    while ((ch = getch()) != ERR)
    {
    }

    for (int i = 0; i < strlen("Press any key to break the rock"); i++) // delete
    {
        mvwprintw(map, 47, 364 + i, " ");
    }

    ch = ERR;

    nodelay(stdscr, FALSE);
    ch = getch();
    breaktherock(map, cam, player);
    nodelay(stdscr, TRUE);

    // pause

    while ((ch = getch()) != ERR)
    {
    }

    for (int i = 0; i < strlen("Well done ! See ya !"); i++) // write flush modifié pour fonctionner avec la cam
    {
        mvwprintw(map, 47, 364 + i, "%c", "Well done ! See ya !"[i]);
        fflush(stdout);
        wrefresh(cam);
        usleep(50000);
    }
    sleep(2);
    for (int i = 0; i < strlen("Well done ! See ya !"); i++) // delete
    {
        mvwprintw(map, 47, 364 + i, " ");
    }

    // pause

    for (int i = 45; i >= 40; i--) // il part mtn
    {
        mvwprintw(map, i + 1 + 1, 358 + 2, " ");
        mvwprintw(map, i + 1 + 2, 358 + 1, "   ");
        mvwprintw(map, i + 1 + 3, 358, "     ");
        mvwprintw(map, i + 1 + 4, 358 + 1, "   ");
        mvwprintw(map, i + 1 + 5, 358 + 1, "   ");
        wattron(map, COLOR_PAIR(BLUE));
        mvwprintw(map, i + 1, 358 + 2, "-");
        mvwprintw(map, i + 2, 358 + 1, "'~'");
        mvwprintw(map, i + 3, 358, "/|+|\\");
        mvwprintw(map, i + 4, 358 + 1, "|-|");
        mvwprintw(map, i + 5, 358 + 1, "- -");
        wattroff(map, COLOR_PAIR(BLUE));
        wrefresh(cam);
        usleep(750000);
    }
}