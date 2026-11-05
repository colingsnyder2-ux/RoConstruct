// from server: 48% by atomic.potato
struct S
{
    char pad[12];
    float value;
};

float __fastcall func_007ab9a0(S* p, float x)
{
    extern float g_00b7cc38;
    return x + p->value * g_00b7cc38;
}
