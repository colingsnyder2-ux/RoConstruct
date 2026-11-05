// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_headmeshbuilderctor5d1d191168c9e9f3.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
struct Vec3
{
    float x, y, z;

    Vec3();
    Vec3(const Vec3 &);
};

inline Vec3::Vec3(const Vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

inline const float &minimum(const float &a, const float &b)
{
    return b < a ? b : a;
}

struct Mesh : G3D::ReferenceCountedObject {unsigned char storage[28];Mesh(int);void dispose();};
typedef G3D::ReferenceCountedPointer<Mesh> Ref;
struct Holder
{
    void assign(const Ref &);
};

struct Base
{
    virtual ~Base();
    unsigned char padding[8];
    G3D::Array<Ref> mesh;

    Base();
};

struct RenderSurfaceTypes {unsigned value;RenderSurfaceTypes():value(0){}};
struct Work {char prefix[20];Ref p;char tail[16];Work(Ref,G3D::Vector3,RenderSurfaceTypes,int,float);void initialize(void*,int);};
struct HeadBuilder : Base
{
    HeadBuilder(const Vec3 &, void *);
    virtual ~HeadBuilder();
};

extern const float scale;
HeadBuilder::HeadBuilder(const Vec3 &size, void *arg)
{
    float radius = minimum(size.x, size.z) * scale;
    Mesh *created = new Mesh(5);

    {
        Ref reference(created);
        mesh.append(reference);
    }

    Work work(created,reinterpret_cast<const G3D::Vector3&>(size),RenderSurfaceTypes(),9,radius);
    work.initialize(arg, 1);
}
