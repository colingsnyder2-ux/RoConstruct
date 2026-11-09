// roc 2012-06 00b11fe0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11fe0
//
// 00b11fe0  a1e49be100           mov eax, dword ptr [0xe19be4]
// 00b11fe5  50                   push eax
// 00b11fe6  e82901e7ff           call 0x982114
// 00b11feb  83c404               add esp, 4
// 00b11fee  c705b89be1002c3cb400 mov dword ptr [0xe19bb8], 0xb43c2c
// 00b11ff8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11fe0(int);
void func_00b11fe0()
{
    G4_func_00b11fe0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
