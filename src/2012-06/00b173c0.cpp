// roc 2012-06 00b173c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b173c0
//
// 00b173c0  a15417e300           mov eax, dword ptr [0xe31754]
// 00b173c5  50                   push eax
// 00b173c6  e849ade6ff           call 0x982114
// 00b173cb  83c404               add esp, 4
// 00b173ce  c7052c17e3002c3cb400 mov dword ptr [0xe3172c], 0xb43c2c
// 00b173d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b173c0(int);
void func_00b173c0()
{
    G4_func_00b173c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
