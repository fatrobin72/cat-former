void startScreen(){
    set_bkg_data(0,138,startscreen_data);
    set_bkg_tiles(0,0,20,18, startscreen_map);

    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);
}