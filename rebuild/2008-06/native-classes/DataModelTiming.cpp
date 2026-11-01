#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

double RBX::DataModel::getGameTime() const { return runService->gameTime(); }
double RBX::DataModel::getFrameRate() const { return runService->frameRate(); }
