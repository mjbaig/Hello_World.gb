#include <gb/gb.h>
#include <stdio.h>
#include "mc.c"

void setup();
void update();
void player_update();
void player_setup();

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

void player_update() {
    set_sprite_tile(1, 6);
    set_sprite_tile(0, 4);

    delay(500);
    set_sprite_tile(1,2);
    set_sprite_tile(0,0);
    delay(500);

    set_sprite_prop(1, S_FLIPX);
    set_sprite_prop(0, S_FLIPX);

    get_sprite_prop(1);
    get_sprite_prop(0);
    
    move_sprite(0, 75 + 8, 75);
    move_sprite(1, 75, 75);

    delay(500);
}

void player_setup() {
    set_sprite_data(0, 8, mc);
    set_sprite_tile(0, 0);
    move_sprite(0, 75, 75);
    
    set_sprite_tile(1, 2);
    move_sprite(1, 75 + 8, 75);
}