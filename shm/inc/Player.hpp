#pragma once

#include <cstddef>
#include <memory>

#include "shm/inc/Delegate.hpp"
#include "shm/inc/Ship.hpp"

class Cargo;

// class responsible for manage user in game
class Player : public Delegate {

public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);
    ~Player() override {};

    std::unique_ptr<Ship> getShip() { return std::move(ship_); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_.second; };
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    Cargo* getCargo(const std::string& name) const;
    
    //override from Delegate
    void payCrew(const size_t payCrew) override;
    void setPlayerPtr();

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    std::pair<bool, size_t> availableSpace_;
    size_t countAvailableSpace() const;
};
