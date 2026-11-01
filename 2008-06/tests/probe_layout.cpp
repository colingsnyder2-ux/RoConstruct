// Layout probe (measurement only, not linked into anything): prints rbxgs-app header offsets of fields whose
// 2008 offsets the exact units record, so header corrections can be checked against the evidence.
// Private members are measured by opening access for this probe only.
#define private public
#define protected public
#include "v8world/Primitive.h"
#include "v8kernel/Body.h"
#undef private
#undef protected
#include <cstddef>
#include <cstdio>

#define FIELD(type, member, expected) \
    std::printf("%-10s %-12s 0x%03x  2008 0x%03x  %s\n", #type, #member, (unsigned)offsetof(type, member), \
                (unsigned)(expected), offsetof(type, member) == (expected) ? "ok" : "DIFFERS")

int main()
{
    using namespace RBX;
    FIELD(Primitive, geometry, 0x9c);
    FIELD(Primitive, body, 0xa0);
    FIELD(Primitive, myOwner, 0xa4);
    FIELD(Primitive, surfaceType, 0xb8);
    FIELD(Body, root, 0x10);
    FIELD(Body, children, 0x1c);
    FIELD(Body, cofm, 0x28);
    FIELD(Body, canThrottle, 0x30);
    FIELD(Body, mass, 0x8c);
    FIELD(Body, pv, 0x94);
    std::printf("sizeof Primitive 0x%x Body 0x%x\n", (unsigned)sizeof(Primitive), (unsigned)sizeof(Body));
    return 0;
}
