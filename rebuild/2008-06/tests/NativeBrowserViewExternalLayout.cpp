#include <afxwin.h>
#include <stddef.h>
#include "CBrowserViewExternal.h"
// CComObjectNoLock<CBrowserViewExternal>: operator new(0x20) in creator 0040fbf0, RTTI vtable 0080d778.
typedef char ExternalObjectSize[sizeof(ATL::CComObjectNoLock<CBrowserViewExternal>) == 0x20 ? 1 : -1];
typedef char ExternalClassSize[sizeof(CBrowserViewExternal) == 0x20 ? 1 : -1];
typedef char ExternalIsIDE[offsetof(CBrowserViewExternal, isIDE) == 0x1c ? 1 : -1];
