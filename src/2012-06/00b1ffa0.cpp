// roc 2012-06 00b1ffa0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ffa0
//
// 00b1ffa0  a1b849e500           mov eax, dword ptr [0xe549b8]
// 00b1ffa5  50                   push eax
// 00b1ffa6  e86921e6ff           call 0x982114
// 00b1ffab  83c404               add esp, 4
// 00b1ffae  c7059049e5002c3cb400 mov dword ptr [0xe54990], 0xb43c2c
// 00b1ffb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ffa0(int);
void func_00b1ffa0()
{
    G4_func_00b1ffa0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
