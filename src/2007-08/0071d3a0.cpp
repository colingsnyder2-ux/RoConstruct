// from server: 100% by colin
struct CXTPTabPaintManager_CColorSetWhidbey
{
    CXTPTabPaintManager_CColorSetWhidbey* construct();
    int field_0;
    char pad[0x214];
    int field_218;
};

extern "C" void __stdcall sub_6ae110();

CXTPTabPaintManager_CColorSetWhidbey* CXTPTabPaintManager_CColorSetWhidbey::construct()
{
    sub_6ae110();
    *(int*)this = 0x7e0d20;
    field_218 = 0;
    return this;
}
