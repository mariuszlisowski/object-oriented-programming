#include "shm/inc/Cargo.hpp"

class Item : public Cargo {
public:
   enum class Rarity {
        common = 1,
        rare = 4,
        epic = 9,
        legendary = 15
    };

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);

    bool operator==(const Cargo& item) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getPrice() const override;
    Rarity getRarity() const;

private:
    const Rarity rarity_;
};