// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_a84ff96589d61955.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_w_s_f_f {
struct A;
void target(boost::weak_ptr<A>, std::string, boost::function0<void>, boost::function0<void>);
void make(boost::function0<void>& out, boost::weak_ptr<A> a, const std::string& s, const boost::function0<void>& f, const boost::function0<void>& g)
{
    out = boost::bind(&target, a, s, f, g);
}
}
