#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

typedef struct field{
    bool fieldtab[48][84];
    int X;
    int Y;
}field;

void init_field(field &tab);
void init_field(field &tab, int X, int Y);

void rand_field(field &tab, int chance);

void copy_field(field &tab, field orig);

void disp_field(field tab);

int neighbours(field tab, int k, int l);

bool next_gen_cell(bool cell, int neighbours);

void next_gen_field(field &tab);

#endif // GRID_H_INCLUDED
