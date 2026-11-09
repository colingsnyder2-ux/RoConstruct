// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_pbbsurfacetypes_d675e7b63d1a5813.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
typedef unsigned int size_t;

extern "C" {
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
}

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

typedef G3D::Vector3 Vector3;
class RenderSurfaceTypes { public: unsigned data; RenderSurfaceTypes():data(0){} };
struct Resource {
    virtual void destroy(unsigned int);
    volatile long references;
    void* data;
    unsigned char storage[28];

    Resource(int);
    void releaseData();
};

struct Reference {
    Resource* p;

    Reference(Resource* value) : p(0) {
        if (value) {
            p = value;
            InterlockedIncrement(&value->references);
        }
    }

    ~Reference() {
        if (p) {
            if (!InterlockedDecrement(&p->references)) {
                p->releaseData();
                if (p)
                    p->destroy(1);
            }
            p = 0;
        }
    }
};

struct Holder {
    Resource* p;

    void assign(const Reference&);
};

struct Temporary {
    unsigned char prefix[20];
    Reference resource;
    unsigned char suffix[16];

    Temporary(const Reference&, Vector3, RenderSurfaceTypes);
    void apply(void*, int);
};

struct Base {
    unsigned int state[2];

    Base();
    virtual ~Base();
};

struct Builder : Base {
    Holder resource;

    Builder(const Vector3&, void*);
    virtual ~Builder();
};

Builder::Builder(const Vector3& position, void* value)
    : Base() {
    Reference reference(new Resource(5));
    resource.assign(reference);
    Temporary temporary(reference, position, RenderSurfaceTypes());
    temporary.apply(value, 1);
}
