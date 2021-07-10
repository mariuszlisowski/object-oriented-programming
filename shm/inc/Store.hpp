#pragma once

#include <memory>
#include <vector>

#include "shm/inc/Item.hpp"
#include "shm/inc/Subscriber.hpp"

class Cargo;
class Player;

constexpr size_t MIN_CARGO_IN_STORE{ 0 };
constexpr size_t MAX_CARGO_IN_STORE{ 100 };
constexpr size_t STORE_CAPACITY { 1000 };

class Store : public Subscriber {
public:
    explicit Store(const size_t & storeSize);
    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    Cargo* getCargo(const std::string& name) const;

    // override from Subscriber
    void nextDay() override;
    size_t randomGenerate(size_t min, size_t max);
    Item::Rarity rarityConversion(size_t numberForConversion);
    
private:
    void generateAllCargo();
    void convertDataFromFile(std::string lineFromFile);
    void generateSingleCargo(std::vector<std::string>const & cargo);
    void generateFruit(std::vector<std::string>const & cargo);
    void generateAlcohol(std::vector<std::string>const & cargo);
    void generateItem(std::vector<std::string>const & cargo);
    void generateDryFruits(std::vector<std::string>const & cargo);
    std::vector<std::unique_ptr<Cargo>> cargo_;
};
