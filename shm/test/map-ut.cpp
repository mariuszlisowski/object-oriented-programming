#include "gtest/gtest.h"

#define private public
#include "shm/inc/Map.hpp"
#undef private

namespace shm_test {
Map map;
TEST(MapTest, ShouldGenerateVectorOfIslands) {
    EXPECT_EQ(map.vectorOfIslands_.size(), ISLANDS_COUNT);
}
TEST(MapTest, ShouldReturnAllIslands) {
    for (const auto& island : map.vectorOfIslands_) {
        auto coords = island.getCoordinates();
        EXPECT_EQ(map.getIsland(coords), &island);
    }
}
TEST(MapTest, ShouldReturnCurrentPosition) {
    auto FIRST_ISLAND = &map.vectorOfIslands_[0];
    EXPECT_EQ(map.currentPosition_, FIRST_ISLAND);
}

}  // namespace shm_test
