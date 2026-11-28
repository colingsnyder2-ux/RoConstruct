// native-flags: /Od /Ob0 /GS /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: local non-colliding stand-ins for G3D::Vector3 and G3D::Array<Vector3>
// compiled with /Od /Ob0 /GS /EHs, matching G3D::Array::append's two-local copy branch.
struct Local_0054aed0_Vec3 {
    float x, y, z;
    Local_0054aed0_Vec3(const Local_0054aed0_Vec3&);
    Local_0054aed0_Vec3& operator=(const Local_0054aed0_Vec3&);
};

struct Local_0054aed0_Arr {
    Local_0054aed0_Vec3* data;
    int num;
    int numAllocated;

    bool inArray(const Local_0054aed0_Vec3* e);
    void resize(int n, bool shrinkIfNecessary);
};

typedef void (__thiscall *ThisFn_0054aed0)(Local_0054aed0_Arr*, const Local_0054aed0_Vec3*, const Local_0054aed0_Vec3*);

// INFERRED: G3D::Array<Vector3>::append(const Vector3&, const Vector3&)
extern "C" void __fastcall fn_0054aed0(Local_0054aed0_Arr* self, int,
                                       const Local_0054aed0_Vec3* a, const Local_0054aed0_Vec3* b)
{
    if (self->inArray(a) || self->inArray(b)) {
        Local_0054aed0_Vec3 t1 = *a;
        Local_0054aed0_Vec3 t2 = *b;
        ((ThisFn_0054aed0)(void*)fn_0054aed0)(self, &t1, &t2);
    } else if (self->num + 1 < self->numAllocated) {
        new (self->data + self->num) Local_0054aed0_Vec3(*a);
        new (self->data + self->num + 1) Local_0054aed0_Vec3(*b);
        self->num += 2;
    } else {
        self->resize(self->num + 2, false);
        self->data[self->num - 2] = *a;
        self->data[self->num - 1] = *b;
    }
}
