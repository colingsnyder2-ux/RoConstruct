// =============================================================================
// BoundFuncDesc.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/reflection/BoundFuncDesc.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
