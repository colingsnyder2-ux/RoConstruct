// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Vec3 { float x, y, z; };

// INFERRED: layout of an MSVC9 std::vector<Ogre::Vector3>: +0 unknown (passed to the insert helper), +8 allocator, +0xc first, +0x10 last, +0x14 end of storage.
struct Vec3Vector {
    int field0;
    int field4;
    char alloc;
    char pad[3];
    Vec3* first;
    Vec3* last;
    Vec3* end;
};

extern "C" void fn_004dca70(Vec3* dest, int count, const Vec3* val, void* alloc, const Vec3* valty, int tag);
extern "C" int __fastcall fn_004de100(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" void __stdcall _invalid_parameter_noinfo(void);

extern "C" void __fastcall fn_004de250(Vec3Vector* self, int unusedEdx, const Vec3* val)
{
    Vec3* first = self->first;
    Vec3* last = self->last;
    unsigned cap = first ? (unsigned)(self->end - first) : 0;
    if ((unsigned)(last - first) < cap) {
        fn_004dca70(last, 1, val, &self->alloc, val, 0);
        self->last = last + 1;
        return;
    }
    if (first > last)
        _invalid_parameter_noinfo();
    int tmp[2];
    fn_004de100(self, 0, (int)tmp, self->field0, (int)last, (int)val);
}
