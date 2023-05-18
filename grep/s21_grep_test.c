#include "s21_grep.h"
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_GREP(STRING)                                                                      \
    {                                                                                         \
        system("./s21_" STRING " >1");                                                        \
        system(STRING " >2");                                                                   \
        ck_assert_msg(system("diff -s 1 2 >result") == 0, "Failed on: '" STRING "'"); \
    }

START_TEST(test_s21_cat_1opt) {
    TEST_GREP("grep g test.txt");
    TEST_GREP("grep -e g test.txt test1.txt");
    TEST_GREP("grep -i h test.txt test1.txt");
    TEST_GREP("grep -v f test.txt test1.txt");
    TEST_GREP("grep -c f test.txt test1.txt");
    TEST_GREP("grep -l f test.txt test1.txt");
    TEST_GREP("grep -n f test.txt test1.txt");

    TEST_GREP("grep g test.txt test1.txt");
    TEST_GREP("grep -e g test.txt test1.txt");
    TEST_GREP("grep -i h test.txt test1.txt");
    TEST_GREP("grep -v f test.txt test1.txt");
    TEST_GREP("grep -c f test.txt test1.txt");
    TEST_GREP("grep -l f test.txt test1.txt");
    TEST_GREP("grep -n f test.txt test1.txt");

    TEST_GREP("grep gg test.txt test1.txt");
    TEST_GREP("grep -e gg test.txt test1.txt");
    TEST_GREP("grep -i hh test.txt test1.txt");
    TEST_GREP("grep -v ff test.txt test1.txt");
    TEST_GREP("grep -c ff test.txt test1.txt");
    TEST_GREP("grep -l ff test.txt test1.txt");
    TEST_GREP("grep -n ff test.txt test1.txt");

    TEST_GREP("grep -h f test.txt");
    TEST_GREP("grep -h f test.txt test1.txt");
    TEST_GREP("grep -s f t.txt");
    TEST_GREP("grep -s f t.txt test1.txt ");
    TEST_GREP("grep -f test3.txt test.txt");
    TEST_GREP("grep -f  test3.txt test.txt test1.txt");
    TEST_GREP("grep -o o test.txt");
    TEST_GREP("grep -o o test.txt test1.txt");
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Cat_tests");
    SRunner *sr = srunner_create(s1);
    int nf;

    TCase *tc1_1 = tcase_create("Test with 1 option");
    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_s21_cat_1opt);

    srunner_run_all(sr, CK_VERBOSE);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
