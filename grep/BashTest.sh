
./s21_grep g test.txt > 1
grep g test.txt > 2
diff -s 1 2

./s21_grep g test.txt test1.txt > 1
grep g test.txt test1.txt > 2
diff -s 1 2
#
./s21_grep -e "[1-3]" test.txt > 1
grep -e "[1-3]" test.txt > 2
diff -s 1 2

./s21_grep g test.txt test1.txt > 1
grep g test.txt test1.txt > 2
diff -s 1 2



#  e  #
./s21_grep -e g test.txt > 1
grep -e g test.txt > 2
diff -s 1 2

./s21_grep -e test.txt test1.txt > 1
grep -e test.txt test1.txt > 2
diff -s 1 2

#  i  #
./s21_grep -i h test.txt > 1
grep -i h test.txt > 2
diff -s 1 2

./s21_grep -i h test.txt test1.txt > 1
grep -i h test.txt test1.txt > 2
diff -s 1 2

#  v  #
./s21_grep -v f test.txt > 1
grep -v f test.txt > 2
diff -s 1 2

./s21_grep -v f test.txt test1.txt > 1
grep -v f test.txt test1.txt > 2
diff -s 1 2

#  c  #
./s21_grep -c f test.txt > 1
grep -c f test.txt > 2
diff -s 1 2

./s21_grep -c f test.txt test1.txt > 1
grep -c f test.txt test1.txt > 2
diff -s 1 2

#  l  #
./s21_grep -l f test.txt > 1
grep -l f test.txt > 2
diff -s 1 2

./s21_grep -l f test.txt test1.txt > 1
grep -l f test.txt test1.txt > 2
diff -s 1 2

#  n  #
./s21_grep -n f test.txt > 1
grep -n f test.txt > 2
diff -s 1 2

./s21_grep -n f test.txt test1.txt > 1
grep -n f test.txt test1.txt > 2
diff -s 1 2

#  h  #
./s21_grep -h f test.txt > 1
grep -h f test.txt > 2
diff -s 1 2

./s21_grep -h f test.txt test1.txt > 1
grep -h f test.txt test1.txt > 2
diff -s 1 2

#  s  #
./s21_grep -s f t.txt > 1
grep -s f t.txt > 2
diff -s 1 2

./s21_grep -s f t.txt test1.txt > 1
grep -s f t.txt test1.txt > 2
diff -s 1 2

#  f  #
./s21_grep -f  test3.txt test.txt > 1
grep -f test3.txt test.txt > 2
diff -s 1 2

./s21_grep -f  test3.txt test.txt test1.txt > 1
grep -f  test3.txt test.txt test1.txt > 2
diff -s 1 2

#  o  #
./s21_grep -o o test.txt > 1
grep -o o test.txt > 2
diff -s 1 2

./s21_grep -o o test.txt test1.txt > 1
grep -o o test.txt test1.txt > 2
diff -s 1 2
