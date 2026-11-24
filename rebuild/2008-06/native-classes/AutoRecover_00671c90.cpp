// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is an MSVC 2008 checked std::vector<8-byte element>::insert(iterator where, const T& val).
// Iterators are {container proxy, pointer} pairs, and the result is returned through a hidden out pointer.
struct Vec8 {
    void* proxy;        // +0x00 checked-iterator container pointer
    int   pad[2];       // +0x04, +0x08
    char* first;        // +0x0c
    char* last;         // +0x10
};

struct Iter8 {
    void* cont;
    char* ptr;
};

extern "C" int __fastcall fn_0065af80(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

extern "C" Iter8* __fastcall fn_00671c90(Vec8* self, int unusedEdx, Iter8* out, void* whereCont, char* wherePtr, const void* val)
{
    int off;
    if (((unsigned)(self->last - self->first) & 0xfffffff8u) == 0)
        off = 0;
    else
        off = (int)(wherePtr - self->first) >> 3;

    fn_0065af80(self, 0, (int)whereCont, (int)wherePtr, 1, (int)val);

    char* first = self->first;
    void* cont = self->proxy;
    out->cont = cont;
    out->ptr = first + off * 8;
    return out;
}
