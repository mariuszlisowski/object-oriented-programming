#include "shm/inc/Cargo.hpp"
#include "shm/inc/Island.hpp"
#include "shm/inc/Player.hpp"
#include "shm/inc/Ship.hpp"
#include "gtest/gtest.h"

#include <cstddef>
#include <memory>

namespace shm_test {

constexpr size_t SHIP_CAPACITY = 500;
constexpr char SHIP_NAME[] = "Titanic";
constexpr size_t SHIP_MAX_CREW = 20;
constexpr size_t SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 1;
constexpr size_t AVAILABLE_SPACE = 100;                             // Ship or Player
// constexpr size_t SHIP_CREW = 5;

constexpr size_t PLAYER_MONEY = 1000;

constexpr char CARGO_NAME[] = "Banana";
constexpr size_t CARGO_AMOUNT = 16;
constexpr size_t CARGO_BASEPRICE = 3;

auto ship = std::make_unique<Ship>(SHIP_ID, SHIP_NAME, SHIP_SPEED, SHIP_MAX_CREW, SHIP_CAPACITY);

TEST(ShipTest, ShouldInitShip)
{
    EXPECT_EQ(ship->getId(), SHIP_ID);
    EXPECT_EQ(ship->getMaxCrew(), SHIP_MAX_CREW);
    EXPECT_EQ(ship->getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship->getCapacity(), SHIP_CAPACITY);
}
TEST(ShipTest, ShouldAddCrew)
{
    // ship += SHIP_CREW;
    // EXPECT_EQ(ship->getCrew(), SHIP_CREW);
}
TEST(ShipTest, ShouldSubtractCrew)
{
    // ship -= SHIP_CREW;
    // EXPECT_EQ(ship->getCrew(), 0);
}

Player player(std::move(ship), PLAYER_MONEY, AVAILABLE_SPACE);
TEST(PlayerTest, ShouldInitPlayer)
{
    EXPECT_EQ(player.getMoney(), PLAYER_MONEY);
    EXPECT_EQ(player.getAvailableSpace(), AVAILABLE_SPACE);
}

Cargo cargo(CARGO_NAME, CARGO_AMOUNT, CARGO_BASEPRICE);
TEST(CargoTest, ShouldAddCargo) {

}

}  // namespace shm_test
