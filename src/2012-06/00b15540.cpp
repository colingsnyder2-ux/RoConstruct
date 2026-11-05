// roc 2012-06 00b15540  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15540
//
// 00b15540  a1c89fe200           mov eax, dword ptr [0xe29fc8]
// 00b15545  50                   push eax
// 00b15546  e8c9cbe6ff           call 0x982114
// 00b1554b  83c404               add esp, 4
// 00b1554e  c705a09fe2002c3cb400 mov dword ptr [0xe29fa0], 0xb43c2c
// 00b15558  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15540(int);
void func_00b15540()
{
    G4_func_00b15540(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
