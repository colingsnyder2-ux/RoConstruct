#include "CBrowserDoc.h"

// CBrowserDoc: CRuntimeClass 0080cfac (size 0x58, CreateObject 0040e4f0). The original constructor is inlined into the
// factory: CDocument ctor, most-derived vptr, view (+0x54) = 0. Defined inline here as a codegen analog.
inline CBrowserDoc::CBrowserDoc() : view(NULL) {}

IMPLEMENT_DYNCREATE(CBrowserDoc, CNullDoc)
