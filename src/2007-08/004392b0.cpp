// from server: 100% by Yeetserama
// roc 2007-08 004392b0  unit: HVCXTPPropertyGridItem::?$XItem  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004392b0
//
// 004392b0  6aff                 push -1
// 004392b2  68c2e77300           push 0x73e7c2
// 004392b7  64a100000000         mov eax, dword ptr fs:[0]
// 004392bd  50                   push eax
// 004392be  83ec24               sub esp, 0x24
// 004392c1  53                   push ebx
// 004392c2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004392c7  33c4                 xor eax, esp
// 004392c9  50                   push eax
// 004392ca  8d44242c             lea eax, [esp + 0x2c]
// 004392ce  64a300000000         mov dword ptr fs:[0], eax
// 004392d4  8d442408             lea eax, [esp + 8]
// 004392d8  50                   push eax
// 004392d9  e872fbffff           call 0x438e50
// 004392de  8bc8                 mov ecx, eax
// 004392e0  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004392e8  ff1598dd7700         call dword ptr [0x77dd98]
// 004392ee  50                   push eax
// 004392ef  8d4c2414             lea ecx, [esp + 0x14]
// 004392f3  ff1598e67700         call dword ptr [0x77e698]
// 004392f9  8d4c240c             lea ecx, [esp + 0xc]
// 004392fd  51                   push ecx
// 004392fe  8d542414             lea edx, [esp + 0x14]
// 00439302  52                   push edx
// 00439303  c644243c01           mov byte ptr [esp + 0x3c], 1
// 00439308  e873781400           call 0x580b80
// 0043930d  83c408               add esp, 8
// 00439310  8d4c2410             lea ecx, [esp + 0x10]
// 00439314  8ad8                 mov bl, al
// 00439316  c644243400           mov byte ptr [esp + 0x34], 0
// 0043931b  ff15ace67700         call dword ptr [0x77e6ac]
// 00439321  8d4c2408             lea ecx, [esp + 8]
// 00439325  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0043932b  f6db                 neg bl
// 0043932d  1bdb                 sbb ebx, ebx
// 0043932f  235c240c             and ebx, dword ptr [esp + 0xc]
// 00439333  8bc3                 mov eax, ebx
// 00439335  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00439339  64890d00000000       mov dword ptr fs:[0], ecx
// 00439340  59                   pop ecx
// 00439341  5b                   pop ebx
// 00439342  83c430               add esp, 0x30
// 00439345  c3                   ret 
// copied from an identical function in another client (function ?f@X_00437ed0@ns_ROCX000005@@QAEHXZ)

namespace ns_ROCX000005 {
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
}
