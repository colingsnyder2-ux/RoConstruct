// roc 2012-06 00b1e0d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e0d0
//
// 00b1e0d0  a18001e500           mov eax, dword ptr [0xe50180]
// 00b1e0d5  50                   push eax
// 00b1e0d6  e83940e6ff           call 0x982114
// 00b1e0db  83c404               add esp, 4
// 00b1e0de  c7055801e5002c3cb400 mov dword ptr [0xe50158], 0xb43c2c
// 00b1e0e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e0d0(int);
void func_00b1e0d0()
{
    G4_func_00b1e0d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
