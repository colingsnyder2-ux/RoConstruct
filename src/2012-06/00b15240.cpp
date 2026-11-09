// roc 2012-06 00b15240  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15240
//
// 00b15240  a1dc9ae200           mov eax, dword ptr [0xe29adc]
// 00b15245  50                   push eax
// 00b15246  e8c9cee6ff           call 0x982114
// 00b1524b  83c404               add esp, 4
// 00b1524e  c705b49ae2002c3cb400 mov dword ptr [0xe29ab4], 0xb43c2c
// 00b15258  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15240(int);
void func_00b15240()
{
    G4_func_00b15240(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
