// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layouts from disassembly only; G3D Array<Vector4> is 3 dwords with data pointer first.
extern "C" void __fastcall fn_00507d20_unused();
namespace G3D { struct System { static void alignedFree(void* p); }; }

struct Vec4Array {
    void* data;
    int   a;
    int   b;
    ~Vec4Array() { G3D::System::alignedFree(data); }
};

extern "C" void __fastcall fn_00496ef0(Vec4Array* self, int unusedEdx, const Vec4Array* src);

struct Obj498610 {
    int       id;
    Vec4Array arr;
    bool      f1;
    bool      f2;
};

extern "C" Obj498610* __fastcall fn_00498610(Obj498610* self, int unusedEdx, int id,
                                             int unusedArg2, Vec4Array src,
                                             bool f1, bool f2)
{
    self->id = id;
    fn_00496ef0(&self->arr, 0, &src);
    self->f1 = f1;
    self->f2 = f2;
    return self;
}
