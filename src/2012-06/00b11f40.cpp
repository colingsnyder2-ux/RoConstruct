// roc 2012-06 00b11f40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11f40
//
// 00b11f40  a14c99e100           mov eax, dword ptr [0xe1994c]
// 00b11f45  50                   push eax
// 00b11f46  e8c901e7ff           call 0x982114
// 00b11f4b  83c404               add esp, 4
// 00b11f4e  c7052099e1002c3cb400 mov dword ptr [0xe19920], 0xb43c2c
// 00b11f58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11f40(int);
void func_00b11f40()
{
    G4_func_00b11f40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
