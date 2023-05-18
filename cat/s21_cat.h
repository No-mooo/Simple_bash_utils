#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

struct option_status {
    int b;
    int e;
    int s;
    int t;
    int n;
    int v;
};

void print_txt(const char* file_txt, struct option_status option);
int option_s(char next_symbol, int* num_s);
int option_v(char next_symbol);

#endif  // SRC_CAT_S21_CAT_H_
