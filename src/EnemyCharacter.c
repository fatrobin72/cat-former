//#include "GameCharacter.c"

typedef struct EnemyCharacter{
    GameCharacter Character;
    UBYTE MostLeftTile;
    UBYTE MostRightTile;
    BYTE visable;
    UBYTE halfwayThroughTile;
    UBYTE moveFrequency;
    UBYTE lastMoved;
    BYTE direction;

} EnemyCharacter;