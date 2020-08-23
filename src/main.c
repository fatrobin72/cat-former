#include <stdio.h>
#include <gb/gb.h>
#include <gb/font.h>


#include "Sprites.c"
#include "Objects.c"
#include "map1.c"
#include "map2.c"
#include "map3.c"
#include "blankMap.c"
#include "TileSet.c"
#include "WindowMap.c"

#include "GameCharacter.c"
#include "EnemyCharacter.c"
#include "GameObject.c"
#include "lib.c"
#include "soundEffects.c"
#include "BackgroundInteractions.c"
#include "player.c"
#include "Enemy.c"
#include "card.c"

#include "startscreen_data.c"
#include "startscreen_map.c"
#include "startscreen.c"

#include "GameOver_data.c"
#include "GameOver_map.c"
#include "GameOverScreen.c"

#include "YouWin_data.c"
#include "YouWin_map.c"
#include "WinScreen.c"

#include "plainSplashScreen.c"




UBYTE gamerunning;
UBYTE level1Win = 0;
UBYTE level2Win = 0;
UBYTE level3Win = 0;

UINT8 columnOffset = 0; 
BYTE ScrollXFlag = 0; // should range between -8 (scroll Left) and +8 (scroll right)
WORD counter = 0;
const char BackStory[] = " Zoey has lost all\n  her Magic Cards.\n\n   Travel Through\n  Extra History To\n  Collect them All.\n\n Take Care to Avoid\ntouching anyone and\n  changing history.\n\nIt's London in 1720,avoid the thieves &\nThief Taker General\n\n\n   Press Start to\n      Continue";
const char Level1ClearMessage[] = "\n\n\n\n\n\n\n   Level 1 clear.\n    Press Start\n    for Level 2";
const char Level2ClearMessage[] = "\n\n\n\n\n\n\n   Level 2 clear.\n    Press Start\n    for Level 3";




void resetGameLogic(){
    columnOffset = 0; 
    ScrollXFlag = 0;
    counter = 0;
    cards_collected[0] = noCards[0];
    move_bkg(0,0);  
}

void drawBackground1(UBYTE startY, UBYTE width){
    for( UBYTE i = 0; i != backgroundMap1Height; i++ ){

                set_bkg_tiles( startY , i, width, 1, &backgroundMap1[counter]);
                counter = counter + backgroundMap1Width;
            }
}

void DrawLevel1(){
    resetGameLogic();
    font_t min_font;
    font_init();
    min_font = font_load(font_min); // 36 tiles
    font_set(min_font);

    set_sprite_data(0, 6, Sprites);
    set_sprite_data(7,1, Objects);
    set_bkg_data(37, 9, TileSet);
    drawBackground1(0, 22);

    set_win_tiles(0,0,7,2,windowMap);
    set_win_tiles(6,1,1,1, lives);
    move_win(24,128);
    
    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    Map1SetupEnemies();
    Map1SetupCards();

}

void drawBackground2(UBYTE startY, UBYTE width){
    for( UBYTE i = 0; i != backgroundMap2Height; i++ ){

                set_bkg_tiles( startY , i, width, 1, &backgroundMap2[counter]);
                counter = counter + backgroundMap2Width;
            }
}

void DrawLevel2(){
    resetGameLogic();
    font_t min_font;
    font_init();
    min_font = font_load(font_min); // 36 tiles
    font_set(min_font);

    set_sprite_data(0, 6, Sprites);
    set_sprite_data(7,1, Objects);
    set_bkg_data(37, 9, TileSet);
    drawBackground2(0, 22);

    set_win_tiles(0,0,7,2,windowMap);
    set_win_tiles(6,1,1,1, lives);
    move_win(24,128);
    
    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    Map2SetupEnemies();
    Map2SetupCards();

}

void drawBackground3(UBYTE startY, UBYTE width){
    for( UBYTE i = 0; i != backgroundMap3Height; i++ ){

                set_bkg_tiles( startY , i, width, 1, &backgroundMap3[counter]);
                counter = counter + backgroundMap3Width;
            }
}

void DrawLevel3(){
    resetGameLogic();
    font_t min_font;
    font_init();
    min_font = font_load(font_min); // 36 tiles
    font_set(min_font);

    set_sprite_data(0, 6, Sprites);
    set_sprite_data(7,1, Objects);
    set_bkg_data(37, 9, TileSet);
    drawBackground3(0, 22);

    set_win_tiles(0,0,7,2,windowMap);
    set_win_tiles(6,1,1,1, lives);
    move_win(24,128);
    
    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    Map3SetupEnemies();
    Map3SetupCards();

}

void scroll(INT8 pixels){
    scroll_bkg(pixels, 0);
}

