GameCharacter player;
const INT8 gravity = -2;
const UINT8 HSpeed = 4;
const UINT8 VSpeed = 16;
const UINT8 playerX = 74;
const INT8 maxDownSpeed = -8;
unsigned char lives[1] = {0x0B};
const unsigned char maxLives[1] = {0x0B};
const unsigned char noLives[1] = {0x02};
UINT8 lifetimer = 0;


void jump(struct GameCharacter* character, UINT8 MapNumber){

    if(character->jumping==0){
        character->jumping=1;
        character->currentSpeedY = VSpeed;
        JumpingSound();
    }

    // work out current speed - effect of gravities accelleration down
    if (character->currentSpeedY + gravity >= -8){
        character->currentSpeedY = character->currentSpeedY + gravity;
    }
    else{
        character->currentSpeedY = -8;
    }

    UINT8 projectedYPosition = character->ActualY - character->currentSpeedY;

    if (wouldHitSurface((projectedYPosition + 16) / 8, character->LogicalXTile, MapNumber) && character->currentSpeedY < 0){
        character->jumping = 0;
        moveGameCharacter(character,playerX,(projectedYPosition / 8) * 8);
        character->ActualY=projectedYPosition;
    }
    else{
        moveGameCharacter(character,playerX,projectedYPosition);
        character->ActualY=projectedYPosition;
    }

}

void setupPlayerSprite(){
    player.height = 16;
    player.width = 8;
    player.spriteids[0] = 0;
    player.spriteids[1] = 1;
    player.LogicalXTile = playerX / 8;
    player.ActualX = playerX;
    player.ActualY = 120;
    player.currentSpeedY = 0;
    player.jumping = 0;
    set_sprite_tile(player.spriteids[0], 0);
    set_sprite_tile(player.spriteids[1], 1);
    moveGameCharacter(&player, player.ActualX, player.ActualY);
}