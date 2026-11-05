// roc 2012-06 00b1f6c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f6c0
//
// 00b1f6c0  a1342ee500           mov eax, dword ptr [0xe52e34]
// 00b1f6c5  50                   push eax
// 00b1f6c6  e8492ae6ff           call 0x982114
// 00b1f6cb  83c404               add esp, 4
// 00b1f6ce  c7050c2ee5002c3cb400 mov dword ptr [0xe52e0c], 0xb43c2c
// 00b1f6d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f6c0(int);
void func_00b1f6c0()
{
    G4_func_00b1f6c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
