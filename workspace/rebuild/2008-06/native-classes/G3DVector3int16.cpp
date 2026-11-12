// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DVector3int16 (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/Vector3int16.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DVector3int16 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 4b1b9c3f | roc native-status --write
#line 1 ".\\G3Dcpp\\Vector3int16.cpp"
/**
 @file Vector3int16.cpp
 
 @author Morgan McGuire, matrix@graphics3d.com
  
 @created 2003-04-07
 @edited  2006-01-17
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3int16.h"
#include "G3D/Vector3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

Vector3int16::Vector3int16(const class Vector3& v) {
    x = (int16)iFloor(v.x + 0.5);
    y = (int16)iFloor(v.y + 0.5);
    z = (int16)iFloor(v.z + 0.5);
}


Vector3int16::Vector3int16(class BinaryInput& bi) {
    deserialize(bi);
}


void Vector3int16::serialize(class BinaryOutput& bo) const {
    bo.writeInt16(x);
    bo.writeInt16(y);
    bo.writeInt16(z);
}


void Vector3int16::deserialize(class BinaryInput& bi) {
    x = bi.readInt16();
    y = bi.readInt16();
    z = bi.readInt16();
}


}
