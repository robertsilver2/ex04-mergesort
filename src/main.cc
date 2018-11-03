/**
 * CS V15 Data Structures and Algorithms
 * CRN: 70342
 * Assignment: ex04-mergesort
 *
 *
 * Statement of code ownership: I hereby state that I have written all of this
 * code and I have not copied this code from any other person or source.
 *
 * @robertsilver2
 */

#include<iostream>
#include "mergesort.h"
using edu::vcccd::vc::csv15::mergesort;


int main(int argc, char *argv[]) {
    uint64_t searchTarget = 3;
    uint64_t array[] = {1, 3 , 3, 7};
    uint64_t start = 0;
    uint64_t  end = 3;
    mergesort(array, start, end);
    //mergesort(array, searchTarget);
}