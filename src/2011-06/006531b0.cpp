// from server: 32% by atomic.potato
struct Decal {
    char pad[0xcc];
    float field_cc;
    void setSomething(float value);
};

extern float g_float_a690b4;
extern char g_str_ccd30c[];

void Decal::setSomething(float value) {
    if (field_cc == value) {
        return;
    }
    if (value > g_float_a690b4) {
        field_cc = value;
        g_str_ccd30c[0] = 0;
        // call to some function at 0x411f60
        extern void __cdecl someFunc(const char*, ...);
        someFunc("%.4e", value);
    }
}
