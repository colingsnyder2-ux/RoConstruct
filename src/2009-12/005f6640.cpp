// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: g3d-6.09 G3Dcpp/Color4uint8.cpp

// Candidate translation unit (score above; library headers required).
/**
 @file Color4uint8.cpp
 
 @author Morgan McGuire, matrix@graphics3d.com
  
 @created 2003-04-07
 @edited  2006-01-07
 */
#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Color4uint8.h"
#include "G3D/Color4.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

Color4uint8::Color4uint8(const class Color4& c) {
    r = iMin(255, iRound(c.r * 256));
    g = iMin(255, iRound(c.g * 256));
    b = iMin(255, iRound(c.b * 256));
    a = iMin(255, iRound(c.a * 256));
}


Color4uint8::Color4uint8(class BinaryInput& bi) {
    deserialize(bi);
}


void Color4uint8::serialize(class BinaryOutput& bo) const {
    bo.writeUInt8(r);
    bo.writeUInt8(g);
    bo.writeUInt8(b);
    bo.writeUInt8(a);
}


void Color4uint8::deserialize(class BinaryInput& bi) {
    r = bi.readUInt8();
    g = bi.readUInt8();
    b = bi.readUInt8();
    a = bi.readUInt8();
}


}
