// dllmain.cpp : Определяет точку входа для приложения DLL.

#include <iostream>


static unsigned long long previous;
static unsigned long long current;
static unsigned index;

void fibonacci_init(const unsigned long long a, const unsigned long long b) {
    previous = b;
    current = a;
    index = 1;
}

bool fibonacci_next() {
    if (current > ULLONG_MAX - previous) {
        return false; // переполнение
    }

    unsigned long long next = previous + current;
    previous = current;
    current = next;
    index++;
    return true;
}

unsigned long long fibonacci_current() {
    return current;
}

unsigned fibonacci_index() {
    return index;
}

