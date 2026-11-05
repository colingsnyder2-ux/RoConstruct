// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_021f5d769b00178a.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_i_s_wp_f_p1 {
struct A;
void target(int, std::string, boost::weak_ptr<A>, boost::function0<void>, int);
void make(boost::function1<void, int>& out, int a, const std::string& s, const boost::weak_ptr<A>& w, const boost::function0<void>& f)
{
    out = boost::bind(&target, a, s, w, f, _1);
}
}
