#ifndef GENERATE_RANDOM_VEC
#define GENERATE_RANDOM_VEC

#include <random>
#include <limits>
#include <map>

namespace {
    std::vector<int> GenerateRandomVec(size_t n) {
        static std::map<size_t, std::vector<int>> random_vecs{};

        if (random_vecs.contains(n)) {
            return random_vecs[n];
        }

        std::random_device rnd_device{};
        std::mt19937 mersenne_engine{rnd_device()};
        std::uniform_int_distribution<int> dist{std::numeric_limits<int>::min(), std::numeric_limits<int>::max()};

        auto gen = [&dist, &mersenne_engine]() {
            return dist(mersenne_engine);
        };

        std::vector<int> vec(n);
        std::generate(begin(vec), end(vec), gen);

        random_vecs[n] = vec;

        return vec;
    }
}

#endif // GENERATE_RANDOM_VEC