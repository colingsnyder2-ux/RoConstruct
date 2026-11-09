// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064e180  unit: RBX::P8Camera::?$GetSetImpl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064e180
//
// 0064e180  56                   push esi
// 0064e181  57                   push edi
// 0064e182  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0064e186  8db144010000         lea esi, [ecx + 0x144]
// 0064e18c  57                   push edi
// 0064e18d  8bce                 mov ecx, esi
// 0064e18f  ff150c248000         call dword ptr [0x80240c]
// 0064e195  8b471c               mov eax, dword ptr [edi + 0x1c]
// 0064e198  5f                   pop edi
// 0064e199  89461c               mov dword ptr [esi + 0x1c], eax
// 0064e19c  5e                   pop esi
// 0064e19d  c20400               ret 4

struct String {
    unsigned char data[28];
};

typedef String& (__thiscall *StringAssign)(String*, const String&);
extern StringAssign assignString;

struct Value {
    String text;
    int value;
};

struct S {
    unsigned char padding[0xa0];
    Value field;
    void set(const Value& source);
};

void S::set(const Value& source)
{
    Value* destination = &field;
    assignString(&destination->text, source.text);
    destination->value = source.value;
}
