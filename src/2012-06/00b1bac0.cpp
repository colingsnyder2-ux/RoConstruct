// roc 2012-06 00b1bac0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bac0
//
// 00b1bac0  a15ca0e400           mov eax, dword ptr [0xe4a05c]
// 00b1bac5  50                   push eax
// 00b1bac6  e84966e6ff           call 0x982114
// 00b1bacb  83c404               add esp, 4
// 00b1bace  c70530a0e4002c3cb400 mov dword ptr [0xe4a030], 0xb43c2c
// 00b1bad8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1bac0(int);
void func_00b1bac0()
{
    G4_func_00b1bac0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
