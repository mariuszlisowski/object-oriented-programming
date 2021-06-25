#include "gtest/gtest.h"

#define private public
#include "shm/inc/Map.hpp"
#undef private

extern size_t ISLANDS_COUNT;

namespace shm_test {

TEST(MapTest, ShouldGenerateVectorOfIslands) {
    Map map;
    EXPECT_EQ(map.vectorOfIslands_.size(), ISLANDS_COUNT);
}

}  // namespace shm_test
