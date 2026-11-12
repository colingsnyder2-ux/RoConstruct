// from server: 93% by EspClaude
// from server: 52% by colin
// roc 2007-08 0072501f  unit: CXTIconHandle  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0072501f
//
// 0072501f  55                   push ebp
// 00725020  8d6c2488             lea ebp, [esp - 0x78]
// 00725024  81ec98000000         sub esp, 0x98
// 0072502a  a188518b00           mov eax, dword ptr [0x8b5188]
// 0072502f  33c5                 xor eax, ebp
// 00725031  894574               mov dword ptr [ebp + 0x74], eax
// 00725034  56                   push esi
// 00725035  8bf1                 mov esi, ecx
// 00725037  e837ffffff           call 0x724f73
// 0072503c  b800004000           mov eax, 0x400000
// 00725041  6894000000           push 0x94
// 00725046  894608               mov dword ptr [esi + 8], eax
// 00725049  894604               mov dword ptr [esi + 4], eax
// 0072504c  8d45e0               lea eax, [ebp - 0x20]
// 0072504f  6a00                 push 0
// 00725051  50                   push eax
// 00725052  c7063c000000         mov dword ptr [esi], 0x3c
// 00725058  c6460c00             mov byte ptr [esi + 0xc], 0
// 0072505c  e82bbbf0ff           call 0x630b8c
// 00725061  83c40c               add esp, 0xc
// 00725064  8d45e0               lea eax, [ebp - 0x20]
// 00725067  50                   push eax
// 00725068  c745e094000000       mov dword ptr [ebp - 0x20], 0x94
// 0072506f  ff1518d27700         call dword ptr [0x77d218]
// 00725075  837df002             cmp dword ptr [ebp - 0x10], 2
// 00725079  7508                 jne 0x725083
// 0072507b  837de405             cmp dword ptr [ebp - 0x1c], 5
// 0072507f  721a                 jb 0x72509b
// 00725081  eb14                 jmp 0x725097
// 00725083  837df001             cmp dword ptr [ebp - 0x10], 1
// 00725087  7512                 jne 0x72509b
// 00725089  837de404             cmp dword ptr [ebp - 0x1c], 4
// 0072508d  7708                 ja 0x725097
// 0072508f  750a                 jne 0x72509b
// 00725091  837de800             cmp dword ptr [ebp - 0x18], 0
// 00725095  7604                 jbe 0x72509b
// 00725097  c6460c01             mov byte ptr [esi + 0xc], 1
// 0072509b  8d4e18               lea ecx, [esi + 0x18]
// 0072509e  c7461000080000       mov dword ptr [esi + 0x10], 0x800
// 007250a5  c74614c0507e00       mov dword ptr [esi + 0x14], 0x7e50c0
// 007250ac  e81fc8cdff           call 0x4018d0
// 007250b1  85c0                 test eax, eax
// 007250b3  7d07                 jge 0x7250bc
// 007250b5  c60598be8b0001       mov byte ptr [0x8bbe98], 1
// 007250bc  8b4d74               mov ecx, dword ptr [ebp + 0x74]
// 007250bf  8bc6                 mov eax, esi
// 007250c1  33cd                 xor ecx, ebp
// 007250c3  5e                   pop esi
// 007250c4  e855b9f0ff           call 0x630a1e
// 007250c9  83c578               add ebp, 0x78
// 007250cc  c9                   leave 
// 007250cd  c3                   ret 
// 007250ce  56                   push esi
// 007250cf  ff3528988c00         push dword ptr [0x8c9828]
// 007250d5  8bf1                 mov esi, ecx
// 007250d7  56                   push esi
// 007250d8  e836feffff           call 0x724f13
// 007250dd  8d4e20               lea ecx, [esi + 0x20]
// 007250e0  5e                   pop esi
// 007250e1  e9a8fdffff           jmp 0x724e8e

// roc-flags: /O1 /GS /EHsc /MD

#include <string.h>

typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef long HRESULT;
typedef struct HINSTANCE__ *HINSTANCE;
struct GUID { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };
struct IMAGE_DOS_HEADER { unsigned short e_magic; };
struct CRITICAL_SECTION { void *a; long b, c; void *d, *e; unsigned long f; };
struct OSVERSIONINFO {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    char szCSDVersion[128];
};
#define VER_PLATFORM_WIN32_WINDOWS 1
#define VER_PLATFORM_WIN32_NT 2
#define FAILED(hr) (((HRESULT)(hr)) < 0)
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(OSVERSIONINFO *);

extern "C" IMAGE_DOS_HEADER __ImageBase;
extern "C" const GUID GUID_ATLVer70;

struct CComCriticalSection {
    CRITICAL_SECTION m_sec;
    HRESULT Init();
};

struct _ATL_BASE_MODULE_Base {
    _ATL_BASE_MODULE_Base();
};

struct CAtlBaseModule : _ATL_BASE_MODULE_Base {
    UINT cbSize;
    HINSTANCE m_hInst;
    HINSTANCE m_hInstResource;
    bool m_bNT5orWin98;
    DWORD dwAtlBuildVer;
    const GUID *pguidVer;
    CComCriticalSection m_csResource;
    static bool m_bInitFailed;
    CAtlBaseModule();
};

CAtlBaseModule::CAtlBaseModule()
{
    cbSize = 0x3c;

    m_hInst = m_hInstResource = reinterpret_cast<HINSTANCE>(&__ImageBase);

    m_bNT5orWin98 = false;
    OSVERSIONINFO version;
    memset(&version, 0, sizeof(version));
    version.dwOSVersionInfoSize = sizeof(version);
    ::GetVersionExA(&version);
    if (version.dwPlatformId == VER_PLATFORM_WIN32_NT)
    {
        if (version.dwMajorVersion >= 5)
        {
            m_bNT5orWin98 = true;
        }
    }
    else if (version.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
    {
        if ((version.dwMajorVersion > 4) || ((version.dwMajorVersion == 4) &&
            (version.dwMinorVersion > 0)))
        {
            m_bNT5orWin98 = true;
        }
    }

    dwAtlBuildVer = 0x800;
    pguidVer = &GUID_ATLVer70;

    if (FAILED(m_csResource.Init()))
    {
        CAtlBaseModule::m_bInitFailed = true;
    }
}
