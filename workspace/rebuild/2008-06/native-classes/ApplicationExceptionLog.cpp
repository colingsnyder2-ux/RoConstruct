// >>> native-status (generated) -- do not edit >>>
// ApplicationExceptionLog | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e9cf8550 | roc native-status --write
#include "util/standardout.h"
#include "CRobloxApp.h"
#include <exception>

void LogManager::ReportException(const std::exception& error)
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error.what());
}
