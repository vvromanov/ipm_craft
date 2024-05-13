#include "Item.h"
#include "MiningSettings.h"

Item::Item(const std::string &name, double recept_price, double price, uint32_t timeToProduce, const Resources &resources)
        : Alloy(name, recept_price, price, timeToProduce, resources) {
}

ResourceType Item::getType() const {
    return rtItem;
}

double Item::GetK() const {
    return IPM_CRAFT_RESOURCE_K;
}

double Item::getTimeToProduce(bool scaled) const {
    return Alloy::getTimeToProduce(false)/(scaled?IPM_CRAFT_TIME_K:1);
}
