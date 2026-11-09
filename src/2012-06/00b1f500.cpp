// roc 2012-06 00b1f500  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f500
//
// 00b1f500  a15c2be500           mov eax, dword ptr [0xe52b5c]
// 00b1f505  50                   push eax
// 00b1f506  e8092ce6ff           call 0x982114
// 00b1f50b  83c404               add esp, 4
// 00b1f50e  c705342be5002c3cb400 mov dword ptr [0xe52b34], 0xb43c2c
// 00b1f518  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f500(int);
void func_00b1f500()
{
    G4_func_00b1f500(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
