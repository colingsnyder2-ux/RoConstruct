// from server: 55% by colin
struct Vector3 {
    float x, y, z;
};

struct Humanoid {
    char pad[0x134];
    int state;
    char pad2[0x14c - 0x138];
    float x;
    float y;
    float z;
    Vector3 getMoveDirection(Vector3* out);
};

extern float g_797988;
extern int g_8bd138;
extern float g_8bd12c;
extern float g_8bd130;
extern float g_8bd134;

extern "C" void* __stdcall sub_5a5c60();
extern "C" char __stdcall sub_5a4ac0();
extern "C" void* __stdcall sub_573f80();
extern "C" void* __stdcall sub_475020();
extern "C" void __stdcall sub_4e7df0();

Vector3 Humanoid::getMoveDirection(Vector3* out) {
    if (state == 3) {
        out->x = x;
        out->y = y;
        out->z = z;
        return *out;
    }
    if (state == 2) {
        void* p = sub_5a5c60();
        if (p) {
            Vector3 v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            if (sub_5a4ac0()) {
                void* q = sub_573f80();
                float dx = v.x - *(float*)((char*)q + 0x24);
                float dz = v.z - *(float*)((char*)q + 0x2c);
                float dist = dx * dx + dz * dz;
                if (dist > g_797988) {
                    state = 3;
                    void* r = sub_475020();
                    out->x = *(float*)r;
                    out->y = *(float*)((char*)r + 4);
                    out->z = *(float*)((char*)r + 8);
                    return *out;
                }
                sub_4e7df0();
                return *out;
            }
        }
    }
    if (!(g_8bd138 & 1)) {
        g_8bd138 |= 1;
        g_8bd12c = 0.0f;
        g_8bd130 = 0.0f;
        g_8bd134 = 0.0f;
    }
    out->x = g_8bd12c;
    out->y = g_8bd130;
    out->z = g_8bd134;
    return *out;
}
