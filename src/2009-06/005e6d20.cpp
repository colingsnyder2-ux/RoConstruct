// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e7b0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e7b0
//
// 0056e7b0  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0056e7b3  8b01                 mov eax, dword ptr [ecx]
// 0056e7b5  8b542404             mov edx, dword ptr [esp + 4]
// 0056e7b9  8b4008               mov eax, dword ptr [eax + 8]
// 0056e7bc  53                   push ebx
// 0056e7bd  56                   push esi
// 0056e7be  52                   push edx
// 0056e7bf  ffd0                 call eax
// 0056e7c1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056e7c5  83c610               add esi, 0x10
// 0056e7c8  8bce                 mov ecx, esi
// 0056e7ca  8ad8                 mov bl, al
// 0056e7cc  e8ffda0000           call 0x57c2d0
// 0056e7d1  885e08               mov byte ptr [esi + 8], bl
// 0056e7d4  c7460404000000       mov dword ptr [esi + 4], 4
// 0056e7db  5e                   pop esi
// 0056e7dc  5b                   pop ebx
// 0056e7dd  c20800               ret 8

struct Getter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual bool get(void* object) = 0;
};

struct Value {
    unsigned int reserved;
    unsigned int type;
    bool data;

    void clear();
};

struct Output {
    char reserved[16];
    Value value;
};

struct S {
    char reserved[24];
    Getter* getter;

    void f(void* object, Output* output);
};

void S::f(void* object, Output* output)
{
    bool result = getter->get(object);
    Value* value = &output->value;
    value->clear();
    value->data = result;
    value->type = 4;
}
