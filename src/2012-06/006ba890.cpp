// from server: 100% by Xemicl
// roc 2012-06 006ba890  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006ba890
//
// 006ba890  53                   push ebx
// 006ba891  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006ba895  57                   push edi
// 006ba896  8bf9                 mov edi, ecx
// 006ba898  85db                 test ebx, ebx
// 006ba89a  750a                 jne 0x6ba8a6
// 006ba89c  6857000780           push 0x80070057
// 006ba8a1  e80a99d4ff           call 0x4041b0
// 006ba8a6  55                   push ebp
// 006ba8a7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 006ba8ab  56                   push esi
// 006ba8ac  55                   push ebp
// 006ba8ad  53                   push ebx
// 006ba8ae  ff15dc28b200         call dword ptr [0xb228dc]
// 006ba8b4  8bf0                 mov esi, eax
// 006ba8b6  8b07                 mov eax, dword ptr [edi]
// 006ba8b8  8b50f8               mov edx, dword ptr [eax - 8]
// 006ba8bb  83e810               sub eax, 0x10
// 006ba8be  b901000000           mov ecx, 1
// 006ba8c3  2b480c               sub ecx, dword ptr [eax + 0xc]
// 006ba8c6  2bd6                 sub edx, esi
// 006ba8c8  83c408               add esp, 8
// 006ba8cb  0bca                 or ecx, edx
// 006ba8cd  7d08                 jge 0x6ba8d7
// 006ba8cf  56                   push esi
// 006ba8d0  8bcf                 mov ecx, edi
// 006ba8d2  e8f94ddbff           call 0x46f6d0
// 006ba8d7  8b0f                 mov ecx, dword ptr [edi]
// 006ba8d9  55                   push ebp
// 006ba8da  53                   push ebx
// 006ba8db  8d4601               lea eax, [esi + 1]
// 006ba8de  50                   push eax
// 006ba8df  51                   push ecx
// 006ba8e0  ff158428b200         call dword ptr [0xb22884]
// 006ba8e6  83c410               add esp, 0x10
// 006ba8e9  85f6                 test esi, esi
// 006ba8eb  7c17                 jl 0x6ba904
// 006ba8ed  8b07                 mov eax, dword ptr [edi]
// 006ba8ef  3b70f8               cmp esi, dword ptr [eax - 8]
// 006ba8f2  7f10                 jg 0x6ba904
// 006ba8f4  8970f4               mov dword ptr [eax - 0xc], esi
// 006ba8f7  8b17                 mov edx, dword ptr [edi]
// 006ba8f9  c6041600             mov byte ptr [esi + edx], 0
// 006ba8fd  5e                   pop esi
// 006ba8fe  5d                   pop ebp
// 006ba8ff  5f                   pop edi
// 006ba900  5b                   pop ebx
// 006ba901  c20800               ret 8
// 006ba904  6857000780           push 0x80070057
// 006ba909  e8a298d4ff           call 0x4041b0
// copied from an identical function in another client (function ?format@S@ns_ROCX00000a@@QAEXPBDPAD@Z)

namespace ns_ROCX00000a {
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
}
