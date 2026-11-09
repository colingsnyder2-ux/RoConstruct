// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_16409cc9428d16eb.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_s_i_s_l_sp_b_f {
struct A;
void target(std::string, int, std::string, std::list<std::string>, boost::shared_ptr<A>, bool, boost::function0<void>);
void make(boost::function0<void>& out, const std::string& a, int i, const std::string& b, const std::list<std::string>& l, const boost::shared_ptr<A>& p, bool f, const boost::function0<void>& g)
{
    out = boost::bind(&target, a, i, b, l, p, f, g);
}
}
