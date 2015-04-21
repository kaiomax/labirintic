#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "utils.h"
#include "tile.h"
#include "board.h"
#include "maze.h"
#include "character.h"
using namespace std;
using namespace constants;

int main() {
    float fps = 60;
    bool endGame = false;

    Board board;
    Maze maze(&board);
    Character player(&board, &maze);

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_set_new_display_flags(ALLEGRO_WINDOWED);

    ALLEGRO_DISPLAY *display = al_create_display(700, 700);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    while(!endGame) {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            int allegroKeyCode = event.keyboard.keycode;

            if(allegroKeyCode == ALLEGRO_KEY_ESCAPE)
                endGame = true;
            else
                player.move(allegroKeyCode);
        }

        if (!player.canMove) {
            maze.restart();
            player.goToStartPosition();
        }

        if (player.isWinner) {
            maze.generate();
            player.goToStartPosition();
            player.isWinner = false;
        }

        if (event.type == ALLEGRO_EVENT_TIMER) {
            board.draw();

            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
        }

    }

    if(player.isWinner)
        cout << "Parabéns! Você ganhou!" << endl;

    return 0;
}
