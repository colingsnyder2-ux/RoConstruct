// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from the disassembly only; field names are guesses.
struct Vec4f { float x, y, z, w; };

struct Func685e30Obj {
    int   f0;
    char  b4;
    int   f8;
    int   fC;
    Vec4f v;
    float p0, p1, p2;
};

// INFERRED: float constant at 0x0081c3b8, name is a guess.
extern "C" float g_float_0081c3b8;

extern "C" void __fastcall fn_00685e30(Func685e30Obj* self, int unusedEdx)
{
    self->v.x = 1.0f; self->v.y = 1.0f; self->v.z = 1.0f; self->v.w = 1.0f;
    self->f0 = 0;
    self->b4 = 0;
    self->f8 = 0;
    Vec4f t = { g_float_0081c3b8, g_float_0081c3b8, g_float_0081c3b8, g_float_0081c3b8 };
    self->v = t;
    self->fC = 2;
    self->p0 = 0.0f;
    self->p1 = 0.0f;
    self->p2 = 0.0f;
}
