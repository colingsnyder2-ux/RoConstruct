#include "util/standardout.h"
#include "CRobloxApp.h"
#include <exception>

void LogManager::ReportException(const std::exception& error)
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error.what());
}
