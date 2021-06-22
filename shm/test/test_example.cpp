#include "gtest/gtest.h"

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Island.hpp"
#include "shm/inc/Player.hpp"
#include "shm/inc/Ship.hpp"

#include <cstddef>
#include <memory>

namespace shm_test {

/* Ship class */
constexpr size_t SHIP_CAPACITY = 500;
constexpr char SHIP_NAME[] = "Titanic";
constexpr size_t SHIP_MAX_CREW = 20;
constexpr size_t SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 1;
constexpr size_t AVAILABLE_SPACE = 100;
constexpr size_t SHIP_CREW = 5;

// given (one instance for every test)
Ship ship(SHIP_ID, SHIP_NAME, SHIP_SPEED, SHIP_MAX_CREW, SHIP_CAPACITY);
TEST(ShipTest, ShouldInitShip) {
    EXPECT_EQ(ship.getId(), SHIP_ID);
    EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW);        // next test not recommended here
    EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship.getCapacity(), SHIP_CAPACITY);
}
TEST(ShipTest, ShouldAddCrew) {
    ship += SHIP_CREW;
    // EXPECT_EQ(ship->getCrew(), 0);                    // no getCre() method in a class
}
TEST(ShipTest, ShouldSubtractCrew) {
    ship -= SHIP_CREW;
    // EXPECT_EQ(ship->getCrew(), 0);                    // no getCre() method in a class
}
TEST(ShipTest, ShouldNotAddCrew) {
    ship += SHIP_MAX_CREW + 1;
    // EXPECT_EQ(ship.getCrew(), 0);                    // no getCre() method in a class
}
TEST(ShipTest, ShouldSetName) {
    // when
    ship.setName("Ola");
    // then
    EXPECT_EQ(ship.getName(), "Ola");
}

/* Cargo class */
constexpr char CARGO_NAME[] = "Banana";
constexpr size_t CARGO_AMOUNT = 16;
constexpr size_t CARGO_BASEPRICE = 3;

TEST(CargoTest, ShouldAddCargo) {
    // given
    Cargo cargo(CARGO_NAME, CARGO_AMOUNT, CARGO_BASEPRICE);
    // when
    cargo += 10;
    // then
    EXPECT_EQ(cargo.getAmount(), 26);
}
TEST(CargoTest, ShouldSubtractCargo) {
    // given
    Cargo cargo(CARGO_NAME, CARGO_AMOUNT, CARGO_BASEPRICE);
    // when
    cargo -= 10;
    // then
    EXPECT_EQ(cargo.getAmount(), 6);
}
TEST(CargoTest, ShouldNotSubtractCargo) {
    // given
    Cargo cargo(CARGO_NAME, CARGO_AMOUNT, CARGO_BASEPRICE);
    // when
    cargo -= 20;
    // then
    EXPECT_EQ(cargo.getAmount(), 16);
}
TEST(CargoTest, ShouldCompareCargoFalse) {
    // given
    Cargo banana("banana", CARGO_AMOUNT, CARGO_BASEPRICE);
    Cargo lemon("lemon", CARGO_AMOUNT, CARGO_BASEPRICE);
    // then
    EXPECT_FALSE(banana == lemon);
}
TEST(CargoTest, ShouldCompareCargoTrue) {
    // given
    Cargo bananaA("banana", CARGO_AMOUNT, CARGO_BASEPRICE);
    Cargo bananaB("banana", CARGO_AMOUNT, CARGO_BASEPRICE);
    // then
    EXPECT_TRUE(bananaA == bananaB);
}

/* Player class */
constexpr size_t PLAYER_MONEY = 1000;

Player player(std::make_unique<Ship>(SHIP_ID, SHIP_NAME, SHIP_SPEED, SHIP_MAX_CREW, SHIP_CAPACITY),
              PLAYER_MONEY,
              AVAILABLE_SPACE);
TEST(PlayerTest, ShoudDoSomething) {
    // TODO:
}

}  // namespace shm_test
