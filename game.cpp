#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "utils.h"
#include "tile.h"
#include "labyrinth.h"
#include "board.h"
#include "character.h"
using namespace std;
using namespace constants;

int main() {
    int alfa[2] = {2,5};
    int omega[2] = {8,13};
    int labyrinthTiles[16][2] = {
        {3,5},{4,5},{5,5},{6,5},{6,6},{6,7},{6,8},{6,9},{6,10},{6,11},
        {6,12},{6,13},{7,7},{8,7},{9,7},{10,7}
    };
    float fps = 60;
    bool endGame = false;

    Labyrinth labyrinth(alfa, omega, 16, labyrinthTiles);
    Board board(BOARD_ORDER, BOARD_ORDER, &labyrinth);
    Character player(&board);

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_set_new_display_flags(ALLEGRO_WINDOWED);

    ALLEGRO_DISPLAY *display = al_create_display(DISPLAY_SIZE, DISPLAY_SIZE);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    while(!endGame && !player.isWinner) {

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
            board.initialize();
            player.goToStartPosition();
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
