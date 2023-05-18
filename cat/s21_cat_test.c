#include "s21_cat.h"
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_CAT(STRING)                                                                      \
    {                                                                                         \
        system("./s21_" STRING " >1");                                                        \
        system(STRING " >2");                                                                   \
        ck_assert_msg(system("diff -s 1 2 >result") == 0, "Failed on: '" STRING "'"); \
    }

START_TEST(test_s21_cat_1opt) {
    TEST_CAT("cat test.txt");
    TEST_CAT("cat -b test.txt");
    TEST_CAT("cat -s test.txt");
    TEST_CAT("cat -t test.txt");
    TEST_CAT("cat -s test.txt");
    TEST_CAT("cat -n test.txt");
}
END_TEST

START_TEST(test_s21_cat_2opt) {
    TEST_CAT("cat -bn test.txt");
    TEST_CAT("cat -be test.txt");
    TEST_CAT("cat -bs test.txt");
    TEST_CAT("cat -bt test.txt");
    TEST_CAT("cat -nb test.txt");
    TEST_CAT("cat -ne test.txt");
    TEST_CAT("cat -ns test.txt");
    TEST_CAT("cat -nt test.txt");
    TEST_CAT("cat -eb test.txt");
    TEST_CAT("cat -en test.txt");
    TEST_CAT("cat -es test.txt");
    TEST_CAT("cat -et test.txt");
    TEST_CAT("cat -sb test.txt");
    TEST_CAT("cat -sn test.txt");
    TEST_CAT("cat -se test.txt");
    TEST_CAT("cat -st test.txt");
    TEST_CAT("cat -tb test.txt");
    TEST_CAT("cat -tn test.txt");
    TEST_CAT("cat -te test.txt");
    TEST_CAT("cat -ts test.txt");
}
END_TEST

START_TEST(test_s21_cat_5opt) {
    TEST_CAT("cat -bestn test.txt");
    TEST_CAT("cat -enstb test.txt");
    TEST_CAT("cat -nstbe test.txt");
    TEST_CAT("cat -stebn test.txt");
    TEST_CAT("cat -tbens test.txt");
}
END_TEST

START_TEST(test_s21_cat_5opt2files) {
    TEST_CAT("cat -bestn test.txt test2.txt");
    TEST_CAT("cat -enstb test.txt test2.txt");
    TEST_CAT("cat -nstbe test.txt test2.txt");
    TEST_CAT("cat -stebn test.txt test2.txt");
    TEST_CAT("cat -tbens test.txt test2.txt");
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Cat_tests");
    SRunner *sr = srunner_create(s1);
    int nf;

    TCase *tc1_1 = tcase_create("Test with 1 option");
    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_s21_cat_1opt);

    TCase *tc2_1 = tcase_create("Test with 2 options");
    suite_add_tcase(s1, tc2_1);
    tcase_add_test(tc2_1, test_s21_cat_2opt);

    TCase *tc3_1 = tcase_create("Test with 5 options");
    suite_add_tcase(s1, tc3_1);
    tcase_add_test(tc3_1, test_s21_cat_5opt);

    TCase *tc4_1 = tcase_create("Test with 5 options and 2 files");
    suite_add_tcase(s1, tc4_1);
    tcase_add_test(tc4_1, test_s21_cat_5opt2files);

    srunner_run_all(sr, CK_VERBOSE);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
