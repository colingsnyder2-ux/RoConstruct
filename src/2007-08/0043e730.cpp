// from server: 100% by colin
struct Vector3ComponentItem {
    char pad[0x11c];
    int field_0x11c;
    bool compare(const float* a, const float* b) const;
};

bool Vector3ComponentItem::compare(const float* a, const float* b) const {
    int idx = field_0x11c;
    idx += idx;
    idx += idx;
    float x = *(const float*)((const char*)a + idx);
    float y = *(const float*)((const char*)b + idx);
    return x == y;
}
