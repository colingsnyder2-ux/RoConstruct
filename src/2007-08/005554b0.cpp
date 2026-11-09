// from server: 100% by colin
extern float G_7a8340;
extern float G_8c1e18;
extern float G_8c1e1c;
extern float G_8c1e20;
extern float G_8c1e24;
extern unsigned int G_8c1e28;

float* func_005554b0()
{
    if (!(G_8c1e28 & 1))
    {
        G_8c1e28 |= 1;
        G_8c1e18 = G_7a8340;
        G_8c1e1c = G_7a8340;
        G_8c1e20 = G_7a8340;
        G_8c1e24 = 1.0f;
    }
    return &G_8c1e18;
}
