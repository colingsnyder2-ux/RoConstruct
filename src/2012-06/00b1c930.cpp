// roc 2012-06 00b1c930  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c930
//
// 00b1c930  a148d7e400           mov eax, dword ptr [0xe4d748]
// 00b1c935  50                   push eax
// 00b1c936  e8d957e6ff           call 0x982114
// 00b1c93b  83c404               add esp, 4
// 00b1c93e  c70520d7e4002c3cb400 mov dword ptr [0xe4d720], 0xb43c2c
// 00b1c948  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c930(int);
void func_00b1c930()
{
    G4_func_00b1c930(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
