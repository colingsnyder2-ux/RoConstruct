// from server: 100% by Yeetserama
// roc 2010-06 004ef5d0  unit: RBX::Network::Replicator::EventInvocationItem  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ef5d0
//
// 004ef5d0  64a100000000         mov eax, dword ptr fs:[0]
// 004ef5d6  6aff                 push -1
// 004ef5d8  68095b9800           push 0x985b09
// 004ef5dd  50                   push eax
// 004ef5de  64892500000000       mov dword ptr fs:[0], esp
// 004ef5e5  83ec24               sub esp, 0x24
// 004ef5e8  53                   push ebx
// 004ef5e9  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004ef5ed  56                   push esi
// 004ef5ee  57                   push edi
// 004ef5ef  8d442440             lea eax, [esp + 0x40]
// 004ef5f3  50                   push eax
// 004ef5f4  53                   push ebx
// 004ef5f5  8bf1                 mov esi, ecx
// 004ef5f7  e8d41affff           call 0x4e10d0
// 004ef5fc  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004ef600  83c408               add esp, 8
// 004ef603  6a00                 push 0
// 004ef605  51                   push ecx
// 004ef606  8bce                 mov ecx, esi
// 004ef608  e8738d1600           call 0x658380
// 004ef60d  33ff                 xor edi, edi
// 004ef60f  397c2440             cmp dword ptr [esp + 0x40], edi
// 004ef613  7667                 jbe 0x4ef67c
// 004ef615  8d54240c             lea edx, [esp + 0xc]
// 004ef619  52                   push edx
// 004ef61a  53                   push ebx
// 004ef61b  e8301affff           call 0x4e1050
// 004ef620  83c408               add esp, 8
// 004ef623  8d4c2414             lea ecx, [esp + 0x14]
// 004ef627  ff1504a49e00         call dword ptr [0x9ea404]
// 004ef62d  8d442414             lea eax, [esp + 0x14]
// 004ef631  50                   push eax
// 004ef632  53                   push ebx
// 004ef633  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004ef63b  e8b01dffff           call 0x4e13f0
// 004ef640  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ef644  83c408               add esp, 8
// 004ef647  51                   push ecx
// 004ef648  83ec1c               sub esp, 0x1c
// 004ef64b  8d542434             lea edx, [esp + 0x34]
// 004ef64f  8bcc                 mov ecx, esp
// 004ef651  89642430             mov dword ptr [esp + 0x30], esp
// 004ef655  52                   push edx
// 004ef656  ff150ca49e00         call dword ptr [0x9ea40c]
// 004ef65c  8bce                 mov ecx, esi
// 004ef65e  e86d39ffff           call 0x4e2fd0
// 004ef663  8d4c2414             lea ecx, [esp + 0x14]
// 004ef667  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004ef66f  ff1500a49e00         call dword ptr [0x9ea400]
// 004ef675  47                   inc edi
// 004ef676  3b7c2440             cmp edi, dword ptr [esp + 0x40]
// 004ef67a  7299                 jb 0x4ef615
// 004ef67c  8b4610               mov eax, dword ptr [esi + 0x10]
// 004ef67f  2b460c               sub eax, dword ptr [esi + 0xc]
// 004ef682  83c9ff               or ecx, 0xffffffff
// 004ef685  c1f802               sar eax, 2
// 004ef688  85c0                 test eax, eax
// 004ef68a  760b                 jbe 0x4ef697
// 004ef68c  8d642400             lea esp, [esp]
// 004ef690  d1e8                 shr eax, 1
// 004ef692  41                   inc ecx
// 004ef693  85c0                 test eax, eax
// 004ef695  77f9                 ja 0x4ef690
// 004ef697  41                   inc ecx
// 004ef698  894e18               mov dword ptr [esi + 0x18], ecx
// 004ef69b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ef69f  5f                   pop edi
// 004ef6a0  5e                   pop esi
// 004ef6a1  64890d00000000       mov dword ptr fs:[0], ecx
// 004ef6a8  5b                   pop ebx
// 004ef6a9  83c430               add esp, 0x30
// 004ef6ac  c20400               ret 4
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