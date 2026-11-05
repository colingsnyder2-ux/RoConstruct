// from server: 96% by atomic.potato
struct VCEvent {
    char pad0[0x88];
    int field_88;
    char pad8c[0x98 - 0x8c];
    int field_98;
    int field_9c;
    int* sub_7fb710(int* out);
    void func();
};

void VCEvent::func() {
    int tmp[2];
    field_88 = 1;
    int* p = sub_7fb710(tmp);
    field_98 = p[0];
    field_9c = p[1];
}
