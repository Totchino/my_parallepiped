/*
** ETNA PROJECT, 20/03/2021 by ultsch_c
** my_parallelepiped
** File description:
**      [...]
*/
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}


void fill_with_space(int a, int b, char tab[a][b], int x, int y)
{

  for (int j = 0; j < b; j++) {
    for (int i = 0; i < a; i++) {
      tab[i][j] = ' ';
    }
  }

}

void set_depth_diagonal(int a, int b, char tab[a][b], int x, int y, int z)
{

  for (int j = 1; j < z-1; j++) {
    for (int i = 1; i < z-1; i++) {
      if ( i == j ) {
        tab[i][b-1-(y-1)-j] = '/';
        tab[x-1+i][b-1-(y-1)-j] = '/';
        tab[x-1+i][b-1-j] = '/';
      }
    }
  }

}

void set_width_horizontal(int a, int b, char tab[a][b], int x, int y)
{

  for (int i = 1; i < x-1; i++) {
    tab[i][b-1-(y-1)] = '-';
    tab[i][b-1] = '-';
    tab[a-1-(x-1)+i][0] = '-';
  }

}

void set_height_vertical(int a, int b, char tab[a][b], int x, int y)
{

  for (int j = b-y+1; j < b-1; j++) {
    tab[0][j] = '|';
    tab[x-1][j] = '|';
    tab[a-1][j-b+y] = '|';
  }

}

void set_corner_point(int a, int b, char tab[a][b], int x, int y)
{

  int offset_a = (a - 1) - (x - 1);
  int offset_b = (b - 1) - (y - 1);

  // FRONT CORNER
  tab[0][offset_b] = '*';
  tab[x - 1][offset_b] = '*';
  tab[0][b - 1] = '*';
  tab[x - 1][b - 1] = '*';

  // BACK CORNER
  tab[offset_a][0] = '*';
  // tab[offset_a][y - 1] = '*';
  tab[a - 1][0] = '*';
  tab[a - 1][y - 1] = '*';

}

void draw_char_array(int a, int b, char tab[a][b], int x, int y)
{

  for (int j = 0; j < b; j++) {
    for (int i = 0; i < a; i++) {
      my_putchar(tab[i][j]);
    }
    my_putchar('\n');
  }

}

int my_parallelepiped(int x, int y, int z)
{

  int valid = 1;
  int a;
  int b;

  if ( x + z - 1 >= 0 && y + z - 1 >= 0 ) {
    a = x + z - 1;
    b = y + z - 1;
  } else {
    valid = 0;
  }

  if (valid) {
    char tab[a][b];

    fill_with_space(a, b, tab, x, y);
    set_depth_diagonal(a, b, tab, x, y, z);
    set_height_vertical(a, b, tab, x, y);
    set_width_horizontal(a, b, tab, x, y);
    set_corner_point(a, b, tab, x, y);
    draw_char_array(a, b, tab, x, y);

  }

}

int main()
{

  my_parallelepiped(0, 0, 0);
  my_parallelepiped(1, 1, 1);
  my_parallelepiped(2, 2, 2);
  my_parallelepiped(6, 4, 2);
  my_parallelepiped(4, 4, 4);
  my_parallelepiped(18, 4, 7);
  my_parallelepiped(12, 14, 3);
  my_parallelepiped(4,5,1);
  my_parallelepiped(5,1,4);
  my_parallelepiped(1,4,5);
  my_parallelepiped(-1,-1,-1);

  //my_parallelepiped('a','b','c');

}