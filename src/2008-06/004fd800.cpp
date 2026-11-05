// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_cylindersurfacetypes_4e8426dfb94586ba.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long *);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);

extern "C" {
}

void * __cdecl operator new(size_t);
void __cdecl operator delete(void *);

struct Object {
    virtual ~Object();
    volatile long references;
    void *resource;
    char storage[28];

    Object(int);
    void release();
};

struct Reference {
    Object *pointer;

    Reference(Object *p) : pointer(0) {
        if (p) {
            pointer = p;
            InterlockedIncrement(&p->references);
        }
    }

    ~Reference() {
        if (pointer) {
            if (InterlockedDecrement(&pointer->references) == 0) {
                pointer->release();
                if (pointer)
                    delete pointer;
            }
            pointer = 0;
        }
    }

    void assign(const Reference &);
};

typedef G3D::Vector3 Vector;

class RenderSurfaceTypes { public: unsigned data; RenderSurfaceTypes():data(0){} };
struct Sphere {
    char prefix[20];
    Reference reference;
    char suffix[12];

    Sphere(const Reference &, Vector, RenderSurfaceTypes, int);
    void build(void *, int);
};

struct Base {
    virtual ~Base();
    char prefix[8];
    Reference reference;
    char suffix[116];

    Base();
};

struct Cylinder : Base {
    int kind;
    Cylinder(const Vector &, void *);
};

Cylinder::Cylinder(const Vector &size, void *destination)
    : Base()
{
    kind = 3;
    Reference object(new Object(5));
    reference.assign(object);
    Sphere sphere(object, size, RenderSurfaceTypes(), 12);
    sphere.build(destination, 1);
}