// from server: 100% by EspClaude
// roc 2009-06 004e90d0  unit: RBX::JointsService  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e90d0
//
// 004e90d0  64a100000000         mov eax, dword ptr fs:[0]
// 004e90d6  6aff                 push -1
// 004e90d8  68d9b88500           push 0x85b8d9
// 004e90dd  50                   push eax
// 004e90de  64892500000000       mov dword ptr fs:[0], esp
// 004e90e5  83ec24               sub esp, 0x24
// 004e90e8  53                   push ebx
// 004e90e9  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004e90ed  56                   push esi
// 004e90ee  57                   push edi
// 004e90ef  8d442440             lea eax, [esp + 0x40]
// 004e90f3  50                   push eax
// 004e90f4  53                   push ebx
// 004e90f5  8bf1                 mov esi, ecx
// 004e90f7  e80441ffff           call 0x4dd200
// 004e90fc  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004e9100  83c408               add esp, 8
// 004e9103  6a00                 push 0
// 004e9105  51                   push ecx
// 004e9106  8bce                 mov ecx, esi
// 004e9108  e8f3731900           call 0x680500
// 004e910d  33ff                 xor edi, edi
// 004e910f  397c2440             cmp dword ptr [esp + 0x40], edi
// 004e9113  7667                 jbe 0x4e917c
// 004e9115  8d54240c             lea edx, [esp + 0xc]
// 004e9119  52                   push edx
// 004e911a  53                   push ebx
// 004e911b  e86040ffff           call 0x4dd180
// 004e9120  83c408               add esp, 8
// 004e9123  8d4c2414             lea ecx, [esp + 0x14]
// 004e9127  ff15c0e48900         call dword ptr [0x89e4c0]
// 004e912d  8d442414             lea eax, [esp + 0x14]
// 004e9131  50                   push eax
// 004e9132  53                   push ebx
// 004e9133  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004e913b  e8e043ffff           call 0x4dd520
// 004e9140  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e9144  83c408               add esp, 8
// 004e9147  51                   push ecx
// 004e9148  83ec1c               sub esp, 0x1c
// 004e914b  8d542434             lea edx, [esp + 0x34]
// 004e914f  8bcc                 mov ecx, esp
// 004e9151  89642430             mov dword ptr [esp + 0x30], esp
// 004e9155  52                   push edx
// 004e9156  ff15b8e48900         call dword ptr [0x89e4b8]
// 004e915c  8bce                 mov ecx, esi
// 004e915e  e87d75ffff           call 0x4e06e0
// 004e9163  8d4c2414             lea ecx, [esp + 0x14]
// 004e9167  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004e916f  ff15c4e48900         call dword ptr [0x89e4c4]
// 004e9175  47                   inc edi
// 004e9176  3b7c2440             cmp edi, dword ptr [esp + 0x40]
// 004e917a  7299                 jb 0x4e9115
// 004e917c  8b4610               mov eax, dword ptr [esi + 0x10]
// 004e917f  2b460c               sub eax, dword ptr [esi + 0xc]
// 004e9182  83c9ff               or ecx, 0xffffffff
// 004e9185  c1f802               sar eax, 2
// 004e9188  85c0                 test eax, eax
// 004e918a  760b                 jbe 0x4e9197
// 004e918c  8d642400             lea esp, [esp]
// 004e9190  d1e8                 shr eax, 1
// 004e9192  41                   inc ecx
// 004e9193  85c0                 test eax, eax
// 004e9195  77f9                 ja 0x4e9190
// 004e9197  41                   inc ecx
// 004e9198  894e18               mov dword ptr [esi + 0x18], ecx
// 004e919b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004e919f  5f                   pop edi
// 004e91a0  5e                   pop esi
// 004e91a1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e91a8  5b                   pop ebx
// 004e91a9  83c430               add esp, 0x30
// 004e91ac  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000000_004b17f0@S@@QAEXI@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern void __cdecl read_count(unsigned int, unsigned int *);
extern void __cdecl read_key(unsigned int, unsigned int *);
extern void __cdecl read_string(unsigned int, std::string *);

struct S {
    unsigned char padding[12];
    unsigned int *begin;
    unsigned int *end;
    unsigned int *capacity;
    unsigned int bits;

    void reserve(unsigned int, unsigned int);
    void insert(std::string, unsigned int);
    void func_004b17f0(unsigned int);
};

void S::func_004b17f0(unsigned int count)
{
    unsigned int source = count;
    read_count(source, &count);
    reserve(count, 0);

    for (unsigned int i = 0; i < count; ++i) {
        unsigned int key;
        read_key(source, &key);
        std::string text;
        read_string(source, &text);
        insert(text, key);
    }

    unsigned int size = end - begin;
    unsigned int result = ~0u;
    while (size > 0) {
        size >>= 1;
        ++result;
    }
    bits = result + 1;
}