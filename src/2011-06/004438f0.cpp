// from server: 100% by Yeetserama
// roc 2011-06 004438f0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004438f0
//
// 004438f0  6aff                 push -1
// 004438f2  68395f9d00           push 0x9d5f39
// 004438f7  64a100000000         mov eax, dword ptr fs:[0]
// 004438fd  50                   push eax
// 004438fe  64892500000000       mov dword ptr fs:[0], esp
// 00443905  51                   push ecx
// 00443906  56                   push esi
// 00443907  8d442404             lea eax, [esp + 4]
// 0044390b  33f6                 xor esi, esi
// 0044390d  50                   push eax
// 0044390e  89742408             mov dword ptr [esp + 8], esi
// 00443912  e8d9f7ffff           call 0x4430f0
// 00443917  8bc8                 mov ecx, eax
// 00443919  89742410             mov dword ptr [esp + 0x10], esi
// 0044391d  ff15c82da400         call dword ptr [0xa42dc8]
// 00443923  8b742418             mov esi, dword ptr [esp + 0x18]
// 00443927  50                   push eax
// 00443928  8bce                 mov ecx, esi
// 0044392a  ff15c404a400         call dword ptr [0xa404c4]
// 00443930  8d4c2404             lea ecx, [esp + 4]
// 00443934  ff15082ea400         call dword ptr [0xa42e08]
// 0044393a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044393e  8bc6                 mov eax, esi
// 00443940  5e                   pop esi
// 00443941  64890d00000000       mov dword ptr fs:[0], ecx
// 00443948  83c410               add esp, 0x10
// 0044394b  c20400               ret 4
// copied from an identical function in another client (function ?convert@X@ns_ROCX000004@@QAEPAUStr@2@PAU32@@Z)

namespace ns_ROCX000004 {
// from server: 100% by colin
struct Str {
    int words[8];
};

struct X {
    char pad[0xa4];
    Str value;
    Str* copy(Str* out);
    Str* convert(Str* out);
};

extern const char* (__thiscall* text_data)(Str*);
extern void (__thiscall* text_destroy)(void*);
extern void (__thiscall* string_construct)(Str*, const char*);

struct Temporary {
    int value;
    Temporary(X* owner, Str*& text);
    __declspec(dllimport) ~Temporary() throw();
};

inline Temporary::Temporary(X* owner, Str*& text)
{
    value = 0;
    text = owner->copy(reinterpret_cast<Str*>(this));
}


Str* X::convert(Str* out)
{
    Str* text;
    Temporary temporary(this, text);
    string_construct(out, text_data(text));
    return out;
}
}
