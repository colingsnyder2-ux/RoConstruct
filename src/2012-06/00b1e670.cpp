// roc 2012-06 00b1e670  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e670
//
// 00b1e670  a1c808e500           mov eax, dword ptr [0xe508c8]
// 00b1e675  50                   push eax
// 00b1e676  e8993ae6ff           call 0x982114
// 00b1e67b  83c404               add esp, 4
// 00b1e67e  c705a008e5002c3cb400 mov dword ptr [0xe508a0], 0xb43c2c
// 00b1e688  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e670(int);
void func_00b1e670()
{
    G4_func_00b1e670(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
