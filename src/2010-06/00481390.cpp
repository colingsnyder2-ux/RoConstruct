// from server: 100% by Yeetserama
// roc 2010-06 00481390  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00481390
//
// 00481390  55                   push ebp
// 00481391  8bec                 mov ebp, esp
// 00481393  83e4f8               and esp, 0xfffffff8
// 00481396  6aff                 push -1
// 00481398  686e579800           push 0x98576e
// 0048139d  64a100000000         mov eax, dword ptr fs:[0]
// 004813a3  50                   push eax
// 004813a4  64892500000000       mov dword ptr fs:[0], esp
// 004813ab  83ec14               sub esp, 0x14
// 004813ae  53                   push ebx
// 004813af  55                   push ebp
// 004813b0  56                   push esi
// 004813b1  57                   push edi
// 004813b2  8be9                 mov ebp, ecx
// 004813b4  896c2414             mov dword ptr [esp + 0x14], ebp
// 004813b8  c74500a42ea100       mov dword ptr [ebp], 0xa12ea4
// 004813bf  8b4554               mov eax, dword ptr [ebp + 0x54]
// 004813c2  8b00                 mov eax, dword ptr [eax]
// 004813c4  8b753c               mov esi, dword ptr [ebp + 0x3c]
// 004813c7  8bd8                 mov ebx, eax
// 004813c9  c744242c03000000     mov dword ptr [esp + 0x2c], 3
// 004813d1  89742418             mov dword ptr [esp + 0x18], esi
// 004813d5  895c241c             mov dword ptr [esp + 0x1c], ebx
// 004813d9  8da42400000000       lea esp, [esp]
// 004813e0  8b7d54               mov edi, dword ptr [ebp + 0x54]
// 004813e3  8b453c               mov eax, dword ptr [ebp + 0x3c]
// 004813e6  85f6                 test esi, esi
// 004813e8  7404                 je 0x4813ee
// 004813ea  3bf0                 cmp esi, eax
// 004813ec  7406                 je 0x4813f4
// 004813ee  ff150ca99e00         call dword ptr [0x9ea90c]
// 004813f4  3bdf                 cmp ebx, edi
// 004813f6  743b                 je 0x481433
// 004813f8  85f6                 test esi, esi
// 004813fa  7533                 jne 0x48142f
// 004813fc  ff150ca99e00         call dword ptr [0x9ea90c]
// 00481402  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00481405  7506                 jne 0x48140d
// 00481407  ff150ca99e00         call dword ptr [0x9ea90c]
// 0048140d  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00481410  85c9                 test ecx, ecx
// 00481412  7408                 je 0x48141c
// 00481414  8b01                 mov eax, dword ptr [ecx]
// 00481416  8b10                 mov edx, dword ptr [eax]
// 00481418  6a01                 push 1
// 0048141a  ffd2                 call edx
// 0048141c  8d4c2418             lea ecx, [esp + 0x18]
// 00481420  e8bb652600           call 0x6e79e0
// 00481425  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00481429  8b742418             mov esi, dword ptr [esp + 0x18]
// 0048142d  ebb1                 jmp 0x4813e0
// 0048142f  8b36                 mov esi, dword ptr [esi]
// 00481431  ebcf                 jmp 0x481402
// 00481433  8b4574               mov eax, dword ptr [ebp + 0x74]
// 00481436  8b00                 mov eax, dword ptr [eax]
// 00481438  8b755c               mov esi, dword ptr [ebp + 0x5c]
// 0048143b  8d7d5c               lea edi, [ebp + 0x5c]
// 0048143e  8be8                 mov ebp, eax
// 00481440  89742418             mov dword ptr [esp + 0x18], esi
// 00481444  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00481448  8b5f18               mov ebx, dword ptr [edi + 0x18]
// 0048144b  8b07                 mov eax, dword ptr [edi]
// 0048144d  85f6                 test esi, esi
// 0048144f  7404                 je 0x481455
// 00481451  3bf0                 cmp esi, eax
// 00481453  7406                 je 0x48145b
// 00481455  ff150ca99e00         call dword ptr [0x9ea90c]
// 0048145b  3beb                 cmp ebp, ebx
// 0048145d  743b                 je 0x48149a
// 0048145f  85f6                 test esi, esi
// 00481461  7533                 jne 0x481496
// 00481463  ff150ca99e00         call dword ptr [0x9ea90c]
// 00481469  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 0048146c  7506                 jne 0x481474
// 0048146e  ff150ca99e00         call dword ptr [0x9ea90c]
// 00481474  8b4d28               mov ecx, dword ptr [ebp + 0x28]
// 00481477  85c9                 test ecx, ecx
// 00481479  7408                 je 0x481483
// 0048147b  8b01                 mov eax, dword ptr [ecx]
// 0048147d  8b10                 mov edx, dword ptr [eax]
// 0048147f  6a01                 push 1
// 00481481  ffd2                 call edx
// 00481483  8d4c2418             lea ecx, [esp + 0x18]
// 00481487  e8b44d4400           call 0x8c6240
// 0048148c  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00481490  8b742418             mov esi, dword ptr [esp + 0x18]
// 00481494  ebb2                 jmp 0x481448
// 00481496  8b36                 mov esi, dword ptr [esi]
// 00481498  ebcf                 jmp 0x481469
// 0048149a  8bcf                 mov ecx, edi
// 0048149c  c644242c02           mov byte ptr [esp + 0x2c], 2
// 004814a1  e81ac3ffff           call 0x47d7c0
// 004814a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004814aa  83c13c               add ecx, 0x3c
// 004814ad  c644242c01           mov byte ptr [esp + 0x2c], 1
// 004814b2  e8e97afeff           call 0x468fa0
// 004814b7  8b742414             mov esi, dword ptr [esp + 0x14]
// 004814bb  8d4e20               lea ecx, [esi + 0x20]
// 004814be  c644242c00           mov byte ptr [esp + 0x2c], 0
// 004814c3  ff1500a49e00         call dword ptr [0x9ea400]
// 004814c9  8d4e04               lea ecx, [esi + 4]
// 004814cc  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004814d4  ff1500a49e00         call dword ptr [0x9ea400]
// 004814da  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004814de  5f                   pop edi
// 004814df  64890d00000000       mov dword ptr fs:[0], ecx
// 004814e6  5e                   pop esi
// 004814e7  5d                   pop ebp
// 004814e8  5b                   pop ebx
// 004814e9  8be5                 mov esp, ebp
// 004814eb  5d                   pop ebp
// 004814ec  c3                   ret 
// copied from an identical function in another client (function ??1LDraw2RobloxColorMap@LDraw2Lua@RBX@@UAE@XZ)

// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) bstr(const bstr& r) { _Mysize = r._Mysize; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bool operator<(const bstr& r) const { return _Mysize < r._Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> Str;

namespace RBX {
namespace LDraw2Lua {

class Color {
public:
    virtual ~Color();
};

class LDraw2RobloxColorMap {
public:
    virtual ~LDraw2RobloxColorMap();
    Str name;
    Str fileName;
    std::map<int, Color*> colors;
    std::map<Str, Color*> namedColors;
};

LDraw2RobloxColorMap::~LDraw2RobloxColorMap()
{
    std::map<int, Color*>::iterator it;
    for (it = colors.begin(); it != colors.end(); ++it)
        delete it->second;
    std::map<Str, Color*>::iterator it2;
    for (it2 = namedColors.begin(); it2 != namedColors.end(); ++it2)
        delete it2->second;
}

}
}