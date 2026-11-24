// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>
#include <math.h>

// INFERRED: plain 3-float vector; the target is a random unit vector (rejection sampling in the unit ball, then normalize).
struct Vec3f { float x, y, z; };

extern "C" Vec3f* fn_00518650(Vec3f* self)
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    self->x = 0.0f;
    self->y = 0.0f;
    self->z = 0.0f;
    do {
        z = (float)rand() * (2.0f / 32767.0f) - 1.0f;
        y = (float)rand() * (2.0f / 32767.0f) - 1.0f;
        x = (float)rand() * (2.0f / 32767.0f) - 1.0f;
        self->x = x;
        self->y = y;
        self->z = z;
    } while (!(x * x + y * y + z * z < 1.0f));

    float len = sqrtf(x * x + y * y + z * z);
    if (len > 1e-6f) { // INFERRED: epsilon constant at 0x826e70
        float inv = 1.0f / len;
        self->x = x * inv;
        self->y = y * inv;
        self->z = z * inv;
    }
    return self;
}
