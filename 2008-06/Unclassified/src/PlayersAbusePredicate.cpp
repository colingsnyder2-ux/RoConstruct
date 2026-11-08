// >>> native-status (generated) -- do not edit >>>
// PlayersAbusePredicate | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src e343d018 | roc native-status --write
#include "Network/Players.h"
namespace RBX { namespace Network {
bool Players::canReportAbuse() const { return abuseReporter || clientIsPresent(this, true); }
} }
