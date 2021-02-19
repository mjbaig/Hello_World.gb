#include <gb/gb.h>
#include <stdio.h>
#include "player.h"

void setup();
void update();


void main() {
    
    setup();

    while(1){
		
        update();

	}
}

void setup() {
    SPRITES_8x16;

    player_setup();

    SHOW_SPRITES;
}

void update() {
    player_update();
}
