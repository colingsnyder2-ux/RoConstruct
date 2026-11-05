// from server: 100% by EspClaude
// roc 2009-06 00443520  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00443520
//
// 00443520  56                   push esi
// 00443521  8bf1                 mov esi, ecx
// 00443523  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00443527  e894fbffff           call 0x4430c0
// 0044352c  d95c240c             fstp dword ptr [esp + 0xc]
// 00443530  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00443533  8b01                 mov eax, dword ptr [ecx]
// 00443535  8b400c               mov eax, dword ptr [eax + 0xc]
// 00443538  8d54240c             lea edx, [esp + 0xc]
// 0044353c  52                   push edx
// 0044353d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00443541  52                   push edx
// 00443542  ffd0                 call eax
// 00443544  5e                   pop esi
// 00443545  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX00002b@@QAEXPAXPAUValue@2@@Z)

namespace ns_ROCX00002b {
struct Value {
    float convert();
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const float &);
};

struct S {
    char padding[24];
    Setter *setter;
    void f(void *, Value *);
};

void S::f(void *object, Value *value)
{
    float &converted = reinterpret_cast<float &>(value);
    converted = value->convert();
    setter->set(object, converted);
}
}
