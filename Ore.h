#pragma once

#include "Resource.h"

class Ore: public Resource {
public:
    Ore(const std::string &name, double price);

    ResourceType getType() const override;

    double GetK() const override;

    uint32_t getTimeToProduce(bool scaled) const override;
};
