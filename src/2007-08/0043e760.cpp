// from server: 54% by colin
extern "C" {
    int __stdcall sprintf(char* buffer, const char* format, ...);
    void* __stdcall unknown_77e968();
    void* __stdcall unknown_77ddb8();
    void __cdecl unknown_630a1e();
}

struct Vector3ComponentItem {
    char pad[0x11c];
    int field_0x11c;
    float field_0x120;
    float field_0x124;
    float field_0x128;
    void set(const float* src);
};

void Vector3ComponentItem::set(const float* src) {
    field_0x120 = src[0];
    field_0x124 = src[1];
    field_0x128 = src[2];
    int idx = field_0x11c;
    double val = (double)src[idx];
    char buffer[16];
    sprintf(buffer, "%.3g", val);
    unknown_77e968();
    unknown_77ddb8();
    void (__thiscall *fn)(Vector3ComponentItem*) = *(void (__thiscall **)(Vector3ComponentItem*))((*(char**)this) + 0x60);
    fn(this);
}
