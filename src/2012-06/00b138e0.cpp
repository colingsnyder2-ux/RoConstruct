// roc 2012-06 00b138e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b138e0
//
// 00b138e0  a11c1ee200           mov eax, dword ptr [0xe21e1c]
// 00b138e5  50                   push eax
// 00b138e6  e829e8e6ff           call 0x982114
// 00b138eb  83c404               add esp, 4
// 00b138ee  c705f41de2002c3cb400 mov dword ptr [0xe21df4], 0xb43c2c
// 00b138f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b138e0(int);
void func_00b138e0()
{
    G4_func_00b138e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
