// >>> native-status (generated) -- do not edit >>>
// HttpTrustState | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 66412684 | roc native-status --write
#include <boost/thread/once.hpp>

namespace RBX {
bool skipTrustCheck;
boost::once_flag trustCheckOnce = BOOST_ONCE_INIT;
}
