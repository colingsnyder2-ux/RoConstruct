// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from disassembly; Array<Vector4> = {data, num, numAllocated, flagA, flagB}, owner holds int at +0 and array at +4.
extern "C" void __fastcall fn_00496ef0(void* self, int unusedEdx, const void* src); // G3D::Array<Vector4>::_copy
extern "C" void fn_00507d20(void* p); // G3D::System::alignedFree

struct ArrayV4 {
    void* data;
    int num;
    int numAllocated;
    unsigned char flagA;
    unsigned char flagB;
    ~ArrayV4() { fn_00507d20(data); }
};

struct Func00498610Obj {
    int first;
    ArrayV4 arr;
};

// INFERRED: by-value ArrayV4 argument is destroyed by the callee (ret 0x18); second int arg unused.
extern "C" Func00498610Obj* __fastcall fn_00498610(Func00498610Obj* self, int unusedEdx, int a, int unused, ArrayV4 src)
{
    self->first = a;
    fn_00496ef0(&self->arr, 0, &src);
    self->arr.flagA = src.flagA;
    self->arr.flagB = src.flagB;
    return self;
}
