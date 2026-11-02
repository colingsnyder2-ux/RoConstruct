// CRobloxView native recovery trial: constructor/destructor/methods plus OnInitialUpdate in one unit.
#include "../native-classes/CRobloxViewInit.cpp"
#include "../native-classes/CRobloxView.cpp"
#include "../native-classes/CRobloxViewMethods.cpp"
#include "../native-classes/ToggleToolboxVerb.cpp"

// 0045ac40 is G3D::Vector3::operator-, emitted out of line in the original.
#include <G3D/Vector3.h>
typedef G3D::Vector3 (G3D::Vector3::*VectorSubtract)(const G3D::Vector3&) const;
VectorSubtract keepVectorSubtract = &G3D::Vector3::operator-;
