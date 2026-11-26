// from server: 100% by Xemicl
// roc 2012-06 00a95690  unit: seg_00a90000  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a95690
//
// 00a95690  6aff                 push -1
// 00a95692  684961ab00           push 0xab6149
// 00a95697  64a100000000         mov eax, dword ptr fs:[0]
// 00a9569d  50                   push eax
// 00a9569e  64892500000000       mov dword ptr fs:[0], esp
// 00a956a5  83ec1c               sub esp, 0x1c
// 00a956a8  56                   push esi
// 00a956a9  33f6                 xor esi, esi
// 00a956ab  56                   push esi
// 00a956ac  8d442408             lea eax, [esp + 8]
// 00a956b0  68a0fac300           push 0xc3faa0
// 00a956b5  50                   push eax
// 00a956b6  e88536baff           call 0x638d40
// 00a956bb  8d4c2410             lea ecx, [esp + 0x10]
// 00a956bf  51                   push ecx
// 00a956c0  89742438             mov dword ptr [esp + 0x38], esi
// 00a956c4  e83771eeff           call 0x97c800
// 00a956c9  83c410               add esp, 0x10
// 00a956cc  84c0                 test al, al
// 00a956ce  743c                 je 0xa9570c
// 00a956d0  8d4c2404             lea ecx, [esp + 4]
// 00a956d4  46                   inc esi
// 00a956d5  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00a956dd  ff153c26b200         call dword ptr [0xb2263c]
// 00a956e3  56                   push esi
// 00a956e4  8d542408             lea edx, [esp + 8]
// 00a956e8  68a0fac300           push 0xc3faa0
// 00a956ed  52                   push edx
// 00a956ee  e84d36baff           call 0x638d40
// 00a956f3  8d442410             lea eax, [esp + 0x10]
// 00a956f7  50                   push eax
// 00a956f8  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00a95700  e8fb70eeff           call 0x97c800
// 00a95705  83c410               add esp, 0x10
// 00a95708  84c0                 test al, al
// 00a9570a  75c4                 jne 0xa956d0
// 00a9570c  8d4c2404             lea ecx, [esp + 4]
// 00a95710  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00a95718  ff153c26b200         call dword ptr [0xb2263c]
// 00a9571e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00a95722  8bc6                 mov eax, esi
// 00a95724  5e                   pop esi
// 00a95725  64890d00000000       mov dword ptr fs:[0], ecx
// 00a9572c  83c428               add esp, 0x28
// 00a9572f  c3                   ret 
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