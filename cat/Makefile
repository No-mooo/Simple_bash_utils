CC=gcc
FLAGS=-Werror -Wall -Wextra -std=c11
OS=$(shell uname)

ifeq ($(OS), Linux)
    LIBS=-lcheck -pthread -lrt -lm -lsubunit
    OPEN=xdg-open
else
    LIBS=-lcheck
    OPEN=open
endif

FILE1=s21_cat
FILE2=s21_cat_test


all: 
	make s21_cat
	make test
	make clean

s21_cat: $(FILE1).c
	$(CC) -o ./s21_cat $(FLAGS) s21_cat.c

test: s21_cat
	$(CC) -o ./s21_cat_test $(FLAGS) s21_cat_test.c $(LIBS)
	-./s21_cat_test

clean:
	rm -rf  *.o *.a *.out *.hex *. 1 2 result
	rm -rf ./s21_cat_test
	rm -rf *.gcda *.gcno *.info *.dSYM *.info report CPPLINT.cfg

check:
	@# cpp check
	@echo "\033[31m--------- CPPCHECK --------- \n\033[0m"
	@cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

	@#style test
	@echo "\n\033[31m--------- STYLE TEST --------- \n\033[32m"
	@python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h

	@#shell test
	@echo "\n\033[31m--------- SHELL TEST --------- \n\033[0m"
	@sh BashTest.sh
go:
	@echo "\033[31mCompilation without flags...\033[0m"
	@$(CC) s21_cat.c -o s21_cat

gof:
	@echo "\033[32mCompilation with flags...\033[0m"
	@$(CC) $(FLAGS) s21_cat.c s21_cat