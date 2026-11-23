// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::vector<Ogre::Vector3>::insert(iterator, const Vector3&) with checked iterators.
// Layout inferred from disassembly: [0]=proxy/container, [0xc]=_Myfirst, [0x10]=_Mylast.
struct Vec3 { float x, y, z; };

struct CheckedIter {
    void* container;
    Vec3* ptr;
};

struct Vec3Vector {
    void* proxy;
    int pad[2];
    Vec3* first;
    Vec3* last;
};

extern "C" void __fastcall fn_004ddbc0(Vec3Vector* self, int unusedEdx, void* a1, Vec3* a2, int count, const Vec3* val);

extern "C" CheckedIter* __fastcall fn_004de100(Vec3Vector* self, int unusedEdx,
                                               CheckedIter* ret, void* where0,
                                               Vec3* where1, const Vec3* val)
{
    int off;
    if (((self->last - self->first)) == 0)
        off = 0;
    else
        off = (int)(where1 - self->first);
    fn_004ddbc0(self, 0, where0, where1, 1, val);
    Vec3* p = self->first + off;
    ret->container = self->proxy;
    ret->ptr = p;
    return ret;
}
