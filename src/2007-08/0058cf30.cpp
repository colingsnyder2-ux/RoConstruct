// from server: 100% by colin
// roc 2007-08 0058cf30  unit: RBX::SoundService  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058cf30
//
// 0058cf30  83ec1c               sub esp, 0x1c
// 0058cf33  56                   push esi
// 0058cf34  8b742424             mov esi, dword ptr [esp + 0x24]
// 0058cf38  57                   push edi
// 0058cf39  6a02                 push 2
// 0058cf3b  6a00                 push 0
// 0058cf3d  68a0f67a00           push 0x7af6a0
// 0058cf42  8bce                 mov ecx, esi
// 0058cf44  ff158ce47700         call dword ptr [0x77e48c]
// 0058cf4a  8bf8                 mov edi, eax
// 0058cf4c  85ff                 test edi, edi
// 0058cf4e  7d08                 jge 0x58cf58
// 0058cf50  5f                   pop edi
// 0058cf51  32c0                 xor al, al
// 0058cf53  5e                   pop esi
// 0058cf54  83c41c               add esp, 0x1c
// 0058cf57  c3                   ret 
// 0058cf58  57                   push edi
// 0058cf59  6a00                 push 0
// 0058cf5b  8d442410             lea eax, [esp + 0x10]
// 0058cf5f  50                   push eax
// 0058cf60  8bce                 mov ecx, esi
// 0058cf62  ff1538e67700         call dword ptr [0x77e638]
// 0058cf68  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0058cf6c  7205                 jb 0x58cf73
// 0058cf6e  8b4004               mov eax, dword ptr [eax + 4]
// 0058cf71  eb03                 jmp 0x58cf76
// 0058cf73  83c004               add eax, 4
// 0058cf76  53                   push ebx
// 0058cf77  8b1d80e97700         mov ebx, dword ptr [0x77e980]
// 0058cf7d  55                   push ebp
// 0058cf7e  50                   push eax
// 0058cf7f  ffd3                 call ebx
// 0058cf81  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 0058cf85  83c404               add esp, 4
// 0058cf88  8d4c2410             lea ecx, [esp + 0x10]
// 0058cf8c  66894500             mov word ptr [ebp], ax
// 0058cf90  ff15ace67700         call dword ptr [0x77e6ac]
// 0058cf96  8b4614               mov eax, dword ptr [esi + 0x14]
// 0058cf99  8d4f01               lea ecx, [edi + 1]
// 0058cf9c  3bc1                 cmp eax, ecx
// 0058cf9e  7d0a                 jge 0x58cfaa
// 0058cfa0  5d                   pop ebp
// 0058cfa1  5b                   pop ebx
// 0058cfa2  5f                   pop edi
// 0058cfa3  32c0                 xor al, al
// 0058cfa5  5e                   pop esi
// 0058cfa6  83c41c               add esp, 0x1c
// 0058cfa9  c3                   ret 
// 0058cfaa  2bc1                 sub eax, ecx
// 0058cfac  50                   push eax
// 0058cfad  51                   push ecx
// 0058cfae  8d4c2418             lea ecx, [esp + 0x18]
// 0058cfb2  51                   push ecx
// 0058cfb3  8bce                 mov ecx, esi
// 0058cfb5  ff1538e67700         call dword ptr [0x77e638]
// 0058cfbb  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0058cfbf  7205                 jb 0x58cfc6
// 0058cfc1  8b4004               mov eax, dword ptr [eax + 4]
// 0058cfc4  eb03                 jmp 0x58cfc9
// 0058cfc6  83c004               add eax, 4
// 0058cfc9  50                   push eax
// 0058cfca  ffd3                 call ebx
// 0058cfcc  83c404               add esp, 4
// 0058cfcf  8d4c2410             lea ecx, [esp + 0x10]
// 0058cfd3  66894502             mov word ptr [ebp + 2], ax
// 0058cfd7  ff15ace67700         call dword ptr [0x77e6ac]
// 0058cfdd  5d                   pop ebp
// 0058cfde  5b                   pop ebx
// 0058cfdf  5f                   pop edi
// 0058cfe0  b001                 mov al, 1
// 0058cfe2  5e                   pop esi
// 0058cfe3  83c41c               add esp, 0x1c
// 0058cfe6  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000@@YA_NPBUString@@PAF@Z)

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