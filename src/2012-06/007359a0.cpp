// from server: 31% by atomic.potato
struct S {
    void* vfptr;
    char pad1[0x1c];
    int field20;
    char pad2[4];
    char field28;
    int ctor();
};

extern "C" void __stdcall sub_b22654();
extern "C" int __cdecl sub_67f480();
extern "C" void __cdecl sub_70c670();

int S::ctor() {
    vfptr = (void*)0xba8154;
    sub_b22654();
    field20 = sub_67f480();
    sub_70c670();
    return (int)this;
}
