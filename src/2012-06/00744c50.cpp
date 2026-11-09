// roc 2012-06 00744c50  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00744c50
//
// 00744c50  83ec1c               sub esp, 0x1c
// 00744c53  56                   push esi
// 00744c54  8b742424             mov esi, dword ptr [esp + 0x24]
// 00744c58  57                   push edi
// 00744c59  6a02                 push 2
// 00744c5b  6a00                 push 0
// 00744c5d  6880a9ba00           push 0xbaa980
// 00744c62  8bce                 mov ecx, esi
// 00744c64  ff154424b200         call dword ptr [0xb22444]
// 00744c6a  8bf8                 mov edi, eax
// 00744c6c  85ff                 test edi, edi
// 00744c6e  7d08                 jge 0x744c78
// 00744c70  5f                   pop edi
// 00744c71  32c0                 xor al, al
// 00744c73  5e                   pop esi
// 00744c74  83c41c               add esp, 0x1c
// 00744c77  c3                   ret 
// 00744c78  57                   push edi
// 00744c79  6a00                 push 0
// 00744c7b  8d442410             lea eax, [esp + 0x10]
// 00744c7f  50                   push eax
// 00744c80  8bce                 mov ecx, esi
// 00744c82  ff15e826b200         call dword ptr [0xb226e8]
// 00744c88  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00744c8c  7205                 jb 0x744c93
// 00744c8e  8b4004               mov eax, dword ptr [eax + 4]
// 00744c91  eb03                 jmp 0x744c96
// 00744c93  83c004               add eax, 4
// 00744c96  53                   push ebx
// 00744c97  8b1dd42ab200         mov ebx, dword ptr [0xb22ad4]
// 00744c9d  55                   push ebp
// 00744c9e  50                   push eax
// 00744c9f  ffd3                 call ebx
// 00744ca1  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 00744ca5  83c404               add esp, 4
// 00744ca8  8d4c2410             lea ecx, [esp + 0x10]
// 00744cac  66894500             mov word ptr [ebp], ax
// 00744cb0  ff153c26b200         call dword ptr [0xb2263c]
// 00744cb6  8b4614               mov eax, dword ptr [esi + 0x14]
// 00744cb9  8d4f01               lea ecx, [edi + 1]
// 00744cbc  3bc1                 cmp eax, ecx
// 00744cbe  7d0a                 jge 0x744cca
// 00744cc0  5d                   pop ebp
// 00744cc1  5b                   pop ebx
// 00744cc2  5f                   pop edi
// 00744cc3  32c0                 xor al, al
// 00744cc5  5e                   pop esi
// 00744cc6  83c41c               add esp, 0x1c
// 00744cc9  c3                   ret 
// 00744cca  2bc1                 sub eax, ecx
// 00744ccc  50                   push eax
// 00744ccd  51                   push ecx
// 00744cce  8d4c2418             lea ecx, [esp + 0x18]
// 00744cd2  51                   push ecx
// 00744cd3  8bce                 mov ecx, esi
// 00744cd5  ff15e826b200         call dword ptr [0xb226e8]
// 00744cdb  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00744cdf  7205                 jb 0x744ce6
// 00744ce1  8b4004               mov eax, dword ptr [eax + 4]
// 00744ce4  eb03                 jmp 0x744ce9
// 00744ce6  83c004               add eax, 4
// 00744ce9  50                   push eax
// 00744cea  ffd3                 call ebx
// 00744cec  83c404               add esp, 4
// 00744cef  8d4c2410             lea ecx, [esp + 0x10]
// 00744cf3  66894502             mov word ptr [ebp + 2], ax
// 00744cf7  ff153c26b200         call dword ptr [0xb2263c]
// 00744cfd  5d                   pop ebp
// 00744cfe  5b                   pop ebx
// 00744cff  5f                   pop edi
// 00744d00  b001                 mov al, 1
// 00744d02  5e                   pop esi
// 00744d03  83c41c               add esp, 0x1c
// 00744d06  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_005be950@@YA_NPBUString@@PAF@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

extern const char separators[3];
extern unsigned int (__thiscall *find_first_of)(
    const String*, const char*, unsigned int, unsigned int);
extern String* (__thiscall *substring)(
    const String*, String*, unsigned int, unsigned int);
extern void (__thiscall *destroy_string)(String*);
extern int (__cdecl *convert_integer)(const char*);

bool func_005be950(const String* source, short* output)
{
    String temporary;
    int position = find_first_of(source, separators, 0, 2);
    if (position < 0)
        return false;

    String* part = substring(source, &temporary, 0, position);
    const char* text =
        part->capacity >= 16 ? part->storage.pointer : part->storage.buffer;
    int (__cdecl *convert)(const char*) = convert_integer;
    output[0] = (short)convert(text);
    destroy_string(&temporary);

    int next = position + 1;
    if ((int)source->length < next)
        return false;

    part = substring(source, &temporary, next, source->length - next);
    output[1] = (short)convert(
        part->capacity >= 16 ? part->storage.pointer : part->storage.buffer);
    destroy_string(&temporary);
    return true;
}