// from server: 40% by tester
struct Ogre_AxisAlignedBox {
    Ogre_AxisAlignedBox();
};

struct Ogre_Entity {
    Ogre_Entity();
};

struct Ogre_RbxEntity {
    char pad0[0x278];
    Ogre_AxisAlignedBox box;
    char pad1[0x1c];
    void* ptr;
    char pad2[0xc];
    int a;
    int b;
    int c;
    char pad3[0x1b8];
    unsigned char flag;
    Ogre_RbxEntity();
};

extern "C" void __stdcall sub_8A0428();
extern "C" void __stdcall sub_8A0B88();
extern "C" void* __cdecl sub_718A38(int);

Ogre_RbxEntity::Ogre_RbxEntity()
{
    sub_8A0428();
    *(void**)this = (void*)0x923bd4;
    *(void**)((char*)this + 4) = (void*)0x923bc0;
    *(void**)((char*)this + 0xc8) = (void*)0x923bb4;
    sub_8A0B88();
    void* p = sub_718A38(4);
    if (p != 0) {
        *(void**)p = (char*)this + 0x298;
    } else {
        p = 0;
    }
    *(void**)((char*)this + 0x298) = p;
    *(int*)((char*)this + 0x2a4) = 0;
    *(int*)((char*)this + 0x2a8) = 0;
    *(int*)((char*)this + 0x2ac) = 0;
    *(unsigned char*)((char*)this + 0x1d4) = 1;
}
