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
            strcpy(colorPairs[(i*5)+j].minorColor, minorColor[i]);
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

    assert(getColorMapList() == 25);

    assert(strcmp(colorPairs[0].majorColor, "White") == 0);
    assert(strcmp(colorPairs[0].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[1].majorColor, "White") == 0);
    assert(strcmp(colorPairs[1].minorColor, "Orange") == 0);
    assert(strcmp(colorPairs[2].majorColor, "White") == 0);
    assert(strcmp(colorPairs[2].minorColor, "Green") == 0);
    assert(strcmp(colorPairs[3].majorColor, "White") == 0);
    assert(strcmp(colorPairs[3].minorColor, "Brown") == 0);
    assert(strcmp(colorPairs[4].majorColor, "White") == 0);
    assert(strcmp(colorPairs[4].minorColor, "Slate") == 0);
    assert(strcmp(colorPairs[5].majorColor, "Red") == 0);
    assert(strcmp(colorPairs[5].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[6].majorColor, "Red") == 0);
    assert(strcmp(colorPairs[6].minorColor, "Orange") == 0);
    assert(strcmp(colorPairs[7].majorColor, "Red") == 0);
    assert(strcmp(colorPairs[7].minorColor, "Green") == 0);
    assert(strcmp(colorPairs[8].majorColor, "Red") == 0);
    assert(strcmp(colorPairs[8].minorColor, "Brown") == 0);
    assert(strcmp(colorPairs[9].majorColor, "Red") == 0);
    assert(strcmp(colorPairs[9].minorColor, "Slate") == 0);
    assert(strcmp(colorPairs[10].majorColor, "Black") == 0);
    assert(strcmp(colorPairs[10].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[11].majorColor, "Black") == 0);
    assert(strcmp(colorPairs[11].minorColor, "Orange") == 0);
    assert(strcmp(colorPairs[12].majorColor, "Black") == 0);
    assert(strcmp(colorPairs[12].minorColor, "Green") == 0);
    assert(strcmp(colorPairs[13].majorColor, "Black") == 0);
    assert(strcmp(colorPairs[13].minorColor, "Brown") == 0);
    assert(strcmp(colorPairs[14].majorColor, "Black") == 0);
    assert(strcmp(colorPairs[14].minorColor, "Slate") == 0);
    assert(strcmp(colorPairs[15].majorColor, "Yellow") == 0);
    assert(strcmp(colorPairs[15].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[16].majorColor, "Yellow") == 0);
    assert(strcmp(colorPairs[16].minorColor, "Orange") == 0);
    assert(strcmp(colorPairs[17].majorColor, "Yellow") == 0);
    assert(strcmp(colorPairs[17].minorColor, "Green") == 0);
    assert(strcmp(colorPairs[18].majorColor, "Yellow") == 0);
    assert(strcmp(colorPairs[18].minorColor, "Brown") == 0);
    assert(strcmp(colorPairs[19].majorColor, "Yellow") == 0);
    assert(strcmp(colorPairs[19].minorColor, "Slate") == 0);
    assert(strcmp(colorPairs[20].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[20].minorColor, "Blue") == 0);
    assert(strcmp(colorPairs[21].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[21].minorColor, "Orange") == 0);
    assert(strcmp(colorPairs[22].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[22].minorColor, "Green") == 0);
    assert(strcmp(colorPairs[23].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[23].minorColor, "Brown") == 0);
    assert(strcmp(colorPairs[24].majorColor, "Violet") == 0);
    assert(strcmp(colorPairs[24].minorColor, "Slate") == 0);

    printf("All is well (maybe!)\n");
    return 0;
}
