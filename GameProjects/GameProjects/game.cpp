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
    RoomRegistry reg;
    int currentRoomId=0;
    std::ifstream input("../Elemets/world.txt");
    if (input.is_open()) {

        currentRoomId=reg.loadFormsStream(input);

        draw("../Pictures/GameName.txt");
        Sleep(2500);
        if (mainmenu() == false) { return; }
        typewriter("какой-то текст предыстории");
        //if (gameovermenu() == false) { return; }
        while (true) {
            int currentRoomIdtmp;      
            const RoomDef* currentRoom = reg.getRoomDef(currentRoomId);
            std::vector <std::string> choices;
            std::transform(
                currentRoom->conectedRooms.begin(),
                currentRoom->conectedRooms.end(),
                std::back_inserter(choices),
                [&reg](int roomId) { return reg.getRoomDef(roomId)->name; });
            int choice = dialog(currentRoom->description, "Куда идём?>", choices); 
            currentRoomIdtmp = currentRoom->conectedRooms[choice];
            if (!reg.getRoomDef(currentRoomIdtmp)->locked) { currentRoomId = currentRoomIdtmp; }
            else {std::cout << "Закрыто..." << std::endl;}
        }
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

int Game::dialog(const std::string& message, const std::string& promt, const std::vector<std::string>& choices)
{
    typewriter(message);

    typewriter(promt);

    for (int i = 0; i < choices.size(); i++) {
        std::cout << i + 1 << ". " << choices[i] << std::endl;
    }

    typewriter(promt);
    std::string choice;
    std::vector <std::string> words;
    do {
        std::cin>>choice;
        words = sepstring(choice);
    } while (!(isint(words[0]) or (std::stoi(words[0]) < 1) or (std::stoi(words[0]) > choices.size())));

    return (std::stoi(words[0])-1);

}

