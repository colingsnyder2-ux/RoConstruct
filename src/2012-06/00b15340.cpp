// roc 2012-06 00b15340  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15340
//
// 00b15340  a12c9ee200           mov eax, dword ptr [0xe29e2c]
// 00b15345  50                   push eax
// 00b15346  e8c9cde6ff           call 0x982114
// 00b1534b  83c404               add esp, 4
// 00b1534e  c705009ee2002c3cb400 mov dword ptr [0xe29e00], 0xb43c2c
// 00b15358  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15340(int);
void func_00b15340()
{
    G4_func_00b15340(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
