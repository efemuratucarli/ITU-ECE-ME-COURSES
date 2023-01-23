@echo off

if exist q1.c (
    gcc q1.c student.c -o q1
)
if exist q2.c (
    gcc q2.c student.c -o q2
)
if exist q3.c (
    gcc q3.c student.c -o q3
)
