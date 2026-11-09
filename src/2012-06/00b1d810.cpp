// roc 2012-06 00b1d810  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d810
//
// 00b1d810  a114ebe400           mov eax, dword ptr [0xe4eb14]
// 00b1d815  50                   push eax
// 00b1d816  e8f948e6ff           call 0x982114
// 00b1d81b  83c404               add esp, 4
// 00b1d81e  c705eceae4002c3cb400 mov dword ptr [0xe4eaec], 0xb43c2c
// 00b1d828  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d810(int);
void func_00b1d810()
{
    G4_func_00b1d810(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
