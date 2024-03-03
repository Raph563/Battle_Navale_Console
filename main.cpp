#include <iostream>
#include "color.hpp"
#include <random>
#include <chrono>
#include <thread>
#include <string>
#include <vector>


using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
using namespace std;


//Déclaration et définition des arrays strings pour les visuels ASCII
string planeAsciiArray[9] = {
        {"______\n"},
        {"| | # \\                                      |\n"},
        {"| ____ \\_________|----^\"|\"\"\"\"\"|\"\\___________ |\n"},
        {" \\___\\   FO + 94 >>    `\"\"\"\"\"\"\"\"     =====  \"|D\n"},
        {"        ^^-------____--\"\"\"\"\"\"\"\"\"\"+\"\"--_  __--\"|\n"},
        {"                    `\"\"|\"-->####)+---|`\"\"     |\n"},
        {"                                  \\  \\\n"},
        {"                                 <- O -)\n"},
        {"                                   `\"'"}
};
string batailleNavaleAsciiArray[6] = {
        {""},
        {R"(   ____        _        _ _ _          _   _                  _      )"},
        {R"(  | __ )  __ _| |_ __ _(_) | | ___    | \ | | __ ___   ____ _| | ___ )"},
        {R"(  |  _ \ / _` | __/ _` | | | |/ _ \   |  \| |/ _` \ \ / / _` | |/ _ \)"},
        {R"(  | |_) | (_| | || (_| | | | |  __/   | |\  | (_| |\ V / (_| | |  __/)"},
        {R"(  |____/ \__,_|\__\__,_|_|_|_|\___|   |_| \_|\__,_| \_/ \__,_|_|\___|)"}
};
string boatAsciiArray[6] = {
        {"\n"},
        {"\n"},
        {"\t\t                __/___            \n"},
        {"\t\t          _____/______|           \n"},
        {"\t\t  _______/_____\\_______\\_____     \n"},
        {"\t\t  \\              < < <       |      "},
};
string planewithMenuBannerAsciiArray[7] = {
        {"                                                    _\n"},
        {"\\---------------------\\                           -=\\`\\\n"},
        {" \\  1. Multijoueur     \\                      |\\ ____\\_\\__\n"},
        {"  >     2. Solo         >--------------------=\\c`\"\"\"\"\"\"\" \"`)\n"},
        {" /  3. Paramètres     /                        `~~~~~/ /~~`\n"},
        {"/---------------------/                           -==/ /\n"},
        {"                                                    '-'"}
};
string menuAsciiArray[6] = {
        "   __  __                 \t",
        "  |  \\/  | ___ _ __  _   _ \t",
        "  | |\\/| |/ _ \\ '_ \\| | | |\t",
        "  | |  | |  __/ | | | |_| |\t",
        "  |_|  |_|\\___|_| |_|\\__,_|\t"
};
string parametreAsciiArray[5] = {
        " ____                            __  _                 ",
        R"(|  _ \ __ _ _ __ __ _ _ __ ___   \_\| |_ _ __ ___  ___ )",
        R"(| |_) / _` | '__/ _` | '_ ` _ \ / _ \ __| '__/ _ \/ __|)",
        R"(|  __/ (_| | | | (_| | | | | | |  __/ |_| | |  __/\__ \)",
        R"(|_|   \__,_|_|  \__,_|_| |_| |_|\___|\__|_|  \___||___/)"
};
string boatMiniAsciiOne[5] = {
    "\n",
    "\t   _~        \n",
    "\t_~ )_)_~     \n",
    "\t)_))_))_)    \n",
    "\t_!__!__!_    \n",
};
string boatMiniAsciiTwo[8] = {
    " .  o ..             ",
    "o . o o.o            ",
    "     ...oo           ",
    "       __[]__        ",
    R"(    __|_o_o_o\__     )",
    R"(    \""""""""""/     )",
    R"(     \. ..  . /      )",
    "~~~~~~~~~~~~~~~~~~~~~~~"
};
string gear_icon[22] = {
        "     __,",
        "  .-'  /      ",
        ".'    /   /`.",
        "|    /   /  |",
        "|    \\__/   |",
        "`.         .'",
        "  `.     .'",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "    | ][ |",
        "  .'  __  `.",
        "  |  /  \\  |",
        "  |  \\__/  |",
        "  `.      .'",
        "    `----'\n"
};
string antennaSatellite[15] = {
        "\n\t         ,-.",
        "\n\t        / \\  `.  __..-,O",
        "\n\t       :   \\ --''_..-'.'",
        "\n\t       |    . .-' `. '.",
        "\n\t       :     .     .`.'",
        "\n\t        \\     `.  /  ..",
        "\n\t         \\      `.   ' .",
        "\n\t          `,       `.   \\",
        "\n\t         ,|,`.        `-.\\",
        "\n\t        '.||  ``-...__..-`",
        "\n\t         |  |",
        "\n\t         |__|",
        "\n\t         /||\\",
        "\n\t        //||\\\\",
        "\n\t       // || \\\\\n"
};
string captainShockedAsciiArray[11] = {
        "                   ______      ",
        "                   |x  ||      ",
        "                   /__/-'      ",
        "   ________         ,          ",
        " _|       .|      ,---.        ",
        "|:|       .|      0/0 ?        ",
        " \\|       .|   ,==|D_\\===,   ",
        "  |________|   '|   :  =x= \\  ",
        "  __|___|__ __/_|___:____|/<___",
        " [_________]   ,--------,      ",
        "               ========/"
};
string miseEnPlaceAsciiArray[6] = {
        R"(    __  __ _                               _                )",
        R"(   |  \/  (_)___  ___    ___ _ __    _ __ | | __ _  ___ ___ )",
        R"(   | |\/| | / __|/ _ \  / _ \ '_ \  | '_ \| |/ _` |/ __/ _ \)",
        R"(   | |  | | \__ \  __/ |  __/ | | | | |_) | | (_| | (_|  __/)",
        R"(   |_|  |_|_|___/\___|  \___|_| |_| | .__/|_|\__,_|\___\___|)",
        R"(                                    |_|                     )"
};
string capitainThinkingAsciiArray[8] = {
    "   ________         ?          ",
    " _|       .|      ,---.        ",
    "|:|       .|      0/0 ?        ",
    " \\|       .|   ,==|°_\\===,   ",
    "  |________|   '|   :  =x= \\  ",
    "  __|___|__ __/_|___:____|/<___",
    " [_________]   ,--------,      ",
    "               ========/"
};
string saisisNomJoueurAsciiArray[6] = {
    R"()",
    R"(    ____          _       _            _                                           )",
    R"(   / ___|   __ _ (_) ___ (_) ___    __| |  ___  ___   _ __    ___   _ __ ___   ___ )",
    R"(   \___ \  / _` || |/ __|| |/ __|  / _` | / _ \/ __| | '_ \  / _ \ | '_ ` _ \ / __|)",
    R"(    ___) || (_| || |\__ \| |\__ \ | (_| ||  __/\__ \ | | | || (_) || | | | | |\__ \)",
    R"(   |____/  \__,_||_||___/|_||___/  \__,_| \___||___/ |_| |_| \___/ |_| |_| |_||___/)",
};
string playerOneAsciiArray[5] = {
    R"(        _                                    _   )",
    R"(       | |  ___   _   _   ___  _   _  _ __  / |  )",
    R"(    _  | | / _ \ | | | | / _ \| | | || '__| | |  )",
    R"(   | |_| || (_) || |_| ||  __/| |_| || |    | |  )",
    R"(    \___/  \___/  \__,_| \___| \__,_||_|    |_|  )"
};
string playerTwoAsciiArray[5] = {
    R"(        _                                    ____  )",
    R"(       | |  ___   _   _   ___  _   _  _ __  |___ \ )",
    R"(    _  | | / _ \ | | | | / _ \| | | || '__|   __) |)",
    R"(   | |_| || (_) || |_| ||  __/| |_| || |     / __/ )",
    R"(    \___/  \___/  \__,_| \___| \__,_||_|    |_____|)"
};
string separatorWaveAscii[18] = {
    R"(_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,)",
    R"(-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~')",
    R"('~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-)",
    R"(,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__)",
    R"(,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__,.-'~'-.)",
    R"('-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~)",
    R"(_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_)",
    R"(,.-'~'-_,.-'~'-.,__,.-'~'-.,___,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.)",
    R"(_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,)",
    R"(-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~')",
    R"('~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-)",
    R"(,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__)",
    R"(_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,)",
    R"(-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~')",
    R"('~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-)",
    R"(,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__)",
    R"('~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-)",
    R"(,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_,.-'~'-.,__,.-'~'-.,__)"
};
string militaryBoatTwoAsciiArray[13] = {
    R"(                                      |__)",
    R"(                                     |\/)",
    R"(                                     ---)",
    R"(                                     / | [)",
    R"(                              !      | |||)",
    R"(                            _/|     _/|-++')",
    R"(                        +  +--|    |--|--|_ |-)",
    R"(                     { /|__|  |/\__|  |--- |||__/)",
    R"(                    +---------------___[}-_===_.'____               /\)",
    R"(                ____`-' ||___-{]_| _[}-  |     |_[___\==--          \/   _)",
    R"( __..._____--==/___]_|__|_____________________________[___\==--___,-----' .7)",
    R"(|                                                                   BB-61/)",
    R"( \_______________________________________________________________________|)"
};
string saisirChoixEtMilitaryBoatOneAsciiArray[7] = {
    R"(                                                                                        )___(                           )",
    R"(                                                                                 _______/__/_                           )",
    R"(                                                                        ___     /===========|   ___                     )",
    R"(    ___     _                    _        _           ____       __    [\\\]___/____________|__[///]  __                )",
    R"(   | __|_ _| |_ _ _ ___ _ _   __| |_  ___(_)_ __      \   \_____[\\]__/___________________________\__[//]___            )",
    R"(   | _|| ' \  _| '_/ -_) '_| / _| ' \/ _ \ \ \ /       \40A                                                 |           )",
    R"(   |___|_||_\__|_| \___|_|   \__|_||_\___/_/_\_\        \                                                  /            )"
};
string saisirChoixAsciiArray[4] = {
    R"( ___     _                    _        _     )",
    R"(| __|_ _| |_ _ _ ___ _ _   __| |_  ___(_)_ __)",
    R"(| _|| ' \  _| '_/ -_) '_| / _| ' \/ _ \ \ \ /)",
    R"(|___|_||_\__|_| \___|_|   \__|_||_\___/_/_\_\)"
};
string menuAttaqueAsciiArray[7] = {
    R"(       _   _   _                         )",
    R"(      / \ | |_| |_ __ _  __ _ _   _  ___ )",
    R"(     / _ \| __| __/ _` |/ _` | | | |/ _ \)",
    R"(    / ___ \ |_| || (_| | (_| | |_| |  __/)",
    R"(   /_/   \_\__|\__\__,_|\__, |\__,_|\___|)",
    R"(                           |_|           )",
    R"(                                         )"
};
string debugAsciiArray[7] = {
    R"(    ____       _                 )",
    R"(   |  _ \  ___| |__  _   _  __ _ )",
    R"(   | | | |/ _ \ '_ \| | | |/ _` |)",
    R"(   | |_| |  __/ |_) | |_| | (_| |)",
    R"(   |____/ \___|_.__/ \__,_|\__, |)",
    R"(                           |___/ )",
    R"(                                 )"
};
string armyBoatAsciiArray[7] = {
    R"(                                  )___(                )",
    R"(                           _______/__/_                )",
    R"(                  ___     /===========|   ___          )",
    R"(____       __    [\\\]___/____________|__[///]  __     )",
    R"(\   \_____[\\]__/___________________________\__[//]___ )",
    R"( \40A                                                 |)",
    R"(  \                                                  / )"
};
bool debug = false, player;
int menuChoice;
int boatMax = 6;

