// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: type descriptors 0x92907c (source) / 0x92e15c (target) are unnamed; stand-in polymorphic classes.
struct Node {
    virtual ~Node() {}
    char pad[0x100];   // INFERRED: pad so parent sits at +0x104 (vptr at +0)
    Node* parent;
};
struct FoundNode : Node {};

extern "C" void* __fastcall fn_0045de20(void* self, int unusedEdx);

// INFERRED: walks parent chain to first ancestor castable to FoundNode, returns fn_0045de20(it)
extern "C" void* fn_005a3330(Node* node)
{
    for (; node; node = node->parent) {
        FoundNode* hit = dynamic_cast<FoundNode*>(node);
        if (hit)
            return fn_0045de20(hit, 0);
    }
    return 0;
}
