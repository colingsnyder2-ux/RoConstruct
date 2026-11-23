// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native rows of the ScriptContext translation unit (script/ScriptContext.cpp) inside the application range
// 005ac000..005b0000 (inactive). Verified by tests/record_native_app_unit5ac.py; the unit map is in its receipt.
//
// Headers are read-only here: the native script/ScriptContext.h (RTTI .?AV?$DescribedCreatable@VScriptContext@RBX@@
// VInstance@2@$1?sScriptContext@2@3PADA@RBX@@, vtable 0083465c: the class name is a char array, 3PADA, as the header
// declares it) and reflection/reflection.h / v8tree/Instance.h, which declare these template members without bodies.
#include <boost/thread/once.hpp>
#include "script/ScriptContext.h"

namespace RBX
{
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() {}

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable() {}

	template<class C, class D, const char* N>
	const RBX::Name& FactoryProduct<C, D, N>::className() { return RBX::Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }
}

namespace R = RBX::Reflection;

// DescribedCreatable<ScriptContext>() 005ad930 (base constructor of ScriptContext() 005ae490; it calls
// FactoryProduct<ScriptContext>() 005a8970 and Described<ScriptContext>::classDescriptor() 005ad200)
template RBX::DescribedCreatable<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext>::DescribedCreatable();

// Described<ScriptContext>::classDescriptor() 005ad200 ("ScriptContext", classDescriptor<Instance> 0040ad80)
template R::ClassDescriptor& R::Described<RBX::ScriptContext, RBX::sScriptContext,
	RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext> >::classDescriptor();

// FactoryProduct<ScriptContext>::getClassName() const 005ac030 (call_once 00557330 on callDoDeclare<sScriptContext>
// 0042d090, then doDeclare 0042ced0)
template const RBX::Name& RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext>::getClassName() const;

// BoundFuncDesc<ScriptContext, void(double), 1>(function, name, arg1Name, security) 005ad9f0 (the header's
// default-argument-free constructor: Value() at +0x40, ret 0x14; its only caller is the static-initializer code at
// 007f4f9a) and its execute 005ada90 (vtable 008346a0,
// RTTI .?AV?$BoundFuncDesc@VScriptContext@RBX@@$$A6AXN@Z$00@Reflection@RBX@@: slot 1).
template R::BoundFuncDesc<RBX::ScriptContext, void(double), 1>::BoundFuncDesc(
	R::BoundFuncDesc<RBX::ScriptContext, void(double), 1>::FunctionSig, const char*, const char*,
	R::FunctionDescriptor::Security);

// scoped_ptr<Lua::YieldingThreads>::~scoped_ptr 005ae210 (ScriptContext::yieldEvent +0x1a8): ~vector<WaitingThread>
// of the waitingThreads member at +4, then operator delete.
template boost::scoped_ptr<RBX::Lua::YieldingThreads>::~scoped_ptr();

#ifdef SCRIPTCONTEXT_HEADER_DECLARES_ONHOOK
// 005adbf0 (registry placeholder func_005adbf0, 112 B, ret 8): the member that the static lua_Hook scriptHook 005ae230
// (count hook set by openState 005aefa0) calls on getContext(L) while timedOutScripts (00976b78) > 0. exeState (+0x1c8)
// set and Security::Context::current() 00493760 identity GameScript (2) -> std::runtime_error("Game script timout")
// 008346a8 (runtime_error(const string&) 00409d50, _CxxThrowException with 008d1bc8). INFERRED: the name onHook.
// Blocked by headers this unit may not edit: script/ScriptContext.h must declare 'void onHook(lua_State* L,
// lua_Debug* ar);' and core security/SecurityContext.h keeps Context::identity private. Measured byte-identical
// (credited by --infer-names, with __ehhandler 007cfeb9) against scratch copies of both headers; the volatile read
// gives the target's mov/test (exeState is shared with the watchdog through InterlockedExchange).
#include <stdexcept>
#include "security/SecurityContext.h"
namespace RBX
{
	void ScriptContext::onHook(lua_State* L, lua_Debug* ar)
	{
		if (*static_cast<volatile int*>(&exeState))
		{
			if (Security::Context::current().identity == Security::GameScript)
				throw std::runtime_error("Game script timout");
		}
	}
}
#endif
