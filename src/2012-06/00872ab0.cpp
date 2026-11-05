// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_990dc6dce6d6b7c3.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_w_i64_f_f {
struct A;
void target(boost::weak_ptr<A>, __int64, boost::function0<void>, boost::function0<void>);
void make(boost::function0<void>& out, boost::weak_ptr<A> a, __int64 i, const boost::function0<void>& f, const boost::function0<void>& g)
{
    out = boost::bind(&target, a, i, f, g);
}
}
