// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 00438160  unit: HVCXTPPropertyGridItem::?$XItem  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438160
//
// 00438160  6aff                 push -1
// 00438162  6882037c00           push 0x7c0382
// 00438167  64a100000000         mov eax, dword ptr fs:[0]
// 0043816d  50                   push eax
// 0043816e  64892500000000       mov dword ptr fs:[0], esp
// 00438175  83ec24               sub esp, 0x24
// 00438178  53                   push ebx
// 00438179  8d442404             lea eax, [esp + 4]
// 0043817d  50                   push eax
// 0043817e  e84dfdffff           call 0x437ed0
// 00438183  8bc8                 mov ecx, eax
// 00438185  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0043818d  ff15e03e8000         call dword ptr [0x803ee0]
// 00438193  50                   push eax
// 00438194  8d4c2410             lea ecx, [esp + 0x10]
// 00438198  ff1558248000         call dword ptr [0x802458]
// 0043819e  8d4c2408             lea ecx, [esp + 8]
// 004381a2  51                   push ecx
// 004381a3  8d542410             lea edx, [esp + 0x10]
// 004381a7  52                   push edx
// 004381a8  c644243801           mov byte ptr [esp + 0x38], 1
// 004381ad  e8ee631800           call 0x5be5a0
// 004381b2  83c408               add esp, 8
// 004381b5  8d4c240c             lea ecx, [esp + 0xc]
// 004381b9  8ad8                 mov bl, al
// 004381bb  c644243000           mov byte ptr [esp + 0x30], 0
// 004381c0  ff1568248000         call dword ptr [0x802468]
// 004381c6  8d4c2404             lea ecx, [esp + 4]
// 004381ca  ff15143f8000         call dword ptr [0x803f14]
// 004381d0  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004381d4  0fb6c3               movzx eax, bl
// 004381d7  f7d8                 neg eax
// 004381d9  1bc0                 sbb eax, eax
// 004381db  23442408             and eax, dword ptr [esp + 8]
// 004381df  5b                   pop ebx
// 004381e0  64890d00000000       mov dword ptr fs:[0], ecx
// 004381e7  83c430               add esp, 0x30
// 004381ea  c3                   ret 

struct Str_00437ed0 { int words[8]; };

extern const char* (__thiscall* string_data)(Str_00437ed0*);
extern void (__thiscall* string_release)(Str_00437ed0*);

struct Temporary {
    int storage;
    __declspec(dllimport) ~Temporary() throw();
};

struct X_00437ed0 {
    char pad[0xa4];
    Str_00437ed0 value;
    Temporary copy();
    int f();
};

struct Text {
    char storage[28];
    Text(const char*);
    ~Text();
};

extern void (__thiscall* text_construct)(Text*, const char*);
extern void (__thiscall* text_destroy)(Text*);
extern bool __cdecl lookup(const Text*, int*);


__forceinline Text::Text(const char* source)
{
    text_construct(this, source);
}

__forceinline Text::~Text()
{
    text_destroy(this);
}

int X_00437ed0::f()
{
    int result;
    bool found = lookup(
        &Text(string_data(reinterpret_cast<Str_00437ed0*>(&copy()))),
        &result);
    return found ? result : 0;
}
