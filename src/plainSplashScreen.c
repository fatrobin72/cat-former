void plainSplashScreen(const char *Message){
    move_bkg(0,0);
    HIDE_SPRITES;
    HIDE_WIN;
    set_bkg_tiles(0,0,20,18,BlankMap);
    printf(Message);

    waitpad(J_START);
}