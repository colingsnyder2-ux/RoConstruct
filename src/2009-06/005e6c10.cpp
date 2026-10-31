// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e6a0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e6a0
//
// 0056e6a0  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0056e6a3  8b01                 mov eax, dword ptr [ecx]
// 0056e6a5  8b542404             mov edx, dword ptr [esp + 4]
// 0056e6a9  8b4008               mov eax, dword ptr [eax + 8]
// 0056e6ac  56                   push esi
// 0056e6ad  52                   push edx
// 0056e6ae  ffd0                 call eax
// 0056e6b0  d95c2408             fstp dword ptr [esp + 8]
// 0056e6b4  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0056e6b8  83c610               add esi, 0x10
// 0056e6bb  8bce                 mov ecx, esi
// 0056e6bd  e80edc0000           call 0x57c2d0
// 0056e6c2  d9442408             fld dword ptr [esp + 8]
// 0056e6c6  d95e08               fstp dword ptr [esi + 8]
// 0056e6c9  c7460407000000       mov dword ptr [esi + 4], 7
// 0056e6d0  5e                   pop esi
// 0056e6d1  c20800               ret 8

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual float get(void *object);
};

struct Value {
    unsigned int reserved;
    int type;
    float number;
    void clear();
};

struct Result {
    unsigned char padding[16];
    Value value;
};

struct S {
    unsigned char padding[24];
    Getter *getter;
    void read(void *object, Result *result);
};

void S::read(void *object, Result *result)
{
    float number = getter->get(object);
    Value *value = &result->value;
    value->clear();
    value->number = number;
    value->type = 7;
}
