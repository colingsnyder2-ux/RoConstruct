#include <boost/thread/once.hpp>

namespace RBX {
bool skipTrustCheck;
boost::once_flag trustCheckOnce = BOOST_ONCE_INIT;
}
