// roc 2012-06 00b14f40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14f40
//
// 00b14f40  a13899e200           mov eax, dword ptr [0xe29938]
// 00b14f45  50                   push eax
// 00b14f46  e8c9d1e6ff           call 0x982114
// 00b14f4b  83c404               add esp, 4
// 00b14f4e  c7051099e2002c3cb400 mov dword ptr [0xe29910], 0xb43c2c
// 00b14f58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14f40(int);
void func_00b14f40()
{
    G4_func_00b14f40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
