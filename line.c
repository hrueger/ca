#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000000

void line(int x0, int y0, int x1, int y1) {
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x0 < x1 ? 1 : -1;
  int sy = y0 < y1 ? 1 : -1;
  int err = dx - dy;

  while (x0 != x1 || y0 != y1) {
    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      x0 += sx;
    }
    if (e2 < dx) {
      err += dx;
      y0 += sy;
    }
  }
}

void line2(int x0, int y0, int x1, int y1) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int steps = fmax(abs(dx), abs(dy));
  float xIncrement = (float)dx / steps;
  float yIncrement = (float)dy / steps;
  float x = x0;
  float y = y0;

  for (int i = 0; i < steps; i++) {
    x += xIncrement;
    y += yIncrement;
  }
}

void line3(int x0, int y0, int x1, int yl) {
  int dx, dy, incrE, incrNE, d, x, y;
  dx = x1 - x0;
  dy = yl - y0;
  d = dy * 2 - dx;
  incrE = dy * 2;
  incrNE = (dy - dx) * 2;
  x = x0;
  y = y0;
  while (x < x1) {
    if (d <= 0) {
      d += incrE;
      x++;
    } else {
      d += incrNE;
      x++;
      y++;
    }
  }
}
int main() {
  const int from_x = 0, from_y = 0, to_x = 1000, to_y = 1000;

  clock_t start, end;

  // Basic Algorithm
  start = clock();
  for (int i = 0; i < COUNT; i++) {
    line(from_x, from_y, to_x, to_y);
  }
  end = clock();
  printf("Line with Basic Algorithm: %lf seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  // Incremental Algorithm
  start = clock();
  for (int i = 0; i < COUNT; i++) {
    line2(from_x, from_y, to_x, to_y);
  }
  end = clock();
  printf("Line with Incremental Algorithm: %lf seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  // Bresenham Algorithm
  start = clock();
  for (int i = 0; i < COUNT; i++) {
    line3(from_x, from_y, to_x, to_y);
  }
  end = clock();
  printf("Line with Bresenham Algorithm: %lf seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}
