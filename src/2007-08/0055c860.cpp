// from server: 100% by colin
struct VDataModelBoundFuncDesc {
    char pad[0x11c];
    void* construct();
};

extern void func_0054a3b0();

void* VDataModelBoundFuncDesc::construct()
{
    func_0054a3b0();
    *(int*)((char*)this + 0x00) = 0x7a8bb4;
    *(int*)((char*)this + 0x04) = 0x7a8ba8;
    *(int*)((char*)this + 0x10) = 0x7a8ba0;
    *(int*)((char*)this + 0x14) = 0x7a8b90;
    *(int*)((char*)this + 0x2c) = 0x7a8b80;
    *(int*)((char*)this + 0x44) = 0x7a8b70;
    *(int*)((char*)this + 0x5c) = 0x7a8b60;
    *(int*)((char*)this + 0x74) = 0x7a8b50;
    *(int*)((char*)this + 0x8c) = 0x7a8b40;
    *(int*)((char*)this + 0xe8) = 0x7a8b30;
    *(int*)((char*)this + 0x100) = 0x7a8b20;
    *(int*)((char*)this + 0x118) = 0x7a8b10;
    return this;
}
