void GameOverScreen(){
    HIDE_SPRITES;
    HIDE_WIN;
    move_bkg(0,0);
    set_bkg_data(0,250,GameOver_data);
    set_bkg_tiles(0,0,20,18, GameOver_map);
}