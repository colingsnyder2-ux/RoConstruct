// roc 2012-06 00b1fdc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fdc0
//
// 00b1fdc0  a1683be500           mov eax, dword ptr [0xe53b68]
// 00b1fdc5  50                   push eax
// 00b1fdc6  e84923e6ff           call 0x982114
// 00b1fdcb  83c404               add esp, 4
// 00b1fdce  c705403be5002c3cb400 mov dword ptr [0xe53b40], 0xb43c2c
// 00b1fdd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fdc0(int);
void func_00b1fdc0()
{
    G4_func_00b1fdc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
