// >>> native-status (generated) -- do not edit >>>
// GuidRegistryInitialize | 2008-06 | inactive
// 0/1 exact by name (0%) | 0/1 exact bodies | no strings | verified 2026-11-07| by king_originala (chatgpt:gpt-6.1-sol)
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
