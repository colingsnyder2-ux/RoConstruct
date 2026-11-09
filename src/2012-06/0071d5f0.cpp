// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_8f398528ea9dc422.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_ww_s {
struct A;
struct B;
void target(boost::weak_ptr<A>, boost::weak_ptr<B>, std::string);
void make(boost::function0<void>& out, boost::weak_ptr<A> a, boost::weak_ptr<B> b, const std::string& s)
{
    out = boost::bind(&target, a, b, s);
}
}
