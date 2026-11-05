// roc 2012-06 00b179d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b179d0
//
// 00b179d0  a1b02de300           mov eax, dword ptr [0xe32db0]
// 00b179d5  50                   push eax
// 00b179d6  e839a7e6ff           call 0x982114
// 00b179db  83c404               add esp, 4
// 00b179de  c705882de3002c3cb400 mov dword ptr [0xe32d88], 0xb43c2c
// 00b179e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b179d0(int);
void func_00b179d0()
{
    G4_func_00b179d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
