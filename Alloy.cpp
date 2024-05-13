#include "Alloy.h"
#include "MiningSettings.h"

Alloy::Alloy(const std::string &name, double recept_price, double price, uint32_t timeToProduce, const Resources &resources)
        : Resource(name, recept_price, price, resources), time_to_produce(timeToProduce) {}

ResourceType Alloy::getType() const {
    return rtAlloy;
}

double Alloy::GetK() const {
    return IPM_SMELT_RESOURCE_K;
}

double Alloy::getTimeToProduce(bool scaled) const {
    return time_to_produce/(scaled?IPM_SMELT_TIME_K:1);
}