int victory = 0;
int playerOneBoatNumber = 0, playerTwoBoatNumber = 0;
int playerNumberOfTurn = 1;
string playerOneName, playerTwoName;

//Déclaration Fonctions
int showOpeningMenu(bool comingFromSettings = false);
void showLineSeparator(bool startDoubleReturnLine = true, bool endDoubleReturnLine = true, bool startOneReturn = false, bool endOneReturn = false);
void showEmptyGrid(int size1 = 8, int size2 = -1, bool showNumbers = true, int tabulation = 0);
void showBoard(const vector<vector<bool>>& visualBoard);
int showAttackedBoard(const vector<vector<int>>& attackedBoard, bool player, int boatMax);
vector<vector<bool>> miseEnPlaceBateau(vector<vector<bool>>& settingUpBoard, int boatMax, bool player, string playerName, bool debug);
vector<vector<int>> attackShipMenu(vector<vector<int>>& attackedBoard, const vector<vector<bool>>& enemyBoard, bool player, string playerName, int boatMax, int playerNumberOfTurn);
string getName(int player);
void showSettingsMenu(vector<vector<bool>>& playerOne, vector<vector<bool>>& playerTwo,
                      vector<vector<int>>& attackedPlayerOne, vector<vector<int>>& attackedPlayerTwo,
                      int& boatMax);
