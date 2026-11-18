// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0057f310: explicit instantiation of the class the body at 0057f310 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "v8datamodel/Selection.h"
#include "v8datamodel/ModelInstance.h"
template class RBX::FilteredSelection<class RBX::ModelInstance>;
