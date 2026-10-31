// from server: 100% by EspClaude
// roc 2009-06 00470ff0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00470ff0
//
// 00470ff0  55                   push ebp
// 00470ff1  8bec                 mov ebp, esp
// 00470ff3  83e4f8               and esp, 0xfffffff8
// 00470ff6  6aff                 push -1
// 00470ff8  68ee3a8500           push 0x853aee
// 00470ffd  64a100000000         mov eax, dword ptr fs:[0]
// 00471003  50                   push eax
// 00471004  64892500000000       mov dword ptr fs:[0], esp
// 0047100b  83ec14               sub esp, 0x14
// 0047100e  53                   push ebx
// 0047100f  55                   push ebp
// 00471010  56                   push esi
// 00471011  57                   push edi
// 00471012  8be9                 mov ebp, ecx
// 00471014  896c2414             mov dword ptr [esp + 0x14], ebp
// 00471018  c745006cd88b00       mov dword ptr [ebp], 0x8bd86c
// 0047101f  8b4554               mov eax, dword ptr [ebp + 0x54]
// 00471022  8b00                 mov eax, dword ptr [eax]
// 00471024  8b753c               mov esi, dword ptr [ebp + 0x3c]
// 00471027  8bd8                 mov ebx, eax
// 00471029  c744242c03000000     mov dword ptr [esp + 0x2c], 3
// 00471031  89742418             mov dword ptr [esp + 0x18], esi
// 00471035  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00471039  8da42400000000       lea esp, [esp]
// 00471040  8b7d54               mov edi, dword ptr [ebp + 0x54]
// 00471043  8b453c               mov eax, dword ptr [ebp + 0x3c]
// 00471046  85f6                 test esi, esi
// 00471048  7404                 je 0x47104e
// 0047104a  3bf0                 cmp esi, eax
// 0047104c  7406                 je 0x471054
// 0047104e  ff15ace98900         call dword ptr [0x89e9ac]
// 00471054  3bdf                 cmp ebx, edi
// 00471056  743b                 je 0x471093
// 00471058  85f6                 test esi, esi
// 0047105a  7533                 jne 0x47108f
// 0047105c  ff15ace98900         call dword ptr [0x89e9ac]
// 00471062  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00471065  7506                 jne 0x47106d
// 00471067  ff15ace98900         call dword ptr [0x89e9ac]
// 0047106d  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00471070  85c9                 test ecx, ecx
// 00471072  7408                 je 0x47107c
// 00471074  8b01                 mov eax, dword ptr [ecx]
// 00471076  8b10                 mov edx, dword ptr [eax]
// 00471078  6a01                 push 1
// 0047107a  ffd2                 call edx
// 0047107c  8d4c2418             lea ecx, [esp + 0x18]
// 00471080  e8eb801700           call 0x5e9170
// 00471085  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00471089  8b742418             mov esi, dword ptr [esp + 0x18]
// 0047108d  ebb1                 jmp 0x471040
// 0047108f  8b36                 mov esi, dword ptr [esi]
// 00471091  ebcf                 jmp 0x471062
// 00471093  8b4574               mov eax, dword ptr [ebp + 0x74]
// 00471096  8b00                 mov eax, dword ptr [eax]
// 00471098  8b755c               mov esi, dword ptr [ebp + 0x5c]
// 0047109b  8d7d5c               lea edi, [ebp + 0x5c]
// 0047109e  8be8                 mov ebp, eax
// 004710a0  89742418             mov dword ptr [esp + 0x18], esi
// 004710a4  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004710a8  8b5f18               mov ebx, dword ptr [edi + 0x18]
// 004710ab  8b07                 mov eax, dword ptr [edi]
// 004710ad  85f6                 test esi, esi
// 004710af  7404                 je 0x4710b5
// 004710b1  3bf0                 cmp esi, eax
// 004710b3  7406                 je 0x4710bb
// 004710b5  ff15ace98900         call dword ptr [0x89e9ac]
// 004710bb  3beb                 cmp ebp, ebx
// 004710bd  743b                 je 0x4710fa
// 004710bf  85f6                 test esi, esi
// 004710c1  7533                 jne 0x4710f6
// 004710c3  ff15ace98900         call dword ptr [0x89e9ac]
// 004710c9  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 004710cc  7506                 jne 0x4710d4
// 004710ce  ff15ace98900         call dword ptr [0x89e9ac]
// 004710d4  8b4d28               mov ecx, dword ptr [ebp + 0x28]
// 004710d7  85c9                 test ecx, ecx
// 004710d9  7408                 je 0x4710e3
// 004710db  8b01                 mov eax, dword ptr [ecx]
// 004710dd  8b10                 mov edx, dword ptr [eax]
// 004710df  6a01                 push 1
// 004710e1  ffd2                 call edx
// 004710e3  8d4c2418             lea ecx, [esp + 0x18]
// 004710e7  e824d91c00           call 0x63ea10
// 004710ec  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004710f0  8b742418             mov esi, dword ptr [esp + 0x18]
// 004710f4  ebb2                 jmp 0x4710a8
// 004710f6  8b36                 mov esi, dword ptr [esi]
// 004710f8  ebcf                 jmp 0x4710c9
// 004710fa  8bcf                 mov ecx, edi
// 004710fc  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00471101  e8fac31500           call 0x5cd500
// 00471106  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047110a  83c13c               add ecx, 0x3c
// 0047110d  c644242c01           mov byte ptr [esp + 0x2c], 1
// 00471112  e8c9911700           call 0x5ea2e0
// 00471117  8b742414             mov esi, dword ptr [esp + 0x14]
// 0047111b  8d4e20               lea ecx, [esi + 0x20]
// 0047111e  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00471123  ff15c4e48900         call dword ptr [0x89e4c4]
// 00471129  8d4e04               lea ecx, [esi + 4]
// 0047112c  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00471134  ff15c4e48900         call dword ptr [0x89e4c4]
// 0047113a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0047113e  5f                   pop edi
// 0047113f  64890d00000000       mov dword ptr fs:[0], ecx
// 00471146  5e                   pop esi
// 00471147  5d                   pop ebp
// 00471148  5b                   pop ebx
// 00471149  8be5                 mov esp, ebp
// 0047114b  5d                   pop ebp
// 0047114c  c3                   ret 
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