// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00427950  unit: RobloxCrashReporter  size: 259 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00427950
//
// 00427950  6aff                 push -1
// 00427952  68bec87300           push 0x73c8be
// 00427957  64a100000000         mov eax, dword ptr fs:[0]
// 0042795d  50                   push eax
// 0042795e  81ec2c010000         sub esp, 0x12c
// 00427964  a188518b00           mov eax, dword ptr [0x8b5188]
// 00427969  33c4                 xor eax, esp
// 0042796b  89842428010000       mov dword ptr [esp + 0x128], eax
// 00427972  56                   push esi
// 00427973  57                   push edi
// 00427974  a188518b00           mov eax, dword ptr [0x8b5188]
// 00427979  33c4                 xor eax, esp
// 0042797b  50                   push eax
// 0042797c  8d842438010000       lea eax, [esp + 0x138]
// 00427983  64a300000000         mov dword ptr fs:[0], eax
// 00427989  8bb42448010000       mov esi, dword ptr [esp + 0x148]
// 00427990  6844a07800           push 0x78a044
// 00427995  83c10c               add ecx, 0xc
// 00427998  51                   push ecx
// 00427999  8d44241c             lea eax, [esp + 0x1c]
// 0042799d  50                   push eax
// 0042799e  8974241c             mov dword ptr [esp + 0x1c], esi
// 004279a2  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004279aa  ff1544e67700         call dword ptr [0x77e644]
// 004279b0  83c40c               add esp, 0xc
// 004279b3  8d4c2430             lea ecx, [esp + 0x30]
// 004279b7  51                   push ecx
// 004279b8  8d4c2418             lea ecx, [esp + 0x18]
// 004279bc  c784244401000001000000 mov dword ptr [esp + 0x144], 1
// 004279c7  ff15a8e67700         call dword ptr [0x77e6a8]
// 004279cd  8b3dc4eb7700         mov edi, dword ptr [0x77ebc4]
// 004279d3  50                   push eax
// 004279d4  6a00                 push 0
// 004279d6  6a00                 push 0
// 004279d8  681a800000           push 0x801a
// 004279dd  6a00                 push 0
// 004279df  ffd7                 call edi
// 004279e1  85c0                 test eax, eax
// 004279e3  741d                 je 0x427a02
// 004279e5  8d542430             lea edx, [esp + 0x30]
// 004279e9  52                   push edx
// 004279ea  8d4c2418             lea ecx, [esp + 0x18]
// 004279ee  ff15a8e67700         call dword ptr [0x77e6a8]
// 004279f4  50                   push eax
// 004279f5  6a00                 push 0
// 004279f7  6a00                 push 0
// 004279f9  6823800000           push 0x8023
// 004279fe  6a00                 push 0
// 00427a00  ffd7                 call edi
// 00427a02  8d442430             lea eax, [esp + 0x30]
// 00427a06  50                   push eax
// 00427a07  8bce                 mov ecx, esi
// 00427a09  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00427a0f  8d4c2414             lea ecx, [esp + 0x14]
// 00427a13  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00427a1b  c684244001000000     mov byte ptr [esp + 0x140], 0
// 00427a23  ff15ace67700         call dword ptr [0x77e6ac]
// 00427a29  8bc6                 mov eax, esi
// 00427a2b  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 00427a32  64890d00000000       mov dword ptr fs:[0], ecx
// 00427a39  59                   pop ecx
// 00427a3a  5f                   pop edi
// 00427a3b  5e                   pop esi
// 00427a3c  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 00427a43  33cc                 xor ecx, esp
// 00427a45  e8d48f2000           call 0x630a1e
// 00427a4a  81c438010000         add esp, 0x138
// 00427a50  c20400               ret 4

extern const char* (__thiscall *stringData)(const void*);

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class T, class A>
    class basic_string {
        unsigned char storage[28];
    public:
        __declspec(dllimport) ~basic_string();
        const C* c_str() const { return stringData(this); }
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    template<class C, class T, class A>
    __declspec(dllimport) basic_string<C, T, A> __cdecl operator+(const basic_string<C, T, A>&, const C*);
}

class CString {
    char* m_pszData;
public:
    __declspec(dllimport) CString(const char*);
    ~CString();
};

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathAndSubDirA(void* hwnd, int csidl, void* hToken, unsigned long dwFlags, const char* pszSubDir, char* pszPath);

class RobloxCrashReporter
{
    char pad0[0xc];
    std::string outputPath;
public:
    CString getLogDirectory();
};

CString RobloxCrashReporter::getLogDirectory()
{
    char path[260];
    std::string subDir = outputPath + "\\logs";
    if (SHGetFolderPathAndSubDirA(0, 0x801a, 0, 0, stringData(&subDir), path) != 0)
        SHGetFolderPathAndSubDirA(0, 0x8023, 0, 0, stringData(&subDir), path);
    return path;
}
