// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the real class names are unknown. These local stand-ins give a
// polymorphic base (RTTI descriptor 0x92907c) and a derived type
// (descriptor 0x92e15c). The parent pointer is at offset 0x104.
struct InstanceBase {
    virtual ~InstanceBase() {}
    char pad[0x100];
    InstanceBase* parent; // +0x104
};

struct TargetType : public InstanceBase {
    virtual void anchor() {}
};

// thiscall helper at 0x452b40, declared per the fixed convention.
// INFERRED: the return type is a pointer-sized value.
extern "C" void* __fastcall fn_00452b40(TargetType* self, int unusedEdx);

// Walks up the parent chain and calls fn_00452b40 on the first ancestor
// that is a TargetType (tail call). Returns null if none is found.
extern "C" void* fn_00656640(InstanceBase* node)
{
    while (node) {
        TargetType* t = dynamic_cast<TargetType*>(node);
        if (t)
            return fn_00452b40(t, 0);
        node = node->parent;
    }
    return 0;
}
