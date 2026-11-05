// roc 2012-06 00b20800  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20800
//
// 00b20800  a1f058e500           mov eax, dword ptr [0xe558f0]
// 00b20805  50                   push eax
// 00b20806  e80919e6ff           call 0x982114
// 00b2080b  83c404               add esp, 4
// 00b2080e  c705c858e5002c3cb400 mov dword ptr [0xe558c8], 0xb43c2c
// 00b20818  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20800(int);
void func_00b20800()
{
    G4_func_00b20800(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
