#include "Project.h"

Project::Project(const std::string &name,
                 const Resources &resources) : Resource(name, 0, resources) {}

ResourceType Project::getType() const {
    return rtProject;
}

double Project::GetK() const {
    return 1;
}

uint32_t Project::getTimeToProduce(bool scaled) const {
    return 0;
}
