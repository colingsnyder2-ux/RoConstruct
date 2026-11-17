// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// INFERRED: sub_004d6fb0 (placeholder name for 004d6fb0 from the identity tier): returns the translation of the camera focus frame; body byte-proved
#include "v8datamodel/Camera.h"
namespace RBX {
G3D::Vector3 Camera::sub_004d6fb0() const
{
	return G3D::Vector3(cameraFocus.translation.x, cameraFocus.translation.y, cameraFocus.translation.z);
}
}
