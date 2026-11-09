// roc 2012-06 00b1d870  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d870
//
// 00b1d870  a120eee400           mov eax, dword ptr [0xe4ee20]
// 00b1d875  50                   push eax
// 00b1d876  e89948e6ff           call 0x982114
// 00b1d87b  83c404               add esp, 4
// 00b1d87e  c705f8ede4002c3cb400 mov dword ptr [0xe4edf8], 0xb43c2c
// 00b1d888  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d870(int);
void func_00b1d870()
{
    G4_func_00b1d870(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
