// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_be6f0a8159c3440d.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_p_s_s_s {
struct A;
void target(A*, std::string, std::string, std::string);
void make(boost::function0<void>& out, A* p, const std::string& a, const std::string& b, const std::string& c)
{
    out = boost::bind(&target, p, a, b, c);
}
}
