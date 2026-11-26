// from server: 100% by Xemicl
// roc 2012-06 004b0b20  unit: RBX::VideoControl  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0b20
//
// 004b0b20  81ec94000000         sub esp, 0x94
// 004b0b26  6890000000           push 0x90
// 004b0b2b  8d442408             lea eax, [esp + 8]
// 004b0b2f  6a00                 push 0
// 004b0b31  50                   push eax
// 004b0b32  e83d284d00           call 0x983374
// 004b0b37  83c40c               add esp, 0xc
// 004b0b3a  8d0c24               lea ecx, [esp]
// 004b0b3d  51                   push ecx
// 004b0b3e  c744240494000000     mov dword ptr [esp + 4], 0x94
// 004b0b46  ff15fc21b200         call dword ptr [0xb221fc]
// 004b0b4c  85c0                 test eax, eax
// 004b0b4e  7417                 je 0x4b0b67
// 004b0b50  837c241002           cmp dword ptr [esp + 0x10], 2
// 004b0b55  7510                 jne 0x4b0b67
// 004b0b57  837c240406           cmp dword ptr [esp + 4], 6
// 004b0b5c  7209                 jb 0x4b0b67
// 004b0b5e  b001                 mov al, 1
// 004b0b60  81c494000000         add esp, 0x94
// 004b0b66  c3                   ret 
// 004b0b67  32c0                 xor al, al
// 004b0b69  81c494000000         add esp, 0x94
// 004b0b6f  c3                   ret 
// copied from an identical function in another client (function ?isVistaOrLater@@YA_NXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned long DWORD;
typedef struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize; DWORD dwMajorVersion; DWORD dwMinorVersion;
    DWORD dwBuildNumber; DWORD dwPlatformId; char szCSDVersion[128];
} OSVERSIONINFOA;
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(OSVERSIONINFOA* lpVersionInformation);
bool isVistaOrLater()
{
    OSVERSIONINFOA vi = { 0 };
    vi.dwOSVersionInfoSize = sizeof(vi);
    if (GetVersionExA(&vi) && vi.dwPlatformId == 2 && vi.dwMajorVersion >= 6)
        return true;
    return false;
}