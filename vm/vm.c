#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: vg run <file.vg>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Failed to open file");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), f)) {
        // trim newline
        line[strcspn(line, "\n")] = 0;

        // very simple parser
        if (strncmp(line, "print ", 6) == 0) {
            char *text = line + 6;

            // remove quotes if present
            if (text[0] == '"' && text[strlen(text) - 1] == '"') {
                text[strlen(text) - 1] = 0;
                text++;
            }

            printf("%s\n", text);
        }
    }

    fclose(f);
    return 0;
}
