// from server: 50% by atomic.potato
struct VSmoke {
    char pad[0xa8];
    float field_a8;
    void sub_411f60(const char*);
    void set(float);
};

void VSmoke::set(float v) {
    if (field_a8 != v) {
        sub_411f60((const char*)0xcd36d8);
        field_a8 = v;
        sub_411f60((const char*)0xcd3760);
    }
}
