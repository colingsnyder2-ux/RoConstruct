// from server: 100% by EspClaude
// roc 2009-06 005e6d90  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e6d90
//
// 005e6d90  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e6d93  8b01                 mov eax, dword ptr [ecx]
// 005e6d95  8b542404             mov edx, dword ptr [esp + 4]
// 005e6d99  8b4008               mov eax, dword ptr [eax + 8]
// 005e6d9c  56                   push esi
// 005e6d9d  57                   push edi
// 005e6d9e  52                   push edx
// 005e6d9f  ffd0                 call eax
// 005e6da1  8b742410             mov esi, dword ptr [esp + 0x10]
// 005e6da5  83c610               add esi, 0x10
// 005e6da8  8bce                 mov ecx, esi
// 005e6daa  8bf8                 mov edi, eax
// 005e6dac  e81f2d0200           call 0x609ad0
// 005e6db1  897e08               mov dword ptr [esi + 8], edi
// 005e6db4  5f                   pop edi
// 005e6db5  c7460405000000       mov dword ptr [esi + 4], 5
// 005e6dbc  5e                   pop esi
// 005e6dbd  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000014@@QAEXPAXPAUOutput@2@@Z)

namespace ns_ROCX000014 {
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual int get(void* object);
};

struct Value {
    unsigned char padding[4];
    int tag;
    int value;
    void clear();
};

struct Output {
    unsigned char padding[16];
    Value data;
};

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void f(void* object, Output* output);
};

void S::f(void* object, Output* output)
{
    int value = accessor->get(object);
    Value* data = &output->data;
    data->clear();
    data->value = value;
    data->tag = 5;
}
}
