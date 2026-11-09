// roc 2012-06 00b1c870  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c870
//
// 00b1c870  a140d6e400           mov eax, dword ptr [0xe4d640]
// 00b1c875  50                   push eax
// 00b1c876  e89958e6ff           call 0x982114
// 00b1c87b  83c404               add esp, 4
// 00b1c87e  c70514d6e4002c3cb400 mov dword ptr [0xe4d614], 0xb43c2c
// 00b1c888  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c870(int);
void func_00b1c870()
{
    G4_func_00b1c870(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
