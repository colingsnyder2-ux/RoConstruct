// roc 2012-06 00b20af0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20af0
//
// 00b20af0  a1cc5de500           mov eax, dword ptr [0xe55dcc]
// 00b20af5  50                   push eax
// 00b20af6  e81916e6ff           call 0x982114
// 00b20afb  83c404               add esp, 4
// 00b20afe  c705a45de5002c3cb400 mov dword ptr [0xe55da4], 0xb43c2c
// 00b20b08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20af0(int);
void func_00b20af0()
{
    G4_func_00b20af0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
