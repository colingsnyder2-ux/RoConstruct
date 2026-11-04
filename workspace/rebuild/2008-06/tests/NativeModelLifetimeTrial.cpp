#include "v8datamodel/ModelInstance.h"

namespace RBX {
extern bool physicalCharacterHacked;
ModelInstance::ModelInstance()
    : Base("Model"), modelInPrimary(), primaryPart(NULL),
      FlagHeight(this, &ModelInstance::computeFlagHeight),
      LocalGridExtents(this, &ModelInstance::computeLocalGridExtents),
      WorldGridExtents(this, &ModelInstance::computeWorldGridExtents) {
    if (!physicalCharacterHacked) {
        const Name& name = Name::declare("PhysicalCharacter", -1);
        AbstractFactoryProduct<Instance>::getCreators()[&name] = &getCreator();
        physicalCharacterHacked = true;
    }
}
ModelInstance::~ModelInstance() {}
}
