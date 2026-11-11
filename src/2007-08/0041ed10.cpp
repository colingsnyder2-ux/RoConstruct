// from server: 100% by EspClaude
// roc-flags: /O2 /Ob0 /GS /EHsc /MD
// from server: 71% by colin
// roc 2007-08 0041ed10  unit: CSettingsExplorer  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041ed10
//
// 0041ed10  56                   push esi
// 0041ed11  8bf1                 mov esi, ecx
// 0041ed13  837e0400             cmp dword ptr [esi + 4], 0
// 0041ed17  753a                 jne 0x41ed53
// 0041ed19  57                   push edi
// 0041ed1a  8d7e0c               lea edi, [esi + 0xc]
// 0041ed1d  8bcf                 mov ecx, edi
// 0041ed1f  ff157cd57700         call dword ptr [0x77d57c]
// 0041ed25  50                   push eax
// 0041ed26  ff15c8d27700         call dword ptr [0x77d2c8]
// 0041ed2c  85c0                 test eax, eax
// 0041ed2e  894604               mov dword ptr [esi + 4], eax
// 0041ed31  751d                 jne 0x41ed50
// 0041ed33  8bcf                 mov ecx, edi
// 0041ed35  ff157cd57700         call dword ptr [0x77d57c]
// 0041ed3b  50                   push eax
// 0041ed3c  ff157cd27700         call dword ptr [0x77d27c]
// 0041ed42  85c0                 test eax, eax
// 0041ed44  894604               mov dword ptr [esi + 4], eax
// 0041ed47  0f95c0               setne al
// 0041ed4a  884608               mov byte ptr [esi + 8], al
// 0041ed4d  8b4604               mov eax, dword ptr [esi + 4]
// 0041ed50  5f                   pop edi
// 0041ed51  5e                   pop esi
// 0041ed52  c3                   ret 
// 0041ed53  8b4604               mov eax, dword ptr [esi + 4]
// 0041ed56  5e                   pop esi
// 0041ed57  c3                   ret 

// IAT 0x77d57c = MFC80.DLL ord3397 (thiscall, CString accessor); 0x77d2c8 = GetModuleHandleA; 0x77d27c = LoadLibraryA
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);

class CStr {
public:
    char* m_pszData;
    __declspec(dllimport) operator const char*() const { return m_pszData; }
};

struct CSettingsExplorer {
    int field_0;
    void* m_hModule;
    bool m_bLoaded;
    char pad_9[3];
    CStr m_name;
    void* get();
};

void* CSettingsExplorer::get()
{
    if (m_hModule == 0) {
        m_hModule = GetModuleHandleA(m_name);
        if (m_hModule == 0) {
            m_hModule = LoadLibraryA(m_name);
            m_bLoaded = (m_hModule != 0);
        }
    }
    return m_hModule;
}
