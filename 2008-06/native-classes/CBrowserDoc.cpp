#include "CBrowserDoc.h"

CNullDoc::CNullDoc() {}
CBrowserDoc::CBrowserDoc() : view(NULL) {}

IMPLEMENT_DYNCREATE(CNullDoc, CDocument)
IMPLEMENT_DYNCREATE(CBrowserDoc, CNullDoc)
