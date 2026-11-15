#include "CBrowserDoc.h"

inline CNullDoc::CNullDoc()
{
}

CBrowserDoc::CBrowserDoc() : view(NULL) {}

IMPLEMENT_DYNCREATE(CNullDoc, CDocument)
IMPLEMENT_DYNCREATE(CBrowserDoc, CNullDoc)
