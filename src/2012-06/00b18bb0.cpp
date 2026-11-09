// roc 2012-06 00b18bb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18bb0
//
// 00b18bb0  a1b873e300           mov eax, dword ptr [0xe373b8]
// 00b18bb5  50                   push eax
// 00b18bb6  e85995e6ff           call 0x982114
// 00b18bbb  83c404               add esp, 4
// 00b18bbe  c7059073e3002c3cb400 mov dword ptr [0xe37390], 0xb43c2c
// 00b18bc8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18bb0(int);
void func_00b18bb0()
{
    G4_func_00b18bb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
