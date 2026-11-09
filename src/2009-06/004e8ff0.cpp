// from server: 100% by EspClaude
// roc 2009-06 004e8ff0  unit: RBX::JointsService  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8ff0
//
// 004e8ff0  64a100000000         mov eax, dword ptr fs:[0]
// 004e8ff6  6aff                 push -1
// 004e8ff8  68d9b88500           push 0x85b8d9
// 004e8ffd  50                   push eax
// 004e8ffe  64892500000000       mov dword ptr fs:[0], esp
// 004e9005  83ec24               sub esp, 0x24
// 004e9008  53                   push ebx
// 004e9009  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004e900d  56                   push esi
// 004e900e  57                   push edi
// 004e900f  8d442440             lea eax, [esp + 0x40]
// 004e9013  50                   push eax
// 004e9014  53                   push ebx
// 004e9015  8bf1                 mov esi, ecx
// 004e9017  e8e441ffff           call 0x4dd200
// 004e901c  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004e9020  83c408               add esp, 8
// 004e9023  6a00                 push 0
// 004e9025  51                   push ecx
// 004e9026  8bce                 mov ecx, esi
// 004e9028  e8d3741900           call 0x680500
// 004e902d  33ff                 xor edi, edi
// 004e902f  397c2440             cmp dword ptr [esp + 0x40], edi
// 004e9033  7667                 jbe 0x4e909c
// 004e9035  8d54240c             lea edx, [esp + 0xc]
// 004e9039  52                   push edx
// 004e903a  53                   push ebx
// 004e903b  e84041ffff           call 0x4dd180
// 004e9040  83c408               add esp, 8
// 004e9043  8d4c2414             lea ecx, [esp + 0x14]
// 004e9047  ff15c0e48900         call dword ptr [0x89e4c0]
// 004e904d  8d442414             lea eax, [esp + 0x14]
// 004e9051  50                   push eax
// 004e9052  53                   push ebx
// 004e9053  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004e905b  e8c044ffff           call 0x4dd520
// 004e9060  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e9064  83c408               add esp, 8
// 004e9067  51                   push ecx
// 004e9068  83ec1c               sub esp, 0x1c
// 004e906b  8d542434             lea edx, [esp + 0x34]
// 004e906f  8bcc                 mov ecx, esp
// 004e9071  89642430             mov dword ptr [esp + 0x30], esp
// 004e9075  52                   push edx
// 004e9076  ff15b8e48900         call dword ptr [0x89e4b8]
// 004e907c  8bce                 mov ecx, esi
// 004e907e  e83d55ffff           call 0x4de5c0
// 004e9083  8d4c2414             lea ecx, [esp + 0x14]
// 004e9087  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004e908f  ff15c4e48900         call dword ptr [0x89e4c4]
// 004e9095  47                   inc edi
// 004e9096  3b7c2440             cmp edi, dword ptr [esp + 0x40]
// 004e909a  7299                 jb 0x4e9035
// 004e909c  8b4610               mov eax, dword ptr [esi + 0x10]
// 004e909f  2b460c               sub eax, dword ptr [esi + 0xc]
// 004e90a2  83c9ff               or ecx, 0xffffffff
// 004e90a5  c1f802               sar eax, 2
// 004e90a8  85c0                 test eax, eax
// 004e90aa  760b                 jbe 0x4e90b7
// 004e90ac  8d642400             lea esp, [esp]
// 004e90b0  d1e8                 shr eax, 1
// 004e90b2  41                   inc ecx
// 004e90b3  85c0                 test eax, eax
// 004e90b5  77f9                 ja 0x4e90b0
// 004e90b7  41                   inc ecx
// 004e90b8  894e18               mov dword ptr [esi + 0x18], ecx
// 004e90bb  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004e90bf  5f                   pop edi
// 004e90c0  5e                   pop esi
// 004e90c1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e90c8  5b                   pop ebx
// 004e90c9  83c430               add esp, 0x30
// 004e90cc  c20400               ret 4
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