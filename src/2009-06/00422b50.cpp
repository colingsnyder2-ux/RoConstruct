// from server: 100% by EspClaude
// roc 2009-06 00422b50  unit: RobloxCrashReporter  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00422b50
//
// 00422b50  8b442404             mov eax, dword ptr [esp + 4]
// 00422b54  56                   push esi
// 00422b55  50                   push eax
// 00422b56  e8d5c30a00           call 0x4cef30
// 00422b5b  8bf0                 mov esi, eax
// 00422b5d  b801000000           mov eax, 1
// 00422b62  84050ca2a300         test byte ptr [0xa3a20c], al
// 00422b68  7512                 jne 0x422b7c
// 00422b6a  8a0df0a1a300         mov cl, byte ptr [0xa3a1f0]
// 00422b70  09050ca2a300         or dword ptr [0xa3a20c], eax
// 00422b76  880d09a2a300         mov byte ptr [0xa3a209], cl
// 00422b7c  803d09a2a30000       cmp byte ptr [0xa3a209], 0
// 00422b83  7519                 jne 0x422b9e
// 00422b85  6a00                 push 0
// 00422b87  68100b8b00           push 0x8b0b10
// 00422b8c  68c80a8b00           push 0x8b0ac8
// 00422b91  6a00                 push 0
// 00422b93  a209a2a300           mov byte ptr [0xa3a209], al
// 00422b98  ff1508ee8900         call dword ptr [0x89ee08]
// 00422b9e  8bc6                 mov eax, esi
// 00422ba0  5e                   pop esi
// 00422ba1  c20400               ret 4
// copied from an identical function in another client (function ?crashHandler@ns_ROCX0000a0@@YGHPAX@Z)

namespace ns_ROCX0000a0 {
extern bool initialShown;
extern "C" int __stdcall reportCrash(void *);
extern "C" int (__stdcall *MessageBoxA)(void *, const char *, const char *, unsigned int);

int __stdcall crashHandler(void *argument)
{
    int result = reportCrash(argument);
    static bool shown = initialShown;
    if (!shown)
    {
        shown = true;
        MessageBoxA(0,
            "An unexpected error occurred and ROBLOX needs to quit.  We're sorry!",
            "ROBLOX Crash", 0);
    }
    return result;
}
}
