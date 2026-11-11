// >>> native-status (generated) -- do not edit >>>
// GuidRegistryInitialize | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7650686e | roc native-status --write
#include "util/GuidRegistry.h"
#include <boost/thread/once.hpp>

namespace RBX {

GuidRegistry* guidRegistry = 0;
boost::once_flag guidRegistryInitialized = BOOST_ONCE_INIT;

void initializeGuidRegistry()
{
    guidRegistry = new GuidRegistry;
}
}
