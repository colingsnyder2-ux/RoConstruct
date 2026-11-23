// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// The original calls this through the import pointer at 0x802890, so it is declared dllimport.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: this is an MSVC 2008 std::set/map iterator operator++ (checked iterator).
// Layout: [0] = container/proxy pointer, [4] = current node pointer.
struct RbNode {
    RbNode* left;    // +0
    RbNode* parent;  // +4
    RbNode* right;   // +8
    char    pad[0x39 - 0xc];
    char    isnil;   // +0x39
};

struct RbIter {
    void*   cont;
    RbNode* ptr;
};

extern "C" void __fastcall fn_0068d210(RbIter* self, int unusedEdx)
{
    if (self->cont == 0)
        _invalid_parameter_noinfo();

    RbNode* node = self->ptr;
    if (node->isnil) {
        _invalid_parameter_noinfo();
        return;
    }

    RbNode* r = node->right;
    if (!r->isnil) {
        RbNode* n = r;
        RbNode* l = n->left;
        while (!l->isnil) {
            n = l;
            l = n->left;
        }
        self->ptr = n;
        return;
    }

    RbNode* p = node->parent;
    while (!p->isnil && self->ptr == p->right) {
        self->ptr = p;
        p = p->parent;
    }
    self->ptr = p;
}
