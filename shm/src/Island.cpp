#include "shm/inc/Island.hpp"

#include <cmath>

Island::Coordinates::Coordinates(size_t positionX, size_t positionY) 
    : positionX_(positionX)
    , positionY_(positionY)
{}

bool Island::Coordinates::operator==(const Coordinates& position) const {
    return (positionX_ == position.positionX_ && positionY_ == position.positionY_); 
}

static size_t Island::Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    return std::sqrt(std::pow((int)lhs.positionX_ - (int)rhs.positionX_, 2) + std::pow((int)lhs.positionY_ - (int)rhs.positionY_, 2));
}

Island::Island(const Island::Coordinates& position)
    : position_(position)
{}
