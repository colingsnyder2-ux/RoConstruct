// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void alignedFree(void* ptr);
};

// INFERRED: layout of G3D::Array<Vector4> (data, num, numAllocated), from [this+0/4/8] accesses
class Vector4 {
public:
    float x, y, z, w;
    Vector4(const Vector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
};

class Vector4Array {
public:
    Vector4* data;
    int num;
    int numAllocated;

    // INFERRED: G3D Array::realloc(oldNum): copy min(oldNum, numAllocated) elements, free old buffer
    void realloc(int oldNum);
};

void Vector4Array::realloc(int oldNum)
{
    Vector4* oldData = data;
    data = (Vector4*)System::alignedMalloc(numAllocated * sizeof(Vector4), 16);

    int n = (oldNum < numAllocated) ? oldNum : numAllocated;
    for (int i = 0; i < n; ++i) {
        ::new (data + i) Vector4(oldData[i]);
    }

    System::alignedFree(oldData);
}
}

extern "C" void __fastcall fn_00489aa0(G3D::Vector4Array* self, int unusedEdx, int oldNum)
{
    self->realloc(oldNum);
}
