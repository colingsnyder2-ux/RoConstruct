// roc 2012-06 00b1d610  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d610
//
// 00b1d610  a150eae400           mov eax, dword ptr [0xe4ea50]
// 00b1d615  50                   push eax
// 00b1d616  e8f94ae6ff           call 0x982114
// 00b1d61b  83c404               add esp, 4
// 00b1d61e  c70528eae4002c3cb400 mov dword ptr [0xe4ea28], 0xb43c2c
// 00b1d628  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d610(int);
void func_00b1d610()
{
    G4_func_00b1d610(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
