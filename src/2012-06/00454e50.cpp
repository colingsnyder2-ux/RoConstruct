// from server: 100% by Xemicl
// roc 2012-06 00454e50  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00454e50
//
// 00454e50  6aff                 push -1
// 00454e52  68d9aea900           push 0xa9aed9
// 00454e57  64a100000000         mov eax, dword ptr fs:[0]
// 00454e5d  50                   push eax
// 00454e5e  64892500000000       mov dword ptr fs:[0], esp
// 00454e65  51                   push ecx
// 00454e66  56                   push esi
// 00454e67  8d442404             lea eax, [esp + 4]
// 00454e6b  33f6                 xor esi, esi
// 00454e6d  50                   push eax
// 00454e6e  89742408             mov dword ptr [esp + 8], esi
// 00454e72  e8c9f7ffff           call 0x454640
// 00454e77  8bc8                 mov ecx, eax
// 00454e79  89742410             mov dword ptr [esp + 0x10], esi
// 00454e7d  ff159847b200         call dword ptr [0xb24798]
// 00454e83  8b742418             mov esi, dword ptr [esp + 0x18]
// 00454e87  50                   push eax
// 00454e88  8bce                 mov ecx, esi
// 00454e8a  ff154826b200         call dword ptr [0xb22648]
// 00454e90  8d4c2404             lea ecx, [esp + 4]
// 00454e94  ff15d047b200         call dword ptr [0xb247d0]
// 00454e9a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00454e9e  8bc6                 mov eax, esi
// 00454ea0  5e                   pop esi
// 00454ea1  64890d00000000       mov dword ptr fs:[0], ecx
// 00454ea8  83c410               add esp, 0x10
// 00454eab  c20400               ret 4
// copied from an identical function in another client (function ?convert@X@ns_ROCX000002@@QAEPAUStr@2@PAU32@@Z)

namespace ns_ROCX000002 {
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