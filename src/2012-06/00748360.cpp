// from server: 45% by atomic.potato
struct Decal {
    char pad[0xcc];
    float field_cc;
    void set(float value);
};

extern float g_b53ac8;
extern char g_e35740;

void Decal::set(float value) {
    if (field_cc == value) {
        return;
    }
    if (value > g_b53ac8) {
        field_cc = value;
        g_e35740 = 0;
    }
}
