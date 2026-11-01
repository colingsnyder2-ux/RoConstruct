#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

double RBX::DataModel::getDutyCycle() const { return runService->dutyCycle(); }
