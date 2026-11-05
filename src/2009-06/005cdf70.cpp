// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc 2009-06 005cdf70  unit: RBX::P8Instance::?$GetSetImpl  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005cdf70
//
// 005cdf70  56                   push esi
// 005cdf71  8b714c               mov esi, dword ptr [ecx + 0x4c]
// 005cdf74  85f6                 test esi, esi
// 005cdf76  7506                 jne 0x5cdf7e
// 005cdf78  33c0                 xor eax, eax
// 005cdf7a  5e                   pop esi
// 005cdf7b  c20400               ret 4
// 005cdf7e  8b4610               mov eax, dword ptr [esi + 0x10]
// 005cdf81  2b460c               sub eax, dword ptr [esi + 0xc]
// 005cdf84  53                   push ebx
// 005cdf85  55                   push ebp
// 005cdf86  57                   push edi
// 005cdf87  c1f803               sar eax, 3
// 005cdf8a  33ff                 xor edi, edi
// 005cdf8c  85c0                 test eax, eax
// 005cdf8e  7636                 jbe 0x5cdfc6
// 005cdf90  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005cdf94  8b2d44e48900         mov ebp, dword ptr [0x89e444]
// 005cdf9a  3bf8                 cmp edi, eax
// 005cdf9c  7206                 jb 0x5cdfa4
// 005cdf9e  ff15ace98900         call dword ptr [0x89e9ac]
// 005cdfa4  8b460c               mov eax, dword ptr [esi + 0xc]
// 005cdfa7  8b04f8               mov eax, dword ptr [eax + edi*8]
// 005cdfaa  83c054               add eax, 0x54
// 005cdfad  53                   push ebx
// 005cdfae  50                   push eax
// 005cdfaf  ffd5                 call ebp
// 005cdfb1  83c408               add esp, 8
// 005cdfb4  84c0                 test al, al
// 005cdfb6  7517                 jne 0x5cdfcf
// 005cdfb8  8b4610               mov eax, dword ptr [esi + 0x10]
// 005cdfbb  2b460c               sub eax, dword ptr [esi + 0xc]
// 005cdfbe  47                   inc edi
// 005cdfbf  c1f803               sar eax, 3
// 005cdfc2  3bf8                 cmp edi, eax
// 005cdfc4  72de                 jb 0x5cdfa4
// 005cdfc6  5f                   pop edi
// 005cdfc7  5d                   pop ebp
// 005cdfc8  5b                   pop ebx
// 005cdfc9  33c0                 xor eax, eax
// 005cdfcb  5e                   pop esi
// 005cdfcc  c20400               ret 4
// 005cdfcf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005cdfd2  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 005cdfd5  c1f903               sar ecx, 3
// 005cdfd8  3bf9                 cmp edi, ecx
// 005cdfda  7206                 jb 0x5cdfe2
// 005cdfdc  ff15ace98900         call dword ptr [0x89e9ac]
// 005cdfe2  8b560c               mov edx, dword ptr [esi + 0xc]
// 005cdfe5  8b04fa               mov eax, dword ptr [edx + edi*8]
// 005cdfe8  5f                   pop edi
// 005cdfe9  5d                   pop ebp
// 005cdfea  5b                   pop ebx
// 005cdfeb  5e                   pop esi
// 005cdfec  c20400               ret 4

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <string>
struct Instance {
    char padding[0x54];
    std::string name;
};
struct Ptr {
    Instance *px;
    void *pn;
};
struct S {
    char padding[0x4c];
    std::vector<Ptr> *children;
    Instance *f(const std::string &name);
};
Instance *S::f(const std::string &name)
{
    std::vector<Ptr> *p = children;
    if (!p)
        return 0;
    for (size_t i = 0; i < p->size(); ++i) {
        const std::string &childName = (*p)[i].px->name;
        if (childName == name)
            return (*p)[i].px;
    }
    return 0;
}
