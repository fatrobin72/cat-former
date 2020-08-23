unsigned char cards_collected[1] = {0x02};
const unsigned char cards_target[1] = {0x05};
const unsigned char noCards[1] = {0x02};

GameObject cards[3];

void hideCards(){
    for( UBYTE i = 0; i < 3; i++ ){
        cards[i].visable = 0;
        move_sprite(cards[i].spriteid, 0,0); 
    }
}

void DrawCardsThatAreVisable(UINT8 columnOffset){
    UINT8 MinX = columnOffset;
    UINT8 MaxX = (columnOffset + 20);
    for( UBYTE i = 0; i < 3; i++ ){
        if (cards[i].collected == 0){
            if (cards[i].LogicalXTile >= MinX && cards[i].LogicalXTile <= MaxX){
                if (cards[i].visable == 0){
                    cards[i].visable = 1;
                    cards[i].ActualX = (cards[i].LogicalXTile - columnOffset) * 8;
                    move_sprite(cards[i].spriteid, cards[i].ActualX, cards[i].ActualY);
                }
            }
            else if (cards[i].visable == 1){
                cards[i].visable = 0;
                move_sprite(cards[i].spriteid, 0,0);
            }
        }
    }

}

void ScrollCards(BYTE distance){
    for( UBYTE i = 0; i < 3; i++ ){
        if (cards[i].visable == 1){
            cards[i].ActualX = cards[i].ActualX + distance;
            move_sprite(cards[i].spriteid, cards[i].ActualX, cards[i].ActualY);
        }
    }
}

void Map1SetupCards(){
    cards[0].LogicalXTile = 20;
    cards[0].ActualY = 96;
    cards[0].spriteid = 8;
    cards[0].width = 8;
    cards[0].height = 8;
    cards[0].collected = 0;
    set_sprite_tile(cards[0].spriteid, 7);

    cards[1].LogicalXTile = 32;
    cards[1].ActualY = 120;
    cards[1].spriteid = 9;
    cards[1].width = 8;
    cards[1].height = 8;
    cards[1].collected = 0;
    set_sprite_tile(cards[1].spriteid, 7);

    cards[2].LogicalXTile = 50;
    cards[2].ActualY = 96;
    cards[2].spriteid = 10;
    cards[2].width = 8;
    cards[2].height = 8;
    cards[2].collected = 0;
    set_sprite_tile(cards[2].spriteid, 7);

    DrawCardsThatAreVisable(0);
}

void Map2SetupCards(){
    cards[0].LogicalXTile = 20;
    cards[0].ActualY = 40;
    cards[0].spriteid = 8;
    cards[0].width = 8;
    cards[0].height = 8;
    cards[0].collected = 0;
    set_sprite_tile(cards[0].spriteid, 7);

    cards[1].LogicalXTile = 35;
    cards[1].ActualY = 80;
    cards[1].spriteid = 9;
    cards[1].width = 8;
    cards[1].height = 8;
    cards[1].collected = 0;
    set_sprite_tile(cards[1].spriteid, 7);

    cards[2].LogicalXTile = 50;
    cards[2].ActualY = 96;
    cards[2].spriteid = 10;
    cards[2].width = 8;
    cards[2].height = 8;
    cards[2].collected = 0;
    set_sprite_tile(cards[2].spriteid, 7);

    DrawCardsThatAreVisable(0);
}

void Map3SetupCards(){
    cards[0].LogicalXTile = 20;
    cards[0].ActualY = 20;
    cards[0].spriteid = 8;
    cards[0].width = 8;
    cards[0].height = 8;
    cards[0].collected = 0;
    set_sprite_tile(cards[0].spriteid, 7);

    cards[1].LogicalXTile = 35;
    cards[1].ActualY = 120;
    cards[1].spriteid = 9;
    cards[1].width = 8;
    cards[1].height = 8;
    cards[1].collected = 0;
    set_sprite_tile(cards[1].spriteid, 7);

    cards[2].LogicalXTile = 51;
    cards[2].ActualY = 40;
    cards[2].spriteid = 10;
    cards[2].width = 8;
    cards[2].height = 8;
    cards[2].collected = 0;
    set_sprite_tile(cards[2].spriteid, 7);

    DrawCardsThatAreVisable(0);
}