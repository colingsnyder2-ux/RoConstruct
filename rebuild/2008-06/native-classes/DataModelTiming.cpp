// >>> native-status (generated) -- do not edit >>>
// DataModelTiming | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 1b1c9c9c | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

double RBX::DataModel::getGameTime() const { return runService->gameTime(); }
double RBX::DataModel::getFrameRate() const { return runService->frameRate(); }
