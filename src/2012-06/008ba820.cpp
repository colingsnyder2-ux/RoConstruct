// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_8030bca88e170aa9.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_f_i_sp {
struct A;
void target(boost::function0<void>, int, boost::shared_ptr<A>);
void make(boost::function0<void>& out, const boost::function0<void>& f, int i, const boost::shared_ptr<A>& p)
{
    out = boost::bind(&target, f, i, p);
}
}
