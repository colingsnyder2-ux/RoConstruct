// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/luafunction-threadref
// 2008-06 native ATL creators of the aggregatable CLuaFunction COM object (inactive; flags and include profile from
// LuaFunctionCreator2008.cpp, which holds CComCreator<CComObject<CLuaFunction>>::CreateInstance 004186d0).
//   * 004191d0 (registry placeholder func_004191d0, 193 B, ret 0xc): ATL CComCreator<CComAggObject<CLuaFunction>>::
//     CreateInstance: E_POINTER (0x80004003) for a null ppv, new 0x44 inside try/catch(...) (funclet 0041926b), the
//     CComAggObject<CLuaFunction> constructor 00418800 (vtable 0080ec9c, RTTI .?AV?$CComAggObject@VCLuaFunction@@@ATL@@),
//     then vtable slot 0 (_AtlInitialConstruct / FinalConstruct path inlined as in atlcom.h) and Release (slot 3, push 1:
//     the deleting destructor) on failure.
//   * 00419ac0 (registry placeholder func_00419ac0, 26 B): CComCreator2<CComCreator<CComObject<CLuaFunction>>,
//     CComCreator<CComAggObject<CLuaFunction>>>::CreateInstance, tail-jumping to 004186d0 for a null outer unknown
//     and to 004191d0 otherwise.
#include <afxwin.h>
#include "LuaFunctionCom2008.h"

template HRESULT WINAPI ATL::CComCreator<ATL::CComAggObject<CLuaFunction> >::CreateInstance(void*, REFIID, LPVOID*);
template HRESULT WINAPI ATL::CComCreator2<ATL::CComCreator<ATL::CComObject<CLuaFunction> >, ATL::CComCreator<ATL::CComAggObject<CLuaFunction> > >::CreateInstance(void*, REFIID, LPVOID*);
