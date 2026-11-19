// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-classes
// 005a1520: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "SurfaceTool.cpp"
// INFERRED: 005a1520 is a 5-byte jump to RBX::SurfaceTool::~SurfaceTool: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_005a1520 : RBX::SurfaceTool { ~Thunk_005a1520(); };
Thunk_005a1520::~Thunk_005a1520() {}
