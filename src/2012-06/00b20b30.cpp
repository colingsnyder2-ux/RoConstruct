// roc 2012-06 00b20b30  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20b30
//
// 00b20b30  a1145de500           mov eax, dword ptr [0xe55d14]
// 00b20b35  50                   push eax
// 00b20b36  e8d915e6ff           call 0x982114
// 00b20b3b  83c404               add esp, 4
// 00b20b3e  c705ec5ce5002c3cb400 mov dword ptr [0xe55cec], 0xb43c2c
// 00b20b48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20b30(int);
void func_00b20b30()
{
    G4_func_00b20b30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
