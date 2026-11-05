#include "util/standardout.h"
#include <exception>

// Static declaration shared in shape with the application's recovered call site.
class LogManager {
public:
    static void ReportException(const std::exception&);
};

void LogManager::ReportException(const std::exception& error)
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error.what());
}
