// roc 2012-06 00b1f4e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f4e0
//
// 00b1f4e0  a1942be500           mov eax, dword ptr [0xe52b94]
// 00b1f4e5  50                   push eax
// 00b1f4e6  e8292ce6ff           call 0x982114
// 00b1f4eb  83c404               add esp, 4
// 00b1f4ee  c7056c2be5002c3cb400 mov dword ptr [0xe52b6c], 0xb43c2c
// 00b1f4f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f4e0(int);
void func_00b1f4e0()
{
    G4_func_00b1f4e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
