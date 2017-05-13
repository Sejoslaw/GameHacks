/**
        Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw


        This program is a base for registry and memory hacking tutorials.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/// Structure which will be tested.
typedef struct Player {
    int posX, posY;
} Player;

/// Returns pointer to new Player.
Player* get_new_player()
{
    Player *new_player = malloc(sizeof(Player));
    new_player->posX = 0;
    new_player->posY = 0;
    return new_player;
}

int main(int argc, char *argv[])
{
    SetConsoleTitle("GH_MemoryChange");

    Player* player = get_new_player();

    char print = 'o';
    while(print != 'p')
    {
        if(print == 'a') /// Left
            player->posX--;
        else if(print == 'd') /// Right
            player->posX++;
        else if(print == 'w') /// Up
            player->posY++;
        else if(print == 's') /// Down
            player->posY--;

        printf("Player[X=%i ,Y=%i] \n", player->posX, player->posY); /// For checking the position
        scanf("%c", &print);
        system("cls");
    }
}
