// roc 2012-06 00b12000  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12000
//
// 00b12000  a1a49ae100           mov eax, dword ptr [0xe19aa4]
// 00b12005  50                   push eax
// 00b12006  e80901e7ff           call 0x982114
// 00b1200b  83c404               add esp, 4
// 00b1200e  c7057c9ae1002c3cb400 mov dword ptr [0xe19a7c], 0xb43c2c
// 00b12018  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12000(int);
void func_00b12000()
{
    G4_func_00b12000(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
