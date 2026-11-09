// roc 2012-06 00b14090  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14090
//
// 00b14090  a1043ae200           mov eax, dword ptr [0xe23a04]
// 00b14095  50                   push eax
// 00b14096  e879e0e6ff           call 0x982114
// 00b1409b  83c404               add esp, 4
// 00b1409e  c705dc39e2002c3cb400 mov dword ptr [0xe239dc], 0xb43c2c
// 00b140a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14090(int);
void func_00b14090()
{
    G4_func_00b14090(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
