// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
struct Vector3 { float x, y, z; Vector3() {} };
struct X { Vector3 get(int) const; };
float angle(const X& x) { Vector3 v = x.get(0); return atan2f(v.y, v.x); }
