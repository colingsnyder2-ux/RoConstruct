// roc 2012-06 00b1eae0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1eae0
//
// 00b1eae0  a1c40de500           mov eax, dword ptr [0xe50dc4]
// 00b1eae5  50                   push eax
// 00b1eae6  e82936e6ff           call 0x982114
// 00b1eaeb  83c404               add esp, 4
// 00b1eaee  c7059c0de5002c3cb400 mov dword ptr [0xe50d9c], 0xb43c2c
// 00b1eaf8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1eae0(int);
void func_00b1eae0()
{
    G4_func_00b1eae0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
