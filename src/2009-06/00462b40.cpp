// from server: 100% by EspClaude
// roc 2009-06 00462b40  unit: Scintilla::CScintillaFindReplaceDlg  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00462b40
//
// 00462b40  56                   push esi
// 00462b41  6812040000           push 0x412
// 00462b46  8bf1                 mov esi, ecx
// 00462b48  e8af6d2b00           call 0x7198fc
// 00462b4d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00462b50  6a00                 push 0
// 00462b52  6a00                 push 0
// 00462b54  68f0000000           push 0xf0
// 00462b59  50                   push eax
// 00462b5a  ff1590ee8900         call dword ptr [0x89ee90]
// 00462b60  48                   dec eax
// 00462b61  f7d8                 neg eax
// 00462b63  1bc0                 sbb eax, eax
// 00462b65  40                   inc eax
// 00462b66  89869c010000         mov dword ptr [esi + 0x19c], eax
// 00462b6c  5e                   pop esi
// 00462b6d  c3                   ret 
// copied from an identical function in another client (function ?InitDialog@CScintillaFindReplaceDlg@ns_ROCX00006a@@QAEXXZ)

namespace ns_ROCX00006a {
struct CScintillaFindReplaceDlg {
    char pad[0x19c];
    int field_19c;
    void InitDialog();
};

extern "C" void* __stdcall sub_6a1418(int);
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

void CScintillaFindReplaceDlg::InitDialog()
{
    void* p = sub_6a1418(0x412);
    int h = *(int*)((char*)p + 0x20);
    long r = SendMessageA((void*)h, 0xf0, 0, 0);
    field_19c = (r != 1) ? 0 : 1;
}
}
