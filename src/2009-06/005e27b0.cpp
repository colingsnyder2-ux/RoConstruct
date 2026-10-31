// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0055dae0  unit: std::D::DU?$char_traits::V?$basic_string::?$sp_counted_impl_p  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055dae0
//
// 0055dae0  53                   push ebx
// 0055dae1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0055dae5  57                   push edi
// 0055dae6  8bf9                 mov edi, ecx
// 0055dae8  85db                 test ebx, ebx
// 0055daea  750a                 jne 0x55daf6
// 0055daec  6857000780           push 0x80070057
// 0055daf1  e80a35eaff           call 0x401000
// 0055daf6  55                   push ebp
// 0055daf7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0055dafb  56                   push esi
// 0055dafc  55                   push ebp
// 0055dafd  53                   push ebx
// 0055dafe  ff1594278000         call dword ptr [0x802794]
// 0055db04  8bf0                 mov esi, eax
// 0055db06  8b07                 mov eax, dword ptr [edi]
// 0055db08  8b50f8               mov edx, dword ptr [eax - 8]
// 0055db0b  83e810               sub eax, 0x10
// 0055db0e  b901000000           mov ecx, 1
// 0055db13  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0055db16  2bd6                 sub edx, esi
// 0055db18  83c408               add esp, 8
// 0055db1b  0bca                 or ecx, edx
// 0055db1d  7d08                 jge 0x55db27
// 0055db1f  56                   push esi
// 0055db20  8bcf                 mov ecx, edi
// 0055db22  e8d998eaff           call 0x407400
// 0055db27  8b0f                 mov ecx, dword ptr [edi]
// 0055db29  55                   push ebp
// 0055db2a  53                   push ebx
// 0055db2b  8d4601               lea eax, [esi + 1]
// 0055db2e  50                   push eax
// 0055db2f  51                   push ecx
// 0055db30  ff1540278000         call dword ptr [0x802740]
// 0055db36  83c410               add esp, 0x10
// 0055db39  85f6                 test esi, esi
// 0055db3b  7c17                 jl 0x55db54
// 0055db3d  8b07                 mov eax, dword ptr [edi]
// 0055db3f  3b70f8               cmp esi, dword ptr [eax - 8]
// 0055db42  7f10                 jg 0x55db54
// 0055db44  8970f4               mov dword ptr [eax - 0xc], esi
// 0055db47  8b17                 mov edx, dword ptr [edi]
// 0055db49  c6041600             mov byte ptr [esi + edx], 0
// 0055db4d  5e                   pop esi
// 0055db4e  5d                   pop ebp
// 0055db4f  5f                   pop edi
// 0055db50  5b                   pop ebx
// 0055db51  c20800               ret 8
// 0055db54  6857000780           push 0x80070057
// 0055db59  e8a234eaff           call 0x401000

extern "C" {
    extern int (__cdecl * const _vscprintf)(const char *, char *);
    extern int (__cdecl * const vsprintf_s)(char *, unsigned int, const char *, char *);
}

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(long);
}

struct StringData {
    void *manager;
    int length;
    int capacity;
    int references;
};

struct S {
    char *data;
    void prepare(int);
    void format(const char *, char *);
};

void S::format(const char *formatString, char *arguments)
{
    if (!formatString)
        ATL::AtlThrowImpl((long)0x80070057);

    int length = _vscprintf(formatString, arguments);
    StringData *header = reinterpret_cast<StringData *>(data) - 1;

    if (((1 - header->references) | (header->capacity - length)) < 0)
        prepare(length);

    vsprintf_s(data, length + 1, formatString, arguments);

    if (length < 0 ||
        length > (reinterpret_cast<StringData *>(data) - 1)->capacity)
        ATL::AtlThrowImpl((long)0x80070057);

    (reinterpret_cast<StringData *>(data) - 1)->length = length;
    data[length] = 0;
}
