// roc 2012-06 00b1d930  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d930
//
// 00b1d930  a1b8ece400           mov eax, dword ptr [0xe4ecb8]
// 00b1d935  50                   push eax
// 00b1d936  e8d947e6ff           call 0x982114
// 00b1d93b  83c404               add esp, 4
// 00b1d93e  c70590ece4002c3cb400 mov dword ptr [0xe4ec90], 0xb43c2c
// 00b1d948  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d930(int);
void func_00b1d930()
{
    G4_func_00b1d930(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
