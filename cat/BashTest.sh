
./s21_cat test.txt > 1
cat test.txt > 2
diff -s 1 2

./s21_cat -bestn test.txt > 1
cat -bestn test.txt > 2
diff -s 1 2

#  b  #
./s21_cat -b test.txt > 1
cat -b test.txt > 2
diff -s 1 2

./s21_cat -be test.txt > 1
cat -be test.txt > 2
diff -s 1 2

./s21_cat -bn test.txt > 1
cat -bn test.txt > 2
diff -s 1 2

./s21_cat -bs test.txt > 1
cat -bs test.txt > 2
diff -s 1 2

./s21_cat -bt test.txt > 1
cat -bt test.txt > 2
diff -s 1 2

#  e  #
./s21_cat -e test.txt > 1
cat -e test.txt > 2
diff -s 1 2

./s21_cat -eb test.txt > 1
cat -eb test.txt > 2
diff -s 1 2

./s21_cat -en test.txt > 1
cat -en test.txt > 2
diff -s 1 2

./s21_cat -es test.txt > 1
cat -es test.txt > 2
diff -s 1 2

./s21_cat -et test.txt > 1
cat -et test.txt > 2
diff -s 1 2

#  n  #
./s21_cat -nb test.txt > 1
cat -nb test.txt > 2
diff -s 1 2

./s21_cat -ne test.txt > 1
cat -ne test.txt > 2
diff -s 1 2

./s21_cat -ns test.txt > 1
cat -ns test.txt > 2
diff -s 1 2

./s21_cat -nt test.txt > 1
cat -nt test.txt > 2
diff -s 1 2

#  s  #
./s21_cat -sb test.txt > 1
cat -sb test.txt > 2
diff -s 1 2

./s21_cat -se test.txt > 1
cat -se test.txt > 2
diff -s 1 2

./s21_cat -sn test.txt > 1
cat -sn test.txt > 2
diff -s 1 2

./s21_cat -st test.txt > 1
cat -st test.txt > 2
diff -s 1 2

# t  #
./s21_cat -tb test.txt > 1
cat -tb test.txt > 2
diff -s 1 2

./s21_cat -te test.txt > 1
cat -te test.txt > 2
diff -s 1 2

./s21_cat -tn test.txt > 1
cat -tn test.txt > 2
diff -s 1 2

./s21_cat -ts test.txt > 1
cat -ts test.txt > 2
diff -s 1 2
