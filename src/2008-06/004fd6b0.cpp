// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_cylindermeshlayout0ed17185b646521a.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector3.h>
#include <G3D/Array.h>
#include <G3D/ReferenceCount.h>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast



void * __cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

typedef G3D::Vector3 Vector3;

struct Resource : G3D::ReferenceCountedObject {char storage[28];Resource(int);};
typedef G3D::ReferenceCountedPointer<Resource> ResourcePtr;

typedef G3D::Array<ResourcePtr> ResourceList;

struct RenderSurfaceTypes {unsigned int data;};
struct Base
{
    virtual ~Base();
    char prefix[8];
    ResourceList resources;
    char suffix[108];

    Base();
};

struct TemporaryBuilder
{
    char prefix[20];
    ResourcePtr resource;
    char suffix[12];

    TemporaryBuilder(ResourcePtr *, Vector3, RenderSurfaceTypes, int);
    void build(int);

};

struct CylinderBuilder : Base
{
    int kind;

    CylinderBuilder(const Vector3 &, RenderSurfaceTypes);
    virtual ~CylinderBuilder();
};

CylinderBuilder::CylinderBuilder(const Vector3 &size, RenderSurfaceTypes context)
    : Base()
{
    kind = 3;
    {
        ResourcePtr resource(new Resource(5));
        resources.append(resource);
    }

    ResourcePtr& last = resources.last();
    TemporaryBuilder builder(&last, size, context, 12);
    builder.build(0);
}