// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00585df0  unit: RBX::P8Script::?$GetSetImpl  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00585df0
//
// 00585df0  51                   push ecx
// 00585df1  8bc1                 mov eax, ecx
// 00585df3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00585df7  33d2                 xor edx, edx
// 00585df9  891424               mov dword ptr [esp], edx
// 00585dfc  3bca                 cmp ecx, edx
// 00585dfe  7403                 je 0x585e03
// 00585e00  8d51ec               lea edx, [ecx - 0x14]
// 00585e03  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00585e06  8b4008               mov eax, dword ptr [eax + 8]
// 00585e09  56                   push esi
// 00585e0a  57                   push edi
// 00585e0b  03ca                 add ecx, edx
// 00585e0d  ffd0                 call eax
// 00585e0f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00585e13  8bf0                 mov esi, eax
// 00585e15  56                   push esi
// 00585e16  8bcf                 mov ecx, edi
// 00585e18  ff155c248000         call dword ptr [0x80245c]
// 00585e1e  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00585e21  894f1c               mov dword ptr [edi + 0x1c], ecx
// 00585e24  8bc7                 mov eax, edi
// 00585e26  5f                   pop edi
// 00585e27  5e                   pop esi
// 00585e28  59                   pop ecx
// 00585e29  c20800               ret 8

struct String
{
    char data[28];
    String(const String&);
};

extern void (__thiscall *string_copy_ctor)(String*, const String*);

inline String::String(const String& other)
{
    string_copy_ctor(this, &other);
}

struct Value
{
    String text;
    int extra;
};

struct Base
{
    const Value& get();
};

struct Object
{
    char data[20];
};

#pragma pointers_to_members(full_generality, multiple_inheritance)

struct S
{
    char pad[8];
    const Value& (Base::*fn)();
    Value method(Object*);
};

Value S::method(Object* object)
{
    volatile int temporary = 0;
    Base* base = 0;
    if (object != 0)
        base = reinterpret_cast<Base*>(reinterpret_cast<char*>(object) - 20);
    return (base->*fn)();
}
