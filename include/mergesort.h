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
namespace edu {
    namespace vcccd{
        namespace vc{
            namespace csv15{

                void merge2(int64_t array[], uint64_t i, uint64_t split, uint64_t k){
                    //DEBUG: notify entered Merge
                    std::cout << "\n Merge Function Reached \n" << std::endl;
                    std::cout << "in merge: \n i=" << i << ", k =" << k << std::endl;
                    //DEBUG: print sub-array
                    for(int index = i; index < (k-i+1); index++){
                        std::cout << "array[" << index << "] equals " << array[index] << std::endl;
                    }
                    size_t length;
                    if((k^i)!=NULL) { // if K ^ i not null how can it not evaluate to a constant?
                        length = (k - i + 1);
                    }else{
                        length = 0;

                    }
                    //int64_t sorted[length];

                    //DEBUG
                    std::cout << "length = " << length << std::endl;

                    int64_t *sorted = new int64_t [length];
                    //^dynamic array?
                    //source1: https://stackoverflow.com/questions/33423502/expression-did-not-evaluate-to-a-constant-c
                    //source2: https://linuxconfig.org/example-of-c-class-template-array-to-instantiate-an-array-of-any-element-type
                    //
                    std::cout << "split = " << split << std::endl;
                    uint64_t sortPos=0;
                    uint64_t left = i; //beginning of LHS
                    uint64_t right = split+1; //beginning of RHS

                    while((left <= split) && (right <= k)){
                        //put smallest elements into new array
                        //in order smallest to highest
                        //Debug: print index new array
                        std::cout << "sortPos = " << sortPos << std::endl;
                        if(array[left] <= array[right]){
                            sorted[sortPos] = array[left];
                            //Debug
                            std::cout << "left = " << left << " + 1 = ";
                            left++;
                            std::cout << left << std::endl;
                        }else{
                            sorted[sortPos] = array[right];
                            std::cout << "right = " << right << " + 1 = ";
                            right++;
                            std::cout << right << std::endl;
                        }
                        std::cout << "sorted[" << sortPos << "] = " << sorted[sortPos] << std::endl;
                        sortPos++;
                    }
                    //Debug: print index new array
                    std::cout << "sortPos = " << sortPos << std::endl;
                    //fill in all the empty slots with the remaining
                    //members of LHS and RHS
                    while(left <= split){
                        sorted[sortPos] = array[left];
                        //Debug:
                        std::cout << left << std::endl;
                        std::cout << "sorted[" << sortPos << "] = " << sorted[sortPos] << std::endl;
                        sortPos++;
                        //Debug
                        std::cout << "left = " << left << " + 1 = ";
                        left++;
                    }
                    while(right<=k){
                        sorted[sortPos]=array[right];
                       //Debug:
                        std::cout << "sorted[" << sortPos << "] = " << sorted[sortPos] << std::endl;
                        sortPos++;
                        //Debug:
                        std::cout << "right = " << right << " + 1 = ";
                        right++;
                        std::cout << right << std::endl;
                    }
                    //apply changes to original array
                    for(sortPos = 0; sortPos < length; sortPos++){
                        array[i+sortPos]=sorted[sortPos];
                    }
                    //delete[] sorted;
                    //avoid memory leak?
                    //https://stackoverflow.com/questions/33423502/expression-did-not-evaluate-to-a-constant-c
                    //
                }
                //second attempt: still experiencing error on temp array init
                //C:\Users\Scott\CLionProjects\ex04-mergesort\include\mergesort.h(36): error C2131: expression did not evaluate to a constant
                //C:\Users\Scott\CLionProjects\ex04-mergesort\include\mergesort.h(36): note: failure was caused by a read of a variable outside its lifetime
                //C:\Users\Scott\CLionProjects\ex04-mergesort\include\mergesort.h(36): note: see usage of 'length'

