// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_packetstrings_80678edf7fa327c8.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
// from server: 84% by colin
// from server: 79% by king_originala
// roc 2008-06 004ab630  unit: RBX::Network::Replicator::MarkerItem  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ab630
//
// 004ab630  6aff                 push -1
// 004ab632  688d827c00           push 0x7c828d
// 004ab637  64a100000000         mov eax, dword ptr fs:[0]
// 004ab63d  50                   push eax
// 004ab63e  64892500000000       mov dword ptr fs:[0], esp
// 004ab645  81ec2c010000         sub esp, 0x12c
// 004ab64b  56                   push esi
// 004ab64c  57                   push edi
// 004ab64d  8bf9                 mov edi, ecx
// 004ab64f  897c2430             mov dword ptr [esp + 0x30], edi
// 004ab653  e8b8f30000           call 0x4baa10
// 004ab658  c7070c458200         mov dword ptr [edi], 0x82450c
// 004ab65e  c7870c02000000000000 mov dword ptr [edi + 0x20c], 0
// 004ab668  8b0d4c6b9700         mov ecx, dword ptr [0x976b4c]
// 004ab66e  c784243c01000000000000 mov dword ptr [esp + 0x13c], 0
// 004ab679  85c9                 test ecx, ecx
// 004ab67b  7408                 je 0x4ab685
// 004ab67d  8b01                 mov eax, dword ptr [ecx]
// 004ab67f  8b10                 mov edx, dword ptr [eax]
// 004ab681  ffd2                 call edx
// 004ab683  eb02                 jmp 0x4ab687
// 004ab685  33c0                 xor eax, eax
// 004ab687  83c024               add eax, 0x24
// 004ab68a  50                   push eax
// 004ab68b  8d4c2418             lea ecx, [esp + 0x18]
// 004ab68f  ff155c248000         call dword ptr [0x80245c]
// 004ab695  a1e8238000           mov eax, dword ptr [0x8023e8]
// 004ab69a  8b00                 mov eax, dword ptr [eax]
// 004ab69c  6a01                 push 1
// 004ab69e  50                   push eax
// 004ab69f  8d4c2410             lea ecx, [esp + 0x10]
// 004ab6a3  51                   push ecx
// 004ab6a4  8d4c2420             lea ecx, [esp + 0x20]
// 004ab6a8  c684244801000001     mov byte ptr [esp + 0x148], 1
// 004ab6b0  c64424145c           mov byte ptr [esp + 0x14], 0x5c
// 004ab6b5  ff159c248000         call dword ptr [0x80249c]
// 004ab6bb  8b15e8238000         mov edx, dword ptr [0x8023e8]
// 004ab6c1  8b0a                 mov ecx, dword ptr [edx]
// 004ab6c3  51                   push ecx
// 004ab6c4  40                   inc eax
// 004ab6c5  50                   push eax
// 004ab6c6  8d4c241c             lea ecx, [esp + 0x1c]
// 004ab6ca  ff15ec238000         call dword ptr [0x8023ec]
// 004ab6d0  e83be20100           call 0x4c9910
// 004ab6d5  50                   push eax
// 004ab6d6  8d542438             lea edx, [esp + 0x38]
// 004ab6da  6814488200           push 0x824814
// 004ab6df  52                   push edx
// 004ab6e0  ff1530288000         call dword ptr [0x802830]
// 004ab6e6  83c40c               add esp, 0xc
// 004ab6e9  8d442434             lea eax, [esp + 0x34]
// 004ab6ed  50                   push eax
// 004ab6ee  8d4c2418             lea ecx, [esp + 0x18]
// 004ab6f2  ff1548248000         call dword ptr [0x802448]
// 004ab6f8  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ab6fc  be10000000           mov esi, 0x10
// 004ab701  3974242c             cmp dword ptr [esp + 0x2c], esi
// 004ab705  7304                 jae 0x4ab70b
// 004ab707  8d442418             lea eax, [esp + 0x18]
// 004ab70b  6884878100           push 0x818784
// 004ab710  50                   push eax
// 004ab711  ff1514288000         call dword ptr [0x802814]
// 004ab717  83c408               add esp, 8
// 004ab71a  8d4c240c             lea ecx, [esp + 0xc]
// 004ab71e  89870c020000         mov dword ptr [edi + 0x20c], eax
// 004ab724  51                   push ecx
// 004ab725  85c0                 test eax, eax
// 004ab727  7428                 je 0x4ab751
// 004ab729  e8f2de0b00           call 0x569620
// 004ab72e  83c404               add esp, 4
// 004ab731  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ab735  c684243c01000002     mov byte ptr [esp + 0x13c], 2
// 004ab73d  3974242c             cmp dword ptr [esp + 0x2c], esi
// 004ab741  7304                 jae 0x4ab747
// 004ab743  8d4c2418             lea ecx, [esp + 0x18]
// 004ab747  51                   push ecx
// 004ab748  68fc478200           push 0x8247fc
// 004ab74d  6a01                 push 1
// 004ab74f  eb26                 jmp 0x4ab777
// 004ab751  e8cade0b00           call 0x569620
// 004ab756  83c404               add esp, 4
// 004ab759  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ab75d  c684243c01000003     mov byte ptr [esp + 0x13c], 3
// 004ab765  3974242c             cmp dword ptr [esp + 0x2c], esi
// 004ab769  7304                 jae 0x4ab76f
// 004ab76b  8d4c2418             lea ecx, [esp + 0x18]
// 004ab76f  51                   push ecx
// 004ab770  68dc478200           push 0x8247dc
// 004ab775  6a02                 push 2
// 004ab777  8b00                 mov eax, dword ptr [eax]
// 004ab779  50                   push eax
// 004ab77a  e821dc0b00           call 0x5693a0
// 004ab77f  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ab783  83c410               add esp, 0x10
// 004ab786  c684243c01000001     mov byte ptr [esp + 0x13c], 1
// 004ab78e  85c0                 test eax, eax
// 004ab790  742c                 je 0x4ab7be
// 004ab792  8bf0                 mov esi, eax
// 004ab794  83caff               or edx, 0xffffffff
// 004ab797  83c004               add eax, 4
// 004ab79a  f00fc110             lock xadd dword ptr [eax], edx
// 004ab79e  751e                 jne 0x4ab7be
// 004ab7a0  8b06                 mov eax, dword ptr [esi]
// 004ab7a2  8b5004               mov edx, dword ptr [eax + 4]
// 004ab7a5  8bce                 mov ecx, esi
// 004ab7a7  ffd2                 call edx
// 004ab7a9  83c9ff               or ecx, 0xffffffff
// 004ab7ac  8d4608               lea eax, [esi + 8]
// 004ab7af  f00fc108             lock xadd dword ptr [eax], ecx
// 004ab7b3  7509                 jne 0x4ab7be
// 004ab7b5  8b16                 mov edx, dword ptr [esi]
// 004ab7b7  8b4208               mov eax, dword ptr [edx + 8]
// 004ab7ba  8bce                 mov ecx, esi
// 004ab7bc  ffd0                 call eax
// 004ab7be  8d4c2414             lea ecx, [esp + 0x14]
// 004ab7c2  c684243c01000000     mov byte ptr [esp + 0x13c], 0
// 004ab7ca  ff1568248000         call dword ptr [0x802468]
// 004ab7d0  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 004ab7d7  8bc7                 mov eax, edi
// 004ab7d9  5f                   pop edi
// 004ab7da  5e                   pop esi
// 004ab7db  64890d00000000       mov dword ptr fs:[0], ecx
// 004ab7e2  81c438010000         add esp, 0x138
// 004ab7e8  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef std::string String;

struct Settings {
    unsigned char padding[36];
    String path;
};

struct Provider {
    virtual Settings* get();
};

extern Provider* provider;

typedef boost::shared_ptr<void> Shared;

extern Shared __cdecl get_logger();
extern void __cdecl report(void*, int, const char*, ...);
extern unsigned int __cdecl get_time();

struct File;
extern File* (__cdecl *open_file)(const char*, const char*);
extern int (__cdecl *format_text)(char*, const char*, ...);
const char file_mode[]="wt";
const char packet_format[]="PacketLog%i.csv";
const char logging_message[]="Logging packets to %s";
const char failure_message[]="Failed to create log file %s";

struct Base {
    Base();
    virtual ~Base();
    unsigned char padding[520];
};

struct S : Base {
    File* file;
    S(int);
};

S::S(int)
    : Base(), file(0)
{
    String path((provider ? provider->get() : 0)->path);
    path.erase(path.rfind('\\', String::npos) + 1, String::npos);

    char name[256];
    format_text(name, packet_format, get_time());
    path.append(name);

    file = open_file(path.c_str(), file_mode);
    if (file)
        report(get_logger().get(), 1, logging_message, path.c_str());
    else
        report(get_logger().get(), 2, failure_message, path.c_str());
}
