// from server: 37% by atomic.potato
struct RbxEntity {
    char pad0[0x288];
    char pad1[0x24];
    int field2ac;
    int field2b0;
    int field2b4;
    unsigned char field1f4;
    void construct();
};

extern "C" void __stdcall sub_b22c34();
extern "C" void __stdcall sub_b22bcc();

void RbxEntity::construct()
{
    sub_b22c34();
    *(int*)((char*)this + 0x2ac) = 0;
    *(int*)((char*)this + 0x2b0) = 0;
    *(int*)((char*)this + 0x2b4) = 0;
    *(unsigned char*)((char*)this + 0x1f4) = 1;
}
