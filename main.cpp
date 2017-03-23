#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

using namespace std;



int main()
{
    field tableau;
    init_field(tableau, 48, 84);
    rand_field(tableau, 5);
    disp_field(tableau);
    cin.get();
    system("cls");
    int i;

    for(i=0; i>=0; i++){
    next_gen_field(tableau);
    disp_field(tableau);
    system("cls");
    cout << "gen " << i << " complete!" << endl;
    }

    return 0;
}


