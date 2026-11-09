// from server: 50% by atomic.potato
struct Decal {
    char pad[0xd4];
    float field_d4;
    void set(float value);
};

extern float g_limit;
extern char g_format[];
extern void __stdcall report(const char* fmt, float value);

void Decal::set(float value) {
    if (field_d4 == value) {
        return;
    }
    if (value <= g_limit) {
        return;
    }
    field_d4 = value;
    report(g_format, value);
}
