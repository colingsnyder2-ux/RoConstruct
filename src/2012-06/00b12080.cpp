// roc 2012-06 00b12080  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12080
//
// 00b12080  a11899e100           mov eax, dword ptr [0xe19918]
// 00b12085  50                   push eax
// 00b12086  e88900e7ff           call 0x982114
// 00b1208b  83c404               add esp, 4
// 00b1208e  c705ec98e1002c3cb400 mov dword ptr [0xe198ec], 0xb43c2c
// 00b12098  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12080(int);
void func_00b12080()
{
    G4_func_00b12080(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
