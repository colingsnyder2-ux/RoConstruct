// 2008-06 native rows of the reflection-signal instances of the Network::Player / Players units inside
// 0048c000..00498000 (inactive). Verified by tests/record_native_app_unit48c_2008.py. All headers are read-only here.
//
// The Player unit declares two signal signatures (original RTTI of SignalDesc<Player, Sig> vtables 00821db0 / 00821dd8):
// void(std::string, shared_ptr<Instance>) and void(float). Rows built here:
//   * boost::any::holder<function<Sig> > (vtables 00821728 / 00821738): constructor 0048dc30 / 0048dfb0, type()
//     0048dc90 / 0048e010, clone() 0048dca0 / 0048e020; boost::any::any(const function<Sig>&) 0048ddf0 / 0048e110;
//   * boost::signal2 / signal1 ::connect(slot) 0048de50 / 0048e170;
//   * TSignalDesc<void(std::string, shared_ptr<Instance>)>: TSignalInstance constructor 0048e2d0 and newSignalInstance
//     0048e4f0 (slot 2 of SignalDesc<Player / Client / Server, Sig>; the void(float) pair 0048e340 / 0048e560 is
//     counted by humanoid2008);
//   * the void(float) call path: slot_call_iterator caller 004934a0, signal1<void, float>::operator() 004937f0 and
//     SignalDescImpl<1, void(float)>::fire 004940e0;
//   * the void(std::string, shared_ptr<Instance>) helpers in the Players unit: signals::detail::args2 destructor
//     00496740 / constructor 004967c0, function2::operator() 00496ac0 and the caller 00497430;
//   * boost::any::holder<shared_ptr<Instance> > (vtable 00821718): ??_G 0048dc10, type() 0048db50, clone() 0048db60,
//     destructor 0048dba0, and boost::any::operator=<shared_ptr<Instance> > 0048dd00.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// AppUnit48C_2008Signals | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 9688d543 | roc native-status --write
#include "reflection/signal.h"
#include "v8tree/Instance.h"
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <string>

template class RBX::Reflection::SignalDescImpl<1, void(float)>;
template class RBX::Reflection::SignalDescImpl<2, void(std::string, boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TSignalDesc<void(float)>;
template class RBX::Reflection::TSignalDesc<void(std::string, boost::shared_ptr<RBX::Instance>)>;

template class boost::any::holder<boost::shared_ptr<RBX::Instance> >;
template boost::any& boost::any::operator=<boost::shared_ptr<RBX::Instance> >(const boost::shared_ptr<RBX::Instance>&);

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::function1<void,float,std::allocator<void> >;
template class boost::function2<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>,std::allocator<void> >;
template class boost::function<void __cdecl(float),std::allocator<void> >;
template class boost::function<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>),std::allocator<void> >;
template class boost::signal1<void,float,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(float),std::allocator<void> > >;
template class boost::signal2<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>),std::allocator<void> > >;
