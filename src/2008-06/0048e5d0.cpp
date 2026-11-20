// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /I"C:\Users\colin\RoConstruct\2008-06\src\Client\boost_1_34_1\src"
#include <new>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

namespace RBX { namespace Network { class Player { public: void foo(); }; } }

typedef std::allocator<boost::function_base> Fn0Alloc;
typedef boost::_bi::bind_t<void,
    boost::_mfi::mf0<void, RBX::Network::Player>,
    boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Network::Player> > > > Value;

namespace boost {
template<> template<>
function0<void, Fn0Alloc>::function0(Value target, int) throw()
: function_base()
{
    this->assign_to(target);
}
}

static void force_ctor() {
    boost::shared_ptr<RBX::Network::Player> p;
    Value v = boost::bind(&RBX::Network::Player::foo, p);
    boost::function0<void, Fn0Alloc> f(v);
}