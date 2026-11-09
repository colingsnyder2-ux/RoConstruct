// roc 2012-06 00b1d290  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d290
//
// 00b1d290  a1bce3e400           mov eax, dword ptr [0xe4e3bc]
// 00b1d295  50                   push eax
// 00b1d296  e8794ee6ff           call 0x982114
// 00b1d29b  83c404               add esp, 4
// 00b1d29e  c70594e3e4002c3cb400 mov dword ptr [0xe4e394], 0xb43c2c
// 00b1d2a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d290(int);
void func_00b1d290()
{
    G4_func_00b1d290(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
