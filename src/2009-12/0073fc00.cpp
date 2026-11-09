// from server: 22% by atomic.potato
struct VCollectionService_BoundFuncDesc {
    void* ctor();
};

extern "C" void __stdcall sub_73F490(void*);
extern "C" void __stdcall sub_4777C0(void*, void*, void*);

void* VCollectionService_BoundFuncDesc::ctor()
{
    char pad0[0x94];
    char flag94;
    char pad1[3];
    int field98;
    int field9c;
    char fielda0[4];

    sub_73F490((void*)0xB54160);
    flag94 = 1;
    *(int*)((char*)this + 0) = 0x9E2634;
    *(int*)((char*)this + 4) = 0x9E2628;
    *(int*)((char*)this + 0x18) = 0x9E261C;
    *(int*)((char*)this + 0x1c) = 0x9E2614;
    field98 = 0;
    field9c = 0;
    sub_4777C0((void*)((char*)this + 0xa0), (void*)0, (void*)0);

    return this;
}
