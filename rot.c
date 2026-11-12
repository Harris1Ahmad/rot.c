#include <stdio.h>
#include <string.h>

char g[1024][1024];
int rows = 0, w = 0;

int main(void) {
    char line[1024];
    while (rows < 1024 && fgets(line, sizeof line, stdin)) {
        line[strcspn(line, "\n")] = 0;
        int len = strlen(line);
        if (len > w) w = len;
        memset(g[rows], ' ', 1024);
        memcpy(g[rows], line, len);
        rows++;
    }
    for (int c = 0; c < w; c++) {          /* each column becomes a row */
        for (int r = rows - 1; r >= 0; r--) /* bottom-to-top = clockwise */
            putchar(g[r][c]);
        putchar('\n');
    }
    return 0;
}