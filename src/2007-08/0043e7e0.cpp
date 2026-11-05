// from server: 42% by colin
struct Vector3ComponentItem {
    char pad[0x11c];
    int field_0x11c;
    float field_0x120;
    float field_0x124;
    float field_0x128;
    void method(float* out);
};

extern "C" {
    void* __stdcall sub_438E50(float* v);
    int __stdcall sub_580D70(void* a, void* b);
    void* __stdcall sub_77DD98();
    void __stdcall sub_77E698(void* a, void* b);
    void __stdcall sub_77E6AC(void* a);
    void __stdcall sub_77DDBC(void* a);
}

void Vector3ComponentItem::method(float* out) {
    float local[3];
    local[0] = field_0x120;
    local[1] = field_0x124;
    local[2] = field_0x128;

    void* p = sub_438E50(local);
    void* q = sub_77DD98();
    sub_77E698(&p, q);

    int idx = field_0x11c;
    int result = sub_580D70(&p, &local[idx]);
    sub_77E6AC(&p);
    sub_77DDBC(local);

    if (result) {
        out[0] = local[0];
        out[1] = local[1];
        out[2] = local[2];
    } else {
        out[0] = field_0x120;
        out[1] = field_0x124;
        out[2] = field_0x128;
    }
}
