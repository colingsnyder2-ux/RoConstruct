// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_f30abf3e524aa8c4.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace roc_bind_s_i_s_m_s_b_f {
typedef std::map<std::string, std::string> M;
void target(std::string, int, std::string, M, std::string, bool, boost::function0<void>);
void make(boost::function0<void>& out, const std::string& a, int i, const std::string& b, const M& m, const std::string& c, bool z, const boost::function0<void>& f)
{
    out = boost::bind(&target, a, i, b, m, c, z, f);
}
}
