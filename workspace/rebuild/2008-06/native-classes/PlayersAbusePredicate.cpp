// >>> native-status (generated) -- do not edit >>>
// PlayersAbusePredicate | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 0b72f2e4 | roc native-status --write
#include "Network/Players.h"
namespace RBX { namespace Network {
bool Players::canReportAbuse() const { return abuseReporter || clientIsPresent(this, true); }
} }

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<RBX::Network::AbuseReporter>;