void loseLife(UINT8 MapNumber){
    lives[0]--;
    set_win_tiles(6,1,1,1, lives);
    if (lives[0] == noLives[0]){
        gamerunning = 0;
        GameOverScreen();
    }
    else{
        if (MapNumber == 1){
            hideEnemies();
            hideCards();
            DrawLevel1();
            setupPlayerSprite();
        }
        else if (MapNumber == 2){
            hideEnemies();
            hideCards();
            DrawLevel2();
            setupPlayerSprite();
        }
        else if (MapNumber == 3){
            hideEnemies();
            hideCards();
            DrawLevel3();
            setupPlayerSprite();
        }

    }

}

void checkCollisionsWithCards(){
    for( UBYTE i = 0; i < 3; i++ ){
        if (cards[i].visable == 1){
            if (checkCollisionsObject(&player, &cards[i])){
                cards_collected[0]++;
                set_win_tiles(6,0,1,1, cards_collected);
                move_sprite(cards[i].spriteid, 0,0);
                cards[i].visable=0;
                cards[i].collected=1;
            }
        }
    }
}

void checkCollisionsWithEnemies(UINT8 MapNumber){
    for( UBYTE i = 0; i < 3; i++ ){
        if (Enemies[i].visable == 1){
            if (checkCollisionsCharacter(&player, &Enemies[i].Character)){
                loseLife(MapNumber);
            }
        }
    }
}

void gameLoop(UINT8 MapNumber){
    while(gamerunning){
        
        DrawEnemiesWhoAreVisable(columnOffset);
        DrawCardsThatAreVisable(columnOffset);
        EnemyPatrol();
        checkCollisionsWithCards();
        checkCollisionsWithEnemies(MapNumber);

        if  (player.jumping == 0 && !wouldHitSurface((player.ActualY + 16) / 8, player.LogicalXTile, MapNumber)){
            player.jumping = 1;
            player.currentSpeedY = 0;
        }
        if((joypad() & J_A) || player.jumping == 1){
            jump(&player, MapNumber);
        }
        if(joypad() & J_LEFT){
            if (player.LogicalXTile >= 5){
                scroll(-HSpeed);
                ScrollEnemies(HSpeed);
                ScrollCards(HSpeed);
                ScrollXFlag = ScrollXFlag - HSpeed;
            }
        }
        if(joypad() & J_RIGHT){
            if (player.LogicalXTile == 59){
                if (cards_collected[0] == cards_target[0]){
                    gamerunning = 0;
                    HIDE_SPRITES;
                    if (MapNumber == 1){
                        level1Win = 1;
                    }
                    else if (MapNumber == 2){
                        level2Win = 1;
                    }
                    else if (MapNumber == 3){
                        level3Win = 1;
                    }
                    hideEnemies();
                    WinSound();
                }
            }
            else{
                scroll(HSpeed);
                ScrollEnemies(-HSpeed);
                ScrollCards(-HSpeed);
                ScrollXFlag = ScrollXFlag + HSpeed;
            }
        }

        if (ScrollXFlag == 8){
            ScrollXFlag = 0;
            columnOffset++;
            player.LogicalXTile++;
            counter = columnOffset + 21;
            if (MapNumber == 1){
                if (counter <= backgroundMap1Width - 1 && counter >= 0){
                    drawBackground1(counter % 32, 1);
                }
            }
            else if (MapNumber == 2){
                if (counter <= backgroundMap2Width - 1 && counter >= 0){
                    drawBackground2(counter % 32, 1);
                }
            }
            else if (MapNumber == 3){
                if (counter <= backgroundMap3Width - 1 && counter >= 0){
                    drawBackground3(counter % 32, 1);
                }
            }
        }
        else if (ScrollXFlag == -8){
            ScrollXFlag = 0;
            columnOffset--;
            player.LogicalXTile--;
            counter = columnOffset;
            if (MapNumber == 1){
                if (counter <= backgroundMap1Width - 1 && counter >= 0){
                    drawBackground1(counter % 32, 1);
                }
            }
            else if (MapNumber == 2){
                if (counter <= backgroundMap2Width - 1 && counter >= 0){
                    drawBackground2(counter % 32, 1);
                }
            }
            else if (MapNumber == 3){
                if (counter <= backgroundMap2Width - 1 && counter >= 0){
                    drawBackground3(counter % 32, 1);
                }
            }
            
        }

        performantDelay(3);
    }
}

void main(){
    soundInit();
    startScreen();
    plainSplashScreen(BackStory);
    DrawLevel1();
    setupPlayerSprite();
    
    gamerunning = 1;
    gameLoop(1);
    //level1Win =1;

    if (level1Win){
    //    WinScreen();
        plainSplashScreen(Level1ClearMessage);
        DrawLevel2();
        setupPlayerSprite();
    
        gamerunning = 1;
        gameLoop(2);
    }

    if (level2Win){
    //    WinScreen();
        plainSplashScreen(Level2ClearMessage);
        DrawLevel3();
        setupPlayerSprite();
    
        gamerunning = 1;
        gameLoop(3);
    }

    if (level1Win && level2Win && level3Win){
        WinScreen();
    }
}