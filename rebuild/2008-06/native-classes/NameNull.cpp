#include "util/Name.h"
#include <boost/thread/once.hpp>

// Extracted from accepted/App/util/Name.cpp; select only one provider.
static const RBX::Name* nullName;
static void initNullName() {
    nullName = &RBX::Name::declare("", 0);
}

namespace RBX {
const Name& Name::getNullName() {
    static boost::once_flag nullNameFlag = BOOST_ONCE_INIT;
    boost::call_once(initNullName, nullNameFlag);
    return *nullName;
}
}
