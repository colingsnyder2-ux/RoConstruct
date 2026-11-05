// from server: 74% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_0b963edf31030d5d.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_sp_sp_f {
struct A; struct B;
void target(boost::shared_ptr<A>, boost::shared_ptr<B>, boost::function0<void>);
void make(boost::function0<void>& out, const boost::shared_ptr<A>& a, const boost::shared_ptr<B>& b, const boost::function0<void>& f)
{
    out = boost::bind(&target, a, b, f);
}
}
