# *HDataStruct* - Hans' Data Structures Library
A simple &amp; stupid data structure library for C.

## Introduction
This is a small C library containing several header files and `.c` files, which provides basic implementation of data 
structures such as stack, queue and tree. All of them are written in pure C instead of C++.

For there's no generic programming specifics in C, `void` pointers are used to hold our elements. Instead of storing
data directly in the stack or queue or other structures, `void` pointers to the real values are stored. It might be
annoying sometimes for it's not easy to operate pointers smoothly, but in this way can a same `struct` hold different
types in C.

## Now Finished
- Stack
  - Initialize & Destroy
  - Push & Pop
  - Doubly linked list support
- Queue
  - Initialize & Destroy
  - Enqueue
  - Doubly linked list support

## Why this project
I write this library for in my another repo `CAlgoIntro`, I need implementations of different data structures for many
algorithms use them.

## License
This project is licensed under Mozilla Public License 2.0. PR & Issues are always welcomed.