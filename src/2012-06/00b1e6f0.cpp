// roc 2012-06 00b1e6f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e6f0
//
// 00b1e6f0  a19809e500           mov eax, dword ptr [0xe50998]
// 00b1e6f5  50                   push eax
// 00b1e6f6  e8193ae6ff           call 0x982114
// 00b1e6fb  83c404               add esp, 4
// 00b1e6fe  c7057009e5002c3cb400 mov dword ptr [0xe50970], 0xb43c2c
// 00b1e708  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e6f0(int);
void func_00b1e6f0()
{
    G4_func_00b1e6f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
