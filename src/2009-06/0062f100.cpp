// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a4160  unit: RBX::Stats::M::?$TypedStatsItem  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a4160
//
// 005a4160  51                   push ecx
// 005a4161  56                   push esi
// 005a4162  8bf1                 mov esi, ecx
// 005a4164  8d8e58010000         lea ecx, [esi + 0x158]
// 005a416a  e8516ee8ff           call 0x42afc0
// 005a416f  d95c2404             fstp dword ptr [esp + 4]
// 005a4173  8d442404             lea eax, [esp + 4]
// 005a4177  50                   push eax
// 005a4178  8bce                 mov ecx, esi
// 005a417a  e8614f0200           call 0x5c90e0
// 005a417f  5e                   pop esi
// 005a4180  59                   pop ecx
// 005a4181  c3                   ret 

struct Value
{
    float get();
};

struct S
{
    char padding[0x158];
    Value value;

    void setValue(const float &value);
    void f();
};

void S::f()
{
    float result = value.get();
    setValue(result);
}
