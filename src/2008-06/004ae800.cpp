// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_f9d6b222b335c1af.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

struct B1 { int a; };
struct B2 { int b; };
class D;
class C : public B1, public B2 {
public:
    void handler(boost::shared_ptr<D> d, int x);
};

typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, C, boost::shared_ptr<D>, int>,
    boost::_bi::list3<boost::_bi::value<C*>, boost::_bi::value<boost::shared_ptr<D> >, boost::arg<1> > > Bound;

template struct boost::detail::function::void_function_obj_invoker1<Bound, void, int>;
