// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 004478f0  unit: CRobloxModule  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004478f0
//
// 004478f0  64a100000000         mov eax, dword ptr fs:[0]
// 004478f6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004478fa  6aff                 push -1
// 004478fc  68d9b88500           push 0x85b8d9
// 00447901  50                   push eax
// 00447902  64892500000000       mov dword ptr fs:[0], esp
// 00447909  83ec1c               sub esp, 0x1c
// 0044790c  53                   push ebx
// 0044790d  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 00447911  8b03                 mov eax, dword ptr [ebx]
// 00447913  8b4008               mov eax, dword ptr [eax + 8]
// 00447916  51                   push ecx
// 00447917  8bc8                 mov ecx, eax
// 00447919  ff1560e48900         call dword ptr [0x89e460]
// 0044791f  85c0                 test eax, eax
// 00447921  0f8590000000         jne 0x4479b7
// 00447927  56                   push esi
// 00447928  8b742438             mov esi, dword ptr [esp + 0x38]
// 0044792c  57                   push edi
// 0044792d  85f6                 test esi, esi
// 0044792f  7405                 je 0x447936
// 00447931  8d7e08               lea edi, [esi + 8]
// 00447934  eb02                 jmp 0x447938
// 00447936  33ff                 xor edi, edi
// 00447938  8b13                 mov edx, dword ptr [ebx]
// 0044793a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044793d  ff15bce48900         call dword ptr [0x89e4bc]
// 00447943  50                   push eax
// 00447944  57                   push edi
// 00447945  e8c6edffff           call 0x446710
// 0044794a  83c408               add esp, 8
// 0044794d  85f6                 test esi, esi
// 0044794f  7405                 je 0x447956
// 00447951  8d4608               lea eax, [esi + 8]
// 00447954  eb02                 jmp 0x447958
// 00447956  33c0                 xor eax, eax
// 00447958  6a3a                 push 0x3a
// 0044795a  50                   push eax
// 0044795b  e8a0efffff           call 0x446900
// 00447960  83c408               add esp, 8
// 00447963  85f6                 test esi, esi
// 00447965  7405                 je 0x44796c
// 00447967  8d7e08               lea edi, [esi + 8]
// 0044796a  eb02                 jmp 0x44796e
// 0044796c  33ff                 xor edi, edi
// 0044796e  8d44240c             lea eax, [esp + 0xc]
// 00447972  50                   push eax
// 00447973  8bcb                 mov ecx, ebx
// 00447975  e866d3ffff           call 0x444ce0
// 0044797a  50                   push eax
// 0044797b  57                   push edi
// 0044797c  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00447984  ff15e0e38900         call dword ptr [0x89e3e0]
// 0044798a  83c408               add esp, 8
// 0044798d  8d4c240c             lea ecx, [esp + 0xc]
// 00447991  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00447999  ff15c4e48900         call dword ptr [0x89e4c4]
// 0044799f  85f6                 test esi, esi
// 004479a1  7405                 je 0x4479a8
// 004479a3  8d4608               lea eax, [esi + 8]
// 004479a6  eb02                 jmp 0x4479aa
// 004479a8  33c0                 xor eax, eax
// 004479aa  6a3b                 push 0x3b
// 004479ac  50                   push eax
// 004479ad  e84eefffff           call 0x446900
// 004479b2  83c408               add esp, 8
// 004479b5  5f                   pop edi
// 004479b6  5e                   pop esi
// 004479b7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004479bb  5b                   pop ebx
// 004479bc  64890d00000000       mov dword ptr fs:[0], ecx
// 004479c3  83c428               add esp, 0x28
// 004479c6  c3                   ret 

// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct String
{
    unsigned char data[28];
    __declspec(dllimport) int compare(const char* value) const;
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~String();
};

struct NamedValue
{
    String name;
    const String& str() const { return name; }
};

inline const char* name_c_str(NamedValue* value)
{
    NamedValue* named_value = value;
    return named_value->name.c_str();
}

struct Interface
{
    NamedValue* unused;
    NamedValue* display;
    NamedValue* key;
};

struct S
{
    Interface* object;
    int argument;
    String get();
};

struct Stream
{
    int marker;
};

struct InputPart
{
    int reserved[2];
};

struct CombinedStream : InputPart, Stream
{
};

extern Stream& __cdecl insert_text(Stream&, const char*);
extern Stream& __cdecl insert_character(Stream&, char);

typedef Stream& (__cdecl *InsertString)(Stream&, const String&);
extern InsertString insert_string;

void emit(const char* key, CombinedStream* output, S* value)
{
    Interface* o = value->object;
    if (o->key->str().compare(key) != 0)
        return;

    insert_text(*static_cast<Stream*>(output),
                name_c_str(value->object->display));
    insert_character(*static_cast<Stream*>(output), ':');

    insert_string(*static_cast<Stream*>(output), value->get());
    insert_character(*static_cast<Stream*>(output), ';');
}
