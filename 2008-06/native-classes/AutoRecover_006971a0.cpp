// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>
#include <new>

// INFERRED: the mapped value is Ogre::AxisAlignedBox, imported from rgmain (destructor call at node+0x10).
namespace Ogre {
    class __declspec(dllimport) AxisAlignedBox {
        char d[0x28];
    public:
        ~AxisAlignedBox();
    };
}

// INFERRED: layout of an std::map red-black tree node (map<int, Ogre::AxisAlignedBox>).
struct RbNode {
    RbNode* left;
    RbNode* parent;
    RbNode* right;
    int key;
    Ogre::AxisAlignedBox value;
    char color;   // 0 = red, 1 = black
    char isnil;
};

struct RbIter {
    int proxy;
    RbNode* ptr;
};

// INFERRED: std::_Tree body: proxy at +0, head at +0x18, size at +0x1c.
struct RbTree {
    int proxy;
    int pad[5];
    RbNode* head;
    unsigned int size;
};

extern "C" int __fastcall fn_0068d210(void* self, int unusedEdx);          // iterator ++
extern "C" TreeNode *fn_0068d120(TreeNode* node);  // _Min
extern "C" TreeNode *fn_0068d100(TreeNode* node);  // _Max
extern "C" int __fastcall fn_0068df50(void* self, int unusedEdx, int a1);  // _Lrotate
extern "C" int __fastcall fn_0068d140(void* self, int unusedEdx, int a1);  // _Rrotate

extern "C" RbIter* __fastcall fn_006971a0(RbTree* self, int unusedEdx, RbIter* result, int proxy, RbNode* ptr)
{
    RbIter where;
    where.proxy = proxy;
    where.ptr = ptr;

    if (where.ptr->isnil) {
        std::string msg("invalid map/set<T> iterator");
        throw std::out_of_range(msg);
    }

    RbNode* erased = where.ptr;
    fn_0068d210(&where, 0);

    RbNode* fixnode;
    RbNode* fixparent;
    RbNode* pnode = erased;

    if (pnode->left->isnil)
        fixnode = pnode->right;
    else if (pnode->right->isnil)
        fixnode = pnode->left;
    else {
        pnode = where.ptr;
        fixnode = pnode->right;
    }

    if (pnode == erased) {
        fixparent = erased->parent;
        if (!fixnode->isnil)
            fixnode->parent = fixparent;

        if (self->head->parent == erased)
            self->head->parent = fixnode;
        else if (fixparent->left == erased)
            fixparent->left = fixnode;
        else
            fixparent->right = fixnode;

        if (self->head->left == erased) {
            RbNode* v;
            if (fixnode->isnil)
                v = fixparent;
            else
                v = (RbNode*)fn_0068d120(0, 0, (int)fixnode);
            self->head->left = v;
        }
        if (self->head->right == erased) {
            RbNode* v;
            if (fixnode->isnil)
                v = fixparent;
            else
                v = (RbNode*)fn_0068d100(0, 0, (int)fixnode);
            self->head->right = v;
        }
    } else {
        erased->left->parent = pnode;
        pnode->left = erased->left;
        if (pnode == erased->right)
            fixparent = pnode;
        else {
            fixparent = pnode->parent;
            if (!fixnode->isnil)
                fixnode->parent = fixparent;
            fixparent->left = fixnode;
            pnode->right = erased->right;
            erased->right->parent = pnode;
        }

        if (self->head->parent == erased)
            self->head->parent = pnode;
        else if (erased->parent->left == erased)
            erased->parent->left = pnode;
        else
            erased->parent->right = pnode;

        pnode->parent = erased->parent;
        char t = pnode->color;
        pnode->color = erased->color;
        erased->color = t;
        pnode = erased;
    }

    if (pnode->color == 1) {
        for (; fixnode != self->head->parent && fixnode->color == 1; fixparent = fixnode->parent) {
            if (fixnode == fixparent->left) {
                pnode = fixparent->right;
                if (pnode->color == 0) {
                    pnode->color = 1;
                    fixparent->color = 0;
                    fn_0068df50(self, 0, (int)fixparent);
                    pnode = fixparent->right;
                }
                if (pnode->isnil)
                    fixnode = fixparent;
                else if (pnode->left->color == 1 && pnode->right->color == 1) {
                    pnode->color = 0;
                    fixnode = fixparent;
                } else {
                    if (pnode->right->color == 1) {
                        pnode->left->color = 1;
                        pnode->color = 0;
                        fn_0068d140(self, 0, (int)pnode);
                        pnode = fixparent->right;
                    }
                    pnode->color = fixparent->color;
                    fixparent->color = 1;
                    pnode->right->color = 1;
                    fn_0068df50(self, 0, (int)fixparent);
                    break;
                }
            } else {
                pnode = fixparent->left;
                if (pnode->color == 0) {
                    pnode->color = 1;
                    fixparent->color = 0;
                    fn_0068d140(self, 0, (int)fixparent);
                    pnode = fixparent->left;
                }
                if (pnode->isnil)
                    fixnode = fixparent;
                else if (pnode->right->color == 1 && pnode->left->color == 1) {
                    pnode->color = 0;
                    fixnode = fixparent;
                } else {
                    if (pnode->left->color == 1) {
                        pnode->right->color = 1;
                        pnode->color = 0;
                        fn_0068df50(self, 0, (int)pnode);
                        pnode = fixparent->left;
                    }
                    pnode->color = fixparent->color;
                    fixparent->color = 1;
                    pnode->left->color = 1;
                    fn_0068d140(self, 0, (int)fixparent);
                    break;
                }
            }
        }
        fixnode->color = 1;
    }

    erased->value.~AxisAlignedBox();
    ::operator delete(erased);

    if (0 < self->size)
        --self->size;

    result->ptr = where.ptr;
    result->proxy = self->proxy;
    return result;
}
