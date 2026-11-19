// // INFERRED: N=1 ctor #2 at 004a06b0 (RBX::Network::Client) and 004a4760 (DHTMLWindow).
// // INFERRED: N=2 ctor #1 (declared in reflection.h lines 608-613, not needed for these addrs):

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
