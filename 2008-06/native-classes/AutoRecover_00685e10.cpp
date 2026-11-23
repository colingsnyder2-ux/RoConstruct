// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: class unknown; copies a 3-float vector into self+0x20.
struct Vec3f { float x, y, z; };

struct Fn685e10Self {
    char pad[0x20];
    float x, y, z;
};

extern "C" void __fastcall fn_00685e10(Fn685e10Self* self, int unusedEdx, const Vec3f* v)
{
    self->x = v->x;
    self->y = v->y;
    self->z = v->z;
}
