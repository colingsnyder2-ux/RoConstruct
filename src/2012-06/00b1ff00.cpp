// roc 2012-06 00b1ff00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ff00
//
// 00b1ff00  a1604fe500           mov eax, dword ptr [0xe54f60]
// 00b1ff05  50                   push eax
// 00b1ff06  e80922e6ff           call 0x982114
// 00b1ff0b  83c404               add esp, 4
// 00b1ff0e  c705384fe5002c3cb400 mov dword ptr [0xe54f38], 0xb43c2c
// 00b1ff18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ff00(int);
void func_00b1ff00()
{
    G4_func_00b1ff00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
