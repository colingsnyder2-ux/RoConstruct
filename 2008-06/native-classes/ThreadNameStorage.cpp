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
