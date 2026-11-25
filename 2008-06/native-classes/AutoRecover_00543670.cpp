// native-flags: /O2 /Ob2 /Oy /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>

// INFERRED: this is the checked std::set<int>::erase(iterator) tree-removal
// routine (VC9 _Tree::erase), with one proxy dword and one node dword per
// iterator.

struct Local_00543670Iter {
    int proxy;
    int node;
};

struct Local_00543670Tree {
    char pad[0xc];
    char alloc[0x10];   // allocator subobject at +0xc
    unsigned size;      // +0x1c
};

extern "C" int __fastcall fn_0054bf70(void* self, int unusedEdx);          // iterator::_Mynode
extern "C" int __fastcall fn_005428f0(void* self, int unusedEdx);          // iterator::operator++
extern "C" int fn_00541d90(int a1);                                        // _Isnil
extern "C" int fn_00541da0(int a1);                                        // _Right
extern "C" int fn_0054c630(int a1);                                        // _Left
extern "C" int fn_0054c640(int a1);                                        // _Parent
extern "C" int fn_00543630(int a1);                                        // _Color
extern "C" int fn_00545510(int a1);                                        // _Min
extern "C" int fn_005454d0(int a1);                                        // _Max
extern "C" int __fastcall fn_004024a0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005423f0(void* self, int unusedEdx);          // _Root
extern "C" int __fastcall fn_005508e0(void* self, int unusedEdx);          // _Lmost
extern "C" int __fastcall fn_0054cec0(void* self, int unusedEdx);          // _Rmost
extern "C" int __fastcall fn_00550900(void* self, int unusedEdx, int a1);  // _Lrotate
extern "C" int __fastcall fn_00544070(void* self, int unusedEdx, int a1);  // _Rrotate
extern "C" int __fastcall fn_005442d0(void* self, int unusedEdx, int a1);  // destroy
extern "C" int __fastcall fn_00543610(void* self, int unusedEdx, int a1, int a2); // deallocate
extern "C" int __fastcall fn_00544730(void* self, int unusedEdx, int a1, int a2, int a3); // _Make_iter
extern "C" void* __fastcall fn_00543670(Local_00543670Tree* self, int unusedEdx, int retSlot, int proxy, int node);

#define ISNIL(n)   (*(char*)fn_00541d90(n))
#define RIGHT(n)   (*(int*)fn_00541da0(n))
#define LEFT(n)    (*(int*)fn_0054c630(n))
#define PARENT(n)  (*(int*)fn_0054c640(n))
#define COLOR(n)   (*(char*)fn_00543630(n))

