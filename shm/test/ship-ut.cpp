#include "gtest/gtest.h"
#include "shm/inc/Ship.hpp"

#include <cstddef>

namespace shm_test {

constexpr size_t SHIP_ID = 1;
constexpr char SHIP_NAME[] = "Titanic";
constexpr size_t SHIP_SPEED = 20;
constexpr size_t SHIP_CAPACITY = 500;
constexpr size_t SHIP_MAX_CREW = 20;
constexpr size_t SHIP_INITIAL_CREW = 0;
constexpr size_t SHIP_CREW = 5;

Ship ship(SHIP_ID, SHIP_NAME, SHIP_SPEED, SHIP_MAX_CREW, SHIP_CAPACITY);
TEST(ShipTest, ShouldInitShip) {
    EXPECT_EQ(ship.getId(), SHIP_ID);
    EXPECT_EQ(ship.getName(), SHIP_NAME);
    EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW);
    EXPECT_EQ(ship.getCapacity(), SHIP_CAPACITY);
    EXPECT_EQ(ship.getCrew(), SHIP_INITIAL_CREW);
}
TEST(ShipTest, ShouldSetName) {
    const char NEW_SHIP_NAME[] = "Britannia";
    ship.setName(NEW_SHIP_NAME);
    EXPECT_EQ(ship.getName(), NEW_SHIP_NAME);
}
TEST(ShipTest, ShouldAddCrew) {
    ship += SHIP_CREW;
    EXPECT_EQ(ship.getCrew(), SHIP_CREW);
}
TEST(ShipTest, ShouldSubtractCrew) {
    ship -= SHIP_CREW;
    EXPECT_EQ(ship.getCrew(), SHIP_INITIAL_CREW);
}
TEST(ShipTest, ShouldNotAddCrew) {
    ship += SHIP_MAX_CREW + 1;
    EXPECT_EQ(ship.getCrew(), SHIP_INITIAL_CREW);
}

}  // namespace shm_test
