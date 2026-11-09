// roc 2012-06 00b1f2f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f2f0
//
// 00b1f2f0  a13426e500           mov eax, dword ptr [0xe52634]
// 00b1f2f5  50                   push eax
// 00b1f2f6  e8192ee6ff           call 0x982114
// 00b1f2fb  83c404               add esp, 4
// 00b1f2fe  c7050826e5002c3cb400 mov dword ptr [0xe52608], 0xb43c2c
// 00b1f308  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f2f0(int);
void func_00b1f2f0()
{
    G4_func_00b1f2f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
