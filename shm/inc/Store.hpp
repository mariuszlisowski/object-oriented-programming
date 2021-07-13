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

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    std::shared_ptr<Cargo> getCargo(const std::string& name) const;

    // override from Subscriber
    void nextDay() override;
    size_t randomGenerate(size_t min, size_t max);
    Item::Rarity rarityConversion(size_t numberForConversion);

private:
    void generateAllCargo();
    void convertDataFromFile(std::string lineFromFile);
    void valueOneLineAssignment(const size_t & wordNumber, const std::string & singleWordFromFile);
    void generateSingleCargo();
    void generateFruit();
    void generateAlcohol();
    void generateItem();
    void generateDryFruits();
    std::vector<std::shared_ptr<Cargo>> cargo_;

    struct SplitLineFromFile {
        std::string className_{};
        std::string itemName_{};
        size_t minAmount_{};
        size_t maxAmount_{};
        size_t minPrice_{};
        size_t maxPrice_{};
        size_t minUniqueStat_{};
        size_t maxUniqueStat_{};
    } oneLine_;
};
