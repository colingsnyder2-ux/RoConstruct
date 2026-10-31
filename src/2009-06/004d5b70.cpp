// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00564290  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00564290
//
// 00564290  83ec08               sub esp, 8
// 00564293  56                   push esi
// 00564294  8bf1                 mov esi, ecx
// 00564296  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056429a  e841ffffff           call 0x5641e0
// 0056429f  dd5c2404             fstp qword ptr [esp + 4]
// 005642a3  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005642a6  8b01                 mov eax, dword ptr [ecx]
// 005642a8  8b400c               mov eax, dword ptr [eax + 0xc]
// 005642ab  8d542404             lea edx, [esp + 4]
// 005642af  52                   push edx
// 005642b0  8b542414             mov edx, dword ptr [esp + 0x14]
// 005642b4  52                   push edx
// 005642b5  ffd0                 call eax
// 005642b7  5e                   pop esi
// 005642b8  83c408               add esp, 8
// 005642bb  c20800               ret 8

struct Value
{
    double get();
};

struct Accessor;

struct AccessorTable
{
    unsigned char padding[12];
    void (__thiscall *set)(Accessor *, void *, const double *);
};

struct Accessor
{
    AccessorTable *table;
};

struct Descriptor
{
    unsigned char padding[24];
    Accessor *accessor;

    void set(void *object, Value *value);
};

void Descriptor::set(void *object, Value *value)
{
    double converted = value->get();
    accessor->table->set(accessor, object, &converted);
}
