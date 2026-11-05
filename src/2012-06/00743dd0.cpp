// roc 2012-06 00743dd0  unit: boost::bad_lexical_cast  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00743dd0
//
// 00743dd0  56                   push esi
// 00743dd1  8b742408             mov esi, dword ptr [esp + 8]
// 00743dd5  57                   push edi
// 00743dd6  8b3de426b200         mov edi, dword ptr [0xb226e4]
// 00743ddc  683c37b800           push 0xb8373c
// 00743de1  56                   push esi
// 00743de2  ffd7                 call edi
// 00743de4  83c408               add esp, 8
// 00743de7  84c0                 test al, al
// 00743de9  755a                 jne 0x743e45
// 00743deb  688024b700           push 0xb72480
// 00743df0  56                   push esi
// 00743df1  ffd7                 call edi
// 00743df3  83c408               add esp, 8
// 00743df6  84c0                 test al, al
// 00743df8  754b                 jne 0x743e45
// 00743dfa  68e0a8ba00           push 0xbaa8e0
// 00743dff  56                   push esi
// 00743e00  ffd7                 call edi
// 00743e02  83c408               add esp, 8
// 00743e05  84c0                 test al, al
// 00743e07  753c                 jne 0x743e45
// 00743e09  680016b500           push 0xb51600
// 00743e0e  56                   push esi
// 00743e0f  ffd7                 call edi
// 00743e11  83c408               add esp, 8
// 00743e14  84c0                 test al, al
// 00743e16  7521                 jne 0x743e39
// 00743e18  68d8a8ba00           push 0xbaa8d8
// 00743e1d  56                   push esi
// 00743e1e  ffd7                 call edi
// 00743e20  83c408               add esp, 8
// 00743e23  84c0                 test al, al
// 00743e25  7512                 jne 0x743e39
// 00743e27  68d0a8ba00           push 0xbaa8d0
// 00743e2c  56                   push esi
// 00743e2d  ffd7                 call edi
// 00743e2f  83c408               add esp, 8
// 00743e32  84c0                 test al, al
// 00743e34  7503                 jne 0x743e39
// 00743e36  5f                   pop edi
// 00743e37  5e                   pop esi
// 00743e38  c3                   ret 
// 00743e39  8b442410             mov eax, dword ptr [esp + 0x10]
// 00743e3d  5f                   pop edi
// 00743e3e  c60000               mov byte ptr [eax], 0
// 00743e41  b001                 mov al, 1
// 00743e43  5e                   pop esi
// 00743e44  c3                   ret 
// 00743e45  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00743e49  5f                   pop edi
// 00743e4a  c60101               mov byte ptr [ecx], 1
// 00743e4d  b001                 mov al, 1
// 00743e4f  5e                   pop esi
// 00743e50  c3                   ret 
// copied from an identical function in another client (function ?ParseBool@@YA_NPBDPA_N@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) bool __cdecl std_string_eq_cstr(const void* str, const char* cstr);

bool ParseBool(const char* value, bool* out);

bool ParseBool(const char* value, bool* out)
{
    bool (__cdecl *eq)(const void*, const char*) = std_string_eq_cstr;

    if (eq(value, "true") || eq(value, "True") || eq(value, "TRUE"))
    {
        *out = true;
        return true;
    }
    if (eq(value, "false") || eq(value, "False") || eq(value, "FALSE"))
    {
        *out = false;
        return true;
    }
    return false;
}