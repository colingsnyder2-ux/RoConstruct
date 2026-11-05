// from server: 100% by Yeetserama
// roc 2010-06 004ef6b0  unit: RBX::Network::Replicator::EventInvocationItem  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ef6b0
//
// 004ef6b0  64a100000000         mov eax, dword ptr fs:[0]
// 004ef6b6  6aff                 push -1
// 004ef6b8  68095b9800           push 0x985b09
// 004ef6bd  50                   push eax
// 004ef6be  64892500000000       mov dword ptr fs:[0], esp
// 004ef6c5  83ec24               sub esp, 0x24
// 004ef6c8  53                   push ebx
// 004ef6c9  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004ef6cd  56                   push esi
// 004ef6ce  57                   push edi
// 004ef6cf  8d442440             lea eax, [esp + 0x40]
// 004ef6d3  50                   push eax
// 004ef6d4  53                   push ebx
// 004ef6d5  8bf1                 mov esi, ecx
// 004ef6d7  e8f419ffff           call 0x4e10d0
// 004ef6dc  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004ef6e0  83c408               add esp, 8
// 004ef6e3  6a00                 push 0
// 004ef6e5  51                   push ecx
// 004ef6e6  8bce                 mov ecx, esi
// 004ef6e8  e8938c1600           call 0x658380
// 004ef6ed  33ff                 xor edi, edi
// 004ef6ef  397c2440             cmp dword ptr [esp + 0x40], edi
// 004ef6f3  7667                 jbe 0x4ef75c
// 004ef6f5  8d54240c             lea edx, [esp + 0xc]
// 004ef6f9  52                   push edx
// 004ef6fa  53                   push ebx
// 004ef6fb  e85019ffff           call 0x4e1050
// 004ef700  83c408               add esp, 8
// 004ef703  8d4c2414             lea ecx, [esp + 0x14]
// 004ef707  ff1504a49e00         call dword ptr [0x9ea404]
// 004ef70d  8d442414             lea eax, [esp + 0x14]
// 004ef711  50                   push eax
// 004ef712  53                   push ebx
// 004ef713  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004ef71b  e8d01cffff           call 0x4e13f0
// 004ef720  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ef724  83c408               add esp, 8
// 004ef727  51                   push ecx
// 004ef728  83ec1c               sub esp, 0x1c
// 004ef72b  8d542434             lea edx, [esp + 0x34]
// 004ef72f  8bcc                 mov ecx, esp
// 004ef731  89642430             mov dword ptr [esp + 0x30], esp
// 004ef735  52                   push edx
// 004ef736  ff150ca49e00         call dword ptr [0x9ea40c]
// 004ef73c  8bce                 mov ecx, esi
// 004ef73e  e8bd5effff           call 0x4e5600
// 004ef743  8d4c2414             lea ecx, [esp + 0x14]
// 004ef747  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004ef74f  ff1500a49e00         call dword ptr [0x9ea400]
// 004ef755  47                   inc edi
// 004ef756  3b7c2440             cmp edi, dword ptr [esp + 0x40]
// 004ef75a  7299                 jb 0x4ef6f5
// 004ef75c  8b4610               mov eax, dword ptr [esi + 0x10]
// 004ef75f  2b460c               sub eax, dword ptr [esi + 0xc]
// 004ef762  83c9ff               or ecx, 0xffffffff
// 004ef765  c1f802               sar eax, 2
// 004ef768  85c0                 test eax, eax
// 004ef76a  760b                 jbe 0x4ef777
// 004ef76c  8d642400             lea esp, [esp]
// 004ef770  d1e8                 shr eax, 1
// 004ef772  41                   inc ecx
// 004ef773  85c0                 test eax, eax
// 004ef775  77f9                 ja 0x4ef770
// 004ef777  41                   inc ecx
// 004ef778  894e18               mov dword ptr [esi + 0x18], ecx
// 004ef77b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ef77f  5f                   pop edi
// 004ef780  5e                   pop esi
// 004ef781  64890d00000000       mov dword ptr fs:[0], ecx
// 004ef788  5b                   pop ebx
// 004ef789  83c430               add esp, 0x30
// 004ef78c  c20400               ret 4
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