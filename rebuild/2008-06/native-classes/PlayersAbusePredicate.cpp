#include "Network/Players.h"
namespace RBX { namespace Network {
bool Players::canReportAbuse() const { return abuseReporter || clientIsPresent(this, true); }
} }
