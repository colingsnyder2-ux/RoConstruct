// from server: 93% by colin
extern "C" int __stdcall InvalidateRect(void*, const void*, int);

struct CXTColorSelectorCtrl {
    char pad[0x20];
    void* field_20;
    char pad2[0x4c];
    int field_70;
    int field_74;
    bool sub_a66b00();
    void func_a66db0();
};

void CXTColorSelectorCtrl::func_a66db0()
{
    if (!sub_a66b00()) {
        field_70 = -1;
        field_74 = -1;
        InvalidateRect(field_20, 0, 0);
    }
}
