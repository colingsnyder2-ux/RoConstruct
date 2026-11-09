// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_cylindertexturelayout39e9ecf56c1f7ffa.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
// from server: 83% by king_originala
extern "C" {
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
}

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

typedef G3D::Vector2 Vec2;
typedef G3D::Vector3 Vec3;
struct Resource {
    virtual ~Resource();
    volatile long references;
    unsigned char data[32];

    Resource(int);
    void dispose();
};

struct Reference {
    Resource *pointer;
    Reference(Resource *) throw();
    ~Reference();
};

__forceinline Reference::Reference(Resource *p) throw() : pointer(0) {
    if (p) {
        pointer = p;
        InterlockedIncrement(&p->references);
    }
}

__forceinline Reference::~Reference() {
    if (pointer && !InterlockedDecrement(&pointer->references)) {
        pointer->dispose();
        if (pointer)
            delete pointer;
    }
}

struct Member {
    unsigned char data[4];
    void assign(const Reference *);
};

struct Base {
    Base();
    virtual ~Base();
    unsigned char data[8];
};

Vec3 calculate(const Vec3&, int);
struct SurfaceTypes {unsigned value;SurfaceTypes():value(0){}};
extern const float scaleFactor;

struct Temporary {
    unsigned char data[20];
    Resource *pointer;
    Vec2 scale;
    unsigned char tail[4];

    Temporary(const Reference *, Vec3, SurfaceTypes, unsigned);
    ~Temporary();
    void finish(int, int);
};

__forceinline Temporary::~Temporary() {
    if (pointer) {
        if (!InterlockedDecrement(&pointer->references)) {
            pointer->dispose();
            if (pointer)
                delete pointer;
        }
        pointer = 0;
    }
}

struct Builder : Base {
    Member member;
    char padToMode[0x84-sizeof(Base)-sizeof(Member)];unsigned mode;

    Builder(const Vec3 &, int, const Vec2 &);
    virtual ~Builder();
};

Builder::Builder(const Vec3 &first, int second,
                 const Vec2 &dimensions) : mode(3) {
    Reference reference(new Resource(5));
    member.assign(&reference);

    Temporary temporary(&reference, first, SurfaceTypes(), 12);
    temporary.scale = calculate(first,second).xy() * 2.0f / dimensions;
    temporary.finish(second, 1);
}
