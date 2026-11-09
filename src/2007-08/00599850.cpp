// from server: 42% by colin
struct VCamera {
    char pad[0x150];
    float f150;
    float f154;
    float f158;
    char pad2[0x180 - 0x15C];
    float f180;
    float f184;
    float f188;

    bool sub_599480();
    bool func(float arg);
};

extern float g_787050;
extern float g_7b1548;

extern "C" void __stdcall sub_50f630(float* out, float* in, float v);
extern "C" float __cdecl sqrtf(float);

bool VCamera::func(float arg) {
    float dx = f180 - f150;
    float dy = f184 - f154;
    float dz = f188 - f158;

    float len = dx * dx + dy * dy + dz * dz;
    len = sqrtf(len);

    float a = g_787050;
    float b = g_7b1548;

    if (arg == len && a == len) {
        return false;
    }

    if (arg == a && b == len) {
        return false;
    }

    float t;
    if (arg != len) {
        t = arg;
    } else {
        t = a;
    }

    float s;
    if (t != b) {
        s = b;
    } else {
        s = a;
    }

    float v[3];
    v[0] = dx * s;
    v[1] = dy * s;
    v[2] = dz * s;

    float out[3];
    sub_50f630(out, v, t);

    f150 = f180 - out[0];
    f154 = f184 - out[1];
    f158 = f188 - out[2];

    if (sub_599480()) {
        return true;
    }
    return true;
}
