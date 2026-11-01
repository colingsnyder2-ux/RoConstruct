// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_native_connection_enum_f6f7621be8b6b8a3.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#define _ATL_APARTMENT_THREADED
#define _AFXDLL
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>

// Template instantiation context only. The target connection map contains one
// locator at +4 relative to IConnectionPointContainer. Both bases are native
// ATL interfaces; this does not reconstruct CBrowserViewExternal's full layout.
extern const IID targetConnectionInterface;
class ConnectionMapContext :
    public ATL::IConnectionPointContainerImpl<ConnectionMapContext>,
    public ATL::_ICPLocator<&targetConnectionInterface>
{
public:
    BEGIN_CONNECTION_POINT_MAP(ConnectionMapContext)
        CONNECTION_POINT_ENTRY(targetConnectionInterface)
    END_CONNECTION_POINT_MAP()
};
template class ATL::IConnectionPointContainerImpl<ConnectionMapContext>;
