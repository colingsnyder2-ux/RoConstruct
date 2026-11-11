// >>> native-status (generated) -- do not edit >>>
// ThreadNameStorage | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8df9dd69 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::function1<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> > *,std::allocator<boost::function_base> >;
