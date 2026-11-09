// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_a33ed8c9f6fc8f3b.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_s_ip {
struct A;
void intrusive_ptr_add_ref(A*);
void intrusive_ptr_release(A*);
void target(std::string, boost::intrusive_ptr<A>);
void make(boost::function0<void>& out, const std::string& s, const boost::intrusive_ptr<A>& a)
{
    out = boost::bind(&target, s, a);
}
}
