// from server: 44% by atomic.potato
struct RBX_Decal {
    char pad[0xbc];
    float field_bc;
    void setSomething(float value);
};

extern float g_b53ac8;
extern void (__stdcall *g_e35690)(float);

void RBX_Decal::setSomething(float value)
{
    if (field_bc == value)
        return;
    if (value < g_b53ac8)
        return;
    field_bc = value;
    g_e35690(value);
}
