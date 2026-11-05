// roc 2012-06 00b12240  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12240
//
// 00b12240  a1149ce100           mov eax, dword ptr [0xe19c14]
// 00b12245  50                   push eax
// 00b12246  e8c9fee6ff           call 0x982114
// 00b1224b  83c404               add esp, 4
// 00b1224e  c705ec9be1002c3cb400 mov dword ptr [0xe19bec], 0xb43c2c
// 00b12258  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12240(int);
void func_00b12240()
{
    G4_func_00b12240(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
