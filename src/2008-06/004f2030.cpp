// from server: 100% by king_originala
#pragma float_control(precise, off)

extern "C" int (__cdecl *rand)();

extern const float g_826e3c;
const float g_826e40 = 1.0f / 32767.0f;
const float g_819bac = 0.5f;

struct S {
    float x;
    float y;
    bool b8;
    bool b9;
    S* init();
};

S* S::init()
{
    x = 0.0f;
    y = 0.0f;

    int (__cdecl *random)() = rand;

    float na = -g_826e3c;
    float a = g_826e3c;
    int r1 = random();
    x = na + (a - na) * (float)r1 * g_826e40;

    float nb = -g_826e3c;
    float b = g_826e3c;
    int r2 = random();
    y = nb + (b - nb) * (float)r2 * g_826e40;

    int r3 = random();
    b8 = (float)r3 * g_826e40 > g_819bac;

    int r4 = random();
    b9 = (float)r4 * g_826e40 > g_819bac;

    return this;
}