extern "C" void* __fastcall fn_00543670(Local_00543670Tree* self, int unusedEdx, int retSlot, int proxy, int node)
{
    Local_00543670Iter where;
    where.proxy = proxy;
    where.node = node;

    if (ISNIL(fn_0054bf70(&where, 0)))
        throw std::out_of_range(std::string("invalid map/set<T> iterator"));

    int erased = fn_0054bf70(&where, 0);
    fn_005428f0(&where, 0);

    int pnode = erased;
    int fixnode;
    int fixnodeparent;

    if (ISNIL(LEFT(pnode)))
        fixnode = RIGHT(pnode);
    else if (ISNIL(RIGHT(pnode)))
        fixnode = LEFT(pnode);
    else {
        pnode = fn_0054bf70(&where, 0);
        fixnode = RIGHT(pnode);
    }

    if (pnode == erased) {
        fixnodeparent = PARENT(erased);
        if (!ISNIL(fixnode))
            PARENT(fixnode) = fixnodeparent;
        if (*(int*)fn_005423f0(self, 0) == erased)
            *(int*)fn_005423f0(self, 0) = fixnode;
        else if (LEFT(fixnodeparent) == erased)
            LEFT(fixnodeparent) = fixnode;
        else
            RIGHT(fixnodeparent) = fixnode;

        if (*(int*)fn_005508e0(self, 0) == erased)
            *(int*)fn_005508e0(self, 0) = ISNIL(fixnode) ? fixnodeparent : fn_00545510(fixnode);
        if (*(int*)fn_0054cec0(self, 0) == erased)
            *(int*)fn_0054cec0(self, 0) = ISNIL(fixnode) ? fixnodeparent : fn_005454d0(fixnode);
    } else {
        PARENT(LEFT(erased)) = pnode;
        LEFT(pnode) = LEFT(erased);
        if (pnode == RIGHT(erased))
            fixnodeparent = pnode;
        else {
            fixnodeparent = PARENT(pnode);
            if (!ISNIL(fixnode))
                PARENT(fixnode) = fixnodeparent;
            LEFT(fixnodeparent) = fixnode;
            RIGHT(pnode) = RIGHT(erased);
            PARENT(RIGHT(erased)) = pnode;
        }
        if (*(int*)fn_005423f0(self, 0) == erased)
            *(int*)fn_005423f0(self, 0) = pnode;
        else if (LEFT(PARENT(erased)) == erased)
            LEFT(PARENT(erased)) = pnode;
        else
            RIGHT(PARENT(erased)) = pnode;
        PARENT(pnode) = PARENT(erased);
        char t = COLOR(pnode);
        COLOR(pnode) = COLOR(erased);
        COLOR(erased) = t;
    }

    if (COLOR(erased) == 1) {
        for (; fixnode != *(int*)fn_005423f0(self, 0) && COLOR(fixnode) == 1;
             fixnodeparent = PARENT(fixnode)) {
            if (fixnode == LEFT(fixnodeparent)) {
                pnode = RIGHT(fixnodeparent);
                if (COLOR(pnode) == 0) {
                    COLOR(pnode) = 1;
                    COLOR(fixnodeparent) = 0;
                    fn_00550900(self, 0, fixnodeparent);
                    pnode = RIGHT(fixnodeparent);
                }
                if (ISNIL(pnode))
                    fixnode = fixnodeparent;
                else if (COLOR(LEFT(pnode)) == 1 && COLOR(RIGHT(pnode)) == 1) {
                    COLOR(pnode) = 0;
                    fixnode = fixnodeparent;
                } else {
                    if (COLOR(RIGHT(pnode)) == 1) {
                        COLOR(LEFT(pnode)) = 1;
                        COLOR(pnode) = 0;
                        fn_00544070(self, 0, pnode);
                        pnode = RIGHT(fixnodeparent);
                    }
                    COLOR(pnode) = COLOR(fixnodeparent);
                    COLOR(fixnodeparent) = 1;
                    COLOR(RIGHT(pnode)) = 1;
                    fn_00550900(self, 0, fixnodeparent);
                    break;
                }
            } else {
                pnode = LEFT(fixnodeparent);
                if (COLOR(pnode) == 0) {
                    COLOR(pnode) = 1;
                    COLOR(fixnodeparent) = 0;
                    fn_00544070(self, 0, fixnodeparent);
                    pnode = LEFT(fixnodeparent);
                }
                if (ISNIL(pnode))
                    fixnode = fixnodeparent;
                else if (COLOR(RIGHT(pnode)) == 1 && COLOR(LEFT(pnode)) == 1) {
                    COLOR(pnode) = 0;
                    fixnode = fixnodeparent;
                } else {
                    if (COLOR(LEFT(pnode)) == 1) {
                        COLOR(RIGHT(pnode)) = 1;
                        COLOR(pnode) = 0;
                        fn_00550900(self, 0, pnode);
                        pnode = LEFT(fixnodeparent);
                    }
                    COLOR(pnode) = COLOR(fixnodeparent);
                    COLOR(fixnodeparent) = 1;
                    COLOR(LEFT(pnode)) = 1;
                    fn_00544070(self, 0, fixnodeparent);
                    break;
                }
            }
        }
        COLOR(fixnode) = 1;
    }

    fn_005442d0(self->alloc, 0, erased);
    fn_00543610(self->alloc, 0, erased, 1);
    if (self->size > 0)
        --self->size;

    fn_00544730(self, 0, retSlot, where.proxy, where.node);
    return (void*)retSlot;
}
