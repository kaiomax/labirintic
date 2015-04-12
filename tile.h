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
    void getType();
private:
    Type _type;
};

#endif
