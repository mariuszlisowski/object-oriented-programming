#pragma once

#include <cstddef>
#include <memory>

#include "shm/inc/Delegate.hpp"
#include "shm/inc/Ship.hpp"

class Cargo;
class Island;
class Map;

// class responsible for manage user in game
class Player : public Delegate {

public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);
    ~Player() override {};

    Ship* getShip() { return ship_.get(); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_.second; };
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
    Island* getCurrentPosition() const;
    void setCurrentPosition(Island* island);
    Cargo* getCargo(const std::string& name) const;

    //override from Delegate
    void payCrew(const size_t payCrew) override;
    void setPlayerPtr();
    void buy(Cargo* cargo, size_t amount);
    void sell(Cargo* cargo, size_t amount);

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    std::pair<bool, size_t> availableSpace_;
    size_t countAvailableSpace() const;
    Island* currentPosition_;
    Map* map_;
};
