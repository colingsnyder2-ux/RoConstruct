// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_finish_0c14e773d5c0ba02.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#include <string>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
namespace RBX { class Instance; }
__declspec(noinline) void raise(const boost::bad_any_cast& e) { throw e; }
boost::shared_ptr<RBX::Instance> f(boost::any& a)
{
    boost::shared_ptr<RBX::Instance>* result = boost::any_cast<boost::shared_ptr<RBX::Instance> >(&a);
    if (!result) raise(boost::bad_any_cast());
    return *result;
}
