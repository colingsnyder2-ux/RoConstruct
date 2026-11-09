// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_562723fb00fff6bd.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <map>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_sp_s_f_f_1 {
struct A;
void target(boost::shared_ptr<A>, std::string, boost::function0<void>, boost::function0<void>, int);
void make(boost::function1<void, int>& out, const boost::shared_ptr<A>& a, const std::string& s, const boost::function0<void>& f, const boost::function0<void>& g)
{
    out = boost::bind(&target, a, s, f, g, _1);
}
}
