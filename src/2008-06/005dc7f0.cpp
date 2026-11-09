// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_humanoidanglethreshold_81224d90311accfa.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)

#include "G3D/CoordinateFrame.h"
#include "G3D/Vector2.h"
using namespace G3D;
typedef CoordinateFrame Frame;
struct Body {
    char reserved[0x94];
    Frame frame;
    const void* get();
};

struct Link {
    char reserved[0x10];
    Body* body;
};

struct Part {
    char reserved[0x2C8];
    Link* link;
};

struct Humanoid {
    char reserved[0x1B0];
    float angle;
    Part* getPart();
    void notify(const void*);
};

struct S {
    void update(float desiredAngle, bool reset);
};

const float tolerance=0.000001f;
const float angleLimit=0.1f;
extern int angleProperty;
extern float __cdecl directionAngle(const Vector2&);
extern float __cdecl wrapAngle(float);


void S::update(float desiredAngle, bool reset)
{
    if (reset) {
        Humanoid* owner =
            reinterpret_cast<Humanoid*>(reinterpret_cast<char*>(this) - 0x14C);
        if (owner->angle != 0.0f) {
            owner->angle = 0.0f;
            owner->notify((const void*)0x97a2d8);
        }
        return;
    }

    Humanoid* owner =
        reinterpret_cast<Humanoid*>(reinterpret_cast<char*>(this) - 0x14C);
    Part* part = owner->getPart();
    {
        Link* link = part ? part->link : 0;
        _ReadWriteBarrier();
        if (link) {
            Body* body = link->body;
            if (body) {
                body->get();
                Vector3 direction = body->frame.lookVector();
                direction.y = 0.0f;
                direction.unitize(tolerance);

                Vector2 planar;
                planar.x = direction.z;
                planar.y = direction.x;

                float currentAngle = wrapAngle(directionAngle(planar));
                float difference = wrapAngle(wrapAngle(desiredAngle) - currentAngle);
                if (fabs(difference) < angleLimit)
                    difference = 0.0f;

                if (owner->angle != difference) {
                    owner->angle = difference;
                    owner->notify((const void*)0x97a2d8);
                }
            }
        }
    }
}
