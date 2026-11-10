// >>> native-status (generated) -- do not edit >>>
// ThreadName | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2ce26cd8 | roc native-status --write
#include <string>
#include <boost/thread/once.hpp>
#include <boost/thread/tss.hpp>

namespace RBX { namespace boost_detail {
extern boost::thread_specific_ptr<std::string>* foo;
extern boost::once_flag once_init_foo;
void init_foo();
} }

extern const char* defaultThreadName;

const char* currentThreadName()
{
    boost::call_once(&RBX::boost_detail::init_foo, RBX::boost_detail::once_init_foo);
    std::string* name = RBX::boost_detail::foo->get();
    return name ? name->c_str() : defaultThreadName;
}
