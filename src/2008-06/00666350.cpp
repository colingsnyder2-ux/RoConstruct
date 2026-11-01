// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 00666350  unit: RBX::PartDragTool  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00666350
//
// 00666350  b801000000           mov eax, 1
// 00666355  840574d99700         test byte ptr [0x97d974], al
// 0066635b  7524                 jne 0x666381

struct S_func_00666350 {
    float f0;
    float f1;
    float f2;
    void __cdecl f(float* out);
};

static int g_init_97d974;
static float g_97d968;
static float g_97d96c;
static float g_97d970;
extern float g_819dcc;
extern float g_82746c;

void __cdecl S_func_00666350::f(float* out)
{
    if (!(g_init_97d974 & 1)) {
        g_init_97d974 |= 1;
        g_97d968 = g_819dcc;
        g_97d96c = g_82746c;
        g_97d970 = g_819dcc;
    }
    f0 = g_97d968;
    f1 = g_97d96c;
    f2 = g_97d970;
}
