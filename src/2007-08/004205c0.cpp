// from server: 68% by EspClaude
// from server: 52% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_89d8dd0c0817e0b0.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: boost 1.34.1 shared_ptr<RBX::Script>(shared_ptr<RBX::Instance> const&, dynamic_cast_tag)
// (target RTTI descriptors: .?AVInstance@RBX@@ source, .?AVScript@RBX@@ destination).
// Target needs the wrapper settings  // roc-cl: 50727  and  // roc-flags: /O2 /GS /EHsc /MD
#include <boost/config.hpp>
#if defined(BOOST_NO_EXCEPTIONS) && defined(_CPPUNWIND)
#undef BOOST_NO_EXCEPTIONS
#endif
#if _MSC_VER >= 1500
#define BOOST_NO_SFINAE
#endif
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Script : public Instance { public: virtual ~Script(); };
}
template boost::shared_ptr<RBX::Script>::shared_ptr(boost::shared_ptr<RBX::Instance> const&, boost::detail::dynamic_cast_tag);
