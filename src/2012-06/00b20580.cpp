// roc 2012-06 00b20580  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20580
//
// 00b20580  a13054e500           mov eax, dword ptr [0xe55430]
// 00b20585  50                   push eax
// 00b20586  e8891be6ff           call 0x982114
// 00b2058b  83c404               add esp, 4
// 00b2058e  c7050854e5002c3cb400 mov dword ptr [0xe55408], 0xb43c2c
// 00b20598  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20580(int);
void func_00b20580()
{
    G4_func_00b20580(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
