// from server: 100% by EspClaude
// roc 2009-06 0040bce0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040bce0
//
// 0040bce0  56                   push esi
// 0040bce1  8bf1                 mov esi, ecx
// 0040bce3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040bce7  e824eaffff           call 0x40a710
// 0040bcec  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0040bcef  8d54240c             lea edx, [esp + 0xc]
// 0040bcf3  8844240c             mov byte ptr [esp + 0xc], al
// 0040bcf7  8b01                 mov eax, dword ptr [ecx]
// 0040bcf9  8b400c               mov eax, dword ptr [eax + 0xc]
// 0040bcfc  52                   push edx
// 0040bcfd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040bd01  52                   push edx
// 0040bd02  ffd0                 call eax
// 0040bd04  5e                   pop esi
// 0040bd05  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000066@@QAEXPAXPAUValue@2@@Z)

namespace ns_ROCX000066 {
struct Value {
    bool convert();
};

struct Receiver;

struct VTable {
    void* unused[3];
    void (__thiscall* set)(Receiver*, void*, const bool*);
};

struct Receiver {
    VTable* vtable;
};

struct S {
    unsigned char padding[24];
    Receiver* receiver;
    void f(void* object, Value* value);
};

void S::f(void* object, Value* value)
{
    *reinterpret_cast<bool*>(&value) = value->convert();
    receiver->vtable->set(receiver, object, reinterpret_cast<const bool*>(&value));
}
}
