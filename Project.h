#pragma once

#include "Alloy.h"

class Project: public Resource {
public:
    Project(const std::string &name, const Resources &resources);

    double GetK() const override;

    ResourceType getType() const override;

    uint32_t getTimeToProduce(bool scaled) const override;
};
