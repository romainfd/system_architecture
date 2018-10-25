cmake_minimum_required(VERSION 3.12)
project(TD1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TD1
        bits.c
        bits.h
        btest.c
        btest.h
        decl.c
        dlc
        driver.pl
        Driverhdrs.pm
        Driverlib.pm
        fshow.c
        ishow.c
        Makefile
        README
        tests.c)
