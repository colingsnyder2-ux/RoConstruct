// from server: 51% by atomic.potato
struct RBX_Decal {
    char pad[0xc0];
    float field_c0;
    void set(float value);
};

extern float g_b53ac8;
extern char g_e356e8;

void RBX_Decal::set(float value) {
    if (field_c0 == value) {
        return;
    }
    if (value > g_b53ac8) {
        field_c0 = value;
        g_e356e8 = 0;
        ((void (__stdcall *)(char *))0x414da0)(&g_e356e8);
    }
}
