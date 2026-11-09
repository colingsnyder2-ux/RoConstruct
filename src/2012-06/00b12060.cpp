// roc 2012-06 00b12060  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12060
//
// 00b12060  a18c98e100           mov eax, dword ptr [0xe1988c]
// 00b12065  50                   push eax
// 00b12066  e8a900e7ff           call 0x982114
// 00b1206b  83c404               add esp, 4
// 00b1206e  c7056098e1002c3cb400 mov dword ptr [0xe19860], 0xb43c2c
// 00b12078  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12060(int);
void func_00b12060()
{
    G4_func_00b12060(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
