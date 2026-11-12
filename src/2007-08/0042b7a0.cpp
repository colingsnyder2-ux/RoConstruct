// from server: 73% by EspClaude
// from server: 58% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_21df39ecb3f3d2ef.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: boost 1.34.1 shared_count(Y*) constructor (pi_ = new sp_counted_impl_p<Y>(p), 0x10 bytes).
// The roc lib preprocessor runs without /EHsc, so BOOST_NO_EXCEPTIONS is undone to keep the try/catch path.
// Target needs the wrapper settings  // roc-cl: 50727  and  // roc-flags: /O2 /GS /EHsc /MD
#include <boost/config.hpp>
#if defined(BOOST_NO_EXCEPTIONS)
#undef BOOST_NO_EXCEPTIONS
#endif
#include <boost/shared_ptr.hpp>
class LuaFunctionTarget;
namespace boost { template<> inline void checked_delete<LuaFunctionTarget>(LuaFunctionTarget*) {} }
template boost::detail::shared_count::shared_count(LuaFunctionTarget*);
