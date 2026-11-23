// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: signature from the disassembly (thiscall, 3 stack args, ret 0xc); the arg types are guesses.
struct Vec2 { float x, y; };
struct Vec2i16 { short x, y; };

// INFERRED: callee at +0xc in the vtable of the object at [arg+0x18]; takes (ptr, Vector2int16*).
struct Target { virtual void v0(); virtual void v1(); virtual void v2(); virtual void set(void* sub, Vec2i16* v); };
struct Holder { char pad[0x18]; Target* target; };

// G3D::Vector2int16::Vector2int16(const Vector2&)
extern "C" void __fastcall fn_005122d0(Vec2i16* self, int unusedEdx, const Vec2* v);

extern "C" void __fastcall fn_0048b8a0(char* self, int unusedEdx, const Vec2* pair, Holder* a, Holder* b)
{
    Vec2i16 v;
    fn_005122d0(&v, 0, pair);
    a->target->set(self ? self + 0x14 : 0, &v);

    Vec2i16 w;
    fn_005122d0(&w, 0, pair + 1);
    b->target->set(self ? self + 0x14 : 0, &w);
}
