//#include "GameCharacter.c"

void performantDelay(UINT8 numloops){
    UINT8 i;
    for(i = 0; i < numloops; i++){
        wait_vbl_done();
    }     
}
void moveGameCharacter(struct GameCharacter* character, UINT8 x, UINT8 y){
    move_sprite(character->spriteids[0], x, y);
    move_sprite(character->spriteids[1], x, y+8);
}
void hideGameCharacter(struct GameCharacter* character){
    move_sprite(character->spriteids[0], 0, 0);
    move_sprite(character->spriteids[1], 0, 0);
}
UBYTE checkCollisionsObject(GameCharacter* one, GameObject* two){
    return (one->ActualX >= two->ActualX && one->ActualX <= two->ActualX + two->width) &&
    (one->ActualY >= two->ActualY && one->ActualY <= two->ActualY + two->height) ||
    (two->ActualX >= one->ActualX && two->ActualX <= one->ActualX + one->width) &&
    (two->ActualY >= one->ActualY && two->ActualY <= one->ActualY + one->height);
}

UBYTE checkCollisionsCharacter(GameCharacter* one, GameCharacter* two){
    return (one->ActualX >= two->ActualX && one->ActualX <= two->ActualX + two->width) &&
    (one->ActualY >= two->ActualY && one->ActualY <= two->ActualY + two->height) ||
    (two->ActualX >= one->ActualX && two->ActualX <= one->ActualX + one->width) &&
    (two->ActualY >= one->ActualY && two->ActualY <= one->ActualY + one->height);
}