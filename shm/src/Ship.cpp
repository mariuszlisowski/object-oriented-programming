#include "../inc/Ship.hpp"
#include <iostream>

Ship::Ship(size_t id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{}

Ship::Ship(size_t id, size_t speed, size_t maxCrew) 
    : Ship(id, "Ship", speed, maxCrew, 100)
{}

Ship& Ship::operator+=(const size_t amount) {
    if (amount + crew_ <= maxCrew_) {
        crew_ += amount;
    } else {
        std::cerr << "Maximum amount of crew is " << maxCrew_ << '\n';
    }
    return *this;
}

Ship& Ship::operator-=(const size_t amount) {
    if (crew_ <= amount) {
        crew_ -= amount;
    } else {
        std::cerr << "Amount of crew can't be under 0\n";
    }
    return *this;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (cargo_.size() <= index) {
        return nullptr;
    }
    return cargo_[index];
}

size_t Ship::countAvailableSpace() const {
    return capacity_ - std::accumulate(cargo_.cbegin(), cargo_.cend(), 0);
}
