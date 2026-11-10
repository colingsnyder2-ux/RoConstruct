#include <stddef.h>
#include "CBrowserDoc.h"
// CNullDoc: CRuntimeClass 00812410 objectSize 0x54 == sizeof(CDocument); CreateObject 00433310 operator new(0x54)
// then only the vptr store; no method reads or writes a field of its own. No added storage is inferred.
typedef char DocumentSize[sizeof(CDocument) == 0x54 ? 1 : -1];
typedef char NullDocSize[sizeof(CNullDoc) == 0x54 ? 1 : -1];
typedef char NullDocAddsNothing[sizeof(CNullDoc) == sizeof(CDocument) ? 1 : -1];
// CBrowserDoc's first member follows CNullDoc directly (CRuntimeClass 0080cfac size 0x58; view written at +0x54).
typedef char BrowserDocView[offsetof(CBrowserDoc, view) == 0x54 ? 1 : -1];
