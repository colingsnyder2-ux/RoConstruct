// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a checked-iterator std::vector<T*>::insert(iterator where, const T& val)
// returning the new iterator through a hidden sret pointer. The layout below is guessed
// from the disassembly offsets.
struct PtrVecIter {
    void*  container;
    void** ptr;
};

struct PtrVec {
    void*  proxy;      // +0x00 container proxy
    int    pad[2];     // +0x04..+0x0b
    void** first;      // +0x0c
    void** last;       // +0x10
};

extern "C" int __fastcall fn_004c7a90(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

extern "C" PtrVecIter* __fastcall fn_00679120(PtrVec* self, int unusedEdx,
                                              PtrVecIter* ret,
                                              void* whereContainer,
                                              void** wherePtr,
                                              void* value)
{
    void** first = self->first;
    int off;
    if (((char*)self->last - (char*)first) & ~3) {
        off = (int)(wherePtr - first);
    } else {
        off = 0;
    }

    fn_004c7a90(self, 0, (int)whereContainer, (int)wherePtr, 1, (int)value);

    void** newFirst = self->first;
    ret->ptr = newFirst + off;
    ret->container = self->proxy;
    return ret;
}
