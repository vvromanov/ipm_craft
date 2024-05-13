#include "Alloy.h"
#include "MiningSettings.h"

Alloy::Alloy(const std::string &name, double price, uint32_t timeToProduce, const Resources &resources)
        : Resource(name, price, resources), time_to_produce(timeToProduce) {}

ResourceType Alloy::getType() const {
    return rtAlloy;
}

double Alloy::GetK() const {
    return IPM_SMELT_RESOURCE_K;
}

uint32_t Alloy::getTimeToProduce(bool scaled) const {
    return (uint32_t)(time_to_produce/(scaled?IPM_SMELT_TIME_K:1)+0.01);
}
