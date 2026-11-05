// roc 2012-06 00b184d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b184d0
//
// 00b184d0  a1a063e300           mov eax, dword ptr [0xe363a0]
// 00b184d5  50                   push eax
// 00b184d6  e8399ce6ff           call 0x982114
// 00b184db  83c404               add esp, 4
// 00b184de  c7057863e3002c3cb400 mov dword ptr [0xe36378], 0xb43c2c
// 00b184e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b184d0(int);
void func_00b184d0()
{
    G4_func_00b184d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
