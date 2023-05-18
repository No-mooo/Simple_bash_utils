#include "../../src/grep/s21_grep.h"
#define _GNU_SOURCE
#include <getopt.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    int rez;
    struct option_status option = {0};
    int errstatus = 0;
    char *sample = NULL;
    char list_option[30] = "-e-i-v-c-l-n-h-s-f-o";

    while ((rez = getopt(argc, argv, "e:i:v:c:l:n:h:s:f:o:")) != -1 && errstatus == 0) {
        switch (rez) {
        case 'e':
            if (optarg) {
                option.e = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'i':
            if (optarg) {
                option.i = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'v':
            if (optarg) {
                option.v = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'c':
            if (optarg) {
                option.c = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'l':
            if (optarg) {
                option.l = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'n':
            if (optarg) {
                option.n = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'h':
            if (optarg) {
                option.h = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 's':
            if (optarg) {
                option.s = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'f':
            if (optarg) {
                option.f = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        case 'o':
            if (optarg) {
                option.o = 1;
                option.flag_check = 1;
                sample = optarg;

            } else {
                errstatus = 1;
            }
            break;

        default:
            errstatus = 1;
            break;
        }
    }

    for (int i = 1; i < argc; i++) {
        if (strstr(list_option, argv[i]) != NULL) i += 2;
        if (i < argc && strstr(argv[i], ".") != NULL) {
            option.check_file++;
        }
    }

    if (argc >= 3 && errstatus == 0) {
        if (option.flag_check == 0) {
            option.e = 1;
            sample = argv[1];
        }

        for (int i = 1; i < argc; i++) {
            if (strstr(list_option, argv[i]) != NULL) i += 2;
            if (i < argc && strstr(argv[i], ".") != NULL) {
                option.name_file = argv[i];
                print_grep(argv[i], &option, sample);
            }
        }
    }

    return 0;
}

void print_grep(const char *file_txt, struct option_status *option, char *sample) {
    FILE *file;
    file = fopen(file_txt, "r");

    if (file) {
        char *next_text = NULL;
        size_t line_element = 0;
        ssize_t num_text = 0;

        int num_option_c = 0;
        int num_option_l = 0;
        int num_option_n = 0;
        int num_option_o = 0;

        while ((num_text = getline(&next_text, &line_element, file)) != -1) {
            int flag_check = 0;

            if (option->f) {
                if (option_f(sample, next_text)) flag_check = 1;
            }

            if (option->i) {
                if (!regular(next_text, sample, 1)) flag_check = 1;
            }

            if (option->e) {
                if (!regular(next_text, sample, 0)) flag_check = 1;
            }

            if (option->v) {
                if (regular(next_text, sample, 0)) flag_check = 1;
            }

            if (option->c) {
                if (!regular(next_text, sample, 0)) num_option_c++;
            }

            if (option->l) {
                if (!regular(next_text, sample, 0)) num_option_l = 1;
            }

            if (option->h) {
                if (!regular(next_text, sample, 0)) flag_check = 1;
            }

            if (option->n) {
                num_option_n++;
                if (!regular(next_text, sample, 0)) flag_check = 1;
            }

            if (option->s) {
                if (!regular(next_text, sample, 0)) flag_check = 1;
            }

            if (option->o) {
                if ((num_option_o = option_o(next_text, sample, 0)) > 0) flag_check = 1;
            }

            if (flag_check) {
                if (option->check_file >= 2 && !option->h) printf("%s:", option->name_file);
                if (option->n) printf("%d:", num_option_n);
                if (option->o) {
                    while (num_option_o) {
                        printf("%s\n", sample);
                        num_option_o--;
                    }

                } else {
                    printf("%s", next_text);
                    if (next_text[strlen(next_text) - 1] != '\n') printf("\n");
                }
            }
        }
        if (next_text) free(next_text);

        if (option->c) {
            if (option->check_file >= 2) printf("%s:", option->name_file);
            printf("%d\n", num_option_c);
        }

        if (option->l && num_option_l) {
            printf("%s\n", option->name_file);
        }

        fclose(file);

    } else {
        if (!option->s) {
            printf("s21_grep: %s: No such file or directory", file_txt);
        }
    }
}

int regular(const char* str, const char* template, int grep_opt_i) {
    int result, result_value;
    regex_t regex;

    if (grep_opt_i) {
        result_value = regcomp(&regex, template, REG_EXTENDED | REG_ICASE | REG_NOSUB | REG_NEWLINE);

    } else {
        result_value = regcomp(&regex, template, REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
    }

    if (!result_value) {
        regmatch_t match;
        result = regexec(&regex, str, 1, &match, 0);
        regfree(&regex);

    } else {
        result = -1;
    }

    return result;
}

int option_f(char *sample, char *next_text) {
    FILE *file_f;
    file_f = fopen(sample, "r");

    char *next_text_f = NULL;
    int resul = 0;

    if (file_f) {
        size_t line_element = 0;
        ssize_t num_text = 0;
        int flag_n = 0;

        while ((num_text = getline(&next_text_f, &line_element, file_f)) != -1) {
            if (next_text_f[0] == '\n') flag_n = 1;
            int size_next_text_f = 0;
            if (next_text_f[strlen(next_text_f) - 1] == '\n') size_next_text_f = 1;
            if (option_o(next_text, next_text_f, size_next_text_f) || flag_n) {
                resul = 1;
                break;
            }
        }

        fclose(file_f);

    } else {
        printf("s21_grep: %s: No such file or directory", "file_txt");
    }

    if (next_text_f) free(next_text_f);

    return resul;
}

int option_o(char *text, char *symbol, int use_option_f) {
    int resul = 0;
    int line_symbol = strlen(symbol);
    int flag_y = 0;

    if (use_option_f) line_symbol--;
    for (size_t i = 0; i < strlen(text); i++) {
        size_t copy_i = i;

        for (int y = 0; y < line_symbol && copy_i < strlen(text); y++) {
            if (text[copy_i] == symbol[y]) {
                copy_i++;
                flag_y++;

            } else {
                break;
            }
        }

        if (flag_y == line_symbol) {
            i += line_symbol - 1;
            resul++;
        }

        flag_y = 0;
    }

    return resul;
}