void victoryCheck(int playerBoatNumber, int boatMax, bool player);





// Définition de la Fonction pour ouvrir le menu principal
int showOpeningMenu(bool comingFromSettings) {
  int menuChoice = -1;

  do {
    for (int i = 0; i < 10; ++i) {
      for (const auto &j : batailleNavaleAsciiArray)
        cout << j;

      if (debug) {
        //Affichage séparateur spécifique pour mode debug
        cout << dye::grey("\n___________________________________________________________________________________") << dye::green("\"`-._,-\'\"`-._,-\'\"`-._,-\'\"`-") << dye::grey("__________\n\n");
      } else
        //Affichage spécifique pour menu principal
        cout << dye::grey("\n___________________________________________________________________________________") << dye::aqua("\"`-._,-\'\"`-._,-\'\"`-._,-\'\"`-") << dye::grey("__________\n\n");

      //Animation avion paramètre
      for (auto &j : planewithMenuBannerAsciiArray) {
        cout << dye::white(j);
        j.insert(0, "      ");
      }

      if (debug) {
        cout << "\n\n";
        cout << dye::green(separatorWaveAscii[i]);
        cout << "\n\n";
        cout << dye::light_green(separatorWaveAscii[i + 1]);
        cout << "\n\n";
        cout << dye::green(separatorWaveAscii[i + 2]);
        cout << "\n\n";
        cout << dye::light_green(separatorWaveAscii[i + 3]);
      } else {
        cout << "\n\n";
        cout << dye::aqua(separatorWaveAscii[i]);
        cout << "\n\n";
        cout << dye::blue(separatorWaveAscii[i + 1]);
        cout << "\n\n";
        cout << dye::aqua(separatorWaveAscii[i + 2]);
        cout << "\n\n";
        cout << dye::blue(separatorWaveAscii[i + 3]);
      }

      if (i != 9) {
        if (debug) {
          cout << "\n\n";
          cout << dye::green(separatorWaveAscii[i + 4]);
          cout << "\n\n";
          cout << dye::light_green(separatorWaveAscii[i + 5]);
          cout << "\n\n";
          cout << dye::green(separatorWaveAscii[i + 6]);
        } else {
          cout << "\n\n";
          cout << dye::aqua(separatorWaveAscii[i + 4]);
          cout << "\n\n";
          cout << dye::blue(separatorWaveAscii[i + 5]);
          cout << "\n\n";
          cout << dye::aqua(separatorWaveAscii[i + 6]);
        }
        sleep_for(150ms);
        system("CLS");
      }
    }

    //Reset animation avion avec paramètres
    for (int i = 0; i < 10; ++i) {
      for (auto &j : planewithMenuBannerAsciiArray)
        j.erase(0, 6);
    }
    cout << "\n";
    for (const auto &i : saisirChoixAsciiArray)
      cout << "  " << i << "\n";

    cout << "\n\n>> ";
    cin >> menuChoice;

    //menu mode debug
    if (menuChoice == 44) {
      if(debug){
        debug = false;
      }else{
        debug = true;
      }
    } else if (menuChoice == 3) {
      system("CLS");
      for (int i = 0; i < 12; ++i) {
        for (const auto &j : batailleNavaleAsciiArray)
          cout << j;

        if (debug)
          cout << dye::grey("\n___________________________________________________________________________________") << dye::green("\"`-._,-\'\"`-._,-\'\"`-._,-\'\"`-") << dye::grey("__________\n\n");
        else
          cout << dye::grey("\n___________________________________________________________________________________") << dye::aqua("\"`-._,-\'\"`-._,-\'\"`-._,-\'\"`-") << dye::grey("__________\n\n");

        for (auto &j : planeAsciiArray) {
          cout << j;
          j.insert(0, "      ");
        }

        if (debug) {
          cout << "\n\n";
          cout << dye::green(separatorWaveAscii[i]);
          cout << "\n\n";
          cout << dye::light_green(separatorWaveAscii[i + 1]);
          cout << "\n\n";
          cout << dye::green(separatorWaveAscii[i + 2]);
          cout << "\n\n";
          cout << dye::light_green(separatorWaveAscii[i + 3]);
          cout << "\n\n";
          cout << dye::green(separatorWaveAscii[i + 4]);
          cout << "\n\n";
          cout << dye::light_green(separatorWaveAscii[i + 5]);
        } else {
          cout << "\n\n";
          cout << dye::aqua(separatorWaveAscii[i]);
          cout << "\n\n";
          cout << dye::blue(separatorWaveAscii[i + 1]);
          cout << "\n\n";
          cout << dye::aqua(separatorWaveAscii[i + 2]);
          cout << "\n\n";
          cout << dye::blue(separatorWaveAscii[i + 3]);
          cout << "\n\n";
          cout << dye::aqua(separatorWaveAscii[i + 4]);
          cout << "\n\n";
          cout << dye::blue(separatorWaveAscii[i + 5]);
        }

        if (i != 11) {
          sleep_for(150ms);
          system("CLS");
        } else {
          system("CLS");
        }
      }
      for (int i = 0; i < 12; ++i) {
        for (auto &j : planeAsciiArray)
          j.erase(0, 6);
      }
    }
  } while (menuChoice < 1 || menuChoice > 3);

  return menuChoice;
}

