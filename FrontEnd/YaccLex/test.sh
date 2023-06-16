#!/bin/bash

g++ StrDump.cpp build/sysy.lex.cpp build/sysy.tab.cpp src/YaccLex.cpp -DTEST_YACC_LEX
./a.out
