// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 00565510  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 321 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00565510
// 00565510  6aff                 push -1
// 00565512  68e8f68500           push 0x85f6e8
// 00565517  64a100000000         mov eax, dword ptr fs:[0]
// 0056551d  50                   push eax
// 0056551e  64892500000000       mov dword ptr fs:[0], esp
// 00565525  83ec44               sub esp, 0x44
// 00565528  53                   push ebx
// 00565529  33db                 xor ebx, ebx
// 0056552b  56                   push esi
// 0056552c  8bf1                 mov esi, ecx
// 0056552e  895c2408             mov dword ptr [esp + 8], ebx
// 00565532  8974240c             mov dword ptr [esp + 0xc], esi
// 00565536  381d9e1ca400         cmp byte ptr [0xa41c9e], bl
// 0056553c  7407                 je 0x565545
// 0056553e  e85defffff           call 0x5644a0
// 00565543  eb02                 jmp 0x565547
// 00565545  d9ee                 fldz 
// 00565547  d91e                 fstp dword ptr [esi]
// 00565549  e842b71a00           call 0x710c90
// 0056554e  c1e814               shr eax, 0x14
// 00565551  894604               mov dword ptr [esi + 4], eax
// 00565554  e867f4ffff           call 0x5649c0
// 00565559  894608               mov dword ptr [esi + 8], eax
// 0056555c  e8bff3ffff           call 0x564920
// 00565561  89460c               mov dword ptr [esi + 0xc], eax
// 00565564  381d9e1ca400         cmp byte ptr [0xa41c9e], bl
// 0056556a  7407                 je 0x565573
// 0056556c  e8ff15f4ff           call 0x4a6b70
// 00565571  eb1c                 jmp 0x56558f
// 00565573  6800758c00           push 0x8c7500
// 00565578  8d4c2414             lea ecx, [esp + 0x14]
// 0056557c  ff15b4e48900         call dword ptr [0x89e4b4]
// 00565582  895c2454             mov dword ptr [esp + 0x54], ebx
// 00565586  bb01000000           mov ebx, 1
// 0056558b  895c2408             mov dword ptr [esp + 8], ebx
// 0056558f  50                   push eax
// 00565590  8d4e10               lea ecx, [esi + 0x10]
// 00565593  ff15b8e48900         call dword ptr [0x89e4b8]
// 00565599  c744245402000000     mov dword ptr [esp + 0x54], 2
// 005655a1  f6c301               test bl, 1
// 005655a4  7411                 je 0x5655b7
// 005655a6  83e3fe               and ebx, 0xfffffffe
// 005655a9  8d4c2410             lea ecx, [esp + 0x10]
// 005655ad  895c2408             mov dword ptr [esp + 8], ebx
// 005655b1  ff15c4e48900         call dword ptr [0x89e4c4]
// 005655b7  803d9e1ca40000       cmp byte ptr [0xa41c9e], 0
// 005655be  7407                 je 0x5655c7
// 005655c0  e8cb16f4ff           call 0x4a6c90
// 005655c5  eb1b                 jmp 0x5655e2
// 005655c7  6800758c00           push 0x8c7500
// 005655cc  8d4c2430             lea ecx, [esp + 0x30]
// 005655d0  ff15b4e48900         call dword ptr [0x89e4b4]
// 005655d6  83cb02               or ebx, 2
// 005655d9  c644245403           mov byte ptr [esp + 0x54], 3
// 005655de  895c2408             mov dword ptr [esp + 8], ebx
// 005655e2  50                   push eax
// 005655e3  8d4e2c               lea ecx, [esi + 0x2c]
// 005655e6  ff15b8e48900         call dword ptr [0x89e4b8]
// 005655ec  c744245405000000     mov dword ptr [esp + 0x54], 5
// 005655f4  f6c302               test bl, 2
// 005655f7  740a                 je 0x565603
// 005655f9  8d4c242c             lea ecx, [esp + 0x2c]
// 005655fd  ff15c4e48900         call dword ptr [0x89e4c4]
// 00565603  8d4648               lea eax, [esi + 0x48]
// 00565606  50                   push eax
// 00565607  e854f2ffff           call 0x564860
// 0056560c  83c404               add esp, 4
// 0056560f  8d4c242c             lea ecx, [esp + 0x2c]
// 00565613  51                   push ecx
// 00565614  c644245806           mov byte ptr [esp + 0x58], 6
// 00565619  ff15c0e28900         call dword ptr [0x89e2c0]
// 0056561f  8b442434             mov eax, dword ptr [esp + 0x34]
// 00565623  99                   cdq 
// 00565624  81e2ffff0f00         and edx, 0xfffff
// 0056562a  03c2                 add eax, edx
// 0056562c  8d5668               lea edx, [esi + 0x68]
// 0056562f  c1f814               sar eax, 0x14
// 00565632  52                   push edx
// 00565633  894664               mov dword ptr [esi + 0x64], eax
// 00565636  e8e5fdffff           call 0x565420
// 0056563b  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0056563f  83c404               add esp, 4
// 00565642  8bc6                 mov eax, esi
// 00565644  5e                   pop esi
// 00565645  5b                   pop ebx
// 00565646  64890d00000000       mov dword ptr fs:[0], ecx
// 0056564d  83c450               add esp, 0x50
// 00565650  c3                   ret 
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>

extern bool enabled;
extern const char emptyText[];

extern double __cdecl queryFloat();
extern unsigned __cdecl queryCounter();
extern unsigned __cdecl queryFirst();
extern unsigned __cdecl querySecond();
extern const std::string &__cdecl queryFirstString();
extern const std::string &__cdecl querySecondString();

struct MemoryStatus {
    unsigned length;
    unsigned load;
    int totalPhysical;
    unsigned availablePhysical;
    unsigned totalPageFile;
    unsigned availablePageFile;
    unsigned totalVirtual;
    unsigned availableVirtual;
};

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(MemoryStatus *);

inline int queryPhysicalMegabytes()
{
    MemoryStatus status;
    GlobalMemoryStatus(&status);
    return status.totalPhysical / 1048576;
}

extern std::string __cdecl queryBlock();
extern std::string __cdecl queryTail();

struct S {
    float value;
    unsigned counter;
    unsigned first;
    unsigned second;
    std::string firstString;
    std::string secondString;
    std::string block;
    int physicalMegabytes;
    std::string tail;

    S();
};

S::S()
    : value(enabled ? queryFloat() : 0.0),
      counter(static_cast<unsigned>(queryCounter() >> 20)),
      first(queryFirst()),
      second(querySecond()),
      firstString(enabled ? queryFirstString() : std::string(emptyText)),
      secondString(enabled ? querySecondString() : std::string(emptyText)),
      block(queryBlock()),
      physicalMegabytes(queryPhysicalMegabytes()),
      tail(queryTail())
{
}
