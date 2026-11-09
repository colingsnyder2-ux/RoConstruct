// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_mathinvalidnative2549ed8ce07cf4c7.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off, push)
#include <util/Math.h>
#include <limits>
namespace RBX {
static bool isNanInf(float f) { return f==std::numeric_limits<float>::infinity() || f==-std::numeric_limits<float>::infinity() || f==std::numeric_limits<float>::quiet_NaN() || f==std::numeric_limits<float>::signaling_NaN(); }
bool Math::isDenormal(float f) { unsigned int bits=*reinterpret_cast<unsigned int*>(&f); return (bits & 0x7f800000)==0 && (bits & 0x7fffff)!=0; }
bool Math::isNanInfDenorm(float f) {return isNanInf(f)||isDenormal(f);}
bool Math::isNanInfDenormVector3(const G3D::Vector3& v) {return isNanInfDenorm(v.x)||isNanInfDenorm(v.y)||isNanInfDenorm(v.z);}
}
