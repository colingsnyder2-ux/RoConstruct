// from server: 100% by EspClaude
// roc 2009-06 0043f690  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043f690
//
// 0043f690  56                   push esi
// 0043f691  8bf1                 mov esi, ecx
// 0043f693  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043f697  e8f4fcffff           call 0x43f390
// 0043f69c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043f69f  8d54240c             lea edx, [esp + 0xc]
// 0043f6a3  8944240c             mov dword ptr [esp + 0xc], eax
// 0043f6a7  8b01                 mov eax, dword ptr [ecx]
// 0043f6a9  8b400c               mov eax, dword ptr [eax + 0xc]
// 0043f6ac  52                   push edx
// 0043f6ad  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0043f6b1  52                   push edx
// 0043f6b2  ffd0                 call eax
// 0043f6b4  5e                   pop esi
// 0043f6b5  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000018@@QAEPAXPAX0@Z)

namespace ns_ROCX000018 {
struct Value {
    void* convert();
};

struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* get(void*, void**);
};

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void* f(void* result, void* object);
};

void* S::f(void* result, void* object)
{
    object = static_cast<Value*>(object)->convert();
    return accessor->get(result, &object);
}
}