// Définition de la Fonction pour récupérer le nom des joueurs
string getName(int player) {
  string name;
  for (const auto & i : saisisNomJoueurAsciiArray) {
    cout << i << "\n";
  }
  showLineSeparator(false, true);
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  if (player == 1){
    for (const auto & i : playerOneAsciiArray) {
      cout << dye::light_purple(i) << "\n";
    }
    cout << "\n>> ";
    cin >> name;
    return name;
  }else{
    for (const auto & i : playerTwoAsciiArray) {
      cout << dye::light_green(i) << "\n";
    }
    cout << "\n>> ";
    cin >> name;
    return name;
  }


}


// Définition de la Fonction pour afficher une ligne séparatrice standard
void showLineSeparator(bool startDoubleReturnLine, bool endDoubleReturnLine, bool startOneReturn, bool endOneReturn) {
    string separator;

    if (startDoubleReturnLine) {
        separator += "\n\n";
    } else if (startOneReturn) {
        separator += "\n";
    }

    separator += "________________________________________________________________________________________________________________________";

    if (endDoubleReturnLine) {
        separator += "\n\n";
    } else if (endOneReturn) {
        separator += "\n";
    }

    cout << dye::white(separator);
}

// Définition de la Fonction pour afficher grille vierge ou deux pour les paramètres
void showEmptyGrid(int size1, int size2, bool showNumbers, int tabulation) {
  // Affichage des numéros de colonne pour la première grille
  if (showNumbers) {
    cout << string(tabulation, '\t');
    for (int i = 0; i < size1; i++) {
      cout << "   " << i + 1;
    }
  }

  // Ajouter un espacement entre les deux grilles si nécessaire
  if (size2 != -1 && showNumbers) {
    cout << "\t   ";
    for (int i = 0; i < size2; i++) {
      cout << "   " << i + 1;
    }
  }

  // Ajouter un retour à la ligne après l'affichage des numéros de colonne
  cout << "\n";

  // Affichage des grilles côte à côte
  for (int i = 0; i < max(size1, size2); i++) {
    // Affichage de la ligne i pour la première grille
    if (i < size1) {
      if (showNumbers) {
        cout << string(tabulation, '\t') << i + 1 << " ";
      } else {
        cout << string(tabulation, '\t');
      }

      for (int j = 0; j < size1; j++) {
        cout << " \xDB\xDB ";
      }
    }

    // Ajouter un espacement entre les deux grilles si nécessaire
    if (size2 != -1 && i < size2) {
      cout << string(tabulation, '\t');
    }

    // Affichage de la ligne i pour la deuxième grille
    if (size2 != -1 && i < size2) {
      if (showNumbers) {
        cout << "   " << i + 1;
      }

      for (int j = 0; j < size2; j++) {
        cout << " \xDB\xDB ";
      }
    }
    cout << "\n";

    // Ajouter un retour à la ligne supplémentaire entre chaque ligne
    if (i < max(size1, size2) - 1) {
      cout << "\n";
    }
  }

  cout << "\n";
}

