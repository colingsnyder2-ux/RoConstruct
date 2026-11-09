// from server: 21% by atomic.potato
struct DirectPhysicsReceiver {
    char pad0[8];
    int field8;
    char pad1[12];
    float field18;
    int field1c;
    void sub_510340();
};

extern float g_a169bc;

void DirectPhysicsReceiver::sub_510340()
{
    int v = field8;
    float f = (float)v;
    if (v < 0)
        f += g_a169bc;
    f *= field18;
    field1c = -1;
    if (g_a169bc > f)
    {
        field1c = (int)f;
    }
}
