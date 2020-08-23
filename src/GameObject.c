typedef struct GameObject{
    UINT8 LogicalXTile;
    UINT8 ActualX;
    UINT8 ActualY;
    UBYTE spriteid;
    UINT8 width;
    UINT8 height;
    BYTE visable;
    BYTE collected;

} GameObject;