// >>> native-status (generated) -- do not edit >>>
// CScriptDoc | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src fc22c44d | roc native-status --write
#include "CScriptDoc.h"

// CNullDoc::CNullDoc is inline in the original: CNullDoc::CreateObject 00433310 and CScriptDoc::CreateObject
// 004647b0 call CDocument::CDocument directly and store only the most-derived vtable. CBrowserDoc.h declares it
// without a body (shared header, not edited), so the empty inline body is supplied here.
inline CNullDoc::CNullDoc()
{
}

// GetRuntimeClass 004638a0, CreateObject 004647b0 (operator new 0x5c). The implicit destructor 00464670 and
// deleting destructor 004646f0 are emitted with the vtable.
IMPLEMENT_DYNCREATE(CScriptDoc, CNullDoc)
