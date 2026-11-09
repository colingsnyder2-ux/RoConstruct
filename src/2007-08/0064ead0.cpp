// from server: 100% by colin
struct CXTPToolBar_CControlButtonHide {
    void* construct();
};

extern "C" void __stdcall sub_6ca460();

void* CXTPToolBar_CControlButtonHide::construct()
{
    sub_6ca460();
    *(int*)((char*)this + 0x168) = 0;
    *(int*)((char*)this + 0x16c) = 0;
    *(int*)((char*)this) = 0x7c7014;
    *(int*)((char*)this + 0x20) = 0x7c6fb4;
    return this;
}
