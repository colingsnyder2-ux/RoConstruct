// from server: 31% by atomic.potato
struct ErrorCompPhysicsSender
{
    char pad[0x18];
    float f18;
    unsigned int u1c;
    int f(unsigned int);
};

extern float g_a64df0;
extern float g_a63b14;

int ErrorCompPhysicsSender::f(unsigned int a)
{
    if (a > u1c)
    {
        float v = (float)(int)a;
        if ((int)a < 0)
            v += g_a64df0;
        v /= f18;
        v += g_a63b14;
        if (g_a64df0 > v)
        {
            int r = (int)v;
            return ((int (__fastcall *)(void *, int))0x519ad0)(this, r);
        }
        return ((int (__fastcall *)(void *, int))0x519ad0)(this, -1);
    }
    return 0;
}
