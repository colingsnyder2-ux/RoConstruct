// roc 2012-06 00b13130  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13130
//
// 00b13130  a19c07e200           mov eax, dword ptr [0xe2079c]
// 00b13135  50                   push eax
// 00b13136  e8d9efe6ff           call 0x982114
// 00b1313b  83c404               add esp, 4
// 00b1313e  c7057407e2002c3cb400 mov dword ptr [0xe20774], 0xb43c2c
// 00b13148  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13130(int);
void func_00b13130()
{
    G4_func_00b13130(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
