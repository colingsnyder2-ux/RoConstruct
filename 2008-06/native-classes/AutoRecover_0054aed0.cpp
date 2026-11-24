// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
// INFERRED: local minimal G3D declarations are used so the mangled names match
// the real G3D symbols (Vector3 copy ctor, Array<Vector3>::inArray / resize).
// INFERRED: no native headers were shown, so none are included.

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);

namespace G3D {

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
    // INFERRED: the third branch calls what the disassembly names as the copy ctor
    // (folded with operator=); an assignment reproduces "call with ecx = element".
    Vector3& operator=(const Vector3&);
};

template <class T> class Array;

}

extern "C" void __fastcall fn_0054aed0(G3D::Array<G3D::Vector3>* self, int,
                                       const G3D::Vector3* a, const G3D::Vector3* b);

namespace G3D {

template <class T>
class Array {
    T* data;
    int num;
    int numAllocated;

    bool inArray(const T* e);

public:
    void resize(int n, bool shrinkIfNecessary);

    friend void __fastcall ::fn_0054aed0(Array<Vector3>* self, int,
                                         const Vector3* a, const Vector3* b);
};

}

// INFERRED: the original is a __thiscall member; the recursive call goes through a
// thiscall-typed pointer so that edx is not set up, and the unused edx is unnamed.
typedef void (__thiscall *ThisFn0054aed0)(G3D::Array<G3D::Vector3>*, const G3D::Vector3*, const G3D::Vector3*);

#pragma strict_gs_check(on)
#pragma optimize("", off)

// INFERRED: Array<Vector3>::append(const Vector3&, const Vector3&)-like routine.
extern "C" void __fastcall fn_0054aed0(G3D::Array<G3D::Vector3>* self, int,
                                       const G3D::Vector3* a, const G3D::Vector3* b)
{
    using G3D::Vector3;
    if (self->inArray(a) || self->inArray(b)) {
        Vector3 copies[2] = { *a, *b };
        ((ThisFn0054aed0)(void*)fn_0054aed0)(self, &copies[0], &copies[1]);
    } else if (self->num + 1 < self->numAllocated) {
        new (self->data + self->num) Vector3(*a);
        new (self->data + self->num + 1) Vector3(*b);
        self->num += 2;
    } else {
        self->resize(self->num + 2, false);
        self->data[self->num - 2] = *a;
        self->data[self->num - 1] = *b;
    }
}

#pragma optimize("", on)
#pragma strict_gs_check(off)
