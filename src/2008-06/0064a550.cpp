// from server: 100% by colin




struct CleanStage {
    char pad[0xe0];
    int field_e0;
    char pad2[0x100 - 0xe0 - 4];
    int field_100;
    char pad3[0x120 - 0x100 - 4];
    int field_120;
    char pad4[0x140 - 0x120 - 4];
    int field_140;
    char pad5[0x160 - 0x140 - 4];
    int field_160;
    char pad6[0x180 - 0x160 - 4];
    int field_180;

    int* get(int index);
};

int* CleanStage::get(int index) {
    switch (index) {
    case 1: return &field_e0;
    case 2: return &field_100;
    case 3: return &field_120;
    case 4: return &field_140;
    case 5: return &field_160;
    case 6: return &field_180;
    default: return &field_120;
    }
}
