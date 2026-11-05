// roc 2012-06 00b17c40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17c40
//
// 00b17c40  a1a839e300           mov eax, dword ptr [0xe339a8]
// 00b17c45  50                   push eax
// 00b17c46  e8c9a4e6ff           call 0x982114
// 00b17c4b  83c404               add esp, 4
// 00b17c4e  c7057c39e3002c3cb400 mov dword ptr [0xe3397c], 0xb43c2c
// 00b17c58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17c40(int);
void func_00b17c40()
{
    G4_func_00b17c40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
