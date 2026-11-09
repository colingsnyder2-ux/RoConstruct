// roc 2012-06 00b17a80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17a80
//
// 00b17a80  a16434e300           mov eax, dword ptr [0xe33464]
// 00b17a85  50                   push eax
// 00b17a86  e889a6e6ff           call 0x982114
// 00b17a8b  83c404               add esp, 4
// 00b17a8e  c7053c34e3002c3cb400 mov dword ptr [0xe3343c], 0xb43c2c
// 00b17a98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17a80(int);
void func_00b17a80()
{
    G4_func_00b17a80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
