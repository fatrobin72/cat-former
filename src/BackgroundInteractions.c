const char canStandOnTopOf[4] = {0x026, 0x027, 0x02A, 0x02D};
const unsigned char blank[1] = {0x000};


BYTE wouldHitSurface(UINT8 projectedYTile, UINT8 projectXTile, UINT8 MapNumber){
    char targetTile;
    UINT16 tileindexTL;
    BYTE hit = 0;

    if (MapNumber ==1){
        tileindexTL = backgroundMap1Width * (projectedYTile - 2) + (projectXTile - 1);

        targetTile = backgroundMap1[tileindexTL];

        for (UINT8 i = 0; i < 4; i++){

            if (targetTile == canStandOnTopOf[i]){
                hit = 1;
                break;
            }
        }
    }
    else if (MapNumber ==2){
        tileindexTL = backgroundMap2Width * (projectedYTile - 2) + (projectXTile - 1);

        targetTile = backgroundMap2[tileindexTL];

        for (UINT8 i = 0; i < 4; i++){

            if (targetTile == canStandOnTopOf[i]){
                hit = 1;
                break;
            }
        }
    }
    else if (MapNumber ==3){
        tileindexTL = backgroundMap3Width * (projectedYTile - 2) + (projectXTile - 1);

        targetTile = backgroundMap3[tileindexTL];

        for (UINT8 i = 0; i < 4; i++){

            if (targetTile == canStandOnTopOf[i]){
                hit = 1;
                break;
            }
        }
    }

    return hit;
}

