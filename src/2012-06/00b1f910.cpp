// roc 2012-06 00b1f910  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f910
//
// 00b1f910  a18c32e500           mov eax, dword ptr [0xe5328c]
// 00b1f915  50                   push eax
// 00b1f916  e8f927e6ff           call 0x982114
// 00b1f91b  83c404               add esp, 4
// 00b1f91e  c7056432e5002c3cb400 mov dword ptr [0xe53264], 0xb43c2c
// 00b1f928  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f910(int);
void func_00b1f910()
{
    G4_func_00b1f910(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
