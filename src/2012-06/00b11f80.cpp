// roc 2012-06 00b11f80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11f80
//
// 00b11f80  a1489ae100           mov eax, dword ptr [0xe19a48]
// 00b11f85  50                   push eax
// 00b11f86  e88901e7ff           call 0x982114
// 00b11f8b  83c404               add esp, 4
// 00b11f8e  c7051c9ae1002c3cb400 mov dword ptr [0xe19a1c], 0xb43c2c
// 00b11f98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11f80(int);
void func_00b11f80()
{
    G4_func_00b11f80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
