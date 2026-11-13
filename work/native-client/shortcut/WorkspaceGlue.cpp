// Shortcut glue (owner-authorized): exe 00450370 is the ATL CComObject<CWorkspace>::CreateInstance instantiation CRobloxDoc::initializeCommands
// calls through the native name createNativeWorkspace (openrbx RobloxDoc.cpp:392, App.cpp FUN_00407ca0). The stub returned S_OK without
// setting the out pointer, so the first File>New dereferenced null. Plain ATL pattern, nothing inferred beyond it.
#include "CWorkspace.h"

HRESULT __stdcall createNativeWorkspace(CWorkspace** workspace) throw()
{
    return ATL::CComObject<CWorkspace>::CreateInstance(reinterpret_cast<ATL::CComObject<CWorkspace>**>(workspace));
}
