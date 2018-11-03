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
                        std::cout << "mergesort (overloaded 3 input) test" <<std::endl;
                        for(int index = i; index < (k-i+1); index++){
                            std::cout << "list[" << index << "] equals " << array[index] << std::endl;
                        }

                    }
            }
        }
    }
}

#endif //EX04_MERGESORT_MERGESORT_H
