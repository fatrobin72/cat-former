EnemyCharacter Enemies[3];

void hideEnemies(){
    for( UBYTE i = 0; i < 3; i++ ){
        Enemies[i].visable = 0;
        hideGameCharacter(&Enemies[i].Character);  
    }
}
void DrawEnemiesWhoAreVisable(UINT8 columnOffset){
    UINT8 MinX = columnOffset;
    UINT8 MaxX = (columnOffset + 20);
    for( UBYTE i = 0; i < 3; i++ ){
        if (Enemies[i].Character.LogicalXTile >= MinX && Enemies[i].Character.LogicalXTile <= MaxX){
            if (Enemies[i].visable == 0){
                Enemies[i].visable = 1;
                Enemies[i].Character.ActualX = (Enemies[i].Character.LogicalXTile - columnOffset) * 8;
                moveGameCharacter(&Enemies[i].Character, Enemies[i].Character.ActualX, Enemies[i].Character.ActualY);
            }
        }
        else if (Enemies[i].visable == 1){
            Enemies[i].visable = 0;
            hideGameCharacter(&Enemies[i].Character);
        }
    }

}

void ScrollEnemies(BYTE distance){
    for( UBYTE i = 0; i < 3; i++ ){
        if (Enemies[i].visable == 1){
            Enemies[i].Character.ActualX = Enemies[i].Character.ActualX + distance;
            moveGameCharacter(&Enemies[i].Character, Enemies[i].Character.ActualX, Enemies[i].Character.ActualY);
        }
    }
}

void EnemyPatrol(){
    for( UBYTE i = 0; i < 3; i++ ){
        if (Enemies[i].visable == 1){
            if (Enemies[i].lastMoved == Enemies[i].moveFrequency){
                Enemies[i].lastMoved = 0;
                if ((Enemies[i].direction == 1 && Enemies[i].Character.LogicalXTile < Enemies[i].MostRightTile) || Enemies[i].Character.LogicalXTile == Enemies[i].MostLeftTile){
                    //Move Right
                    if (get_sprite_prop(Enemies[i].Character.spriteids[0]) == S_FLIPX){
                        set_sprite_prop(Enemies[i].Character.spriteids[0], get_sprite_prop(Enemies[i].Character.spriteids[0]) & ~S_FLIPX);
                        set_sprite_prop(Enemies[i].Character.spriteids[1], get_sprite_prop(Enemies[i].Character.spriteids[1]) & ~S_FLIPX);
                    }

                    Enemies[i].direction = 1;
                    Enemies[i].Character.ActualX = Enemies[i].Character.ActualX + 4;
                    moveGameCharacter(&Enemies[i].Character, Enemies[i].Character.ActualX, Enemies[i].Character.ActualY);
                }
                else if ((Enemies[i].direction == -1 && Enemies[i].Character.LogicalXTile > Enemies[i].MostLeftTile) || Enemies[i].Character.LogicalXTile == Enemies[i].MostRightTile)
                {
                    //Move Left
                    if (get_sprite_prop(Enemies[i].Character.spriteids[0]) != S_FLIPX){
                        set_sprite_prop(Enemies[i].Character.spriteids[0], S_FLIPX);
                        set_sprite_prop(Enemies[i].Character.spriteids[1], S_FLIPX);
                    }

                    Enemies[i].direction = -1;
                    Enemies[i].Character.ActualX = Enemies[i].Character.ActualX - 4;
                    moveGameCharacter(&Enemies[i].Character, Enemies[i].Character.ActualX, Enemies[i].Character.ActualY);
                }
                Enemies[i].halfwayThroughTile++;
                if (Enemies[i].halfwayThroughTile == 2){
                    Enemies[i].halfwayThroughTile = 0;
                    Enemies[i].Character.LogicalXTile = Enemies[i].Character.LogicalXTile + Enemies[i].direction;
                }
                
            }
            else{
                Enemies[i].lastMoved++;
            }
            
        }
    }
}

void Map1SetupEnemies(){
    Enemies[0].Character.LogicalXTile = 12;
    Enemies[0].Character.ActualY = 120;
    Enemies[0].Character.spriteids[0] = 2;
    Enemies[0].Character.spriteids[1] = 3;
    Enemies[0].Character.height = 16;
    Enemies[0].Character.width = 8;
    Enemies[0].visable = 0;
    Enemies[0].MostLeftTile = 12;
    Enemies[0].MostRightTile = 17;
    Enemies[0].halfwayThroughTile = 0;
    Enemies[0].moveFrequency = 6;
    Enemies[0].lastMoved = 0;
    Enemies[0].direction = 1;

    set_sprite_tile(Enemies[0].Character.spriteids[0], 2);
    set_sprite_tile(Enemies[0].Character.spriteids[1], 3);

    Enemies[1].Character.LogicalXTile = 30;
    Enemies[1].Character.ActualY = 120;
    Enemies[1].Character.spriteids[0] = 4;
    Enemies[1].Character.spriteids[1] = 5;
    Enemies[1].Character.height = 16;
    Enemies[1].Character.width = 8;
    Enemies[1].visable = 0;
    Enemies[1].MostLeftTile = 30;
    Enemies[1].MostRightTile = 35;
    Enemies[1].halfwayThroughTile = 0;
    Enemies[1].moveFrequency = 6;
    Enemies[1].lastMoved = 0;
    Enemies[1].direction = 1;

    set_sprite_tile(Enemies[1].Character.spriteids[0], 2);
    set_sprite_tile(Enemies[1].Character.spriteids[1], 3);

    Enemies[2].Character.LogicalXTile = 50;
    Enemies[2].Character.ActualY = 120;
    Enemies[2].Character.spriteids[0] = 6;
    Enemies[2].Character.spriteids[1] = 7;
    Enemies[2].Character.height = 16;
    Enemies[2].Character.width = 8;
    Enemies[2].visable = 0;
    Enemies[2].MostLeftTile = 50;
    Enemies[2].MostRightTile = 60;
    Enemies[2].halfwayThroughTile = 0;
    Enemies[2].moveFrequency = 4;
    Enemies[2].lastMoved = 0;
    Enemies[2].direction = 1;


    set_sprite_tile(Enemies[2].Character.spriteids[0], 4);
    set_sprite_tile(Enemies[2].Character.spriteids[1], 5);

    DrawEnemiesWhoAreVisable(0);
}

