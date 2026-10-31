// from server: 76% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e8000  unit: RBX::Primitive  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e8000
//
// 005e8000  d9442404             fld dword ptr [esp + 4]
// 005e8004  83ec24               sub esp, 0x24
// 005e8007  56                   push esi
// 005e8008  8bf1                 mov esi, ecx
// 005e800a  51                   push ecx
// 005e800b  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 005e8011  d91c24               fstp dword ptr [esp]
// 005e8014  e897c00200           call 0x6140b0
// 005e8019  d944242c             fld dword ptr [esp + 0x2c]
// 005e801d  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 005e8023  8b01                 mov eax, dword ptr [ecx]
// 005e8025  8b4018               mov eax, dword ptr [eax + 0x18]
// 005e8028  51                   push ecx
// 005e8029  8d542408             lea edx, [esp + 8]
// 005e802d  d91c24               fstp dword ptr [esp]
// 005e8030  52                   push edx
// 005e8031  ffd0                 call eax
// 005e8033  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 005e8039  50                   push eax
// 005e803a  e8d1c00200           call 0x614110
// 005e803f  c686f000000001       mov byte ptr [esi + 0xf0], 1
// 005e8046  5e                   pop esi
// 005e8047  83c424               add esp, 0x24
// 005e804a  c20400               ret 4

struct Result {
    char data[0x24];
};

struct Provider {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual Result compute(float value) = 0;
};

struct Source {
    void set(float value);
    void consume(const Result& value);
};

struct Primitive {
    char reserved0[0x9c];
    Provider* provider;
    Source* source;
    char reserved1[0x4c];
    char changed;

    void func_005e8000(float value);
};

void Primitive::func_005e8000(float value)
{
    source->set(value);
    source->consume(provider->compute(value));
    changed = 1;
}
