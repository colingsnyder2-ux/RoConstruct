// >>> native-status (generated) -- do not edit >>>
// ApplicationExceptionLog | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src e9cf8550 | roc native-status --write
#include "util/standardout.h"
#include "CRobloxApp.h"
#include <exception>

void LogManager::ReportException(const std::exception& error)
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error.what());
}
