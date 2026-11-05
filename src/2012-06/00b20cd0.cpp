// roc 2012-06 00b20cd0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20cd0
//
// 00b20cd0  a1a061e500           mov eax, dword ptr [0xe561a0]
// 00b20cd5  50                   push eax
// 00b20cd6  e83914e6ff           call 0x982114
// 00b20cdb  83c404               add esp, 4
// 00b20cde  c7057461e5002c3cb400 mov dword ptr [0xe56174], 0xb43c2c
// 00b20ce8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20cd0(int);
void func_00b20cd0()
{
    G4_func_00b20cd0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
