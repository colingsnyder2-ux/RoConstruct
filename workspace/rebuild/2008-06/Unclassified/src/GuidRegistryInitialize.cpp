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
