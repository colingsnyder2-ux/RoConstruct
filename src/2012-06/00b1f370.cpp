// roc 2012-06 00b1f370  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f370
//
// 00b1f370  a10026e500           mov eax, dword ptr [0xe52600]
// 00b1f375  50                   push eax
// 00b1f376  e8992de6ff           call 0x982114
// 00b1f37b  83c404               add esp, 4
// 00b1f37e  c705d425e5002c3cb400 mov dword ptr [0xe525d4], 0xb43c2c
// 00b1f388  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f370(int);
void func_00b1f370()
{
    G4_func_00b1f370(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
