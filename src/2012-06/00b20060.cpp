// roc 2012-06 00b20060  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20060
//
// 00b20060  a16c4ee500           mov eax, dword ptr [0xe54e6c]
// 00b20065  50                   push eax
// 00b20066  e8a920e6ff           call 0x982114
// 00b2006b  83c404               add esp, 4
// 00b2006e  c705444ee5002c3cb400 mov dword ptr [0xe54e44], 0xb43c2c
// 00b20078  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20060(int);
void func_00b20060()
{
    G4_func_00b20060(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
