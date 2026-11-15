// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/luafunction-threadref
// 2008-06 native LuaFunctionCreator2008 (inactive): ATL CComCreator<CComObjectNoLock<CLuaFunction>>::CreateInstance (004186d0).
#include <afxwin.h>
#include "LuaFunctionCom2008.h"

template HRESULT WINAPI ATL::CComCreator<ATL::CComObject<CLuaFunction> >::CreateInstance(void*, REFIID, LPVOID*);
template class ATL::CComObject<CLuaFunction>;

CLuaFunction::CLuaFunction() : identity() {}
