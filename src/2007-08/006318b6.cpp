// from server: 88% by EspClaude
// roc-flags: /O1 /Oy- /GS- /MD
// roc 2007-08 006318b6  unit: std::bad_alloc  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006318b6
//
// 006318b6  55                   push ebp
// 006318b7  8bec                 mov ebp, esp
// 006318b9  83ec10               sub esp, 0x10
// 006318bc  a188518b00           mov eax, dword ptr [0x8b5188]
// 006318c1  8365f800             and dword ptr [ebp - 8], 0
// 006318c5  8365fc00             and dword ptr [ebp - 4], 0
// 006318c9  53                   push ebx
// 006318ca  57                   push edi
// 006318cb  bf4ee640bb           mov edi, 0xbb40e64e
// 006318d0  3bc7                 cmp eax, edi
// 006318d2  bb0000ffff           mov ebx, 0xffff0000
// 006318d7  740d                 je 0x6318e6
// 006318d9  85c3                 test ebx, eax
// 006318db  7409                 je 0x6318e6
// 006318dd  f7d0                 not eax
// 006318df  a38c518b00           mov dword ptr [0x8b518c], eax
// 006318e4  eb60                 jmp 0x631946
// 006318e6  56                   push esi
// 006318e7  8d45f8               lea eax, [ebp - 8]
// 006318ea  50                   push eax
// 006318eb  ff15e0d17700         call dword ptr [0x77d1e0]
// 006318f1  8b75fc               mov esi, dword ptr [ebp - 4]
// 006318f4  3375f8               xor esi, dword ptr [ebp - 8]
// 006318f7  ff1538d27700         call dword ptr [0x77d238]
// 006318fd  33f0                 xor esi, eax
// 006318ff  ff15c4d27700         call dword ptr [0x77d2c4]
// 00631905  33f0                 xor esi, eax
// 00631907  ff158cd27700         call dword ptr [0x77d28c]
// 0063190d  33f0                 xor esi, eax
// 0063190f  8d45f0               lea eax, [ebp - 0x10]
// 00631912  50                   push eax
// 00631913  ff1528d27700         call dword ptr [0x77d228]
// 00631919  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 0063191c  3345f0               xor eax, dword ptr [ebp - 0x10]
// 0063191f  33f0                 xor esi, eax
// 00631921  3bf7                 cmp esi, edi
// 00631923  7507                 jne 0x63192c
// 00631925  be4fe640bb           mov esi, 0xbb40e64f
// 0063192a  eb0b                 jmp 0x631937
// 0063192c  85f3                 test ebx, esi
// 0063192e  7507                 jne 0x631937
// 00631930  8bc6                 mov eax, esi
// 00631932  c1e010               shl eax, 0x10
// 00631935  0bf0                 or esi, eax
// 00631937  893588518b00         mov dword ptr [0x8b5188], esi
// 0063193d  f7d6                 not esi
// 0063193f  89358c518b00         mov dword ptr [0x8b518c], esi
// 00631945  5e                   pop esi
// 00631946  5f                   pop edi
// 00631947  5b                   pop ebx
// 00631948  c9                   leave 
// 00631949  c3                   ret 
// 0063194a  6a08                 push 8
// 0063194c  b8e4d77500           mov eax, 0x75d7e4
// 00631951  e86dfbffff           call 0x6314c3
// 00631956  ff7508               push dword ptr [ebp + 8]
// 00631959  8365fc00             and dword ptr [ebp - 4], 0
// 0063195d  e894e5ffff           call 0x62fef6
// 00631962  59                   pop ecx
// 00631963  8945ec               mov dword ptr [ebp - 0x14], eax
// 00631966  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00631969  e88bfbffff           call 0x6314f9
// 0063196e  c3                   ret 

extern "C" {
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned int UINT_PTR;
typedef struct _FILETIME { DWORD dwLowDateTime; DWORD dwHighDateTime; } FILETIME;
typedef union _LARGE_INTEGER { struct { DWORD LowPart; LONG HighPart; }; __int64 QuadPart; } LARGE_INTEGER;
__declspec(dllimport) void __stdcall GetSystemTimeAsFileTime(FILETIME*);
__declspec(dllimport) DWORD __stdcall GetCurrentProcessId();
__declspec(dllimport) DWORD __stdcall GetCurrentThreadId();
__declspec(dllimport) DWORD __stdcall GetTickCount();
__declspec(dllimport) int __stdcall QueryPerformanceCounter(LARGE_INTEGER*);

#define DEFAULT_SECURITY_COOKIE 0xBB40E64E

extern UINT_PTR roc_security_cookie;
extern UINT_PTR roc_security_cookie_complement;

typedef union
{
    unsigned __int64 ft_scalar;
    FILETIME ft_struct;
} FT;

void __cdecl roc_security_init_cookie(void)
{
    UINT_PTR cookie;
    FT systime = {0};
    LARGE_INTEGER perfctr;

    if (roc_security_cookie != DEFAULT_SECURITY_COOKIE
        && (roc_security_cookie & 0xFFFF0000) != 0)
    {
        roc_security_cookie_complement = ~roc_security_cookie;
        return;
    }

    GetSystemTimeAsFileTime(&systime.ft_struct);
    cookie = systime.ft_struct.dwLowDateTime;
    cookie ^= systime.ft_struct.dwHighDateTime;

    cookie ^= GetCurrentProcessId();
    cookie ^= GetCurrentThreadId();
    cookie ^= GetTickCount();

    QueryPerformanceCounter(&perfctr);
    cookie ^= perfctr.LowPart;
    cookie ^= perfctr.HighPart;

    if (cookie == DEFAULT_SECURITY_COOKIE)
        cookie = DEFAULT_SECURITY_COOKIE + 1;
    else if ((cookie & 0xFFFF0000) == 0)
        cookie |= cookie << 16;

    roc_security_cookie = cookie;
    roc_security_cookie_complement = ~cookie;
}
}
