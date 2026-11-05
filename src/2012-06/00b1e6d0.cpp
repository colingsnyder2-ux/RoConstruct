// roc 2012-06 00b1e6d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e6d0
//
// 00b1e6d0  a16c09e500           mov eax, dword ptr [0xe5096c]
// 00b1e6d5  50                   push eax
// 00b1e6d6  e8393ae6ff           call 0x982114
// 00b1e6db  83c404               add esp, 4
// 00b1e6de  c7054409e5002c3cb400 mov dword ptr [0xe50944], 0xb43c2c
// 00b1e6e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e6d0(int);
void func_00b1e6d0()
{
    G4_func_00b1e6d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
