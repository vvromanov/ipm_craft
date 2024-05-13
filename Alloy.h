#pragma once

#include "Resource.h"
#include "ResourceList.h"

class Alloy: public Resource {
    uint32_t time_to_produce;
public:
    Alloy(const std::string &name, double recept_price, double price, uint32_t timeToProduce, const Resources &resources);

    double GetK() const override;

    ResourceType getType() const override;

    double getTimeToProduce(bool scaled) const override;
};