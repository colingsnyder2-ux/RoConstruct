// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the CRT header in this toolchain does not declare this, so declare the MSVCR90 import here.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: layouts reconstructed from raw offsets in the disassembly.
struct TreeNode {
    TreeNode* left;    // +0
    TreeNode* parent;  // +4
    TreeNode* right;   // +8
    int data[5];       // +0xc .. +0x1f (key/value storage)
    char color;        // +0x20
    char isnil;        // +0x21
};

struct TreeIter {
    void* proxy;
    TreeNode* node;
};

struct TreeObj {
    void* proxy;       // +0
    int pad4;          // +4
    int comp;          // +8 (comparator, address passed as 'this')
    int pad0c[3];      // +0xc
    TreeNode* head;    // +0x18
    unsigned size;     // +0x1c
};

extern "C" int __fastcall fn_004e7ad0(void* self, int unusedEdx, TreeIter* ret, int addLeft, TreeNode* where, const int* val);
extern "C" int __fastcall fn_004e6170(void* self, int unusedEdx, const void* a1, const void* a2);
extern "C" TreeIter* __fastcall fn_004e8c40(void* self, int unusedEdx, TreeIter* out, const int* val);
extern "C" void __fastcall fn_004e6270(TreeIter* it);   // const_iterator::_Dec
extern "C" void __fastcall fn_004d7240(TreeIter* it);   // const_iterator::_Inc
extern "C" char __fastcall fn_005ecca0(TreeIter* self, int unusedEdx, TreeIter* other); // iterator ==

extern "C" TreeIter* __fastcall fn_004e9c50(TreeObj* self, int unusedEdx, TreeIter* ret,
                                            void* hintProxy, TreeNode* hintNode, const int* val)
{
    TreeObj* t = self;
    if (t->size == 0) {
        fn_004e7ad0(t, 0, ret, 1, t->head, val);
        return ret;
    }

    TreeNode* begin = t->head->left;
    if (!hintProxy || hintProxy != t->proxy)
        _invalid_parameter_noinfo();

    if (hintNode == begin) {
        int a = val[3];
        int b = hintNode->data[3];
        bool less;
        if (a < b)
            less = true;
        else if (a > b)
            less = false;
        else
            less = (const void*)val < (const void*)&hintNode->data[0];
        if (less) {
            fn_004e7ad0(t, 0, ret, 1, hintNode, val);
            return ret;
        }
    } else {
        TreeNode* head = t->head;
        if (!hintProxy || hintProxy != t->proxy)
            _invalid_parameter_noinfo();

        if (hintNode == head) {
            TreeNode* last = t->head->right;
            if (fn_004e6170(&t->comp, 0, &last->data[0], val) & 0xff) {
                fn_004e7ad0(t, 0, ret, 0, last, val);
                return ret;
            }
        } else {
            bool tryNext = true;
            if (fn_004e6170(&t->comp, 0, val, &hintNode->data[0]) & 0xff) {
                TreeIter it;
                it.proxy = hintProxy;
                it.node = hintNode;
                fn_004e6270(&it);
                TreeNode* prev = it.node;
                if (fn_004e6170(&t->comp, 0, &prev->data[0], val) & 0xff) {
                    if (prev->right->isnil)
                        fn_004e7ad0(t, 0, ret, 0, prev, val);
                    else
                        fn_004e7ad0(t, 0, ret, 1, hintNode, val);
                    return ret;
                }
                tryNext = true;
            }
            if (tryNext && (fn_004e6170(&t->comp, 0, &hintNode->data[0], val) & 0xff)) {
                TreeIter its[2];
                its[0].proxy = hintProxy;
                its[0].node = hintNode;
                its[1].proxy = t->proxy;
                its[1].node = t->head;
                fn_004d7240(&its[0]);
                char atEnd = fn_005ecca0(&its[0], 0, &its[1]);
                TreeNode* next = its[0].node;
                if (atEnd || (fn_004e6170(&t->comp, 0, val, &next->data[0]) & 0xff)) {
                    if (hintNode->right->isnil)
                        fn_004e7ad0(t, 0, ret, 0, hintNode, val);
                    else
                        fn_004e7ad0(t, 0, ret, 1, next, val);
                    return ret;
                }
            }
        }
    }

    TreeIter tmp;
    TreeIter* r = fn_004e8c40(t, 0, &tmp, val);
    ret->proxy = r->proxy;
    ret->node = r->node;
    return ret;
}
