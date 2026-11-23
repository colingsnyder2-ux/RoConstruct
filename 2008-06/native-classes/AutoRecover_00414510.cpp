// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: MSVCR90 import, called through [0x802890]; not declared by the headers available here
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: checked-iterator layout {container proxy, node}; std::map<InstanceHandle,int> with _SECURE_SCL
struct Node { Node* left; Node* parent; Node* right; };
struct Iter { void* cont; Node* ptr; };
struct Tree {
    void* proxy;       // +0
    int pad[5];        // +4..+17
    Node* head;        // +0x18
    int size;          // +0x1c
};

extern "C" void __fastcall fn_00414370(Tree* self, int unusedEdx, Node* where);
extern "C" void __fastcall fn_005b7250(Iter* self);
extern "C" Iter* __fastcall fn_00413d70(Tree* self, int unusedEdx, Iter* ret, void* cont, Node* node);

extern "C" Iter* __fastcall fn_00414510(Tree* self, int unusedEdx, Iter* ret,
                                        void* fcont, Node* fnode, void* lcont, Node* lnode)
{
    Iter first = { fcont, fnode };
    Node* head = self->head->left;
    if (!first.cont || first.cont != self->proxy)
        _invalid_parameter_noinfo();
    if (first.ptr == head) {
        Node* h = self->head;
        if (!lcont || lcont != self->proxy)
            _invalid_parameter_noinfo();
        if (lnode == h) {
            fn_00414370(self, 0, self->head->parent);
            self->head->parent = self->head;
            self->size = 0;
            self->head->left = self->head;
            self->head->right = self->head;
            ret->ptr = self->head->left;
            ret->cont = self->proxy;
            return ret;
        }
    }
    for (;;) {
        if (!first.cont || first.cont != lcont)
            _invalid_parameter_noinfo();
        if (first.ptr == lnode)
            break;
        Iter where = first;
        fn_005b7250(&first);
        Iter tmp;
        fn_00413d70(self, 0, &tmp, where.cont, where.ptr);
    }
    ret->cont = self->proxy;
    ret->ptr = lnode;
    return ret;
}
