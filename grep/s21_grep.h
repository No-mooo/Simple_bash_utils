#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

struct option_status {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
    int flag_check;
    int check_file;
    char *name_file;
};

void print_grep(const char *file_txt, struct option_status *option, char *sample);
int regular(const char* str, const char* template, int grep_opt_i);
int option_o(char *text, char *symbol, int use_option_f);
int option_f(char *sample, char *next_text);
#endif  // SRC_GREP_S21_GREP_H_
