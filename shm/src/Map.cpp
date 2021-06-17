#include "../inc/Map.hpp"

#include <algorithm>

std::shared_ptr<Island> Map::getIsland(const Island& coordinate) {
    std::shared_ptr<Island> islandPtr = nullptr;
    auto islandCoordinate = std::find(vectorOfIslands_.begin(), vectorOfIslands_.end(), coordinate);
    if (islandCoordinate != vectorOfIslands_.end()) {
        islandPtr = std::make_shared<Island>(*islandCoordinate);
    }
    return islandPtr ;
}