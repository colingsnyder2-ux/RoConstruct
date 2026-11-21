// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00616da0: explicit instantiation of the class the body at 00616da0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "v8datamodel/Selection.h"
#include "v8tree/Instance.h"
template class RBX::FilteredSelection<class RBX::Instance>;
