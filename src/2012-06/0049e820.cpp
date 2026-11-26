// from server: 100% by Xemicl
// roc 2012-06 0049e820  unit: Scintilla::CScintillaFindReplaceDlg  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049e820
//
// 0049e820  56                   push esi
// 0049e821  6812040000           push 0x412
// 0049e826  8bf1                 mov esi, ecx
// 0049e828  e8c3474e00           call 0x982ff0
// 0049e82d  8b4020               mov eax, dword ptr [eax + 0x20]
// 0049e830  6a00                 push 0
// 0049e832  6a00                 push 0
// 0049e834  68f0000000           push 0xf0
// 0049e839  50                   push eax
// 0049e83a  ff15043cb200         call dword ptr [0xb23c04]
// 0049e840  48                   dec eax
// 0049e841  f7d8                 neg eax
// 0049e843  1bc0                 sbb eax, eax
// 0049e845  40                   inc eax
// 0049e846  89869c010000         mov dword ptr [esi + 0x19c], eax
// 0049e84c  5e                   pop esi
// 0049e84d  c3                   ret 
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