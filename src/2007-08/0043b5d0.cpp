// from server: 37% by tester
struct CSelectionPropGrid {
    void* vftable;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    void init(int);
    CSelectionPropGrid(int, int);
};

extern "C" void __stdcall sub_0043AAE0(int);

CSelectionPropGrid::CSelectionPropGrid(int a, int b)
{
    this->vftable = (void*)0x78d574;
    this->field_8 = 0;
    this->field_c = 0;
    this->field_10 = 0;
    this->field_14 = b;
    this->init(*(int*)(a + 0xc));
}

void CSelectionPropGrid::init(int x)
{
    sub_0043AAE0(x);
}
