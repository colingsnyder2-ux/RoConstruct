// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_extentobject2ba6da6b13b49e6a.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
typedef G3D::Vector3 Vector3;
typedef G3D::CoordinateFrame Frame;
struct Extents { Vector3 low, high; Extents(const Vector3& a,const Vector3& b):low(a),high(b){} };
struct Body {
    char pad[0x94];
    Vector3 value;
    void updatePV();
};

struct Dimensions {
    char pad[4];
    Vector3 size;
};

struct Primitive {
    char pad[0x9c];
    Dimensions* dimensions;
    Body* body;
    const Frame& getValue();
};

struct S {
    Primitive* primitive;
    char pad[4];
    Vector3 position;
    float f();
};

float S::f(){
 Vector3 half=primitive->dimensions->size*0.5f;
 Extents bounds(-half,half);
 Vector3 local=primitive->getValue().pointToObjectSpace(position);
 Vector3 nearest=local.clamp(bounds.low,bounds.high);
 float dx=local.x-nearest.x,dy=local.y-nearest.y,dz=local.z-nearest.z;
 return (float)sqrt(dz*dz+dy*dy+dx*dx);
}
