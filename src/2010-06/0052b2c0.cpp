// from server: 100% by Yeetserama
// roc 2010-06 0052b2c0  unit: boost::bad_lexical_cast  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052b2c0
//
// 0052b2c0  6aff                 push -1
// 0052b2c2  68095b9800           push 0x985b09
// 0052b2c7  64a100000000         mov eax, dword ptr fs:[0]
// 0052b2cd  50                   push eax
// 0052b2ce  64892500000000       mov dword ptr fs:[0], esp
// 0052b2d5  83ec1c               sub esp, 0x1c
// 0052b2d8  56                   push esi
// 0052b2d9  33f6                 xor esi, esi
// 0052b2db  56                   push esi
// 0052b2dc  8d442408             lea eax, [esp + 8]
// 0052b2e0  68a0eca100           push 0xa1eca0
// 0052b2e5  50                   push eax
// 0052b2e6  e8c5c10200           call 0x5574b0
// 0052b2eb  8d4c2410             lea ecx, [esp + 0x10]
// 0052b2ef  51                   push ecx
// 0052b2f0  89742438             mov dword ptr [esp + 0x38], esi
// 0052b2f4  e857432700           call 0x79f650
// 0052b2f9  83c410               add esp, 0x10
// 0052b2fc  84c0                 test al, al
// 0052b2fe  743c                 je 0x52b33c
// 0052b300  8d4c2404             lea ecx, [esp + 4]
// 0052b304  46                   inc esi
// 0052b305  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0052b30d  ff1500a49e00         call dword ptr [0x9ea400]
// 0052b313  56                   push esi
// 0052b314  8d542408             lea edx, [esp + 8]
// 0052b318  68a0eca100           push 0xa1eca0
// 0052b31d  52                   push edx
// 0052b31e  e88dc10200           call 0x5574b0
// 0052b323  8d442410             lea eax, [esp + 0x10]
// 0052b327  50                   push eax
// 0052b328  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0052b330  e81b432700           call 0x79f650
// 0052b335  83c410               add esp, 0x10
// 0052b338  84c0                 test al, al
// 0052b33a  75c4                 jne 0x52b300
// 0052b33c  8d4c2404             lea ecx, [esp + 4]
// 0052b340  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0052b348  ff1500a49e00         call dword ptr [0x9ea400]
// 0052b34e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0052b352  8bc6                 mov eax, esi
// 0052b354  5e                   pop esi
// 0052b355  64890d00000000       mov dword ptr fs:[0], ecx
// 0052b35c  83c428               add esp, 0x28
// 0052b35f  c3                   ret 
// copied from an identical function in another client (function ?countProcessors@ns_ROCX00000d@@YAHXZ)

namespace ns_ROCX00000d {
// from server: 100% by king_originala
struct String;
extern void (__thiscall *destroyString)(String *);

struct String {
    unsigned char storage[28];
    ~String() { destroyString(this); }
};

extern String __cdecl formatString(const char *, ...);
extern bool __cdecl keyExists(const String &);

int countProcessors()
{
    int count = 0;
    for (;;) {
        String key = formatString(
            "HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\%d",
            count);
        if (!keyExists(key))
            break;
        ++count;
    }
    return count;
}
}
