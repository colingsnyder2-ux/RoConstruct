// from server: 74% by colin
// roc 2007-08 00682260  unit: CXTPCompatibleDC  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00682260
//
// 00682260  7700                 ja 0x682262
// 00682262  e8bceafaff           call 0x630d23
// 00682267  83c404               add esp, 4
// 0068226a  b8588f8c00           mov eax, 0x8c8f58
// 0068226f  c3                   ret 

extern "C" void __cdecl sub_00630d23();
extern int G_008c8f58;

int func_00682260()
{
    sub_00630d23();
    return (int)&G_008c8f58;
}
