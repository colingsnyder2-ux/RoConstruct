// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native boost::function0 / boost::function constructors from bind_t (inactive), by value plus the SFINAE int:
//   00618ec0 Flag (boost::bind(&Flag::member, shared_ptr<Flag>), no EH frame in the original, hence throw());
//   004b44c0 Replicator property-changed slot (function<void(const PropertyDescriptor*)>);
//   005c4b20 Visit::setPing and 00427720 (work_result workers): the original bodies carry an EH frame for the by-value
//   std::string, which a member specialization with throw() cannot reproduce, so these two stay unmatched here.
// Member specializations as in ContentProviderWorkerBinding.cpp. They are declared before any is defined: a definition
// instantiates function0<R>, after which a further declaration is refused (C2770), and worker_thread (util/boost.hpp)
// already instantiates function0<work_result>.
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "util/Name.h"
#include "v8datamodel/Visit.h"
#include "Network/Replicator2008.h"
#include "reflection/reflection.h"

typedef std::allocator<boost::function_base> Fn0Alloc;
typedef RBX::worker_thread::work_result WorkResult;
typedef std::string Str;

// Visit::setPing: boost::bind(&Visit::ping, url, interval)
typedef boost::_bi::bind_t<WorkResult, WorkResult (*)(Str, int),
	boost::_bi::list2<boost::_bi::value<Str>, boost::_bi::value<int> > > PingCall;
// 00427720: boost::bind(&fn, string)
typedef boost::_bi::bind_t<WorkResult, WorkResult (*)(Str), boost::_bi::list1<boost::_bi::value<Str> > > StrCall;
// Replicator: boost::bind(&Replicator::member, this, instance, _1)
typedef boost::_bi::bind_t<void,
	boost::_mfi::mf2<void, RBX::Network::Replicator, boost::shared_ptr<RBX::Instance>, const RBX::Reflection::PropertyDescriptor*>,
	boost::_bi::list3<boost::_bi::value<RBX::Network::Replicator*>, boost::_bi::value<boost::shared_ptr<RBX::Instance> >,
		boost::arg<1> > > ReplCall;

namespace boost {
#define FN0_DECL(R, B) template<> template<> function0<R, Fn0Alloc>::function0(B, int) throw();
#define FN0_DEF(R, B) template<> template<> function0<R, Fn0Alloc>::function0(B target, int) throw() : function_base() { this->assign_to(target); }
FN0_DECL(WorkResult, PingCall)
FN0_DECL(WorkResult, StrCall)
template<> template<>
function<void(const RBX::Reflection::PropertyDescriptor*), std::allocator<void> >::function(ReplCall, int);
FN0_DEF(WorkResult, PingCall)
FN0_DEF(WorkResult, StrCall)
template<> template<>
function<void(const RBX::Reflection::PropertyDescriptor*), std::allocator<void> >::function(ReplCall target, int)
	: function1<void, const RBX::Reflection::PropertyDescriptor*, std::allocator<void> >(target) {}
}

// Flag.h last: its includes instantiate function0<void>, which would refuse the earlier declarations.
#include "v8datamodel/Flag.h"
typedef boost::_bi::bind_t<void, boost::_mfi::mf0<void, RBX::Flag>,
	boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Flag> > > > FlagCall0;
namespace boost {
FN0_DECL(void, FlagCall0)
FN0_DEF(void, FlagCall0)
}
