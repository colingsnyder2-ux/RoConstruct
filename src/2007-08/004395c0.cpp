// from server: 100% by Yeetserama
// roc 2007-08 004395c0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004395c0
//
// 004395c0  6aff                 push -1
// 004395c2  6809477600           push 0x764709
// 004395c7  64a100000000         mov eax, dword ptr fs:[0]
// 004395cd  50                   push eax
// 004395ce  51                   push ecx
// 004395cf  56                   push esi
// 004395d0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004395d5  33c4                 xor eax, esp
// 004395d7  50                   push eax
// 004395d8  8d44240c             lea eax, [esp + 0xc]
// 004395dc  64a300000000         mov dword ptr fs:[0], eax
// 004395e2  8d442408             lea eax, [esp + 8]
// 004395e6  33f6                 xor esi, esi
// 004395e8  50                   push eax
// 004395e9  8974240c             mov dword ptr [esp + 0xc], esi
// 004395ed  e85ef8ffff           call 0x438e50
// 004395f2  8bc8                 mov ecx, eax
// 004395f4  89742414             mov dword ptr [esp + 0x14], esi
// 004395f8  ff1598dd7700         call dword ptr [0x77dd98]
// 004395fe  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00439602  50                   push eax
// 00439603  8bce                 mov ecx, esi
// 00439605  ff1598e67700         call dword ptr [0x77e698]
// 0043960b  8d4c2408             lea ecx, [esp + 8]
// 0043960f  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00439615  8bc6                 mov eax, esi
// 00439617  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043961b  64890d00000000       mov dword ptr fs:[0], ecx
// 00439622  59                   pop ecx
// 00439623  5e                   pop esi
// 00439624  83c410               add esp, 0x10
// 00439627  c20400               ret 4
// copied from an identical function in another client (function ?convert@X@ns_ROCX000006@@QAEPAUStr@2@PAU32@@Z)

namespace ns_ROCX000006 {
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
