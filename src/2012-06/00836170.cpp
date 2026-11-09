// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_a5f3599a4696fcd5.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_ip_s_p1 {
struct A;
void intrusive_ptr_add_ref(A*);
void intrusive_ptr_release(A*);
void target(boost::intrusive_ptr<A>, std::string, int);
void make(boost::function1<void, int>& out, const boost::intrusive_ptr<A>& a, const std::string& s)
{
    out = boost::bind(&target, a, s, _1);
}
}
