// from server: 100% by Xemicl
// roc 2012-06 0049e7e0  unit: Scintilla::CScintillaFindReplaceDlg  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049e7e0
//
// 0049e7e0  56                   push esi
// 0049e7e1  57                   push edi
// 0049e7e2  8bf1                 mov esi, ecx
// 0049e7e4  e819424e00           call 0x982a02
// 0049e7e9  6812040000           push 0x412
// 0049e7ee  8bce                 mov ecx, esi
// 0049e7f0  8bf8                 mov edi, eax
// 0049e7f2  e8f9474e00           call 0x982ff0
// 0049e7f7  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 0049e7fd  8b5020               mov edx, dword ptr [eax + 0x20]
// 0049e800  6a00                 push 0
// 0049e802  51                   push ecx
// 0049e803  68f1000000           push 0xf1
// 0049e808  52                   push edx
// 0049e809  ff15043cb200         call dword ptr [0xb23c04]
// 0049e80f  8bc7                 mov eax, edi
// 0049e811  5f                   pop edi
// 0049e812  5e                   pop esi
// 0049e813  c3                   ret 
// copied from an identical function in another client (function ?func@ScintillaFindReplaceDlg@ns_ROCX000015@@QAEPAXXZ)

namespace ns_ROCX000015 {
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct ScintillaFindReplaceDlg {
    char pad[0x19c];
    void* field_19c;
    void* method_71935c();
    void* method_7198fc(unsigned int);
    void* func();
};

void* ScintillaFindReplaceDlg::func()
{
    void* edi = method_71935c();
    void* eax = method_7198fc(0x412);
    SendMessageA(*(void**)((char*)eax + 0x20), 0xf1, (unsigned int)field_19c, 0);
    return edi;
}
}
