// roc 2012-06 00b20020  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20020
//
// 00b20020  a1944ae500           mov eax, dword ptr [0xe54a94]
// 00b20025  50                   push eax
// 00b20026  e8e920e6ff           call 0x982114
// 00b2002b  83c404               add esp, 4
// 00b2002e  c7056c4ae5002c3cb400 mov dword ptr [0xe54a6c], 0xb43c2c
// 00b20038  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20020(int);
void func_00b20020()
{
    G4_func_00b20020(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
