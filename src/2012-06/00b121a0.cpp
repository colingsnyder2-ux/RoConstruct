// roc 2012-06 00b121a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b121a0
//
// 00b121a0  a1689de100           mov eax, dword ptr [0xe19d68]
// 00b121a5  50                   push eax
// 00b121a6  e869ffe6ff           call 0x982114
// 00b121ab  83c404               add esp, 4
// 00b121ae  c7053c9de1002c3cb400 mov dword ptr [0xe19d3c], 0xb43c2c
// 00b121b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b121a0(int);
void func_00b121a0()
{
    G4_func_00b121a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
