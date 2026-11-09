// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_wedgevalueargs4b797bfe01476f5a.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/Vector3.h"
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#pragma float_control(precise, off)
typedef unsigned int size_t;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long *);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);

void *__cdecl operator new(size_t);
void __cdecl operator delete(void *);

const float faceScale=0.065f;

typedef G3D::Vector3 Vector3;
struct RenderSurfaceTypes {unsigned value;RenderSurfaceTypes():value(0){}};

struct Object {
    virtual ~Object();
    volatile long references;
    char storage[32];

    Object(int);
    void dispose();
};

struct Reference {
    Object *pointer;

    Reference(Object *);
    ~Reference();
};

inline Reference::Reference(Object *p) : pointer(0)
{
    if (p) {
        pointer = p;
        InterlockedIncrement(&p->references);
    }
}

inline Reference::~Reference()
{
    if (pointer) {
        if (!InterlockedDecrement(&pointer->references)) {
            pointer->dispose();
            if (pointer)
                delete pointer;
        }
        pointer = 0;
    }
}

struct Holder {
    void assign(const Reference &);
};

struct BuilderBase {
    virtual ~BuilderBase();
    char storage[8];
    Holder holder;

    BuilderBase();
};

struct __declspec(novtable) FaceBase {
    virtual void unused();
    char storage[16];
    Reference reference;
    char tail[8];

    FaceBase(const Reference &, Vector3, RenderSurfaceTypes);
    ~FaceBase();
    void build(int, int);
};

inline FaceBase::~FaceBase()
{
}

struct Face : FaceBase {
 const float scale;
 Face(const Reference& r,Vector3 size,RenderSurfaceTypes types,float bevel):FaceBase(r,size,types),scale(bevel){}
 virtual void unused();
};

struct WedgeBuilder : BuilderBase {
    WedgeBuilder(const Vector3 &, int);
    virtual ~WedgeBuilder();
};

WedgeBuilder::WedgeBuilder(const Vector3 &size, int purpose)
    : BuilderBase()
{
    Reference reference(new Object(5));
    holder.assign(reference);
    Face face(reference, size, RenderSurfaceTypes(), 0.065f);
    face.build(purpose, 1);
}

