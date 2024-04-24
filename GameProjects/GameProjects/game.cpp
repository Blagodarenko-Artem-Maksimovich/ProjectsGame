#include "game.h"

Game::Game()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, height, width, TRUE);
    game_over = false;
}

int Game::random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    return dist(gen);
}

void Game::main_loop()
{
    draw("../Pictures/GameName.txt");
    Sleep(2500);
    if (mainmenu() == false) { return;}
    typewriter("какой-то текст предыстории");
    if ( gameovermenu() == false) { return; }
    while (true) {

    }

}

bool Game::mainmenu()
{
    system("cls");
    draw("../Pictures/MainMenu.txt");
    std::string main_menu_mode;
    while (true){
        std::cin >> main_menu_mode;
        if ((main_menu_mode == "play") or (main_menu_mode == "PLAY") or (main_menu_mode == "Play") or (main_menu_mode == "1")) {
            system("cls");
            return true;
        }
        else if ((main_menu_mode == "Exit") or (main_menu_mode == "exit") or (main_menu_mode == "EXIT") or (main_menu_mode == "2")) {
            game_over = true;
            return false;
        }
        else {
            system("cls");
            draw("../Pictures/MainMenu.txt");
        }
    }
}

bool Game::gameovermenu()
{
    system("cls");
    draw("../Pictures/GameOverMenu.txt");
    Sleep(2500);
    return (mainmenu());
}

