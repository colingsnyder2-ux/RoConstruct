// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_positionmaximumcfd71dd88a15e80a.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/CoordinateFrame.h>
#include <algorithm>
using G3D::Vector3;
extern const float distanceLimit,distanceScale;
extern char propertyDescriptor;
struct Part{const G3D::CoordinateFrame* getTransform();};
struct S{char pad[0x1dc];Vector3 position;Part* getPart();void notify(const void*);void f(const Vector3*);};
inline const float& minimum(const float& a,const float& b){return b<a ? a:b;}
inline float distance(const Vector3& v){return fabs(v.x)+fabs(v.y)+fabs(v.z);}
void S::f(const Vector3* value){
 float threshold=1.0f;
 if(getPart()){
  float d=distance(getPart()->getTransform()->translation-*value);
  threshold=distanceLimit;
  threshold=minimum(d,threshold)*distanceScale;
 }
 if(distance(*value-position)>threshold){position=*value;notify(&propertyDescriptor);}
}
