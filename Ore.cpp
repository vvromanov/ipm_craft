#include "Ore.h"

Ore::Ore(const std::string &name, double price, int planet) : Resource(name, 0, price), planet(planet) {}

ResourceType Ore::getType() const {
    return rtOre;
}

double Ore::GetK() const {
    return 1;
}

double Ore::getTimeToProduce(bool scaled) const {
    return 0;
}

int Ore::getPlanet() const {
    return planet;
}
