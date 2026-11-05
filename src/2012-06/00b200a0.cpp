// roc 2012-06 00b200a0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b200a0
//
// 00b200a0  a1284ce500           mov eax, dword ptr [0xe54c28]
// 00b200a5  50                   push eax
// 00b200a6  e86920e6ff           call 0x982114
// 00b200ab  83c404               add esp, 4
// 00b200ae  c705004ce5002c3cb400 mov dword ptr [0xe54c00], 0xb43c2c
// 00b200b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b200a0(int);
void func_00b200a0()
{
    G4_func_00b200a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
