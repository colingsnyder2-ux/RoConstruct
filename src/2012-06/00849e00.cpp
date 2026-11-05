// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_2a09ce337325388a.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_wp_s_s_p1 {
struct A;
void target(boost::weak_ptr<A>, std::string, std::string, int);
void make(boost::function1<void, int>& out, const boost::weak_ptr<A>& a, const std::string& s, const std::string& t)
{
    out = boost::bind(&target, a, s, t, _1);
}
}