// Définition de la Fonction du menu des paramètres
void showSettingsMenu(vector<vector<bool>>& playerOne, vector<vector<bool>>& playerTwo,
               vector<vector<int>>& attackedPlayerOne, vector<vector<int>>& attackedPlayerTwo,
               int& boatMax) {
    playerOne.clear();
    playerTwo.clear();
    attackedPlayerOne.clear();
    attackedPlayerTwo.clear();

    int newBoatMax = -1;
    int newSize = -1;
    int menuChoice = -1;
    string confirmTileSize = "N", confirmBoatNumber = "N";
    string concatenatedBoats;

    system("CLS");

    do {

      //Affichage menu paramètres
      for (const auto & i : parametreAsciiArray) {
        cout << dye::bright_white(i);
      }
      //Affichage séparateur paramètres avec vagues
      cout << dye::grey("_____________________________________________________________________________________________") << dye::aqua("~^~") << dye::bright_white("\\______t/") << dye::aqua("~^~") << dye::grey("____________") << "\n                                                                                               " << dye::aqua("~^~^~^~^~^~");

      /*
      for (auto & i : gear_icon) {
        cout << i << "\n";
      }
      */

      cout << "\n1. Changement taille zone combat (Actuellement : " << (sizeof(playerOne) / 3) << "x" << (sizeof(playerOne) / 3) << ")\n";
      cout << "2. Changement nombre de bateaux (Actuellement : " << boatMax << ")\n";
      cout << "3. Revenir au menu principal";
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

      for (const auto & i : saisirChoixEtMilitaryBoatOneAsciiArray) {
        cout << dye::bright_white(i) << "\n";
      }
      cout << "\n>> ";
      cin >> menuChoice;
      sleep_for(500ms);
      system("CLS");

      switch (menuChoice) {
        case 1:
          do {
            //Entête des options
            for (const auto & i : parametreAsciiArray) {
              cout << i;
            }
            //Affichage séparateur paramètres avec vagues
            cout << dye::grey("_____________________________________________________________________________________________") << dye::aqua("~^~") << dye::bright_white("\\______t/") << dye::aqua("~^~") << dye::grey("____________") << "\n                                                                                               " << dye::aqua("~^~^~^~^~^~\n");

            if(newSize == -1){
              // Demander la taille uniquement si elle n'a pas encore été saisie
              cout << "\tGrille actuelle (par défaut : 8x8) : \n\n";
              showEmptyGrid(8,-1, true, 1);
              cout << "\n\nSaisir la nouvelle taille de la zone de combat (ex: 8 pour une grille 8x8) \n";
              cout << ">> ";
              cin >> newSize;
            }else {
              // Afficher l'ancienne et la nouvelle grille pour confirmation
              cout << "\tAncienne grille : \t\t\tNouvelle grille (" << newSize << "x" << newSize << ") :"  "\n\n";
              showEmptyGrid(8,newSize, true, 1);
              cout << dye::bright_white("\n\nConfirmer votre choix (") << dye::green("Y") << "/" << dye::red("N") << dye::bright_white(")\n");
              cout << ">> ";
              cin >> confirmTileSize;
              if (confirmTileSize == "N"){
                newSize = -1;
              }

            }
            system("CLS");
          } while (confirmTileSize == "N" || newSize > 20 || newSize < 2);
        break;
      case 2:
        for (const auto & i : parametreAsciiArray) {
          cout << i;
        }
        //Affichage séparateur paramètres avec vagues
        cout << dye::grey("_____________________________________________________________________________________________") << dye::aqua("~^~") << dye::bright_white("\\______t/") << dye::aqua("~^~") << dye::grey("____________") << "\n                                                                                               " << dye::aqua("~^~^~^~^~^~\n");

        cout << "\nVoici les " << boatMax << " bateaux à votre disposition :\n\n";
        //Affichage bateaux
        for (int i = 0; i < 8; ++i) {
          for (int j = 0; j < boatMax; ++j) {
            concatenatedBoats.append(boatMiniAsciiTwo[i]);
          }
          concatenatedBoats.append("\n"); // Add a new line after each row
        }
        cout << concatenatedBoats ;

        cout << "\nVoulez vous en appeler plus ? (Y/N)\n";
        cin >> confirmBoatNumber;


        cout << "\n\nSaisir le nombre disponible de bateaux par joueur (" << boatMax << " bateaux pour l\'instant)\n";
        cout << ">> ";
        cin >> newBoatMax;
        boatMax = newBoatMax;
        showOpeningMenu(true);
        break;
      case 3:
        showOpeningMenu(true);
        break;
      }

      } while (menuChoice < 1 || menuChoice > 3);

    //(newBoatMax - 4) > (newSize*newSize)

    // Resize and initialize the vectors
    if (menuChoice != 3){
        playerOne.resize(newSize, vector<bool>(newSize, false));
        playerTwo.resize(newSize, vector<bool>(newSize, false));
        attackedPlayerOne.resize(newSize, vector<int>(newSize, 0));
        attackedPlayerTwo.resize(newSize, vector<int>(newSize, 0));
        cout << "Paramètres prit en compte avec succès\n";
    }


    sleep_for(1s);
    system("CLS");
}

