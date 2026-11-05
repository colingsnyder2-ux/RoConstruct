// roc 2012-06 00b1f080  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f080
//
// 00b1f080  a15420e500           mov eax, dword ptr [0xe52054]
// 00b1f085  50                   push eax
// 00b1f086  e88930e6ff           call 0x982114
// 00b1f08b  83c404               add esp, 4
// 00b1f08e  c7052c20e5002c3cb400 mov dword ptr [0xe5202c], 0xb43c2c
// 00b1f098  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f080(int);
void func_00b1f080()
{
    G4_func_00b1f080(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
