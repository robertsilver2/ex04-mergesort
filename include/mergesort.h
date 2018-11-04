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
                template<typename T>
                    void mergesort(T array[], size_t size){
                        std::cout << "mergesort test" <<std::endl;

                    }

                template<typename T> //overloading template with 3 inputs
                    void mergesort(T array[], T i, T k){
                         //Debug: what were inputs
                         std::cout << "mergesort entered \n" << std::endl;
                         std::cout << "i = " << i << "\n" << std::endl;
                         std::cout << "k = " << k << "\n" << std::endl;

                        //partition/recursive call
                        if(i<k){
                            uint64_t  breakpoint = i + ((k-i)/2);
                            mergesort(array, i, breakpoint); //recursive call LHS
                            mergesort(array, breakpoint+1, k); //recursive call RHS

                            //DEBUG:
                            std::cout << "midpoint value array[" << breakpoint << "] = " << array[breakpoint] << std::endl;
                            std::cout << "mergesort (overloaded 3 input) test" <<std::endl;

                            //DEBUG: print sub-array
                            for(int index = i; index < (k-i+1); index++){
                                std::cout << "array[" << index << "] equals " << array[index] << "\n" << std::endl;
                                std::cout << std::endl;
                            }
                        }/*else{
                            //DEBUG: single value in interval i, k: print
                            std::cout << array[i] << "\n" << std::endl;
                        }*/

                    }
            }
        }
    }
}

#endif //EX04_MERGESORT_MERGESORT_H
