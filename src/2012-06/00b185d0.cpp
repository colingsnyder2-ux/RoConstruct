// roc 2012-06 00b185d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b185d0
//
// 00b185d0  a1445ee300           mov eax, dword ptr [0xe35e44]
// 00b185d5  50                   push eax
// 00b185d6  e8399be6ff           call 0x982114
// 00b185db  83c404               add esp, 4
// 00b185de  c7051c5ee3002c3cb400 mov dword ptr [0xe35e1c], 0xb43c2c
// 00b185e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b185d0(int);
void func_00b185d0()
{
    G4_func_00b185d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