void Map2SetupEnemies(){
    Enemies[0].Character.LogicalXTile = 12;
    Enemies[0].Character.ActualY = 120;
    Enemies[0].Character.spriteids[0] = 2;
    Enemies[0].Character.spriteids[1] = 3;
    Enemies[0].Character.height = 16;
    Enemies[0].Character.width = 8;
    Enemies[0].visable = 0;
    Enemies[0].MostLeftTile = 12;
    Enemies[0].MostRightTile = 20;
    Enemies[0].halfwayThroughTile = 0;
    Enemies[0].moveFrequency = 5;
    Enemies[0].lastMoved = 0;
    Enemies[0].direction = 1;

    set_sprite_tile(Enemies[0].Character.spriteids[0], 2);
    set_sprite_tile(Enemies[0].Character.spriteids[1], 3);

    Enemies[1].Character.LogicalXTile = 30;
    Enemies[1].Character.ActualY = 120;
    Enemies[1].Character.spriteids[0] = 4;
    Enemies[1].Character.spriteids[1] = 5;
    Enemies[1].Character.height = 16;
    Enemies[1].Character.width = 8;
    Enemies[1].visable = 0;
    Enemies[1].MostLeftTile = 25;
    Enemies[1].MostRightTile = 30;
    Enemies[1].halfwayThroughTile = 0;
    Enemies[1].moveFrequency = 5;
    Enemies[1].lastMoved = 0;
    Enemies[1].direction = 1;

    set_sprite_tile(Enemies[1].Character.spriteids[0], 2);
    set_sprite_tile(Enemies[1].Character.spriteids[1], 3);

    Enemies[2].Character.LogicalXTile = 50;
    Enemies[2].Character.ActualY = 120;
    Enemies[2].Character.spriteids[0] = 6;
    Enemies[2].Character.spriteids[1] = 7;
    Enemies[2].Character.height = 16;
    Enemies[2].Character.width = 8;
    Enemies[2].visable = 0;
    Enemies[2].MostLeftTile = 55;
    Enemies[2].MostRightTile = 60;
    Enemies[2].halfwayThroughTile = 0;
    Enemies[2].moveFrequency = 3;
    Enemies[2].lastMoved = 0;
    Enemies[2].direction = 1;


    set_sprite_tile(Enemies[2].Character.spriteids[0], 4);
    set_sprite_tile(Enemies[2].Character.spriteids[1], 5);

    DrawEnemiesWhoAreVisable(0);
}

void Map3SetupEnemies(){
    Enemies[0].Character.LogicalXTile = 24;
    Enemies[0].Character.ActualY = 88;
    Enemies[0].Character.spriteids[0] = 2;
    Enemies[0].Character.spriteids[1] = 3;
    Enemies[0].Character.height = 16;
    Enemies[0].Character.width = 8;
    Enemies[0].visable = 0;
    Enemies[0].MostLeftTile = 24;
    Enemies[0].MostRightTile = 28;
    Enemies[0].halfwayThroughTile = 0;
    Enemies[0].moveFrequency = 4;
    Enemies[0].lastMoved = 0;
    Enemies[0].direction = 1;

    set_sprite_tile(Enemies[0].Character.spriteids[0], 2);
    set_sprite_tile(Enemies[0].Character.spriteids[1], 3);

    Enemies[1].Character.LogicalXTile = 30;
    Enemies[1].Character.ActualY = 120;
    Enemies[1].Character.spriteids[0] = 4;
    Enemies[1].Character.spriteids[1] = 5;
    Enemies[1].Character.height = 16;
    Enemies[1].Character.width = 8;
    Enemies[1].visable = 0;
    Enemies[1].MostLeftTile = 30;
    Enemies[1].MostRightTile = 40;
    Enemies[1].halfwayThroughTile = 0;
    Enemies[1].moveFrequency = 4;
    Enemies[1].lastMoved = 0;
    Enemies[1].direction = 1;

    set_sprite_tile(Enemies[1].Character.spriteids[0], 2);
    set_sprite_tile(Enemies[1].Character.spriteids[1], 3);

    Enemies[2].Character.LogicalXTile = 50;
    Enemies[2].Character.ActualY = 120;
    Enemies[2].Character.spriteids[0] = 6;
    Enemies[2].Character.spriteids[1] = 7;
    Enemies[2].Character.height = 16;
    Enemies[2].Character.width = 8;
    Enemies[2].visable = 0;
    Enemies[2].MostLeftTile = 45;
    Enemies[2].MostRightTile = 55;
    Enemies[2].halfwayThroughTile = 0;
    Enemies[2].moveFrequency = 2;
    Enemies[2].lastMoved = 0;
    Enemies[2].direction = 1;


    set_sprite_tile(Enemies[2].Character.spriteids[0], 4);
    set_sprite_tile(Enemies[2].Character.spriteids[1], 5);

    DrawEnemiesWhoAreVisable(0);
}
