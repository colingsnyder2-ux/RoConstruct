// from server: 56% by colin
struct Vec3 { float x, y, z; };

struct Script {
    void* vtable;
    char pad[0xF8 - 4];
    char fieldF8[4];
};

extern "C" {
    void __cdecl sub_4E0180(float, float, float, float, float, float, float, float, float, float, float, float);
    float* __cdecl sub_50B190();
    float* __cdecl sub_50B200();
}

extern float g_7A8370;
extern float g_787050;
extern float g_797E9C;
extern double g_7BFE68;

struct P8Script {
    void GetSet(void* arg);
};

void P8Script::GetSet(void* arg)
{
    Script* self = (Script*)arg;
    void** vt = *(void***)self;
    float v0;
    ((void (__thiscall*)(void*, float*))vt[3])(self, &v0);

    float a = v0 + g_7A8370;
    float b = v0 + g_7A8370;
    float c = v0 + g_7A8370;

    float d = v0 + g_787050;
    float e = v0 + g_787050;
    float f = v0 + g_787050;

    float g = d * g_797E9C;
    float h = e * g_797E9C;
    float i = f * g_797E9C;

    sub_4E0180(a, b, c, g, h, i, a, b, c, g, h, i);

    void** vt2 = *(void***)self;
    void (__thiscall* fn28)(void*, float*, float*) = (void (__thiscall*)(void*, float*, float*))vt2[10];
    float p1, p2;
    fn28(self, &p1, &p2);

    float q1[4];
    float* r1 = sub_50B190();
    q1[0] = r1[0];
    q1[1] = r1[1];
    q1[2] = r1[2];
    q1[3] = 1.0f;

    float q2[4];
    float* r2 = sub_50B200();
    q2[0] = r2[0];
    q2[1] = r2[1];
    q2[2] = r2[2];
    q2[3] = 1.0f;

    void** vt3 = *(void***)self;
    void (__thiscall* fn30)(void*, float*, float*, int, int, double, float*, float*) =
        (void (__thiscall*)(void*, float*, float*, int, int, double, float*, float*))vt3[12];

    fn30(self, q1, q2, 2, 2, g_7BFE68, &p1, (float*)((char*)this + 0xF8));
}
