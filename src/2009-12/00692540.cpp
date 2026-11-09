// from server: 18% by atomic.potato
struct S_func_00692540 {
    char pad[0x24];
    float x;
    float y;
    float z;
};

extern "C" void __stdcall G1_func_006aa8f0();
extern "C" void __stdcall G1_func_006cbd20();
extern "C" void __stdcall G1_func_005f49b0();
extern "C" void __stdcall G1_func_005f3900();

extern float g_b7cc20;
extern float g_b7cc24;
extern float g_b7cc28;
extern int g_b7cc2c;

S_func_00692540* __stdcall func_00692540(S_func_00692540* result, S_func_00692540* src)
{
    S_func_00692540 tmp;
    S_func_00692540* p = 0;
    G1_func_006aa8f0();
    if (p) {
        G1_func_006cbd20();
    } else {
        G1_func_005f49b0();
        G1_func_005f3900();
        if (!(g_b7cc2c & 1)) {
            g_b7cc2c |= 1;
            g_b7cc20 = 0.0f;
            g_b7cc24 = 0.0f;
            g_b7cc28 = 0.0f;
        }
        tmp.x = g_b7cc20;
        tmp.y = g_b7cc24;
        tmp.z = g_b7cc28;
        p = &tmp;
    }
    G1_func_005f3900();
    result->x = p->x;
    result->y = p->y;
    result->z = p->z;
    return result;
}
