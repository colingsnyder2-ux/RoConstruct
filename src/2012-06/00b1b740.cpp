// roc 2012-06 00b1b740  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b740
//
// 00b1b740  a13090e400           mov eax, dword ptr [0xe49030]
// 00b1b745  50                   push eax
// 00b1b746  e8c969e6ff           call 0x982114
// 00b1b74b  83c404               add esp, 4
// 00b1b74e  c7050890e4002c3cb400 mov dword ptr [0xe49008], 0xb43c2c
// 00b1b758  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1b740(int);
void func_00b1b740()
{
    G4_func_00b1b740(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
