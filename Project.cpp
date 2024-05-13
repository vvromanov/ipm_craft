#include "Project.h"
#include "MiningSettings.h"

Project::Project(const std::string &name,
                 const Resources &resources) : Resource(name, 0, 0, resources) {}

ResourceType Project::getType() const {
    return rtProject;
}

double Project::GetK() const {
    return IPM_PROJECT_RESOURCE_K;
}

double Project::getTimeToProduce(bool scaled) const {
    return 0;
}
