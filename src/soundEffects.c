void soundInit(){
    NR52_REG = 0x80; // is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77; // sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF; // is 1111 1111 in binary, select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels

}

void JumpingSound(){
    NR10_REG = 0x00;
    NR11_REG = 0xC0;
    NR12_REG = 0x42;
    NR13_REG = 0xAA;
    NR14_REG = 0x86;
}

void WinSound(){

    NR41_REG = 0x07;
    NR42_REG = 0x54;
    NR43_REG = 0x1a;
    NR44_REG = 0xc0;
    performantDelay(2);

    NR41_REG = 0x07;
    NR42_REG = 0x54;
    NR43_REG = 0x1c;
    NR44_REG = 0xc0;
}