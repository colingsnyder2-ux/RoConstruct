// roc 2012-06 00b1f160  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f160
//
// 00b1f160  a1d01fe500           mov eax, dword ptr [0xe51fd0]
// 00b1f165  50                   push eax
// 00b1f166  e8a92fe6ff           call 0x982114
// 00b1f16b  83c404               add esp, 4
// 00b1f16e  c705a81fe5002c3cb400 mov dword ptr [0xe51fa8], 0xb43c2c
// 00b1f178  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f160(int);
void func_00b1f160()
{
    G4_func_00b1f160(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
