#include <gb/gb.h>
#include <stdio.h>
#include "player.h"
#include "mc.c"
#include "aloo_npc.h"
#include "room_tilemap.c"
#include "room_tileset.c"
#include "blank_map.c"

void setup();
void update();

int background_position_x = 576;
int background_position_y = 512;

UINT16 player_position_x = 72;
UINT16 player_position_y = 64;

UINT16 aloo_position_x = 72;
UINT16 aloo_position_y = 64 - 16;

UINT16 clock_count = 0;
UINT16 IDEAL_CLOCK_COUNT = 4.19 * 1000;

void main() {
    
    setup();

    while(1){
		
        update();

	}
}

void setup() {
    SPRITES_8x16;
    set_sprite_data(0, 38, mc);

    player_setup(player_position_x, player_position_y);

    SHOW_SPRITES;

    
    set_bkg_data(0, 127, room_tileset);
    set_bkg_tiles(0, 0, room_tilemapWidth, room_tilemapHeight, room_tilemap);
    move_bkg(background_position_x, background_position_y);
    SHOW_BKG;
    DISPLAY_ON;
}

void update() {
    clock_count++;

    if (clock_count == IDEAL_CLOCK_COUNT)
    {
        player_update(player_position_x, player_position_y);
        aloo_npc_update(aloo_position_x, aloo_position_y);

        switch (joypad()) {
        case J_LEFT:
            background_position_x -= 16;
            move_bkg(background_position_x, background_position_y);
            break;
        case J_RIGHT:
            background_position_x += 16;
            move_bkg(background_position_x, background_position_y);
            break;
        case J_UP:
            background_position_y += 16;
            move_bkg(background_position_x, background_position_y);
            break;
        case J_DOWN:
            background_position_y -= 16;
            move_bkg(background_position_x, background_position_y);
            break;
        default:
            break;
        }
        
    }

    if (clock_count > IDEAL_CLOCK_COUNT)
    {
        clock_count = 0;

    }
}
