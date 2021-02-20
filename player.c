#include <gb/gb.h>
#include <stdio.h>
#include "player.h"

short is_flipped = 0;

int player_step_toggle = 0x0U;

void player_step_down();

void player_setup() {

}

void player_update() {
    player_step_down();    
}

void player_step_down() {

    if (player_step_toggle == 1){
        set_sprite_tile(1,2);
        set_sprite_tile(0,0);
        player_step_toggle = 0;
    } else  {

        set_sprite_tile(1, 6);
        set_sprite_tile(0, 4);

        int flip_toggle = get_sprite_prop(1) == S_FLIPX 
            ? 0x00 : S_FLIPX;

        set_sprite_prop(1, S_FLIPX & flip_toggle);
        set_sprite_prop(0, S_FLIPX & flip_toggle);

        if (flip_toggle == S_FLIPX) {
            move_sprite(0, 80 + 8, 72);
            move_sprite(1, 80, 72);
        } else {
            move_sprite(0, 80, 72);
            move_sprite(1, 80 + 8, 72);        
        }
        player_step_toggle = 1;
    }
    
}