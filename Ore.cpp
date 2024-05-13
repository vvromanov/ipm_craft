//
// Created by Vladimir Romanov on 01/05/2024.
//

#include "Ore.h"

ResourceType Ore::getType() const {
    return rtOre;
}

Ore::Ore(const std::string &name, double price) : Resource(name, price) {}

double Ore::GetK() const {
    return 1;
}

uint32_t Ore::getTimeToProduce(bool scaled) const {
    return 0;
}
