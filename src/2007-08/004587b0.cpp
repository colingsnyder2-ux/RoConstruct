// from server: 92% by EspClaude
// from server: 56% by tester
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_270430842fac6082.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: boost 1.34.1 shared_count(P, D) constructor instantiated with the
// Creatable<Instance>::Deleter seen in the target's catch funclet (0x458829 calls
// ??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z at 004074c0).
// new(0x14) = sp_counted_impl_pd<Instance*, Deleter> (base 12 + ptr 4 + empty deleter).
// The client build used the exception-handling form of shared_count (catch funclet at
// 0x458829 rethrows with _CxxThrowException(0,0)); the local harness leaves _CPPUNWIND
// undefined, so restore the /EHsc configuration explicitly.
#include <boost/config.hpp>
#undef BOOST_NO_EXCEPTIONS
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance;
template<class T> class Creatable
{
public:
    class Deleter
    {
    public:
        void operator()(T* p);
    };
};
}

template boost::detail::shared_count::shared_count(RBX::Instance*, RBX::Creatable<RBX::Instance>::Deleter);
