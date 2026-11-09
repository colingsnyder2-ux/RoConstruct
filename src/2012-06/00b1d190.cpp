// roc 2012-06 00b1d190  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d190
//
// 00b1d190  a18ce5e400           mov eax, dword ptr [0xe4e58c]
// 00b1d195  50                   push eax
// 00b1d196  e8794fe6ff           call 0x982114
// 00b1d19b  83c404               add esp, 4
// 00b1d19e  c70564e5e4002c3cb400 mov dword ptr [0xe4e564], 0xb43c2c
// 00b1d1a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d190(int);
void func_00b1d190()
{
    G4_func_00b1d190(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
