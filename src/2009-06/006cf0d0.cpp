// from server: 74% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00643360  unit: RBX::HUMAN::Landed  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00643360
//
// 00643360  51                   push ecx
// 00643361  56                   push esi
// 00643362  8bf1                 mov esi, ecx
// 00643364  d94630               fld dword ptr [esi + 0x30]
// 00643367  8b4e08               mov ecx, dword ptr [esi + 8]
// 0064336a  d95c2404             fstp dword ptr [esp + 4]
// 0064336e  e82d5df9ff           call 0x5d90a0
// 00643373  85c0                 test eax, eax
// 00643375  741f                 je 0x643396
// 00643377  8b4e08               mov ecx, dword ptr [esi + 8]
// 0064337a  e8215df9ff           call 0x5d90a0
// 0064337f  8b809c000000         mov eax, dword ptr [eax + 0x9c]
// 00643385  d94008               fld dword ptr [eax + 8]
// 00643388  d80dac9b8100         fmul dword ptr [0x819bac]
// 0064338e  d8442404             fadd dword ptr [esp + 4]
// 00643392  d95c2404             fstp dword ptr [esp + 4]
// 00643396  8b4e08               mov ecx, dword ptr [esi + 8]
// 00643399  e8225df9ff           call 0x5d90c0
// 0064339e  8b4e08               mov ecx, dword ptr [esi + 8]
// 006433a1  85c0                 test eax, eax
// 006433a3  7414                 je 0x6433b9
// 006433a5  e8165df9ff           call 0x5d90c0
// 006433aa  8b889c000000         mov ecx, dword ptr [eax + 0x9c]
// 006433b0  d94108               fld dword ptr [ecx + 8]
// 006433b3  5e                   pop esi
// 006433b4  d80424               fadd dword ptr [esp]
// 006433b7  59                   pop ecx
// 006433b8  c3                   ret 
// 006433b9  e8225df9ff           call 0x5d90e0
// 006433be  85c0                 test eax, eax
// 006433c0  7417                 je 0x6433d9
// 006433c2  8b4e08               mov ecx, dword ptr [esi + 8]
// 006433c5  e8165df9ff           call 0x5d90e0
// 006433ca  8b909c000000         mov edx, dword ptr [eax + 0x9c]
// 006433d0  d94208               fld dword ptr [edx + 8]
// 006433d3  5e                   pop esi
// 006433d4  d80424               fadd dword ptr [esp]
// 006433d7  59                   pop ecx
// 006433d8  c3                   ret 
// 006433d9  d9442404             fld dword ptr [esp + 4]
// 006433dd  5e                   pop esi
// 006433de  59                   pop ecx
// 006433df  c3                   ret 

extern float factor;

struct Value
{
    char padding[8];
    float value;
};

struct Node
{
    char padding[0x9c];
    Value* data;
};

struct Owner
{
    void* first();
    int* second();
    int third();
};

struct S
{
    char padding0[8];
    Owner* owner;
    char padding1[0x24];
    float base;

    double f();
};

double S::f()
{
    float result = base;

    if (owner->first())
        result += ((Node*)owner->first())->data->value * factor;

    if (owner->second())
        return (double)((Node*)owner->second())->data->value + result;

    if (owner->third())
        return (double)((Node*)owner->third())->data->value + result;

    return result;
}
