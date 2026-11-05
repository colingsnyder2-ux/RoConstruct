// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_skyrand46cc2a6a5c05338e.cpp

// Candidate translation unit (score above; library headers required).
// from server: 88% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast




#include <G3D/Vector3.h>
#include <G3D/Vector4.h>
typedef G3D::Vector3 Vector3;
typedef G3D::Vector4 Vector4;
extern Vector3 __cdecl randomVector();

extern const float randomScale;
extern const double sizeOffset;

struct VectorArray {
    Vector4* data;
    int count;
    int capacity;
    void resize(int count, bool preserve);
};

struct FloatArray {
    float* data;
    int count;
    int capacity;
    void resize(int count, bool preserve);
};

struct Sky {
    unsigned char padding[0x38];
    VectorArray vectors;
    FloatArray sizes;
    void setCount(int count);
};

void Sky::setCount(int count) {
    if (count == vectors.count)
        return;

    vectors.resize(count, true);
    sizes.resize(vectors.count, true);

    for (int i = vectors.count - 1; i >= 0; --i) {
        Vector3 temporary;
        vectors.data[i]=Vector4(randomVector(),0.0f);
        double r = rand() * randomScale;
        sizes.data[i] = r * r + sizeOffset;
    }
}
