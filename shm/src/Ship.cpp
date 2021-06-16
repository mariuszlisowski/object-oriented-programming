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

Ship& Ship::operator+=(const size_t value) {
    if ((value + crew_) <= maxCrew_) {
        crew_ += value;
    } else {
        std::cout << "Maximum amount of crew is " << maxCrew_ << '\n';
    }
    return *this;
}

Ship& Ship::operator-=(const size_t value) {
    if (crew_ <= value) {
        crew_ -= value;
    } else {
        std::cout << "Amount of crew can't be under 0\n";
    }
    return *this;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}