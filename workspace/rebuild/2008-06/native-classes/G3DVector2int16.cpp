// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DVector2int16 (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/Vector2int16.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DVector2int16 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 98701271 | roc native-status --write
/**
 @file Vector2int16.cpp
 
 @author Morgan McGuire, matrix@graphics3d.com
  
 @created 2003-08-09
 @edited  2006-01-29
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector2.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

Vector2int16::Vector2int16(const class Vector2& v) {
    x = (int16)iFloor(v.x + 0.5);
    y = (int16)iFloor(v.y + 0.5);
}


Vector2int16::Vector2int16(class BinaryInput& bi) {
    deserialize(bi);
}


void Vector2int16::serialize(class BinaryOutput& bo) const {
    bo.writeInt16(x);
    bo.writeInt16(y);
}


void Vector2int16::deserialize(class BinaryInput& bi) {
    x = bi.readInt16();
    y = bi.readInt16();
}


}
