#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("\nargc --> %d", argc);
    int i;
    for (i=0; i<argc; i++) {
        printf("\nargv[%d] --> %s", i, argv[i]);
    }
    printf("\n\n");
    return 0;
}
        

