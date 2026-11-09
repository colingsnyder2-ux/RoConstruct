// from server: 29% by atomic.potato
struct EnumDesc {
    void* vfptr;
    int a;
    int b;
};

struct SurfaceEnumPropDescriptor {
    char pad0[0x28];
    void* field28;
    EnumDesc* field2c;
};

extern "C" void __stdcall sub_4015A0(void*, void*);
extern "C" void* __cdecl sub_4E77F0();
extern "C" void* __cdecl sub_770510();
extern "C" void __cdecl sub_6CB9E0();
extern "C" void* __cdecl sub_98211A(int);

SurfaceEnumPropDescriptor* SurfaceEnumPropDescriptor_ctor(SurfaceEnumPropDescriptor* self, int a, int b, int c, int d, int e)
{
    void* p1;
    void* p2;
    EnumDesc* ed;
    void* mem;

    sub_4015A0((void*)0x770570, (void*)0xe485a4);
    p1 = sub_770510();
    p2 = sub_4E77F0();
    sub_6CB9E0();
    self->field28 = p1;
    *(void**)self = (void*)0xbccb6c;
    mem = sub_98211A(0xc);
    if (mem) {
        *(void**)mem = (void*)0xbcc8b4;
        *(int*)((char*)mem + 4) = c;
        *(int*)((char*)mem + 8) = d;
        ed = (EnumDesc*)mem;
    } else {
        ed = 0;
    }
    self->field2c = ed;
    return self;
}
