// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/luafunction-threadref
// Inactive native 2008-06 recovery: CComAggObject<CWorkspace> destructor 00403410 and
// CComAggObject<CLuaFunction> constructor 00418800. The real ATL template supplies both bodies;
// RTTI, vftables and the original call/link evidence identify these two specializations.
#include <afxwin.h>
#include "CWorkspace.h"
#include "LuaFunctionCom2008.h"

template class ATL::CComAggObject<CWorkspace>;
template class ATL::CComAggObject<CLuaFunction>;
