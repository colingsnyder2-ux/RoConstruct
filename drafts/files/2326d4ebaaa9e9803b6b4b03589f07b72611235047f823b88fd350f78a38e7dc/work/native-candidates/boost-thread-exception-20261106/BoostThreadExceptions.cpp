// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /DBOOST_ALL_NO_LIB /DWIN32 /DNDEBUG /D_LIB
// Inactive recovery probe: genuine vendor boost::thread exceptions,
// compiled to verify the CRobloxDoc RunService dependency provider.
// No linked selection/runtime activation.
#include <boost/thread/exceptions.hpp>

namespace boost {

thread_exception::thread_exception()
    : m_sys_err(0)
{
}

thread_exception::~thread_exception() throw()
{
}

lock_error::lock_error()
{
}

lock_error::~lock_error() throw()
{
}

const char* lock_error::what() const throw()
{
    return "boost::lock_error";
}

thread_resource_error::thread_resource_error()
{
}

thread_resource_error::~thread_resource_error() throw()
{
}

const char* thread_resource_error::what() const throw()
{
    return "boost::thread_resource_error";
}

} // namespace boost
