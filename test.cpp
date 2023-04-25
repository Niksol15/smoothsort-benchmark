#include <gtest/gtest.h>

#include "generate_random_vec.hpp"
#include "smooth_sort.hpp"

#include <algorithm>

TEST(SmoothSortTest, TestOnRandomData100) {
    auto a = GenerateRandomVec(100);
    auto b = GenerateRandomVec(100);

    std::sort(a.begin(), a.end());
    Smoothsort(b.begin(), b.end());

    EXPECT_EQ(a, b);
}

