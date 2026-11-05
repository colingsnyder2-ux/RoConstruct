// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_3339a6e77612da41.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_w_i_set {
struct A;
void target(boost::weak_ptr<A>, int, std::set<int>);
void make(boost::function0<void>& out, boost::weak_ptr<A> a, int i, const std::set<int>& s)
{
    out = boost::bind(&target, a, i, s);
}
}
