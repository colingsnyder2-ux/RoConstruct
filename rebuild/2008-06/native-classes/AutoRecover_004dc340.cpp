// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "ViewG3D2008/ViewG3D2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
namespace ViewNew {

// INFERRED: 0x004dc340 is the compiler-generated scalar/vector deleting destructor.
// The real destructor body is the out-of-line function at 0x004dc270 (named
// suppressSkybox in ViewG3D2008.cpp). Defining the virtual destructor here makes
// the compiler emit the deleting-destructor thunk: call dtor, then
// operator delete(this) if (flags & 1).
ViewG3D::~ViewG3D()
{
}

} // namespace ViewNew
} // namespace RBX
