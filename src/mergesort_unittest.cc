// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX01-LinearSearch in CSV15 at Ventura College.
//
// Author: aknight@vcccd.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <fstream>
#include <utility>
#include <random>

#include "gtest/gtest.h"
#include "GTestNoDeath.h"
#include "mergesort.h"

namespace {

    void readWords(const std::string &filename, std::string words[], size_t size) {
        std::ifstream in(filename);

        size_t count = 0;
        for (; !in.fail() && !in.eof() && count < size; count++) {
            in >> words[count];
        }
    }

    using namespace ::testing_internal;
    using edu::vcccd::vc::csv15::mergesort;

    class MergeSortTest : public ::testing::Test {
    protected:
        static const uint64_t MAX_TESTED_SCORE = 20;
        static const uint64_t MAX_OVERALL_SCORE = 25;
        static uint64_t _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            }
            else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " (" << (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remainder of 5 points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint64_t MergeSortTest::_testScore = 0;

    // Tests returned string of greetWorld().
    TEST_F(MergeSortTest, BasicInt) {
        // This test is named "Positive", and belongs to the "HelloWorld"
        // test case.

        int array[] = { 5, 3, 12, 9, 10, 1 };
        mergesort(array, 6);
        ASSERT_EQ( 1, array[0]);
        ASSERT_EQ( 3, array[1]);
        ASSERT_EQ( 5, array[2]);
        ASSERT_EQ( 9, array[3]);
        ASSERT_EQ(10, array[4]);
        ASSERT_EQ(12, array[5]);

        int array2[] = { 5, 3, 12, 9, 10, 1 };
        mergesort(array2, 5);
        ASSERT_EQ( 3, array2[0]);
        ASSERT_EQ( 5, array2[1]);
        ASSERT_EQ( 9, array2[2]);
        ASSERT_EQ(10, array2[3]);
        ASSERT_EQ(12, array2[4]);
        ASSERT_EQ( 1, array2[5]);

        _testScore += 6;
    }

    // Tests returned string of greetWorld().
    TEST_F(MergeSortTest, BasicString) {
        // This test is named "Positive", and belongs to the "HelloWorld"
        // test case.

        std::string array[] = { "bee", "ape", "key", "day", "zoo", "man" };
        mergesort(array, 6);
        ASSERT_EQ("ape", array[0]);
        ASSERT_EQ("bee", array[1]);
        ASSERT_EQ("day", array[2]);
        ASSERT_EQ("key", array[3]);
        ASSERT_EQ("man", array[4]);
        ASSERT_EQ("zoo", array[5]);

        std::string array2[] = { "bee", "ape", "key", "day", "zoo", "man" };
        mergesort(array2, 5);
        ASSERT_EQ("ape", array2[0]);
        ASSERT_EQ("bee", array2[1]);
        ASSERT_EQ("day", array2[2]);
        ASSERT_EQ("key", array2[3]);
        ASSERT_EQ("zoo", array2[4]);
        ASSERT_EQ("man", array2[5]);

        _testScore += 6;
    }

    constexpr static size_t MAX_WORDS = 100000;

    TEST_F(MergeSortTest, BasicStringWords) {
        std::string words[MAX_WORDS], randomized[MAX_WORDS];

        readWords("..\\words", words, MAX_WORDS);
        std::copy(words, words + MAX_WORDS, randomized);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(randomized, randomized + MAX_WORDS, g);

        mergesort(randomized, MAX_WORDS);
        for (size_t i = 0; i < MAX_WORDS; i++) {
            ASSERT_EQ(words[i], randomized[i]);
        }

        _testScore += 6;
    }

    }  // namespace

