// roc 2012-06 00b120a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b120a0
//
// 00b120a0  a1ac99e100           mov eax, dword ptr [0xe199ac]
// 00b120a5  50                   push eax
// 00b120a6  e86900e7ff           call 0x982114
// 00b120ab  83c404               add esp, 4
// 00b120ae  c7058099e1002c3cb400 mov dword ptr [0xe19980], 0xb43c2c
// 00b120b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b120a0(int);
void func_00b120a0()
{
    G4_func_00b120a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
