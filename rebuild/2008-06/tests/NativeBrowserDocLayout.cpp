#include <stddef.h>
#include "CBrowserDoc.h"
// CBrowserDoc: CRuntimeClass 0080cfac objectSize 0x58 = CNullDoc (0x54) + the view pointer at +0x54, written by
// CBrowserView::OnInitialUpdate 0040ed50 and zeroed by CreateObject 0040e4f0. No other storage is inferred.
typedef char NullDocSize[sizeof(CNullDoc) == 0x54 ? 1 : -1];
typedef char BrowserDocSize[sizeof(CBrowserDoc) == 0x58 ? 1 : -1];
typedef char BrowserDocView[offsetof(CBrowserDoc, view) == 0x54 ? 1 : -1];
