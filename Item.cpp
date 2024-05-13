#include "Item.h"
#include "MiningSettings.h"

Item::Item(const std::string &name, double price, uint32_t timeToProduce, const Resources &resources)
        : Alloy(name, price, timeToProduce, resources) {
}

ResourceType Item::getType() const {
    return rtItem;
}

double Item::GetK() const {
    return IPM_CRAFT_RESOURCE_K;
}

uint32_t Item::getTimeToProduce(bool scaled) const {
    return (uint32_t)(Alloy::getTimeToProduce(false)/(scaled?IPM_CRAFT_TIME_K:1)+0.01);
}
