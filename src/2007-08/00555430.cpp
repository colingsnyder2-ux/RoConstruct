// from server: 100% by colin
// roc 2007-08 00555430  unit: RBX::VServiceProvider  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00555430

extern float g_7a0be0;
extern float g_797e9c;
extern float g_8c1df0;
extern float g_8c1df4;
extern float g_8c1df8;
extern float g_8c1dfc;
extern unsigned int g_8c1e00;

float* getVector()
{
    if (!(g_8c1e00 & 1)) {
        g_8c1e00 |= 1;
        g_8c1df0 = g_7a0be0;
        g_8c1df4 = g_7a0be0;
        g_8c1df8 = g_7a0be0;
        g_8c1dfc = g_797e9c;
    }
    return &g_8c1df0;
}
