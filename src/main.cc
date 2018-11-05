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
//using edu::vcccd::vc::csv15::mergesort2;


int main(int argc, char *argv[]) {

    //initialize array and related variables
    int64_t array[] = {7, 3, 3, 420, 1, 69};
    uint64_t size = 6;
    uint64_t start = 0;
    uint64_t  end = size-1;

    //DEBUG: print array
    std::cout << "\n starting array: \n" <<std::endl;
    for(int index = start; index < (end-start+1); index++){
        std::cout << "array[" << index << "] equals " << array[index] << std::endl;
    }
    std::cout << std::endl;

    //Sort initial array
    //mergesort2(array, start, end);    //non template int
    mergesort(array, start, end);       //3 param templated
    //mergesort(array, searchTarget);   //2 param templated?


}