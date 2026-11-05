// from server: 100% by colin
struct CMemberTreeView {
    char pad[0x110];
    CMemberTreeView* construct();
};

extern "C" void __stdcall sub_0063065e();

CMemberTreeView* CMemberTreeView::construct()
{
    sub_0063065e();
    *(int*)((char*)this + 0x00) = 0x78c9c4;
    *(volatile int*)((char*)this + 0xf0) = 0;
    *(int*)((char*)this + 0xf4) = 0;
    *(int*)((char*)this + 0xf8) = 0;
    *(int*)((char*)this + 0xfc) = 0;
    *(int*)((char*)this + 0x100) = 0;
    *(int*)((char*)this + 0x104) = 0;
    *(int*)((char*)this + 0x108) = 0;
    *(int*)((char*)this + 0x10c) = 0;
    return this;
}
