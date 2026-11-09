// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_e1516e7b2b86dd2b.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_i_s_w_f {
struct A;
void target(int, std::string, boost::weak_ptr<A>, boost::function0<void>);
void make(boost::function0<void>& out, int i, const std::string& s, boost::weak_ptr<A> a, const boost::function0<void>& f)
{
    out = boost::bind(&target, i, s, a, f);
}
}
