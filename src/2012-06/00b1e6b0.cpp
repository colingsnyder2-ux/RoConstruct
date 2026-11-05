// roc 2012-06 00b1e6b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e6b0
//
// 00b1e6b0  a1f408e500           mov eax, dword ptr [0xe508f4]
// 00b1e6b5  50                   push eax
// 00b1e6b6  e8593ae6ff           call 0x982114
// 00b1e6bb  83c404               add esp, 4
// 00b1e6be  c705cc08e5002c3cb400 mov dword ptr [0xe508cc], 0xb43c2c
// 00b1e6c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e6b0(int);
void func_00b1e6b0()
{
    G4_func_00b1e6b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
