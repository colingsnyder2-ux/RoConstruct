// from server: 25% by colin
struct PhysicsPacketCache {
    char pad[0x24];
    int field20;
    PhysicsPacketCache();
};

extern "C" void __stdcall sub_598990();
extern "C" int __cdecl sub_513450();
extern int dword_CCA818;

PhysicsPacketCache::PhysicsPacketCache()
{
    sub_598990();
    *(int*)((char*)this + 0) = 0xa7e3a4;
    *(int*)((char*)this + 4) = 0xa7e398;
    *(int*)((char*)this + 0x18) = 0xa7e38c;
    *(int*)((char*)this + 0x1c) = 0xa7e380;
    field20 = sub_513450();
    dword_CCA818++;
}
