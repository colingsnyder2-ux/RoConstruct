// roc 2012-06 00b14ce0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14ce0
//
// 00b14ce0  a1c89ce200           mov eax, dword ptr [0xe29cc8]
// 00b14ce5  50                   push eax
// 00b14ce6  e829d4e6ff           call 0x982114
// 00b14ceb  83c404               add esp, 4
// 00b14cee  c705a09ce2002c3cb400 mov dword ptr [0xe29ca0], 0xb43c2c
// 00b14cf8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14ce0(int);
void func_00b14ce0()
{
    G4_func_00b14ce0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
