// roc 2012-06 00b1d690  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d690
//
// 00b1d690  a1e8eae400           mov eax, dword ptr [0xe4eae8]
// 00b1d695  50                   push eax
// 00b1d696  e8794ae6ff           call 0x982114
// 00b1d69b  83c404               add esp, 4
// 00b1d69e  c705c0eae4002c3cb400 mov dword ptr [0xe4eac0], 0xb43c2c
// 00b1d6a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d690(int);
void func_00b1d690()
{
    G4_func_00b1d690(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
