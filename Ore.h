#pragma once

#include "Resource.h"

class Ore: public Resource {
    int planet;
public:
    Ore(const std::string &name, double price, int planet);

    ResourceType getType() const override;

    double GetK() const override;

    double getTimeToProduce(bool scaled) const override;

    int getPlanet() const override;
};
