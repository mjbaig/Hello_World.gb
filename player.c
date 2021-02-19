#include <gb/gb.h>
#include <stdio.h>
#include "player.h"
#include "mc.c"

short is_flipped = 0;

void player_setup() {
    set_sprite_data(0, 8, mc);
    set_sprite_tile(0, 0);
    move_sprite(0, 75, 75);
    
    set_sprite_tile(1, 2);
    move_sprite(1, 75 + 8, 75);
}

void player_update() {
    set_sprite_tile(1, 6);
    set_sprite_tile(0, 4);

    delay(250);
    set_sprite_tile(1,2);
    set_sprite_tile(0,0);

    int flip_toggle = get_sprite_prop(1) == S_FLIPX 
        ? 0x00 : 0x20;

    set_sprite_prop(1, S_FLIPX & flip_toggle);
    set_sprite_prop(0, S_FLIPX & flip_toggle);

    if (flip_toggle == 0x20) {
        move_sprite(0, 75 + 8, 75);
        move_sprite(1, 75, 75);
    } else {
        move_sprite(0, 75, 75);
        move_sprite(1, 75 + 8, 75);        
    }

    delay(250);
}