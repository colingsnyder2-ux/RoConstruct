// from server: 100% by EspClaude
// roc 2009-06 00431f20  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00431f20
//
// 00431f20  6aff                 push -1
// 00431f22  6839068500           push 0x850639
// 00431f27  64a100000000         mov eax, dword ptr fs:[0]
// 00431f2d  50                   push eax
// 00431f2e  64892500000000       mov dword ptr fs:[0], esp
// 00431f35  51                   push ecx
// 00431f36  56                   push esi
// 00431f37  8d442404             lea eax, [esp + 4]
// 00431f3b  33f6                 xor esi, esi
// 00431f3d  50                   push eax
// 00431f3e  89742408             mov dword ptr [esp + 8], esi
// 00431f42  e809f7ffff           call 0x431650
// 00431f47  8bc8                 mov ecx, eax
// 00431f49  89742410             mov dword ptr [esp + 0x10], esi
// 00431f4d  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00431f53  8b742418             mov esi, dword ptr [esp + 0x18]
// 00431f57  50                   push eax
// 00431f58  8bce                 mov ecx, esi
// 00431f5a  ff15b4e48900         call dword ptr [0x89e4b4]
// 00431f60  8d4c2404             lea ecx, [esp + 4]
// 00431f64  ff1510fd8900         call dword ptr [0x89fd10]
// 00431f6a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00431f6e  8bc6                 mov eax, esi
// 00431f70  5e                   pop esi
// 00431f71  64890d00000000       mov dword ptr fs:[0], ecx
// 00431f78  83c410               add esp, 0x10
// 00431f7b  c20400               ret 4
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
