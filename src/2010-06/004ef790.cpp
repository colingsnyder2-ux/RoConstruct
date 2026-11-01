// from server: 100% by Yeetserama
// roc 2010-06 004ef790  unit: RBX::Network::Replicator::EventInvocationItem  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ef790
//
// 004ef790  64a100000000         mov eax, dword ptr fs:[0]
// 004ef796  6aff                 push -1
// 004ef798  68095b9800           push 0x985b09
// 004ef79d  50                   push eax
// 004ef79e  64892500000000       mov dword ptr fs:[0], esp
// 004ef7a5  83ec24               sub esp, 0x24
// 004ef7a8  53                   push ebx
// 004ef7a9  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004ef7ad  56                   push esi
// 004ef7ae  57                   push edi
// 004ef7af  8d442440             lea eax, [esp + 0x40]
// 004ef7b3  50                   push eax
// 004ef7b4  53                   push ebx
// 004ef7b5  8bf1                 mov esi, ecx
// 004ef7b7  e81419ffff           call 0x4e10d0
// 004ef7bc  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004ef7c0  83c408               add esp, 8
// 004ef7c3  6a00                 push 0
// 004ef7c5  51                   push ecx
// 004ef7c6  8bce                 mov ecx, esi
// 004ef7c8  e8b38b1600           call 0x658380
// 004ef7cd  33ff                 xor edi, edi
// 004ef7cf  397c2440             cmp dword ptr [esp + 0x40], edi
// 004ef7d3  7667                 jbe 0x4ef83c
// 004ef7d5  8d54240c             lea edx, [esp + 0xc]
// 004ef7d9  52                   push edx
// 004ef7da  53                   push ebx
// 004ef7db  e87018ffff           call 0x4e1050
// 004ef7e0  83c408               add esp, 8
// 004ef7e3  8d4c2414             lea ecx, [esp + 0x14]
// 004ef7e7  ff1504a49e00         call dword ptr [0x9ea404]
// 004ef7ed  8d442414             lea eax, [esp + 0x14]
// 004ef7f1  50                   push eax
// 004ef7f2  53                   push ebx
// 004ef7f3  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004ef7fb  e8f01bffff           call 0x4e13f0
// 004ef800  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ef804  83c408               add esp, 8
// 004ef807  51                   push ecx
// 004ef808  83ec1c               sub esp, 0x1c
// 004ef80b  8d542434             lea edx, [esp + 0x34]
// 004ef80f  8bcc                 mov ecx, esp
// 004ef811  89642430             mov dword ptr [esp + 0x30], esp
// 004ef815  52                   push edx
// 004ef816  ff150ca49e00         call dword ptr [0x9ea40c]
// 004ef81c  8bce                 mov ecx, esi
// 004ef81e  e87d5bffff           call 0x4e53a0
// 004ef823  8d4c2414             lea ecx, [esp + 0x14]
// 004ef827  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004ef82f  ff1500a49e00         call dword ptr [0x9ea400]
// 004ef835  47                   inc edi
// 004ef836  3b7c2440             cmp edi, dword ptr [esp + 0x40]
// 004ef83a  7299                 jb 0x4ef7d5
// 004ef83c  8b4610               mov eax, dword ptr [esi + 0x10]
// 004ef83f  2b460c               sub eax, dword ptr [esi + 0xc]
// 004ef842  83c9ff               or ecx, 0xffffffff
// 004ef845  c1f802               sar eax, 2
// 004ef848  85c0                 test eax, eax
// 004ef84a  760b                 jbe 0x4ef857
// 004ef84c  8d642400             lea esp, [esp]
// 004ef850  d1e8                 shr eax, 1
// 004ef852  41                   inc ecx
// 004ef853  85c0                 test eax, eax
// 004ef855  77f9                 ja 0x4ef850
// 004ef857  41                   inc ecx
// 004ef858  894e18               mov dword ptr [esi + 0x18], ecx
// 004ef85b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ef85f  5f                   pop edi
// 004ef860  5e                   pop esi
// 004ef861  64890d00000000       mov dword ptr fs:[0], ecx
// 004ef868  5b                   pop ebx
// 004ef869  83c430               add esp, 0x30
// 004ef86c  c20400               ret 4
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