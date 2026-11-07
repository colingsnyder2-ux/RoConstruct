// >>> native-status (generated) -- do not edit >>>
// ThreadNameStorage | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src a76f366b | roc native-status --write
#include <string>
#include <boost/thread/once.hpp>
#include <boost/thread/tss.hpp>

namespace RBX { namespace boost_detail {
boost::thread_specific_ptr<std::string>* foo;
boost::once_flag once_init_foo = BOOST_ONCE_INIT;

void init_foo()
{
    static boost::thread_specific_ptr<std::string> value;
    foo = &value;
}
} }
