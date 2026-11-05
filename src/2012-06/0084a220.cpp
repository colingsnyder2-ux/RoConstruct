// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_07c67e4e9cc44a1a.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_p_s_s {
struct A;
void target(boost::shared_ptr<A>, std::string, std::string);
void make(boost::function0<void>& out, boost::shared_ptr<A> a, const std::string& s, const std::string& t)
{
    out = boost::bind(&target, a, s, t);
}
}
