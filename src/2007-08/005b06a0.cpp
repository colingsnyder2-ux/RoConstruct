// from server: 100% by colin
struct VWeld {
    char pad[0x100];
    void ctor();
};

void VWeld::ctor()
{
    *(int*)((char*)this + 0x00) = 0x7b64bc;
    *(int*)((char*)this + 0x04) = 0x7b64b4;
    *(int*)((char*)this + 0x10) = 0x7b64ac;
    *(int*)((char*)this + 0x14) = 0x7b649c;
    *(int*)((char*)this + 0x2c) = 0x7b648c;
    *(int*)((char*)this + 0x44) = 0x7b647c;
    *(int*)((char*)this + 0x5c) = 0x7b646c;
    *(int*)((char*)this + 0x74) = 0x7b645c;
    *(int*)((char*)this + 0x8c) = 0x7b644c;
    *(int*)((char*)this + 0xe8) = 0x7b6434;
    extern void base_ctor_005b03f0();
    base_ctor_005b03f0();
}
