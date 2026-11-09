// roc 2012-06 00b121c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b121c0
//
// 00b121c0  a1309be100           mov eax, dword ptr [0xe19b30]
// 00b121c5  50                   push eax
// 00b121c6  e849ffe6ff           call 0x982114
// 00b121cb  83c404               add esp, 4
// 00b121ce  c705089be1002c3cb400 mov dword ptr [0xe19b08], 0xb43c2c
// 00b121d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b121c0(int);
void func_00b121c0()
{
    G4_func_00b121c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
