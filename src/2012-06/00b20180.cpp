// roc 2012-06 00b20180  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20180
//
// 00b20180  a14c4de500           mov eax, dword ptr [0xe54d4c]
// 00b20185  50                   push eax
// 00b20186  e8891fe6ff           call 0x982114
// 00b2018b  83c404               add esp, 4
// 00b2018e  c705244de5002c3cb400 mov dword ptr [0xe54d24], 0xb43c2c
// 00b20198  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20180(int);
void func_00b20180()
{
    G4_func_00b20180(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
