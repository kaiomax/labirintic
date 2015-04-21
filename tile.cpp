#include <iostream>
#include <allegro5/allegro.h>
#include "tile.h"
using namespace std;

void Tile::setType(Tile::Type type) {
    this->type = type;
}

ALLEGRO_COLOR Tile::color() {
    switch(this->type) {
        case PATH:
            return al_map_rgb(236, 240, 241);
        case WALL:
            return al_map_rgb(52, 73, 94);
        case ALFA:
            return al_map_rgb(241, 196, 15);
        case OMEGA:
            return al_map_rgb(22, 160, 133);
        case LOCKED:
            return al_map_rgb(192, 57, 43);
    }
}
