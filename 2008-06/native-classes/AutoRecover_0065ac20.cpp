// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::vector<pod8>::_Ufill(E* dest, size_t count, const E& val),
// which returns dest + count. The class name is not known, so self is a void*.
// INFERRED: the disassembly pushes only 6 args (add esp,0x18), so this
// declaration has 6 params. The convention and name are unchanged.
// INFERRED: the 5th argument is a pointer-sized struct passed by value, and the
// 6th is an empty tag struct passed by value.

struct E { int v[2]; };
struct Tag { };
struct PtrWrap { const E* p; };

extern "C" int fn_0067ca20(E* dest, unsigned int count, const E* val, void* alloc, PtrWrap val2, Tag tag);

extern "C" E* __fastcall fn_0065ac20(void* self, int unusedEdx, E* dest, unsigned int count, const E& val)
{
    PtrWrap w;
    w.p = &val;
    fn_0067ca20(dest, count, &val, (char*)self + 8, w, Tag());
    return dest + count;
}
