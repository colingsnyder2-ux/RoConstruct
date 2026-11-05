// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0056e660  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e660
//
// 0056e660  56                   push esi
// 0056e661  57                   push edi
// 0056e662  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056e666  8bf1                 mov esi, ecx
// 0056e668  8bcf                 mov ecx, edi
// 0056e66a  e8a1e10000           call 0x57c810
// 0056e66f  84c0                 test al, al
// 0056e671  7525                 jne 0x56e698
// 0056e673  8d442410             lea eax, [esp + 0x10]
// 0056e677  50                   push eax
// 0056e678  8d4f10               lea ecx, [edi + 0x10]
// 0056e67b  e890df0000           call 0x57c610
// 0056e680  84c0                 test al, al
// 0056e682  7414                 je 0x56e698
// 0056e684  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e687  8b11                 mov edx, dword ptr [ecx]
// 0056e689  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e68c  8d442410             lea eax, [esp + 0x10]
// 0056e690  50                   push eax
// 0056e691  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056e695  50                   push eax
// 0056e696  ffd2                 call edx
// 0056e698  5f                   pop edi
// 0056e699  5e                   pop esi
// 0056e69a  c20c00               ret 0xc

struct Value {
    bool toFloat(float* result);
};

struct Variant {
    char padding[16];
    Value value;
    bool isEmpty();
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* object, const float& value);
};

struct Descriptor {
    char padding[24];
    Setter* setter;
    void apply(void* object, Variant* value, int unused);
};

void Descriptor::apply(void* object, Variant* value, int unused)
{
    if (!value->isEmpty()) {
        float result;
        if (value->value.toFloat(&result))
            setter->set(object, result);
    }
}
