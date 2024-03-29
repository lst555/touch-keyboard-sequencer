#include "resources.h"

namespace lst {

// ---a---
// f     b
// ---g---
// e     c
// ---d---dp

const uint8_t symbols[] = {
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111, //9
    0b01110111, //A 10
    0b01111100, //0b
    0b01011000, //c
    0b01011110, //d
    0b01111001, //e
    0b01110001, //f
    0b00111101, //g
    0b01110100, //h
    0b00000100, //i
    0b00011110, //j 
    0b01110000, //k 20
    0b00111000, //l
    0b01010101, //m
    0b01010100, //n
    0b01011100, //o 
    0b01110011, //p 25
    0b01100111, //q
    0b01010000, //r
    0b01101101, //s //tu memit 
    0b01111000, //t 
    0b00011100, //u 30
    0b00001100, //v 31
    0b01101010, //w
    0b01001001, //x 
    0b01110010, //y 
    0b01011011, //z tu menit 35
    0b00000000,
    0b01111111,
    0b00011000, // 38 down left
    0b00001100, // 39 down right 
    0b00100001, // 40 up left 
    0b00000011 // 41 up right
};

const uint8_t steps[] {
    0b11111110,
    0b11111101,
    0b11111011,
    0b11110111,
    0b11101111,
    0b11011111,
    0b10111111,
    0b01111111
};

const uint8_t binary8[8][3] {
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1}
};

const uint8_t pattern1[8] {0, 5, 1, 6, 2, 7, 3, 4};
// ---a---
// f     b
// ---g---
// e     c
// ---d---dp

const uint8_t masks[] {
    0b00001000, // d
    0b00010000, // e
    0b00100000, // f 
    0b00000001, // a
    0b00000010, // b
    0b00000100, // c 
    0b01000000, // g
    0b10000000, // dp
};

const uint8_t circel_animation[] {
    0b00010000,
    0b01010000,
    0b01000000,
    0b01000010,
    0b00000010,
    0b00000011,
    0b00000001,
    0b00100001,
    0b00100000,
    0b01100000,
    0b01000000,
    0b01000100,
    0b00000100,
    0b00001100,
    0b00001000,
    0b00011000,
};

const uint8_t bar[] {
    0b00000000,
    0b00001000, 
    0b00011000, 
    0b00111000,  
    0b00111001, 
    0b00111011,  
    0b00111111, 
    0b10111111, 
};

const uint8_t arrows[] {
    0b00011000, // down left
    0b00001100, // down right 
    0b00100001, // up left 
    0b00000011 // up right
};

}
