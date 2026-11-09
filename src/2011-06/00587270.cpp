// from server: 26% by atomic.potato
struct RBX_CRenderSettings {
    char pad[0x1b8];
    unsigned int field_1b8;
    unsigned int get(unsigned int index);
};

unsigned int RBX_CRenderSettings::get(unsigned int index) {
    unsigned int *p;
    if (index < field_1b8) {
        p = &index;
    } else {
        p = &field_1b8;
    }
    return *p;
}
