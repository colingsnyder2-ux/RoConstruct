// from server: 100% by colin
// roc 2007-08 00580420  unit: RBX::Log  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00580420
//
// 00580420  56                   push esi
// 00580421  8b742408             mov esi, dword ptr [esp + 8]
// 00580425  57                   push edi
// 00580426  8b3df8e57700         mov edi, dword ptr [0x77e5f8]
// 0058042c  68440b7a00           push 0x7a0b44
// 00580431  56                   push esi
// 00580432  ffd7                 call edi
// 00580434  83c408               add esp, 8
// 00580437  84c0                 test al, al
// 00580439  755a                 jne 0x580495
// 0058043b  68f8bf7a00           push 0x7abff8
// 00580440  56                   push esi
// 00580441  ffd7                 call edi
// 00580443  83c408               add esp, 8
// 00580446  84c0                 test al, al
// 00580448  754b                 jne 0x580495
// 0058044a  68f0bf7a00           push 0x7abff0
// 0058044f  56                   push esi
// 00580450  ffd7                 call edi
// 00580452  83c408               add esp, 8
// 00580455  84c0                 test al, al
// 00580457  753c                 jne 0x580495
// 00580459  68d0797900           push 0x7979d0
// 0058045e  56                   push esi
// 0058045f  ffd7                 call edi
// 00580461  83c408               add esp, 8
// 00580464  84c0                 test al, al
// 00580466  7521                 jne 0x580489
// 00580468  68e8bf7a00           push 0x7abfe8
// 0058046d  56                   push esi
// 0058046e  ffd7                 call edi
// 00580470  83c408               add esp, 8
// 00580473  84c0                 test al, al
// 00580475  7512                 jne 0x580489
// 00580477  68e0bf7a00           push 0x7abfe0
// 0058047c  56                   push esi
// 0058047d  ffd7                 call edi
// 0058047f  83c408               add esp, 8
// 00580482  84c0                 test al, al
// 00580484  7503                 jne 0x580489
// 00580486  5f                   pop edi
// 00580487  5e                   pop esi
// 00580488  c3                   ret 
// 00580489  8b442410             mov eax, dword ptr [esp + 0x10]
// 0058048d  5f                   pop edi
// 0058048e  c60000               mov byte ptr [eax], 0
// 00580491  b001                 mov al, 1
// 00580493  5e                   pop esi
// 00580494  c3                   ret 
// 00580495  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00580499  5f                   pop edi
// 0058049a  c60101               mov byte ptr [ecx], 1
// 0058049d  b001                 mov al, 1
// 0058049f  5e                   pop esi
// 005804a0  c3                   ret 
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