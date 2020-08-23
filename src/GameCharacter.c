typedef struct GameCharacter{
    UINT8 LogicalXTile;
    UINT8 ActualX;
    UINT8 ActualY;
    UBYTE spriteids[2];
    UINT8 width;
    UINT8 height;
    BYTE jumping;
    INT8 currentSpeedY;

} GameCharacter;