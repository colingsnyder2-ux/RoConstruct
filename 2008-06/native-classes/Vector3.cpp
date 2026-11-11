// native-flags: /O2 /GS- /EHsc /MD /IC:\Users\colin\RoConstruct\tools\libs\g3d-6.09\source\G3Dcpp
#include "axis-vector-negation/G3D/Vector3.h"
#include "G3D/Vector3.h"
#include "G3D/g3dmath.h"
#include "G3D/stringutils.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/Vector3int16.h"
#include "G3D/Matrix3.h"
#include "G3D/Vector2.h"

namespace G3D {
Vector2 Vector3::xy() const  { return Vector2       (x, y); }
}