// Définition de la fonction pour installer les bateaux
vector<vector<bool>> miseEnPlaceBateau(vector<vector<bool>>& settingUpBoard, int boatMax, bool player, string playerName, bool debug) {

    //Variable declaration
    int latitude = 0, longitude = 0, playerBoatNumber = 0;
    system("CLS");
    //Condition si mode debug = true alors choix auto des placement bateaux
    if (debug){
      do {
        //cout << "\n";
        system("CLS");
        for (int i = 0; i < 7; ++i) {
          cout << dye::green(debugAsciiArray[i]) << "\t\t\t" << dye::bright_white(armyBoatAsciiArray[i]) << "\n";
        }
        cout << dye::grey("__________________________________________________") << dye::green(".~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.~\"(_.") << dye::grey("____\n\n");
        cout << dye::green("   Placement automatique pour ") << dye::bright_white(playerName) << dye::green(" :\n\n");
        if (player){
          settingUpBoard[0][playerBoatNumber] = true;
          playerBoatNumber++;
        } else {
          settingUpBoard[playerBoatNumber][0] = true;
          playerBoatNumber++;
        }
        showBoard(settingUpBoard);
        sleep_for(300ms);
      } while(playerBoatNumber < boatMax);
      system("PAUSE");
      return settingUpBoard;
    } else { // Condition si !debug donc mode normal
      do {
        // Boucle pour saisir les coordonnées de ses bateaux à un emplacement vide
        do {
          for (int i = 0; i < 2; ++i) {
            //Affichage titre Mise en place
            for (const auto & j : miseEnPlaceAsciiArray) {
              cout << j;
            }
            cout << dye::white("\n___________________________________________________________________________________") << dye::aqua("\"`-._,-\'\"`-._,-\'\"`-._,-\'\"`-") << dye::white("__________\n\n");
            cout << "   Au tour de " << playerName << ".\n\n";
            showBoard(settingUpBoard);

            if (i == 0){
              cout << "Saisir la latitude\n";
              cout << ">> ";
              cin >> latitude;
              latitude--;
            }else{
              cout << "Saisir la longitude\n";
              cout << ">> ";
              cin >> longitude;
              longitude--;
            }
            system("CLS");
          }
        } while (settingUpBoard[latitude][longitude]);
        settingUpBoard[latitude][longitude] = true;
        playerBoatNumber++;
        cout << "\n";
        showBoard(settingUpBoard);
        system("CLS");

      } while (playerBoatNumber < boatMax);
    }
  //Boucle pour placer le nombre max de bateaux

    //Affichage titre Mise en place et bateau
    for (const auto & i : miseEnPlaceAsciiArray) {
      cout << i;
    }
    cout << dye::white("\n___________________________________________________________________________________") << dye::aqua("\"`-._,-\'\"`-._,-\'\"`-._,-\'\"`-") << dye::white("__________\n\n");

    showBoard(settingUpBoard);
    cout << dye::yellow("\nRappelez vous bien de l\'emplacement de vos bateaux\n");
    for (int i = 0; i < 15; ++i) {
        sleep_for(1s);
        cout << " * ";
    }
    system("CLS");
    return settingUpBoard;
}

