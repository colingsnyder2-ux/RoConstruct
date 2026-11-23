// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the CRT header did not declare this, so declare the imported function directly.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: layout of a std::map node (MSVC 2008 _Tree_nod) and of the tree itself.
struct TreeNode {
    TreeNode* left;    // +0
    TreeNode* parent;  // +4
    TreeNode* right;   // +8
    char key[0x28];    // +0xC  (value_type, key is first member)
    char color;        // +0x34
    char isnil;        // +0x35
};

// INFERRED: checked iterator = { proxy, node }
struct TreeIter {
    void* proxy;
    TreeNode* node;
};

struct TreePair {
    TreeIter first;
    int second;
};

struct TreeObj {
    void* proxy;       // +0
    int pad4;          // +4
    int comp;          // +8 (comparator, address used as 'this')
    char pad[0x0C];
    TreeNode* head;    // +0x18
    unsigned size;     // +0x1C
};

extern "C" int __fastcall fn_004dcdd0(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_004dc430(void* self, int unusedEdx, int a1, int a2);
extern "C" TreePair* __fastcall fn_004dd610(void* self, int unusedEdx, TreePair* out, const void* val);
extern "C" void __fastcall fn_0066ff20(TreeIter* self, int unusedEdx);               // _Dec
extern "C" void __fastcall fn_00409f60(TreeIter* self, int unusedEdx);               // _Inc
extern "C" char __fastcall fn_005ecca0(TreeIter* self, int unusedEdx, TreeIter* o);  // operator==

static inline bool Less(TreeObj* t, const void* a, const void* b)
{
    return fn_004dc430((char*)t + 8, 0, (int)a, (int)b) & 0xFF ? true : false;
}

extern "C" TreeIter* __fastcall fn_004dd9a0(TreeObj* self, int unusedEdx, TreeIter* ret,
                                            void* wproxy, TreeNode* wnode, const void* val)
{
    if (self->size == 0) {
        fn_004dcdd0(self, 0, (int)ret, 1, (int)self->head, (int)val);
        return ret;
    }

    TreeNode* begin = self->head->left;
    if (wproxy == 0 || wproxy != self->proxy)
        _invalid_parameter_noinfo();

    if (wnode == begin) {
        // try before begin
        if (Less(self, val, &wnode->key)) {
            fn_004dcdd0(self, 0, (int)ret, 1, (int)wnode, (int)val);
            return ret;
        }
    } else {
        TreeNode* head = self->head;
        if (wproxy == 0 || wproxy != self->proxy)
            _invalid_parameter_noinfo();

        if (wnode == head) {
            // append at end
            TreeNode* rmost = self->head->right;
            if (Less(self, &rmost->key, val)) {
                fn_004dcdd0(self, 0, (int)ret, 0, (int)rmost, (int)val);
                return ret;
            }
        } else {
            if (Less(self, val, &wnode->key)) {
                TreeIter before;
                before.proxy = wproxy;
                before.node = wnode;
                fn_0066ff20(&before, 0);
                if (Less(self, &before.node->key, val)) {
                    if (before.node->right->isnil) {
                        fn_004dcdd0(self, 0, (int)ret, 0, (int)before.node, (int)val);
                        return ret;
                    } else {
                        fn_004dcdd0(self, 0, (int)ret, 1, (int)wnode, (int)val);
                        return ret;
                    }
                }
            }
            // try after
            if (Less(self, &wnode->key, val)) {
                TreeIter after;
                TreeIter endIt;
                after.proxy = wproxy;
                after.node = wnode;
                endIt.node = self->head;
                endIt.proxy = self->proxy;
                fn_00409f60(&after, 0);
                if ((fn_005ecca0(&after, 0, &endIt) & 0xFF) ||
                    Less(self, val, &after.node->key)) {
                    if (wnode->right->isnil) {
                        fn_004dcdd0(self, 0, (int)ret, 0, (int)wnode, (int)val);
                        return ret;
                    } else {
                        fn_004dcdd0(self, 0, (int)ret, 1, (int)after.node, (int)val);
                        return ret;
                    }
                }
            }
        }
    }

    // fall back to plain insert(val).first
    TreePair tmp;
    TreePair* p = fn_004dd610(self, 0, &tmp, val);
    ret->proxy = p->first.proxy;
    ret->node = p->first.node;
    return ret;
}
