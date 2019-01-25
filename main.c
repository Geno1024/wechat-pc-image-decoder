#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @author Geno1024
 * @date 2019-01-26 02:27
 */
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: %s [input] [output].", argv[0]);
        return 0;
    }
    char outfilename[1024];
    strcpy(outfilename, argc == 2 ? "output" : argv[2]);
    FILE *in = fopen(argv[1], "rb");
    FILE *out = fopen(outfilename, "wb");
    int c = getc(in);
    while (c != EOF)
    {
        fprintf(out, "%c", c ^ 0xc7);
        c = getc(in);
    }
    fclose(in);
    fclose(out);
    return 0;
}
