// from server: 100% by EspClaude
// roc 2009-06 0043f620  unit: std::D::DU?$char_traits::V?$basic_string::?$TypedPropertyDescriptor  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043f620
//
// 0043f620  6aff                 push -1
// 0043f622  68d9b88500           push 0x85b8d9
// 0043f627  64a100000000         mov eax, dword ptr fs:[0]
// 0043f62d  50                   push eax
// 0043f62e  64892500000000       mov dword ptr fs:[0], esp
// 0043f635  83ec1c               sub esp, 0x1c
// 0043f638  56                   push esi
// 0043f639  8b7118               mov esi, dword ptr [ecx + 0x18]
// 0043f63c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0043f640  8d442404             lea eax, [esp + 4]
// 0043f644  50                   push eax
// 0043f645  e816effeff           call 0x42e560
// 0043f64a  8b16                 mov edx, dword ptr [esi]
// 0043f64c  8b520c               mov edx, dword ptr [edx + 0xc]
// 0043f64f  50                   push eax
// 0043f650  8b442434             mov eax, dword ptr [esp + 0x34]
// 0043f654  50                   push eax
// 0043f655  8bce                 mov ecx, esi
// 0043f657  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0043f65f  ffd2                 call edx
// 0043f661  8d4c2404             lea ecx, [esp + 4]
// 0043f665  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0043f66d  ff15c4e48900         call dword ptr [0x89e4c4]
// 0043f673  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0043f677  5e                   pop esi
// 0043f678  64890d00000000       mov dword ptr fs:[0], ecx
// 0043f67f  83c428               add esp, 0x28
// 0043f682  c20800               ret 8
// copied from an identical function in another client (function ?set@Descriptor@ns_ROCX000017@@QBEXPAXABUValue@2@@Z)

namespace ns_ROCX000017 {
extern void (__thiscall *destroy_string)(void *);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct Value {
    String toString() const;
};

struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const String &);
};

struct Descriptor {
    char padding[24];
    Accessor *accessor;
    void set(void *, const Value &) const;
};

void Descriptor::set(void *object, const Value &value) const
{
    Accessor *a = accessor;
    a->set(object, value.toString());
}
}
