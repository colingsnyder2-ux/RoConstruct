// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e720  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e720
//
// 0056e720  83ec08               sub esp, 8
// 0056e723  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0056e726  8b01                 mov eax, dword ptr [ecx]
// 0056e728  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0056e72c  8b4008               mov eax, dword ptr [eax + 8]
// 0056e72f  56                   push esi
// 0056e730  52                   push edx
// 0056e731  ffd0                 call eax
// 0056e733  dd5c2404             fstp qword ptr [esp + 4]
// 0056e737  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056e73b  83c610               add esi, 0x10
// 0056e73e  8bce                 mov ecx, esi
// 0056e740  e88bdb0000           call 0x57c2d0
// 0056e745  dd442404             fld qword ptr [esp + 4]
// 0056e749  dd5e08               fstp qword ptr [esi + 8]
// 0056e74c  c7460409000000       mov dword ptr [esi + 4], 9
// 0056e753  5e                   pop esi
// 0056e754  83c408               add esp, 8
// 0056e757  c20800               ret 8

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual double get(void*);
};

struct Variant {
    unsigned int storage;
    unsigned int type;
    double value;

    void clear();
};

struct Output {
    unsigned char padding[16];
    Variant variant;
};

struct S {
    unsigned char padding[24];
    Getter* getter;

    void get(void*, Output*);
};

void S::get(void* object, Output* output)
{
    double value = getter->get(object);
    Variant* result = &output->variant;
    result->clear();
    result->value = value;
    result->type = 9;
}
