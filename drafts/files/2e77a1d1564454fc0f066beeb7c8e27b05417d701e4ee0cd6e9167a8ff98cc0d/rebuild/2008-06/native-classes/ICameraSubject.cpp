// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include "../App/include/util/ICameraSubject.h"
namespace RBX {
float ICameraSubject::getLerp() const { return 0.9f; }
bool ICameraSubject::zoom(float, G3D::CoordinateFrame&, G3D::CoordinateFrame&) { return false; }
void ICameraSubject::stepGoalAndFocus(G3D::CoordinateFrame&, G3D::CoordinateFrame& focus, bool) { focus = getLocation(); }
}
