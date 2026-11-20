// 2008-06 override: out-of-line BoundFuncDesc constructor bodies declared (but not defined)
// in reflection/reflection.h. This header never defines the class template or stand-in types.
//
// // INFERRED: N=1 ctor #2 at 004a06b0 (RBX::Network::Client) and 004a4760 (DHTMLWindow).
//   BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name,
//                 Arg1 default1, Security security)
//     : FuncDesc(name, security), function(function), default1(default1)
//     { declareSignature(arg1Name); }
// Reconstructed from byte-identical disassembly (193 bytes, ret 0x18) at both addresses.
// The 8-byte member function pointer accounts for 24 stack bytes (8+4+4+4+4 = ret 0x18).
// Only one signature.addArgument call is emitted, so this is N=1 ctor #2 (one argument).
//
// // INFERRED: N=2 ctor #1 (declared in reflection.h lines 608-613, not needed for these addrs):
//   BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name,
//                 const char* arg2Name, Security security)
//     : FuncDesc(name, security), function(function), default1(), default2()
//     { declareSignature(arg1Name, arg2Name); }

#pragma once
#include "reflection/reflection.h"

namespace RBX
{
	namespace Reflection
	{

template<typename Class, typename Function>
BoundFuncDesc<Class, Function, 1>::BoundFuncDesc(
    typename BoundFuncDesc<Class, Function, 1>::FunctionSig function,
    const char* name,
    const char* arg1Name,
    typename BoundFuncDesc<Class, Function, 1>::Arg1 default1,
    Security security)
    : FuncDesc(name, security),
      function(function),
      default1(default1)
{
    declareSignature(arg1Name);
}

	}
}
