// roc 2012-06 00b20450  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20450
//
// 00b20450  a1ac50e500           mov eax, dword ptr [0xe550ac]
// 00b20455  50                   push eax
// 00b20456  e8b91ce6ff           call 0x982114
// 00b2045b  83c404               add esp, 4
// 00b2045e  c7058450e5002c3cb400 mov dword ptr [0xe55084], 0xb43c2c
// 00b20468  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20450(int);
void func_00b20450()
{
    G4_func_00b20450(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
