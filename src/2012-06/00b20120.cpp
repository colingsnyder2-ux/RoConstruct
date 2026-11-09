// roc 2012-06 00b20120  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20120
//
// 00b20120  a1c04ae500           mov eax, dword ptr [0xe54ac0]
// 00b20125  50                   push eax
// 00b20126  e8e91fe6ff           call 0x982114
// 00b2012b  83c404               add esp, 4
// 00b2012e  c705984ae5002c3cb400 mov dword ptr [0xe54a98], 0xb43c2c
// 00b20138  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20120(int);
void func_00b20120()
{
    G4_func_00b20120(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
