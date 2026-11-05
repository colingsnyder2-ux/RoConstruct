// from server: 100% by EspClaude
// from server: 93% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_bc7768735680516f.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Velocity.h"

#include <intrin.h>

struct Six {
    float x, y, z, a, b, c;
    Six(double, double, double, double, double, double);
};

__forceinline Six::Six(double X, double Y, double Z,
                       double A, double B, double C)
    : x((float)X), y((float)Y), z((float)Z),
      a((float)A), b((float)B), c((float)C)
{
}

struct ZeroSix {
    float x, y, z, a, b, c;
    ZeroSix() throw();
};

struct Transform {
    RBX::Velocity velocityAtPoint(const G3D::Vector3&) const;
};

struct DataSource {
    char reserved[0x94];
    Transform transform;
    void updatePV() const;
};

struct Attachment {
    char reserved[0xA0];
    DataSource* source;
};

struct Object {
    char reserved[0x228];
    Attachment attachment;
};

struct Scale {
    char reserved[0x80];
    float value;
};

struct Owner {
    char reserved[0x21C];
    Scale* scale;
};

struct S {
    char reserved0[8];
    Owner* owner;
    char reserved1[0x18];
    Object* object;
    char reserved2[4];
    G3D::Vector3 local;
    RBX::Velocity f(int);
};

RBX::Velocity S::f(int)
{
    Attachment* attachment = object ? &object->attachment : 0;
    if (attachment) {
        Scale* scale = owner->scale;
        DataSource* source = attachment->source;
        source->updatePV();
        RBX::Velocity transformed = source->transform.velocityAtPoint(local);
        float factor = scale->value;
        G3D::Vector3 linear = transformed.linear * factor;
        G3D::Vector3 rotational = transformed.rotational * factor;
        return RBX::Velocity(linear, rotational);
    }
    return RBX::Velocity::zero();
}
