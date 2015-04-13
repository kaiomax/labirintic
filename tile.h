#ifndef _TILE_H_
#define _TILE_H_

class Tile {
public:
    enum Type {
        DEFAULT,
        WALL,
        ALFA,
        OMEGA
    };

    void setType(Tile::Type type);
    char getType();
private:
    Type type;
};

#endif
