// from server: 50% by atomic.potato
struct RBX_Decal {
    char pad[0xc8];
    float field_c8;
    void set(float value);
};

extern float g_b53ac8;
extern void __stdcall sub_414da0(const char* fmt, float value);

void RBX_Decal::set(float value) {
    if (field_c8 != value && value > g_b53ac8) {
        field_c8 = value;
        sub_414da0("%.4e", value);
    }
}
