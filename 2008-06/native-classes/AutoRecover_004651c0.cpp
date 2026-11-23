// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the real class names are unknown. Node stands for the polymorphic
// base (type descriptor 0x92907c) and Target for the type searched for
// (type descriptor 0x92e15c).
// INFERRED: the parent pointer sits at +0x104.
struct Node {
    virtual ~Node() {}
    char pad[0x100];
    Node* parent;
};

struct Target : public Node {
};

// INFERRED: thiscall helper at 0x452c80 takes the found ancestor as `this` and returns a pointer.
// Declared with one fastcall parameter so only ecx is set, as in the disassembly.
extern "C" void* __fastcall fn_00452c80(Target* self);

// INFERRED: walks up the parent chain to the first ancestor that dynamic_casts to Target, then calls the helper on it.
extern "C" void* fn_004651c0(Node* node)
{
    while (node) {
        Target* t = dynamic_cast<Target*>(node);
        if (t)
            return fn_00452c80(t);
        node = node->parent;
    }
    return 0;
}
