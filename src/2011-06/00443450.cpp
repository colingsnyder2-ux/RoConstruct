// from server: 100% by Yeetserama
// roc 2011-06 00443450  unit: HVCXTPPropertyGridItem::?$XItem  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00443450
//
// 00443450  6aff                 push -1
// 00443452  68a2179d00           push 0x9d17a2
// 00443457  64a100000000         mov eax, dword ptr fs:[0]
// 0044345d  50                   push eax
// 0044345e  64892500000000       mov dword ptr fs:[0], esp
// 00443465  83ec24               sub esp, 0x24
// 00443468  53                   push ebx
// 00443469  8d442404             lea eax, [esp + 4]
// 0044346d  50                   push eax
// 0044346e  e87dfcffff           call 0x4430f0
// 00443473  8bc8                 mov ecx, eax
// 00443475  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0044347d  ff15c82da400         call dword ptr [0xa42dc8]
// 00443483  50                   push eax
// 00443484  8d4c2410             lea ecx, [esp + 0x10]
// 00443488  ff15c404a400         call dword ptr [0xa404c4]
// 0044348e  8d4c2408             lea ecx, [esp + 8]
// 00443492  51                   push ecx
// 00443493  8d542410             lea edx, [esp + 0x10]
// 00443497  52                   push edx
// 00443498  c644243801           mov byte ptr [esp + 0x38], 1
// 0044349d  e88ecc2000           call 0x650130
// 004434a2  83c408               add esp, 8
// 004434a5  8d4c240c             lea ecx, [esp + 0xc]
// 004434a9  8ad8                 mov bl, al
// 004434ab  c644243000           mov byte ptr [esp + 0x30], 0
// 004434b0  ff15d004a400         call dword ptr [0xa404d0]
// 004434b6  8d4c2404             lea ecx, [esp + 4]
// 004434ba  ff15082ea400         call dword ptr [0xa42e08]
// 004434c0  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004434c4  0fb6c3               movzx eax, bl
// 004434c7  f7d8                 neg eax
// 004434c9  1bc0                 sbb eax, eax
// 004434cb  23442408             and eax, dword ptr [esp + 8]
// 004434cf  5b                   pop ebx
// 004434d0  64890d00000000       mov dword ptr fs:[0], ecx
// 004434d7  83c430               add esp, 0x30
// 004434da  c3                   ret 
// copied from an identical function in another client (function ?f@X_00437ed0@ns_ROCX000003@@QAEHXZ)

namespace ns_ROCX000003 {
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
