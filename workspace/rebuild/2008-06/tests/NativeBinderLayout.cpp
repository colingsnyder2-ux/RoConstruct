#include "../native-headers/VerbBinder.h"

class CRobloxDoc;
class CRobloxView;
template class VerbBinder<CRobloxDoc, CDocument>;
template class VerbBinder<CRobloxView, CView>;

typedef char DocumentBaseSize[sizeof(CDocument) == 0x54 ? 1 : -1];
typedef char ViewBaseSize[sizeof(CView) == 0x58 ? 1 : -1];
typedef char DocumentBinderSize[sizeof(VerbBinder<CRobloxDoc, CDocument>) == 0x74 ? 1 : -1];
typedef char ViewBinderSize[sizeof(VerbBinder<CRobloxView, CView>) == 0x78 ? 1 : -1];
