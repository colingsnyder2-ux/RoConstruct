// from server: 100% by EspClaude
// roc 2009-06 00564920  unit: boost::bad_lexical_cast  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00564920
//
// 00564920  6aff                 push -1
// 00564922  68d9b88500           push 0x85b8d9
// 00564927  64a100000000         mov eax, dword ptr fs:[0]
// 0056492d  50                   push eax
// 0056492e  64892500000000       mov dword ptr fs:[0], esp
// 00564935  83ec1c               sub esp, 0x1c
// 00564938  56                   push esi
// 00564939  33f6                 xor esi, esi
// 0056493b  56                   push esi
// 0056493c  8d442408             lea eax, [esp + 8]
// 00564940  68e8a88c00           push 0x8ca8e8
// 00564945  50                   push eax
// 00564946  e8354a0100           call 0x579380
// 0056494b  8d4c2410             lea ecx, [esp + 0x10]
// 0056494f  51                   push ecx
// 00564950  89742438             mov dword ptr [esp + 0x38], esi
// 00564954  e887b61a00           call 0x70ffe0
// 00564959  83c410               add esp, 0x10
// 0056495c  84c0                 test al, al
// 0056495e  743c                 je 0x56499c
// 00564960  8d4c2404             lea ecx, [esp + 4]
// 00564964  46                   inc esi
// 00564965  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0056496d  ff15c4e48900         call dword ptr [0x89e4c4]
// 00564973  56                   push esi
// 00564974  8d542408             lea edx, [esp + 8]
// 00564978  68e8a88c00           push 0x8ca8e8
// 0056497d  52                   push edx
// 0056497e  e8fd490100           call 0x579380
// 00564983  8d442410             lea eax, [esp + 0x10]
// 00564987  50                   push eax
// 00564988  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00564990  e84bb61a00           call 0x70ffe0
// 00564995  83c410               add esp, 0x10
// 00564998  84c0                 test al, al
// 0056499a  75c4                 jne 0x564960
// 0056499c  8d4c2404             lea ecx, [esp + 4]
// 005649a0  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 005649a8  ff15c4e48900         call dword ptr [0x89e4c4]
// 005649ae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005649b2  8bc6                 mov eax, esi
// 005649b4  5e                   pop esi
// 005649b5  64890d00000000       mov dword ptr fs:[0], ecx
// 005649bc  83c428               add esp, 0x28
// 005649bf  c3                   ret 
// copied from an identical function in another client (function ?countProcessors@ns_ROCX00000f@@YAHXZ)

namespace ns_ROCX00000f {
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
