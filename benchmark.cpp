#include "smooth_sort.hpp"
#include "generate_random_vec.hpp"

#include <benchmark/benchmark.h>

namespace {
    template<size_t N>
    void BM_smoothsort_rand_N(benchmark::State &state) {
        auto vec = GenerateRandomVec(N);
        for (auto _: state) {
            Smoothsort(vec.begin(), vec.end());
        }
    }

    template<size_t N>
    void BM_std_sort_rand_N(benchmark::State &state) {
        auto vec = GenerateRandomVec(N);
        for (auto _: state) {
            std::sort(vec.begin(), vec.end());
        }
    }

    template<size_t N>
    void BM_smoothsort_sorted_N(benchmark::State &state) {
        std::vector<int> vec(N);
        std::iota(vec.begin(), vec.end(), 0);
        for (auto _: state) {
            Smoothsort(vec.begin(), vec.end());
        }
    }

    template<size_t N>
    void BM_smoothsort_worst_N(benchmark::State &state) {
        std::vector<int> vec(N);
        std::iota(vec.rbegin(), vec.rend(), 0);
        for (auto _: state) {
            Smoothsort(vec.begin(), vec.end());
        }
    }

    template<size_t N>
    void BM_std_sort_sorted_N(benchmark::State &state) {
        std::vector<int> vec(N);
        std::iota(vec.begin(), vec.end(), 0);
        for (auto _: state) {
            std::sort(vec.begin(), vec.end());
        }
    }

    template<size_t N>
    void BM_std_sort_worst_N(benchmark::State &state) {
        std::vector<int> vec(N);
        std::iota(vec.rbegin(), vec.rend(), 0);
        for (auto _: state) {
            std::sort(vec.begin(), vec.end());
        }
    }

}

BENCHMARK(BM_smoothsort_rand_N<100>);
BENCHMARK(BM_smoothsort_rand_N<1'000>);
BENCHMARK(BM_smoothsort_rand_N<10'000>);
BENCHMARK(BM_smoothsort_rand_N<100'000>);
BENCHMARK(BM_smoothsort_rand_N<1'000'000>);
BENCHMARK(BM_smoothsort_rand_N<10'000'000>);

BENCHMARK(BM_std_sort_rand_N<100>);
BENCHMARK(BM_std_sort_rand_N<1'000>);
BENCHMARK(BM_std_sort_rand_N<10'000>);
BENCHMARK(BM_std_sort_rand_N<100'000>);
BENCHMARK(BM_std_sort_rand_N<1'000'000>);
BENCHMARK(BM_std_sort_rand_N<10'000'000>);

BENCHMARK(BM_smoothsort_sorted_N<10'000'000>);
BENCHMARK(BM_smoothsort_sorted_N<100'000'000>);
BENCHMARK(BM_smoothsort_sorted_N<1'000'000'000>);

BENCHMARK(BM_std_sort_sorted_N<10'000'000>);
BENCHMARK(BM_std_sort_sorted_N<100'000'000>);
BENCHMARK(BM_std_sort_sorted_N<1'000'000'000>);

BENCHMARK_MAIN();