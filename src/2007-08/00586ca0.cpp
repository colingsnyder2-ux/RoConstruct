// from server: 100% by colin
struct PartTool {
    PartTool* construct(int);
};

extern "C" void __stdcall sub_5e3d10(int);

PartTool* PartTool::construct(int a)
{
    sub_5e3d10(a);
    *(int*)this = 0x7acefc;
    *(int*)((char*)this + 4) = 0x7acee4;
    *(volatile int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    return this;
}
