// from server: 100% by colin
struct CRobloxControlColorSelector {
    char pad[0xfc];
    void* field_fc;
    char pad2[0x144 - 0xfc - 4];
    int field_144;
    int field_148;
    int field_14c;
    char pad3[0x170 - 0x14c - 4];
    int field_170;
    int get();
};

int CRobloxControlColorSelector::get() {
    int result = field_148;
    if (result == -1) {
        result = field_144;
        if (result == 0) {
            result = field_14c;
            if (result == 0) {
                void* p = field_fc;
                if (p != 0) {
                    result = *(int*)((char*)p + 0x170);
                }
            }
        }
    }
    return result;
}
