// roc 2012-06 00b20ad0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20ad0
//
// 00b20ad0  a1a05de500           mov eax, dword ptr [0xe55da0]
// 00b20ad5  50                   push eax
// 00b20ad6  e83916e6ff           call 0x982114
// 00b20adb  83c404               add esp, 4
// 00b20ade  c705745de5002c3cb400 mov dword ptr [0xe55d74], 0xb43c2c
// 00b20ae8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20ad0(int);
void func_00b20ad0()
{
    G4_func_00b20ad0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
