#include <gb/gb.h>
#include <stdio.h>
#include "player.h"
#include "mc.c"
#include "aloo_npc.h"

void setup();
void update();

UINT16 clock_count = 0;
UINT16 IDEAL_CLOCK_COUNT = 3500;

void main() {
    
    setup();

    while(1){
		
        update();

	}
}

void setup() {
    SPRITES_8x16;

    set_sprite_data(0, 38, mc);

    player_setup();

    SHOW_SPRITES;
}

void update() {
    clock_count++;

    if (clock_count == IDEAL_CLOCK_COUNT)
    {
        player_update();
        aloo_npc_update();
    }
    
    if (clock_count > IDEAL_CLOCK_COUNT)
    {
        clock_count = 0;
    }
}
