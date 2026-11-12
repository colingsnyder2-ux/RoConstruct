// 2008-06 native rows of the reflection-signal instances of Network/Replicator.cpp inside 004b0000..004bc000
// (inactive). Verified by tests/record_native_app_unit4b0_2008.py. All headers are read-only here.
//
// The Replicator unit instantiates two signal signatures (original RTTI): void() (TSignalInstance vtable 00824b8c,
// boost::any::holder<function<void()> > vtable 00824b7c) and void(std::string, bool) (TSignalInstance 00824ba4,
// holder 00824b94; SignalDesc<Replicator, void(std::string, bool)> vtable 00824c98). Rows built here:
//   * boost::any::holder<function<Sig> >: constructor 004b1940 / 004b1dc0, type() 004b19a0 / 004b1e20,
//     clone() 004b19b0 / 004b1e30; boost::any::any(const function<Sig>&) 004b1aa0 / 004b1f20;
//   * boost::signal0 / signal2 ::connect(slot) 004b1b00 / 004b1f80;
//   * TSignalDesc<void(std::string, bool)>: TSignalInstance constructor 004b20e0, newSignalInstance 004b2150
//     (the void() pair 004b1c60 / 004b1d50 is counted by humanoid2008);
//   * SignalDescImpl<0, void()>::fire 004b5f40, SignalDescImpl<2, void(std::string, bool)>::fire 004b6040 and the
//     signal2 slot_call_iterator caller 004b4fb0.
#include "reflection/signal.h"
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <string>

template class boost::any::holder<boost::function<void()> >;
template class boost::any::holder<boost::function<void(std::string, bool)> >;
template class RBX::Reflection::TSignalDesc<void()>;
template class RBX::Reflection::TSignalDesc<void(std::string, bool)>;
template class RBX::Reflection::SignalDescImpl<0, void()>;
template class RBX::Reflection::SignalDescImpl<2, void(std::string, bool)>;
