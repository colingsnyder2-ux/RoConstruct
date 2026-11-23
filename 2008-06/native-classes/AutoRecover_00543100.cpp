// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>

// INFERRED: this is std::_Tree<set<int>>::_Insert(bool addleft, _Nodeptr where, const int& val),
// returning an iterator through a hidden return pointer.
struct TreeNode;
struct TreeImpl {
    char pad[0x18];
    TreeNode* head;   // +0x18
    unsigned size;    // +0x1c
};

extern "C" int __fastcall fn_00544760(void* self, int unusedEdx);                  // max_size()
extern "C" TreeNode* __fastcall fn_005453e0(void* self, int unusedEdx, TreeNode* a1, TreeNode* a2, TreeNode* a3, int a4, int a5); // _Buynode
extern "C" TreeNode** __fastcall fn_005423f0(void* self, int unusedEdx);           // _Root
extern "C" TreeNode** __fastcall fn_005508e0(void* self, int unusedEdx);           // _Lmost
extern "C" TreeNode** __fastcall fn_0054cec0(void* self, int unusedEdx);           // _Rmost
extern "C" TreeNode** fn_0054c630(TreeNode* n);                                    // _Left
extern "C" TreeNode** fn_0054c640(TreeNode* n);                                    // _Parent
extern "C" TreeNode** fn_00541da0(TreeNode* n);                                    // _Right
extern "C" char* fn_00544720(TreeNode* n);                                         // _Color
extern "C" void __fastcall fn_00544fc0(void* self, int unusedEdx, TreeNode* n);    // _Lrotate
extern "C" void __fastcall fn_00545130(void* self, int unusedEdx, TreeNode* n);    // _Rrotate
extern "C" void __fastcall fn_0054e320(void* self, int unusedEdx, TreeNode* node, void* tree); // iterator ctor

extern "C" void* __fastcall fn_00543100(TreeImpl* self, int unusedEdx, void* ret, bool addLeft, TreeNode* where, int val)
{
    if ((unsigned)(fn_00544760(self, 0) - 1) <= self->size) {
        // INFERRED: original builds a std::string and a length_error through fn_00402480
        throw std::length_error("map/set<T> too long");
    }

    TreeNode* newnode = fn_005453e0(self, 0, self->head, where, self->head, val, 0);
    ++self->size;

    if (where == self->head) {
        *fn_005423f0(self, 0) = newnode;
        *fn_005508e0(self, 0) = newnode;
        *fn_0054cec0(self, 0) = newnode;
    } else if (addLeft) {
        *fn_0054c630(where) = newnode;
        if (where == *fn_005508e0(self, 0))
            *fn_005508e0(self, 0) = newnode;
    } else {
        *fn_00541da0(where) = newnode;
        if (where == *fn_0054cec0(self, 0))
            *fn_0054cec0(self, 0) = newnode;
    }

    TreeNode* p = newnode;
    while (*fn_00544720(*fn_0054c640(p)) == 0) {
        if (*fn_0054c640(p) == *fn_0054c630(*fn_0054c640(*fn_0054c640(p)))) {
            TreeNode* y = *fn_00541da0(*fn_0054c640(*fn_0054c640(p)));
            if (*fn_00544720(y) == 0) {
                *fn_00544720(*fn_0054c640(p)) = 1;
                *fn_00544720(y) = 1;
                *fn_00544720(*fn_0054c640(*fn_0054c640(p))) = 0;
                p = *fn_0054c640(*fn_0054c640(p));
            } else {
                if (p == *fn_00541da0(*fn_0054c640(p))) {
                    p = *fn_0054c640(p);
                    fn_00544fc0(self, 0, p);
                }
                *fn_00544720(*fn_0054c640(p)) = 1;
                *fn_00544720(*fn_0054c640(*fn_0054c640(p))) = 0;
                fn_00545130(self, 0, *fn_0054c640(*fn_0054c640(p)));
            }
        } else {
            TreeNode* y = *fn_0054c630(*fn_0054c640(*fn_0054c640(p)));
            if (*fn_00544720(y) == 0) {
                *fn_00544720(*fn_0054c640(p)) = 1;
                *fn_00544720(y) = 1;
                *fn_00544720(*fn_0054c640(*fn_0054c640(p))) = 0;
                p = *fn_0054c640(*fn_0054c640(p));
            } else {
                if (p == *fn_0054c630(*fn_0054c640(p))) {
                    p = *fn_0054c640(p);
                    fn_00545130(self, 0, p);
                }
                *fn_00544720(*fn_0054c640(p)) = 1;
                *fn_00544720(*fn_0054c640(*fn_0054c640(p))) = 0;
                fn_00544fc0(self, 0, *fn_0054c640(*fn_0054c640(p)));
            }
        }
    }

    *fn_00544720(*fn_005423f0(self, 0)) = 1;
    fn_0054e320(ret, 0, newnode, self);
    return ret;
}
