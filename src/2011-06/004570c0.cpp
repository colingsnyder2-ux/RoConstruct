// from server: 49% by atomic.potato
struct CRenderSettings {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    int* items;
    bool get(unsigned int index, int* out);
};

bool CRenderSettings::get(unsigned int index, int* out) {
    if (index >= count) {
        return false;
    }
    int value = items[index];
    *out = value;
    return true;
}
