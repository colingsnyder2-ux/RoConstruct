// roc 2012-06 00b16c30  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16c30
//
// 00b16c30  a13cf3e200           mov eax, dword ptr [0xe2f33c]
// 00b16c35  50                   push eax
// 00b16c36  e8d9b4e6ff           call 0x982114
// 00b16c3b  83c404               add esp, 4
// 00b16c3e  c70514f3e2002c3cb400 mov dword ptr [0xe2f314], 0xb43c2c
// 00b16c48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16c30(int);
void func_00b16c30()
{
    G4_func_00b16c30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