                void mergesort2(int64_t array[], uint64_t i, uint64_t k){
                    //Debug: what were inputs
                    std::cout << "mergesort entered" << std::endl;
                    std::cout << "i = " << i << std::endl;
                    std::cout << "k = " << k << std::endl;
                    std::cout << std::endl;
                    //partition/recursive call
                    if(i<k){
                        uint64_t  breakpoint = i + ((k-i)/2);
                        mergesort2(array, i, breakpoint); //recursive call LHS
                        mergesort2(array, breakpoint+1, k); //recursive call RHS

                        //DEBUG:
                        std::cout << "ready to merge from " << i << " to " << k << std::endl;
                        std::cout << "midpoint value array[" << breakpoint << "] = " << array[breakpoint] << std::endl;
                        //std::cout << "mergesort (overloaded 3 input) test" <<std::endl;

                        //pass LHS & RHS (individually sorted) into merge
                        merge2(array, i, breakpoint, k);

                        //DEBUG: print sub-array
                        for(int index = i; index < (k-i+1); index++){
                            std::cout << "array[" << index << "] equals " << array[index] << std::endl;
                        }
                        std::cout << std::endl;
                    }else{
                        //DEBUG: single value in interval i, k: print
                        std::cout << "array[" << i << "] = " << array[i] << std::endl;
                        std::cout << std::endl;
                    }
                }

                /*
                //template<typename T>
                //void merge(T array[], uint64_t i, uint64_t split, uint64_t k){

                    //DEBUG: notify entered Merge
                    std::cout << "\n Merge Function Reached \n" << std::endl;
                    std::cout << "in merge i=" << i << ", k =" << k << std::endl;
                    size_t length = (k-i+1)/2;
                    //DEBUG
                    std::cout << "length = " << length << std::endl;
                    T sorted[length];
                    //T *sorted = new T [length];
                    //^dynamic array?
                    //source1: https://stackoverflow.com/questions/33423502/expression-did-not-evaluate-to-a-constant-c
                    //source2: https://linuxconfig.org/example-of-c-class-template-array-to-instantiate-an-array-of-any-element-type
                    //
                    uint64_t sortPos=0;
                    uint64_t left = i; //beginning of LHS
                    uint64_t right = split+1; //beginning of RHS

                    while(left<=split && right<=k){
                        //put smallest elements into new array
                        //in order smallest to highest
                        if(array[left]<=array[right]){
                            sorted[sortPos]=array[left];
                            left++;
                        }else{
                            sorted[sortPos]=array[right];
                            right++;
                        }
                        sortPos++;
                    }
                    //fill in all the empty slots with the remaining
                    //members of LHS and RHS
                    while(left<=split){
                        sorted[left]=array[left];
                        left++;
                        sortPos++;
                    }
                    while(right<=k){
                        sorted[right]=array[right];
                        right++;
                        sortPos++;
                    }
                    //apply changes to original array
                    for(sortPos = 0; sortPos < length; sortPos++){
                        array[i+sortPos]=sorted[sortPos];
                    }
                    //delete[] sorted;
                    //avoid memory leak?
                    //https://stackoverflow.com/questions/33423502/expression-did-not-evaluate-to-a-constant-c
                    //
                }
                 */
                //merge: 3 parameters, templated



                /*template<typename T>
                    void mergesort(T array[], size_t size){
                        std::cout << "mergesort test" <<std::endl;

                    }
                    */
                //attempt: mergesort class, two parameters inputs



                /*template<typename T> //overloading template with 3 inputs
                void mergesort(T array[], uint64_t i, uint64_t k){
                     //Debug: what were inputs
                    std::cout << "mergesort entered" << std::endl;
                    std::cout << "i = " << i << std::endl;
                    std::cout << "k = " << k << std::endl;
                    std::cout << std::endl;
                    //partition/recursive call
                    if(i<k){
                        uint64_t  breakpoint = i + ((k-i)/2);
                        mergesort(array, i, breakpoint); //recursive call LHS
                        mergesort(array, breakpoint+1, k); //recursive call RHS

                        //DEBUG:
                        std::cout << "ready to merge from " << i << " to " << k << std::endl;
                        std::cout << "midpoint value array[" << breakpoint << "] = " << array[breakpoint] << std::endl;
                        //std::cout << "mergesort (overloaded 3 input) test" <<std::endl;

                        //pass LHS & RHS (individually sorted) into merge
                        merge(array, i, breakpoint, k);

                        //DEBUG: print sub-array
                        for(int index = i; index < (k-i+1); index++){
                            std::cout << "array[" << index << "] equals " << array[index] << std::endl;
                        }
                        std::cout << std::endl;
                    }else{
                        //DEBUG: single value in interval i, k: print
                        std::cout << "array[" << i << "] = " << array[i] << std::endl;
                        std::cout << std::endl;
                    }

                }*/
                //attempt 2: mergesort class overloaded template 3 parameters


            }
        }
    }
}

#endif //EX04_MERGESORT_MERGESORT_H
