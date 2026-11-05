// roc 2012-06 00b20c90  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20c90
//
// 00b20c90  a1c860e500           mov eax, dword ptr [0xe560c8]
// 00b20c95  50                   push eax
// 00b20c96  e87914e6ff           call 0x982114
// 00b20c9b  83c404               add esp, 4
// 00b20c9e  c705a060e5002c3cb400 mov dword ptr [0xe560a0], 0xb43c2c
// 00b20ca8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20c90(int);
void func_00b20c90()
{
    G4_func_00b20c90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
