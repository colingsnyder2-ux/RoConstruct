// roc 2012-06 00b1c810  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c810
//
// 00b1c810  a1b8d7e400           mov eax, dword ptr [0xe4d7b8]
// 00b1c815  50                   push eax
// 00b1c816  e8f958e6ff           call 0x982114
// 00b1c81b  83c404               add esp, 4
// 00b1c81e  c70590d7e4002c3cb400 mov dword ptr [0xe4d790], 0xb43c2c
// 00b1c828  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c810(int);
void func_00b1c810()
{
    G4_func_00b1c810(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
