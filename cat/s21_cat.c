#include "../../src/cat/s21_cat.h"
#include <getopt.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char old_copy_argv[100][100] = {{0}, {0}};

    for (int i = 0; i < argc; i++) {
        // strcat(old_copy_argv[i], argv[i]);
        snprintf(old_copy_argv[i], strlen(argv[i]) + 1, "%s", argv[i]);
    }

    int err_status = 0;
    struct option_status option = {0};

    const char *short_options = "bestnvTE";
    int rez;
    int option_index;

    const struct option long_options[] = {
        {"number-nonblank", no_argument, NULL, 'b'},
        {"number", optional_argument, NULL, 'n'},
        {"squeeze-blank", required_argument, NULL, 's'},
        {NULL, 0, NULL, 0}};

    while ((rez = getopt_long(argc, argv, short_options, long_options,
                              &option_index)) != -1 &&
           err_status == 0) {
        switch (rez) {
            case 'b':
                option.b = 1;
                break;

            case 'e':
                option.e = 1;
                option.v = 1;
                break;

            case 's':
                option.s = 1;
                break;

            case 't':
                option.t = 1;
                option.v = 1;
                break;

            case 'n':
                option.n = 1;
                break;

            case 'v':
                option.v = 1;
                break;

            case 'E':
                option.e = 1;
                option.v = 0;
                break;

            case 'T':
                option.t = 1;
                option.v = 0;
                break;

            default:
                err_status = 1;
                break;
        }
    }

    if (argc > 1 && err_status == 0) {
        int start_open_file = 0;

        for (int i = 1; i < argc; i++) {
            if (strstr(old_copy_argv[i], ".") != NULL || start_open_file == 1) {
                if (i == 1) memset(&option, 0, sizeof(option));
                print_txt(old_copy_argv[i], option);
                start_open_file = 1;
            }
        }
    }

    return 0;
}

void print_txt(const char *file_txt, struct option_status option) {
    FILE *file;
    file = fopen(file_txt, "r");

    if (file) {
        char next_symbol;
        int num_b_n = 1;
        int new_strin = 1;
        int num_s = 0;

        while ((next_symbol = fgetc(file)) != EOF) {
            if (option.s && option_s(next_symbol, &num_s)) continue;

            if ((option.b && new_strin && next_symbol != '\n') || (option.n && !option.b && new_strin)) {
                printf("%6d\t", num_b_n);
                num_b_n++;
                new_strin = 0;
            }
            if (next_symbol == '\n') new_strin = 1;

            if (option.t && next_symbol == '\t') {
                printf("%s", "^I");
                continue;
            }

            if (option.e && next_symbol == '\n') printf("$");

            if (option.v && option_v(next_symbol)) continue;

            printf("%c", next_symbol);
        }

        fclose(file);

    } else {
        printf("s21_cat: %s: No such file or directory", file_txt);
    }
}

int option_s(char next_symbol, int *num_s) {
    int resul = 0;

    if (next_symbol == '\n') {
        *num_s = *num_s + 1;

    } else {
        *num_s = 0;
    }

    if (*num_s >= 3) {
        resul = 1;
    }

    return resul;
}

int option_v(char next_symbol) {
    int resul = 0;
    int copy_next_symbol = next_symbol;

    if ((copy_next_symbol < 32 && copy_next_symbol != 9 &&
         copy_next_symbol != 10) ||
        copy_next_symbol == 127) {
        printf("%c", '^');
        printf("%c", copy_next_symbol + 64);

        resul = 1;
    }

    return resul;
}
