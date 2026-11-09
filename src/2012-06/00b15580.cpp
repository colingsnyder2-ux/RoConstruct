// roc 2012-06 00b15580  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15580
//
// 00b15580  a17095e200           mov eax, dword ptr [0xe29570]
// 00b15585  50                   push eax
// 00b15586  e889cbe6ff           call 0x982114
// 00b1558b  83c404               add esp, 4
// 00b1558e  c7054895e2002c3cb400 mov dword ptr [0xe29548], 0xb43c2c
// 00b15598  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15580(int);
void func_00b15580()
{
    G4_func_00b15580(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
