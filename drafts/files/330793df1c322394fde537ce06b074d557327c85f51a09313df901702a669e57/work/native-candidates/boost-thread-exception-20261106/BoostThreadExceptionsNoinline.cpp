// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /DBOOST_ALL_NO_LIB /DWIN32 /DNDEBUG /D_LIB
// Inactive recovery probe: genuine vendor boost::thread exceptions with
// destructor inlining disabled, so the scalar deleting destructor calls the
// base destructor out-of-line exactly as the original does.
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

#pragma auto_inline(off)
lock_error::~lock_error() throw()
{
}
#pragma auto_inline(on)

#pragma auto_inline(off)
thread_resource_error::~thread_resource_error() throw()
{
}
#pragma auto_inline(on)

} // namespace boost
