// from server: 100% by colin
// roc 2007-08 00555530  unit: RBX::VServiceProvider  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00555530

extern float g_7a8340;
extern float g_8c1e40;
extern float g_8c1e44;
extern float g_8c1e48;
extern float g_8c1e4c;
extern unsigned int g_8c1e50;

float* GetRelativePanelVector()
{
    if (!(g_8c1e50 & 1)) {
        g_8c1e50 |= 1;
        g_8c1e40 = g_7a8340;
        g_8c1e44 = g_7a8340;
        g_8c1e48 = g_7a8340;
        g_8c1e4c = g_7a8340;
    }
    return &g_8c1e40;
}
