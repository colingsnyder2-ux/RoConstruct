// from server: 100% by colin
struct RBX_RocketTool {
    RBX_RocketTool* construct(void* a, char b, int c);
};

extern "C" void __stdcall sub_5e3d10(void* a);

RBX_RocketTool* RBX_RocketTool::construct(void* a, char b, int c)
{
    sub_5e3d10(a);
    *(int*)((char*)this + 0) = 0x7c24fc;
    *(int*)((char*)this + 4) = 0x7c24e0;
    *(volatile int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(char*)((char*)this + 0x28) = b;
    *(int*)((char*)this + 0x2c) = c;
    return this;
}
