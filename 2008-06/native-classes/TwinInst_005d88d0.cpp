// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005d88d0: explicit instantiation of the class the body at 005d88d0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "v8datamodel/Selection.h"
#include "v8datamodel/PartInstance.h"
template class RBX::FilteredSelection<class RBX::PartInstance>;
