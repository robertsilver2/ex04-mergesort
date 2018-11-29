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

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H

#include <cstdint>
#include <iostream>
#include <string>
namespace edu {
    namespace vcccd{
        namespace vc{
            namespace csv15{

                //3 parameter merge templated
                template<typename T>
                void merge(T array[], uint64_t i, uint64_t split, uint64_t k){
                    size_t length=(k-i+1);
                    T *sorted = new T [length];
                    //^dynamic array?
                    //source1: https://stackoverflow.com/questions/33423502/expression-did-not-evaluate-to-a-constant-c
                    //source2: https://linuxconfig.org/example-of-c-class-template-array-to-instantiate-an-array-of-any-element-type
                    //
                    uint64_t sortPos=0;
                    uint64_t left = i; //beginning of LHS
                    uint64_t right = split+1; //beginning of RHS
                    while((left <= split) && (right <= k)){
                        //put smallest elements into new array
                        //in order smallest to highest

                        if(array[left] <= array[right]){
                            sorted[sortPos] = array[left];
                            left++;
                        }else{
                            sorted[sortPos] = array[right];
                            right++;
                        }
                        sortPos++;
                    }
                    //members of LHS and RHS
                    while(left <= split){
                        sorted[sortPos] = array[left];
                        sortPos++;
                        left++;
                    }
                    while(right<=k){
                        sorted[sortPos]=array[right];
                        sortPos++;
                        right++;
                    }
                    //apply changes to original array
                    for(sortPos = 0; sortPos < length; sortPos++){
                        array[i+sortPos]=sorted[sortPos];
                    }
                }

                //3 parameter mergesort templated
                template<typename T> //overloading template with 3 inputs
                void mergeAndSort(T array[], uint64_t i, uint64_t k){
                    //partition/recursive call
                    if(i<k){
                        uint64_t  breakpoint = i + ((k-i)/2);
                        mergeAndSort(array, i, breakpoint); //recursive call LHS
                        mergeAndSort(array, breakpoint+1, k); //recursive call RHS

                        //pass LHS & RHS (individually sorted) into merge
                        merge(array, i, breakpoint, k);
                    }
                }

                //make adapter
               template <typename T>
                void mergesort(T array, size_t size){
                    uint64_t i = 0;
                    uint64_t k = size-1;
                    mergeAndSort(array, i, k);

                }

            }
        }
    }
}

#endif //EX04_MERGESORT_MERGESORT_H
