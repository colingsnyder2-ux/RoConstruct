// from server: 100% by colin
extern float G_7a0be0;
extern float G_8c1e2c;
extern float G_8c1e30;
extern float G_8c1e34;
extern float G_8c1e38;
extern unsigned int G_8c1e3c;

float* getValue()
{
    if (!(G_8c1e3c & 1))
    {
        G_8c1e3c |= 1;
        G_8c1e2c = G_7a0be0;
        G_8c1e30 = G_7a0be0;
        G_8c1e34 = G_7a0be0;
        G_8c1e38 = 1.0f;
    }
    return &G_8c1e2c;
}
