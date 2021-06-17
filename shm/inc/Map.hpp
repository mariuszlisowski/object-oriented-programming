#pragma once

#include <memory>

class Map {
public:
    std::shared_ptr<Island> getIsland(const Island& coordinate);
};

