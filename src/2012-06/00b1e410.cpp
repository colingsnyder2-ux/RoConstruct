// roc 2012-06 00b1e410  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e410
//
// 00b1e410  a18405e500           mov eax, dword ptr [0xe50584]
// 00b1e415  50                   push eax
// 00b1e416  e8f93ce6ff           call 0x982114
// 00b1e41b  83c404               add esp, 4
// 00b1e41e  c7055c05e5002c3cb400 mov dword ptr [0xe5055c], 0xb43c2c
// 00b1e428  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e410(int);
void func_00b1e410()
{
    G4_func_00b1e410(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
