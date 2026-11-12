// from server: 100% by EspClaude
// from server: 58% by Intel
// roc 2007-08 00724e07  unit: CXTIconHandle  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00724e07
//
// 00724e07  55                   push ebp
// 00724e08  8bec                 mov ebp, esp
// 00724e0a  81ec98000000         sub esp, 0x98
// 00724e10  a188518b00           mov eax, dword ptr [0x8b5188]
// 00724e15  33c5                 xor eax, ebp
// 00724e17  8945fc               mov dword ptr [ebp - 4], eax
// 00724e1a  8d8568ffffff         lea eax, [ebp - 0x98]
// 00724e20  50                   push eax
// 00724e21  c78568ffffff94000000 mov dword ptr [ebp - 0x98], 0x94
// 00724e2b  ff1518d27700         call dword ptr [0x77d218]
// 00724e31  83bd78ffffff02       cmp dword ptr [ebp - 0x88], 2
// 00724e38  750e                 jne 0x724e48
// 00724e3a  83bd6cffffff05       cmp dword ptr [ebp - 0x94], 5
// 00724e41  b8034e7200           mov eax, 0x724e03
// 00724e46  7305                 jae 0x724e4d
// 00724e48  b89e4d7200           mov eax, 0x724d9e
// 00724e4d  50                   push eax
// 00724e4e  6864ab8b00           push 0x8bab64
// 00724e53  ff1548d27700         call dword ptr [0x77d248]
// 00724e59  ff1564ab8b00         call dword ptr [0x8bab64]
// 00724e5f  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00724e62  33cd                 xor ecx, ebp
// 00724e64  e8b5bbf0ff           call 0x630a1e
// 00724e69  c9                   leave 
// 00724e6a  c3                   ret 

// roc-flags: /O1 /GS /EHsc /MD /Oy-

struct OSVERSIONINFOA {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(OSVERSIONINFOA*);
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile*, long);

typedef void (__stdcall *PFN)();
extern PFN g_pfnImpl;               // 0x8bab64 (relocated data)
void __stdcall ImplNT5();           // 0x724e03 (code)
void __stdcall ImplOther();         // 0x724d9e (code)

struct CXTIconHandle {
    static void __stdcall CheckVersion();
};

void __stdcall CXTIconHandle::CheckVersion()
{
    OSVERSIONINFOA vi;
    vi.dwOSVersionInfoSize = sizeof(vi);
    GetVersionExA(&vi);
    InterlockedExchange((long volatile*)&g_pfnImpl,
        (vi.dwPlatformId == 2 && vi.dwMajorVersion >= 5) ? (long)&ImplNT5 : (long)&ImplOther);
    g_pfnImpl();
}
