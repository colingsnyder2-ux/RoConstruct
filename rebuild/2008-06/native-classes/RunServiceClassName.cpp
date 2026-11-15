#include "util/RunStateOwner.h"

namespace RBX {
template<>
const Name& FactoryProduct<RunService, Instance, sRunService>::getClassName() const {
    return Name::declare<sRunService>();
}
}
