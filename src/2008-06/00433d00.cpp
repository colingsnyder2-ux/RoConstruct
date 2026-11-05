// from server: 100% by colin
// from server: 95% by colin
// roc 2008-06 00433d00  unit: CObjectBrowser  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00433d00
//
// 00433d00  6aff                 push -1
// 00433d02  68c9107c00           push 0x7c10c9
// 00433d07  64a100000000         mov eax, dword ptr fs:[0]
// 00433d0d  50                   push eax
// 00433d0e  64892500000000       mov dword ptr fs:[0], esp
// 00433d15  51                   push ecx
// 00433d16  56                   push esi
// 00433d17  8bf1                 mov esi, ecx
// 00433d19  57                   push edi
// 00433d1a  8d4c2408             lea ecx, [esp + 8]
// 00433d1e  ff15043f8000         call dword ptr [0x803f04]
// 00433d24  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00433d28  8b4704               mov eax, dword ptr [edi + 4]
// 00433d2b  8d4804               lea ecx, [eax + 4]
// 00433d2e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00433d36  ff1564248000         call dword ptr [0x802464]
// 00433d3c  50                   push eax
// 00433d3d  8d44240c             lea eax, [esp + 0xc]
// 00433d41  68ac038100           push 0x8103ac
// 00433d46  50                   push eax
// 00433d47  ff15dc3e8000         call dword ptr [0x803edc]
// 00433d4d  83c40c               add esp, 0xc
// 00433d50  8d4c2408             lea ecx, [esp + 8]
// 00433d54  ff15e03e8000         call dword ptr [0x803ee0]
// 00433d5a  680200ffff           push 0xffff0002
// 00433d5f  680000ffff           push 0xffff0000
// 00433d64  6a00                 push 0
// 00433d66  6a00                 push 0
// 00433d68  6a00                 push 0
// 00433d6a  6a09                 push 9
// 00433d6c  6a09                 push 9
// 00433d6e  50                   push eax
// 00433d6f  6a23                 push 0x23
// 00433d71  8bce                 mov ecx, esi
// 00433d73  e858d32600           call 0x6a10d0
// 00433d78  57                   push edi
// 00433d79  6a00                 push 0
// 00433d7b  6a00                 push 0
// 00433d7d  6a00                 push 0
// 00433d7f  6a00                 push 0
// 00433d81  6a00                 push 0
// 00433d83  6a04                 push 4
// 00433d85  50                   push eax
// 00433d86  8bce                 mov ecx, esi
// 00433d88  e849d32600           call 0x6a10d6
// 00433d8d  8d4c2408             lea ecx, [esp + 8]
// 00433d91  ff15143f8000         call dword ptr [0x803f14]
// 00433d97  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00433d9b  5f                   pop edi
// 00433d9c  5e                   pop esi
// 00433d9d  64890d00000000       mov dword ptr fs:[0], ecx
// 00433da4  83c410               add esp, 0x10
// 00433da7  c20400               ret 4

struct Text
{
    unsigned int value;
    Text();
    __declspec(dllimport) ~Text() throw();
    const char* data() const;
};

extern void (__thiscall* text_construct)(Text*);
extern void (__thiscall* text_destroy)(Text*);
extern const char* (__thiscall* text_data)(const Text*);
extern const char* (__thiscall* string_data)(const void*);
extern void (__cdecl* text_format)(Text*, const char*, ...);
extern const char format_string[];

inline Text::Text()
{
    text_construct(this);
}

inline const char* Text::data() const
{
    return text_data(this);
}

struct Item
{
    unsigned int reserved;
    char* object;
};

struct CObjectBrowser
{
    void* create(int, const char*, int, int, int, int, int,
                 unsigned int, unsigned int);
    void attach(void*, int, int, int, int, int, int, Item*);
    void func_00433d00(Item*);
};

void CObjectBrowser::func_00433d00(Item* item)
{
    Text text;
    char* obj = item->object;
    text_format(&text, format_string, string_data(obj + 4));
    void* control = create(35, text.data(), 9, 9, 0, 0, 0,
                           0xffff0000U, 0xffff0002U);
    attach(control, 4, 0, 0, 0, 0, 0, item);
}
