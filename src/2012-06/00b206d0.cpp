// roc 2012-06 00b206d0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b206d0
//
// 00b206d0  a1e856e500           mov eax, dword ptr [0xe556e8]
// 00b206d5  50                   push eax
// 00b206d6  e8391ae6ff           call 0x982114
// 00b206db  83c404               add esp, 4
// 00b206de  c705bc56e5002c3cb400 mov dword ptr [0xe556bc], 0xb43c2c
// 00b206e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b206d0(int);
void func_00b206d0()
{
    G4_func_00b206d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
