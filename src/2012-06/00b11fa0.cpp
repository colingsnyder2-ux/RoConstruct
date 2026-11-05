// roc 2012-06 00b11fa0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11fa0
//
// 00b11fa0  a1009de100           mov eax, dword ptr [0xe19d00]
// 00b11fa5  50                   push eax
// 00b11fa6  e86901e7ff           call 0x982114
// 00b11fab  83c404               add esp, 4
// 00b11fae  c705d49ce1002c3cb400 mov dword ptr [0xe19cd4], 0xb43c2c
// 00b11fb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11fa0(int);
void func_00b11fa0()
{
    G4_func_00b11fa0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
