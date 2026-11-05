// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_2923e8977d0ffdc5.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_s_i_s_m_f {
typedef std::map<std::string, std::string> M;
void target(std::string, int, std::string, M, boost::function0<void>);
void make(boost::function0<void>& out, const std::string& a, int i, const std::string& b, const M& m, const boost::function0<void>& f)
{
    out = boost::bind(&target, a, i, b, m, f);
}
}
