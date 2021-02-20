#include <gb/gb.h>
#include <stdio.h>
#include "aloo_npc.h"

int aloo_npc_step_toggle = 0x0U;

void aloo_npc_walk_down();
void aloo_npc_setup() {

}

void aloo_npc_update() {
    aloo_npc_walk_down();
}

void aloo_npc_walk_down() {

    if (aloo_npc_step_toggle == 1){ 
        set_sprite_tile(2, 24);
        move_sprite(2, 60, 72);

        set_sprite_tile(3, 26);
        move_sprite(3, 60 + 8, 72);
        aloo_npc_step_toggle = 0;
    } else {
        set_sprite_tile(2, 28);
        move_sprite(2, 60, 72);

        set_sprite_tile(3, 30);
        move_sprite(3, 60 + 8, 72);
        aloo_npc_step_toggle = 1;
    }
}