// Définition de la Fonction pour afficher la grille
void showBoard(const vector<vector<bool>>& visualBoard) {
  //cout << "\n";

  // Affichage des en-têtes de colonnes
  cout << dye::white("     ");
  for (int i = 0; i < visualBoard[0].size(); i++) {
    cout << "   " << i + 1;
  }
  cout << "\n";

  // Affichage du contenu du plateau de jeu
  for (int i = 0; i < visualBoard.size(); i++) {
    cout << "   " << i + 1 << "  ";
    for (int j = 0; j < visualBoard[i].size(); j++) {
      cout << (visualBoard[i][j] ? dye::red(" \xDB\xDB ") : dye::aqua(" \xDB\xDB "));
    }
    cout << "\n\n";
  }

}

// Définition de la Fonction pour attaquer
vector<vector<int>> attackShipMenu(vector<vector<int>>& attackedBoard, const vector<vector<bool>>& enemyBoard,
                               bool player, string playerName, int boatMax, int playerNumberOfTurn) {


  system("CLS");
  int latitude = 0, longitude = 0;


  do {
    for (int i = 0; i < 3; ++i) {
      //cout << "\n";
      for (int j = 0; j < 7; ++j) {
        cout << dye::red(menuAttaqueAsciiArray[j]) << "\t" << dye::bright_white(armyBoatAsciiArray[j]) << "\n";
      }
      showLineSeparator(false,false,false);
      cout << "\n";
      cout << "Au tour de " << playerName;
      cout << "\n";

      if (i == 0){
        showAttackedBoard(attackedBoard, player, boatMax);
        cout << dye::red("Entrez la latitude >> ");
        cin >> latitude;
      } else if(i == 1) {
        showAttackedBoard(attackedBoard, player, boatMax);
        cout << dye::red("Entrez la longitude >> ");
        cin >> longitude;
      } else {
        latitude--, longitude--;
        if (enemyBoard[latitude][longitude]) {
          if(attackedBoard[latitude][longitude] == 1){
            showAttackedBoard(attackedBoard, player, boatMax);
            cout << dye::yellow("Déjà Touché\n");
            playerNumberOfTurn--;
          }else{
            attackedBoard[latitude][longitude] = 1;
            showAttackedBoard(attackedBoard, player, boatMax);
            cout << dye::green("Touché\n");
            playerNumberOfTurn--;
          }
        } else {
          attackedBoard[latitude][longitude] = 2;
          showAttackedBoard(attackedBoard, player, boatMax);
          cout << dye::red("Manqué\n");
          playerNumberOfTurn--;
        }
        sleep_for(1s);
      }
      system("CLS");
    }

  } while (enemyBoard[latitude][longitude] || playerNumberOfTurn == 0);
  return attackedBoard;
}

