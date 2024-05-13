#pragma once

#include "Alloy.h"

class Item: public Alloy {
public:
    Item(const std::string &name, double price, uint32_t timeToProduce, const Resources &resources);

    ResourceType getType() const override;
    double GetK() const override;
    uint32_t getTimeToProduce(bool scaled = true) const override;
};
