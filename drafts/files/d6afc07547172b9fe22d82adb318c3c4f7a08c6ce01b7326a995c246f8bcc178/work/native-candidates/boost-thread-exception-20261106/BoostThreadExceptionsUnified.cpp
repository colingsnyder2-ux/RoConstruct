// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /DBOOST_ALL_NO_LIB /DWIN32 /DNDEBUG /D_LIB
// Inactive unified probe: genuine vendor boost::thread exceptions with the
// destructor chain kept out-of-line so the scalar deleting destructor calls
// the base destructor exactly as the original does.
// No linked selection/runtime activation.
#include <boost/thread/exceptions.hpp>

namespace boost {

thread_exception::thread_exception()
    : m_sys_err(0)
{
}

#pragma auto_inline(off)
thread_exception::~thread_exception() throw()
{
}
#pragma auto_inline(on)

lock_error::lock_error()
{
}

#pragma auto_inline(off)
lock_error::~lock_error() throw()
{
}
#pragma auto_inline(on)

const char* lock_error::what() const throw()
{
    return "boost::lock_error";
}

thread_resource_error::thread_resource_error()
{
}

#pragma auto_inline(off)
thread_resource_error::~thread_resource_error() throw()
{
}
#pragma auto_inline(on)

const char* thread_resource_error::what() const throw()
{
    return "boost::thread_resource_error";
}

} // namespace boost
