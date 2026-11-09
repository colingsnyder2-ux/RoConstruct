// roc 2012-06 00b18a70  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18a70
//
// 00b18a70  a19470e300           mov eax, dword ptr [0xe37094]
// 00b18a75  50                   push eax
// 00b18a76  e89996e6ff           call 0x982114
// 00b18a7b  83c404               add esp, 4
// 00b18a7e  c7056c70e3002c3cb400 mov dword ptr [0xe3706c], 0xb43c2c
// 00b18a88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18a70(int);
void func_00b18a70()
{
    G4_func_00b18a70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