// Définition de la Fonction pour afficher le terrain attaqué
int showAttackedBoard(const vector<vector<int>>& attackedBoard, bool player, int boatMax) {

  int playerAttackedBoatNumber = 0;
  // Affichage des en-têtes de colonnes
  cout << dye::white("\t");
  for (int i = 0; i < attackedBoard[0].size(); i++) {
    cout << "   " << i + 1;
  }
  cout << "\n\n";

  // Affichage du contenu du plateau de jeu attaqué
  for (int i = 0; i < attackedBoard.size(); i++) {
    cout << "\t" << i + 1 << " ";
    for (int j = 0; j < attackedBoard[i].size(); j++) {
      switch (attackedBoard[i][j]) {
      case 0:
        cout << dye::white(" \xDB\xDB ");
        break;
      case 1:
        cout << dye::red(" \xDB\xDB ");
        playerAttackedBoatNumber++;
        break;
      case 2:
        cout << dye::yellow(" \xDB\xDB ");
        break;
      }
    }
    cout << "\n\n";
  }
  cout << "\n\n";
  victoryCheck(playerAttackedBoatNumber, boatMax, player);
  return playerAttackedBoatNumber;
  // Affichage des en-têtes de colonnes
  /*
  for (const auto & i : antennaSatellite) {
      std::cout << dye::green(i);
  }
  */
}

//Définition de la Fonction pour check Victory
void victoryCheck(int playerBoatNumber, int boatMax, bool player){
  if (playerBoatNumber == boatMax){
    if(!player){
      victory = 1;
    }else{
      victory = 2;
    }
  }
}


int main() {
    //Déclaration et définition des vecteurs (Plateau personnel des joueurs)
    vector<vector<bool>> playerOne(8, vector<bool>(8, false));
    vector<vector<bool>> playerTwo(8, vector<bool>(8, false));

    //Déclaration et définition des vecteurs (Plateau public des joueurs)
    vector<vector<int>> attackedPlayerOne(8, vector<int>(8, 0));
    vector<vector<int>> attackedPlayerTwo(8, vector<int>(8, 0));


    //Boucle pour affichage titre ASCII menu principal avec le bateau et menu Mise en place avec le bateau
    for (int j = 0; j < 6; ++j) {
      batailleNavaleAsciiArray[j].append(boatAsciiArray[j]);
      miseEnPlaceAsciiArray[j].append("\t");
      miseEnPlaceAsciiArray[j].append(boatAsciiArray[j]);
    }
    //Boucle pour affichage titre ASCII menu paramètre
    for (int i = 0; i < 5 ; ++i) {
      parametreAsciiArray[i].insert(0, menuAsciiArray[i]);
      parametreAsciiArray[i].append("\t");
      parametreAsciiArray[i].append(boatMiniAsciiOne[i]);
    }


    sleep_for(2s);
    do {
        menuChoice = showOpeningMenu();
        switch (menuChoice) {
        case 1:
          if (!debug) {
            playerOneName = getName(1);
            system("CLS");
            playerTwoName = getName(2);
            system("CLS");
          } else {
            playerOneName = "player 1 (Debug)";
            playerTwoName = "player 2 (Debug)";
          }
          if (!debug) {
            cout << "\n\n";
            cout << "Au tour de " << playerOneName << " de placer ses bateaux\n";
            sleep_for(2s);
            system("CLS");
          }
          playerOne =
              miseEnPlaceBateau(playerOne, boatMax, false, playerOneName, debug);
          showBoard(playerOne);
          system("CLS");

          if (!debug) {
            cout << "\n\n";
            cout << "Au tour de " << playerTwoName
                 << " de placer ses bateaux\n";
            sleep_for(2s);
            system("CLS");
          }
          playerTwo =
              miseEnPlaceBateau(playerTwo, boatMax, true, playerTwoName, debug);
          showBoard(playerTwo);
          system("CLS");
          do {

            cout << "\n\n";
            cout << playerOneName << ", c'est à vous de jouer !\n";
            attackedPlayerTwo =
                attackShipMenu(attackedPlayerTwo, playerTwo, false, playerOneName, boatMax, playerNumberOfTurn);
            // showBoard(playerTwo);
            sleep_for(2s);


            system("CLS");
            cout << "\n\n";
            cout << playerTwoName << ", c'est à vous de jouer !\n";
            attackedPlayerOne =
                attackShipMenu(attackedPlayerOne, playerOne, true, playerTwoName, boatMax, playerNumberOfTurn);

            // showBoard(playerOne);
            sleep_for(2s);
          } while (victory == 0);
          break;

        case 3:
          showSettingsMenu(playerOne, playerTwo, attackedPlayerOne,
                           attackedPlayerTwo, boatMax);
          break;

        default:
          cout << "Choix invalide.\n";
          break;

        }
    //if (victory != 0){break;}
    } while (menuChoice > 3 || menuChoice < 1);
    if (victory == 1){
      cout << dye::bright_white(playerOneName) << dye::bright_white(" à ") << dye::green("Gagné\n");
      cout << dye::bright_white(playerTwoName) << dye::bright_white(" à ") << dye::red("Perdu");
    } else {
      cout << dye::bright_white(playerTwoName) << dye::bright_white(" à ") << dye::green("Gagné\n");
      cout << dye::bright_white(playerOneName) << dye::bright_white(" à ") << dye::red("Perdu");
    }
    system("PAUSE");
    return 0;
}
