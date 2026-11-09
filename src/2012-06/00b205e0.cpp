// roc 2012-06 00b205e0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b205e0
//
// 00b205e0  a16053e500           mov eax, dword ptr [0xe55360]
// 00b205e5  50                   push eax
// 00b205e6  e8291be6ff           call 0x982114
// 00b205eb  83c404               add esp, 4
// 00b205ee  c7053853e5002c3cb400 mov dword ptr [0xe55338], 0xb43c2c
// 00b205f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b205e0(int);
void func_00b205e0()
{
    G4_func_00b205e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
