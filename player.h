#pragma once
#ifndef _MYHEADER_H_
#define _MYHEADER_H_

    #include "player.c"

    typedef struct PLAYER {
        short isFlippedX;
    };

    void player_update();
    void player_setup();

#endif
