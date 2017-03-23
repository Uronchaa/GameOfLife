#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

void init_field(field &tab){
    int i, j;
    for (i=0; i<tab.X; i++){
        for(j=0; j<tab.Y; j++){
            tab.fieldtab[i][j] = false;
        }
    }
}

void init_field(field &tab, int X, int Y){
    X > 48 ? tab.X = 48 : tab.X = X;
    Y > 84 ? tab.Y = 84 : tab.Y = Y;
    int i, j;
    for (i=0; i<tab.X; i++){
        for(j=0; j<tab.Y; j++){
            tab.fieldtab[i][j] = false;
        }
    }
}

void rand_field(field &tab, int chance){
    int i, j;
    srand(time(NULL));
    for (i=0; i<tab.X; i++){
        for(j=0; j<tab.Y; j++){
            tab.fieldtab[i][j] = !(bool)(rand() % chance);
        }
    }
}

void copy_field(field &tab, field orig){
    tab.X = orig.X;
    tab.Y = orig.Y;
    int i, j;
    for (i=0; i<orig.X; i++){
        for(j=0; j<orig.Y; j++){
            tab.fieldtab[i][j] = orig.fieldtab[i][j];
        }
    }
}

void disp_field(field tab){
    int i,j;
    std::cout << std::endl;
    for (i=0; i<tab.X; i++){
        for(j=0; j<tab.Y; j++){
            !tab.fieldtab[i][j] ? std::cout << /*(char)176*/" " : std::cout << (char)219;
            }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int neighbours(field tab, int x, int y){
    int i, j, k, l;
    int nb = 0;
    for (i = x-1; i <= x+1; i++){
        for (j = y-1; j <= y+1; j++){
            if(i==x && j==y){
                continue;
            }
            if (i < 0){
                k = tab.X-1;
            }else if (i >= tab.X){
                k = 0;
            }else k = i;
            if (j < 0){
                l = tab.Y-1;
            }else if (j >= tab.Y){
                l = 0;
            }else l = j;
            if (tab.fieldtab[k][l]) nb++;
        }
    }
    return nb;
}

bool next_gen_cell(bool cell, int neighbours){
    bool result = false;
    if (cell){
        if (neighbours == 2 || neighbours == 3){
            result = true;
        }
    }else{
        if (neighbours == 3){
            result = true;
        }
    }
    return result;
}

void next_gen_field(field &tab){
    field buffer;
    int i, j;
    copy_field(buffer, tab);
    for (i=0; i < tab.X; i++){
        for(j=0; j < tab.Y; j++){
            buffer.fieldtab[i][j] = next_gen_cell(tab.fieldtab[i][j],neighbours(tab,i,j));
        }
    }
    copy_field(tab, buffer);
}



