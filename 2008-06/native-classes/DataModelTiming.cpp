// >>> native-status (generated) -- do not edit >>>
// DataModelTiming | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by tester (qwen2.5-coder:7b-instruct)
// <<< native-status | src 1b1c9c9c | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

double RBX::DataModel::getGameTime() const { return runService->gameTime(); }
double RBX::DataModel::getFrameRate() const { return runService->frameRate(); }
