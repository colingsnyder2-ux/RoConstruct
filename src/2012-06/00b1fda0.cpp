// roc 2012-06 00b1fda0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fda0
//
// 00b1fda0  a13c3be500           mov eax, dword ptr [0xe53b3c]
// 00b1fda5  50                   push eax
// 00b1fda6  e86923e6ff           call 0x982114
// 00b1fdab  83c404               add esp, 4
// 00b1fdae  c705143be5002c3cb400 mov dword ptr [0xe53b14], 0xb43c2c
// 00b1fdb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fda0(int);
void func_00b1fda0()
{
    G4_func_00b1fda0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
