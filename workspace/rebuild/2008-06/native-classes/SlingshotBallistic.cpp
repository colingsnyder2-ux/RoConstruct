// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// SlingshotBallistic | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 91eb77aa | roc native-status --write
#include <math.h>
#pragma float_control(precise, off)
#pragma intrinsic(fabs, sqrt, atan)
namespace RBX {
float __cdecl ballisticAngle(float speed, float distance, float height, float gravity) {
 double g=fabs(gravity);
 double disc=speed*speed*speed*speed-(distance*distance*g+2.0*(speed*speed)*height)*g;
 if (disc<=0.0) return 0.7853981852531433f;
 double root=sqrt(disc);
 double v2=speed*speed;
 double upper=atan((root+v2)/(distance*g));
 speed=(float)upper;
 double lower=atan((v2-root)/(g*distance));
 gravity=(float)lower;
 const float* result=lower<upper?&gravity:&speed;
 return *result;
}
}
