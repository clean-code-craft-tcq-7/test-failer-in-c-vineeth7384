#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX_COLOR_PAIR 25
#define MAX_COLOR_LEN 10

typedef struct {
    char majorColor[MAX_COLOR_LEN];
    char minorColor[MAX_COLOR_LEN];
}ColorPair;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
ColorPair colorPairs[MAX_COLOR_PAIR];

int getColorMapList() {

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            strcpy(colorPairs[(i*5)+j].majorColor, majorColor[i]);
            strcpy(colorPairs[(i*5)+j].minorColor, minorColor[j]);
        }
    }
    return i * j;
}

void printColorMap() {
    int size, i;
    size = getColorMapList();

    for (i = 0; i < size; i++) {
        printf("%d | %s | %s\n", i, colorPairs[i].majorColor, colorPairs[i].minorColor);
    }
}


int main() {

    printColorMap();

    assert(strcmp(colorPairs[0].majorColor, "White") == 0);
    assert(strcmp(colorPairs[0].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[1].majorColor, "White") == 0);
    assert(strcmp(colorPairs[1].minorColor, "Orange") == 0);
    assert(strcmp(colorPairs[10].majorColor, "Black") == 0);
    assert(strcmp(colorPairs[10].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[11].majorColor, "Black") == 0); 
    assert(strcmp(colorPairs[20].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[20].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[24].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[24].minorColor, "Slate") == 0);
    assert(getColorMapList() == 25);

    printf("All is well (maybe!)\n");
    return 0;
}
