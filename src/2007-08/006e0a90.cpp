// from server: 100% by colin
struct CXTPDockingPaneAutoHidePanel {
    char pad0[0x54];
    char field_54[0x140];
    int field_194;
    char pad198[8];
    void* field_1a0;
    int method_6e0a90();
};

extern "C" int __fastcall sub_68f5e0(void*);
extern "C" void* __fastcall sub_6e0550(void*);

int CXTPDockingPaneAutoHidePanel::method_6e0a90()
{
    if (field_194 != 0 && field_1a0 != 0 && (sub_68f5e0(field_1a0) & 8) == 0) {
        void* p = sub_6e0550(field_54);
        if (*(int*)((char*)p + 0x2c) != 0)
            return 1;
    }
    return 0;
}
