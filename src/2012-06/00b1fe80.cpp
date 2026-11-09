// roc 2012-06 00b1fe80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fe80
//
// 00b1fe80  a12450e500           mov eax, dword ptr [0xe55024]
// 00b1fe85  50                   push eax
// 00b1fe86  e88922e6ff           call 0x982114
// 00b1fe8b  83c404               add esp, 4
// 00b1fe8e  c705f84fe5002c3cb400 mov dword ptr [0xe54ff8], 0xb43c2c
// 00b1fe98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fe80(int);
void func_00b1fe80()
{
    G4_func_00b1fe80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
