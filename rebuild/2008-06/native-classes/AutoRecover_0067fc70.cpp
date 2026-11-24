// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::vector<Ogre::Vector3>::resize(size_type, Vector3) (checked-iterator layout).
// The three trailing stack dwords are a by-value 12-byte Vector3.
struct Vector3Local {
    float x, y, z;
};

struct Vec3Iter {
    void* cont;
    Vector3Local* ptr;
};

struct Vec3Vector {
    void* cont;              // +0x00 (checked iterator container / proxy)
    int pad[2];              // +0x04, +0x08
    Vector3Local* first;     // +0x0c
    Vector3Local* last;      // +0x10
    Vector3Local* end;       // +0x14
};

extern "C" int __fastcall fn_0067fa80(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
extern "C" void __fastcall fn_004ddbc0(void* self, int unusedEdx, void* cont, Vector3Local* where,
                                        unsigned count, const Vector3Local* val);

extern "C" void __fastcall fn_0067fc70(Vec3Vector* self, int unusedEdx, unsigned newSize, Vector3Local val)
{
    unsigned size = (unsigned)(self->last - self->first);
    if (newSize > size) {
        fn_004ddbc0(self, 0, self->cont, self->last, newSize - size, &val);
    } else if (newSize < size) {
        Vec3Iter first;
        first.cont = self->cont;
        first.ptr = self->first + newSize;
        int ret[2];
        fn_0067fa80(self, 0, (int)&ret, (int)first.cont, (int)first.ptr, (int)self->cont, (int)self->last);
    }
}
