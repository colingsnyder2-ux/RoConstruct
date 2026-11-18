// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// 005e1690: explicit instantiation of the class the body at 005e1690 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <G3D/Vector3.h>
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/Lighting2008.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Lighting,class G3D::Vector3 __cdecl(void),0>;
