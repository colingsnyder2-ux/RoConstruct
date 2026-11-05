// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_1c570c469dec2599.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include "util/Extents.h"
//



struct Iterator {
    void* owner;
    void* position;
};

struct Container {
    void* owner;
    char reserved[8];
    void* first;
    void* last;
    void* limit;

    Iterator erase(Iterator first, Iterator last);
};

typedef RBX::Extents Bounds;

struct Data {
    char reserved[24];
};

extern void __cdecl prepare(Data*);
extern bool __cdecl valid(Data*);
extern RBX::Extents __cdecl getBounds(Data*);

struct Object {
    char reserved[0x28c];
    Container container;

    void setVector(const G3D::Vector3&);
};

struct BlockBlockContact {
    char reserved[8];
    Data data;
    unsigned char updated;
    char padding[3];
    Object* object;

    void update();
};

static inline G3D::Vector3 topCenterOf(const RBX::Extents& e)
{
    G3D::Vector3 v = e.center();
    v.y = e.max().y;
    return v;
}
void BlockBlockContact::update()
{
    Container* container = &object->container;

    Iterator last;
    last.position = container->last;
    if (container->first > last.position)
        _invalid_parameter_noinfo();

    Iterator first;
    first.position = container->first;
    last.owner = container->owner;
    if (first.position > container->last)
        _invalid_parameter_noinfo();
    first.owner = container->owner;

    container->erase(first, last);

    Data* value = &data;
    prepare(value);
    if (valid(value)) {
        G3D::Vector3 center = topCenterOf(getBounds(value));
        object->setVector(center);
    }
    updated = 1;
}

