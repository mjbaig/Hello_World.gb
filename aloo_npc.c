#include <gb/gb.h>
#include <stdio.h>
#include "aloo_npc.h"

int aloo_npc_step_toggle = 0x0U;

void aloo_npc_walk_down(UINT16 position_x, UINT16 position_y);

void aloo_npc_setup(UINT16 position_x, UINT16 position_y) {

        set_sprite_tile(2, 28);
        move_sprite(2, position_x, position_y);

        set_sprite_tile(3, 30);
        move_sprite(3, position_x + 8, position_y);

}

void aloo_npc_update(UINT16 position_x, UINT16 position_y) {
    aloo_npc_walk_down(position_x, position_y);
}

void aloo_npc_walk_down(UINT16 position_x, UINT16 position_y) {

    if (aloo_npc_step_toggle == 1){ 
        set_sprite_tile(2, 24);
        move_sprite(2, position_x, position_y);

        set_sprite_tile(3, 26);
        move_sprite(3, position_x + 8, position_y);
        aloo_npc_step_toggle = 0;
    } else {
        set_sprite_tile(2, 28);
        move_sprite(2, position_x, position_y);

        set_sprite_tile(3, 30);
        move_sprite(3, position_x + 8, position_y);
        aloo_npc_step_toggle = 1;
    }
}

