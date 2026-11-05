// roc 2012-06 00b1e0f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e0f0
//
// 00b1e0f0  a15cffe400           mov eax, dword ptr [0xe4ff5c]
// 00b1e0f5  50                   push eax
// 00b1e0f6  e81940e6ff           call 0x982114
// 00b1e0fb  83c404               add esp, 4
// 00b1e0fe  c70530ffe4002c3cb400 mov dword ptr [0xe4ff30], 0xb43c2c
// 00b1e108  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e0f0(int);
void func_00b1e0f0()
{
    G4_func_00b1e0f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
