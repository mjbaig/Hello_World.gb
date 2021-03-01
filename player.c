#include <gb/gb.h>
#include <stdio.h>
#include "player.h"

short is_flipped = 0;

int player_step_toggle = 0x0U;

void player_step_down(UINT16 position_x, UINT16 position_y);

void player_setup(UINT16 position_x, UINT16 position_y) {
    set_sprite_tile(1,2);
    set_sprite_tile(0,0);
    move_sprite(0, position_x, position_y);
    move_sprite(1, position_x + 8, position_y); 
}

void player_update(UINT16 position_x, UINT16 position_y) {
    player_step_down(position_x, position_y);    
}

void player_step_down(UINT16 position_x, UINT16 position_y) {

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
            move_sprite(0, position_x + 8, position_y);
            move_sprite(1, position_x, position_y);
        } else {
            move_sprite(0, position_x, position_y);
            move_sprite(1, position_x + 8, position_y);        
        }
        player_step_toggle = 1;
    }
    
}