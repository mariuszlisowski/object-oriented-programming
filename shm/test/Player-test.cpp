#include "gtest/gtest.h"

#include "shm/inc/Player.hpp"
#include <iostream>

namespace shm_test {

constexpr size_t SHIP_CAPACITY = 500;
constexpr char SHIP_NAME[] = "Titanic";
constexpr size_t SHIP_MAX_CREW = 20;
constexpr size_t SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 1;
constexpr size_t AVAILABLE_SPACE = 100;
constexpr size_t PLAYER_MONEY = 1000;

auto SHIP = std::make_unique<Ship>(SHIP_ID, SHIP_NAME, SHIP_SPEED, SHIP_MAX_CREW, SHIP_CAPACITY);
Player player(std::move(SHIP), PLAYER_MONEY, AVAILABLE_SPACE);

// TEST(PlayerTest, ShoudGetShipPtr) {
//     EXPECT_EQ(player.getShip(), SHIP.get());
// }

TEST(PlayerTest, ShoudGetPlayerMoney) {
    EXPECT_EQ(player.getMoney(), PLAYER_MONEY);
}

TEST(PlayerTest, ShoudGetPlayerAvailableSpace) {
    EXPECT_EQ(player.getAvailableSpace(), AVAILABLE_SPACE);
}

TEST(PlayerTest, ShoudGetShipSpeed) {
    EXPECT_EQ(player.getSpeed(), SHIP_SPEED);
}

// TEST(PlayerTest, ShoudGetShipCargo) {
//     EXPECT_EQ(player.getCargo(), SHIP_SPEED);
// }

}