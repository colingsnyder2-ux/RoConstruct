// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_sphereprojectorder7ce0318a159d635b.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/Vector3.h"
#include "G3D/Vector2.h"
#include <math.h>
void normalize(G3D::Vector3& v){
 float scale;
 if(fabs(v.y)>=fabs(v.x)){
   scale=v.y==0.0f?0.0f:float(fabs(v.y))/v.xy().length();
 }else{
   scale=v.x==0.0f?0.0f:float(fabs(v.x))/v.xy().length();
 }
 v.x*=scale;v.y*=scale;
}
