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
#include <string>
using edu::vcccd::vc::csv15::mergesort;
//using edu::vcccd::vc::csv15::mergesort2;


int main(int argc, char *argv[]) {

    //initialize array and related variables
    int64_t array1[] = {1578, 493, 903, 496, 519, 365, 108, 33, 1639, 613, 1468, 1063, 1776, 464, 1950, 1463, 1999, 1947, 747, 1320};
    //array generated @ https://www.random.org/integer-sets/
    //int64_t array1[] = {420, 1, 7, 3, 69, 42, 3,};
    uint64_t size = 20;
    uint64_t start = 0;
    uint64_t  end = size-1;

    //DEBUG: print array
    std::cout << "\n starting array1: \n" <<std::endl;
    for(int index = start; index < (end-start+1); index++){
        std::cout << "array1[" << index << "] equals " << array1[index] << std::endl;
    }
    std::cout << std::endl;

    //Sort initial array
    //mergesort2(array, start, end);    //non template int
    mergesort(array1, size);       //3 param templated
    //mergesort(array, searchTarget);   //2 param templated?

    //DEBUG: print sorted array
    std::cout << "\n sorted array: \n" <<std::endl;
    for(int index = start; index < (end-start+1); index++){
        std::cout << "array1[" << index << "] equals " << array1[index] << std::endl;
    }
    std::cout << std::endl;


    //Test with strings
    std::string array2[] = { "bee", "ape", "key", "day", "zoo", "man" };

    uint64_t sizeb = 6;
    uint64_t startb = 0;
    uint64_t endb = sizeb-1;

    //DEBUG: print array
    std::cout << "\n starting array2: \n" << std::endl;
    for(int index = startb; index < (endb-startb+1); index++){
        std::cout << "array2[" << index << "] equals " << array2[index] << std::endl;
    }
    std::cout << std::endl;

    //Sort initial array
    //mergesort2(array, start, end);    //non template int
    mergesort(array2, sizeb);       //3 param templated
    //mergesort(array, searchTarget);   //2 param templated?

    //DEBUG: print sorted array
    std::cout << "\n sorted array2: \n" <<std::endl;
    for(uint64_t index = startb; index < (endb-startb+1); index++){
        std::cout << "array2[" << index << "] equals " << array2[index] << std::endl;
    }
    std::cout << std::endl;


}