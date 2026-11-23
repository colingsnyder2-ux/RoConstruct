// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::set<int>::erase(iterator) (_Tree::erase) with inlined RB-tree rebalance.
// Node accessors, named by role: 54c630=_Left 54c640=_Parent 541da0=_Right
// 541d90=_Isnil 543630=_Color 5423f0=_Root 5508e0=_Lmost 54cec0=_Rmost
// 545510=_Min 5454d0=_Max 544070=_Rrotate 550900=_Lrotate
#include <string>
#include <exception>

extern "C" int fn_00541d90(int a1);
extern "C" int __fastcall fn_004024a0(void* self, int unusedEdx, int a1);
extern "C" int fn_0054c630(int arg);
extern "C" char *fn_00541da0(char* self);
extern "C" char *fn_0054c640(char* self);
extern "C" int __fastcall fn_005423f0(void* self, int unusedEdx);
extern "C" int fn_00545510(int a1);
extern "C" int __fastcall fn_0054cec0(void* self, int unusedEdx);
extern "C" int fn_005454d0(int a1);
extern "C" char *fn_00543630(char* base);
extern "C" int __fastcall fn_00544070(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005442d0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00543610(void* self, int unusedEdx, int node, int n);
extern "C" int __fastcall fn_005508e0(void* self, int unusedEdx);
extern "C" int __fastcall fn_00550900(void* self, int unusedEdx, int node);
extern "C" int __fastcall fn_00544730(void* self, int unusedEdx, int ret, int ptr, int proxy);
extern "C" int __fastcall fn_0054bf70(void* self, int unusedEdx);
extern "C" int __fastcall fn_005428f0(void* self, int unusedEdx);
extern "C" void __cdecl fn_004019e0(char& a, char& b);

struct TreeIter { int ptr; int proxy; };
struct TreeBase { int pad[3]; char alloc[4]; int pad2[3]; unsigned size; };

#define ISNIL(n)   (*(char*)fn_00541d90(n))
#define LEFT(n)    (*(int*)fn_0054c630(0, 0, n))
#define PARENT(n)  (*(int*)fn_0054c640(0, 0, n))
#define RIGHT(n)   (*(int*)fn_00541da0(0, 0, n))
#define COLOR(n)   (*(char*)fn_00543630(0, 0, n))

extern "C" int __fastcall fn_00543670(TreeBase* self, int unusedEdx, int retPtr, int itPtr, int itProxy)
{
    TreeIter* it = (TreeIter*)&retPtr + 1; // INFERRED: iterator passed by value after the return slot
    if (ISNIL(fn_0054bf70(it, 0))) {
        std::string msg("invalid map/set<T> iterator");
        throw std::exception(msg.c_str());
    }
    int erased = fn_0054bf70(it, 0);
    fn_005428f0(it, 0); // ++iterator
    int pnode = erased;
    int fixnode;
    int fixparent;
    if (ISNIL(LEFT(pnode))) {
        fixnode = RIGHT(pnode);
    } else if (ISNIL(RIGHT(pnode))) {
        fixnode = LEFT(pnode);
    } else {
        pnode = fn_0054bf70(it, 0);
        fixnode = RIGHT(pnode);
    }
    if (pnode == erased) {
        fixparent = PARENT(erased);
        if (!ISNIL(fixnode))
            PARENT(fixnode) = fixparent;
        if (*(int*)fn_005423f0(self, 0) == erased)
            *(int*)fn_005423f0(self, 0) = fixnode;
        else if (LEFT(fixparent) == erased)
            LEFT(fixparent) = fixnode;
        else
            RIGHT(fixparent) = fixnode;
        if (*(int*)fn_005508e0(self, 0) == erased)
            *(int*)fn_005508e0(self, 0) = ISNIL(fixnode) ? fixparent : fn_00545510(fixnode);
        if (*(int*)fn_0054cec0(self, 0) == erased)
            *(int*)fn_0054cec0(self, 0) = ISNIL(fixnode) ? fixparent : fn_005454d0(fixnode);
    } else {
        PARENT(LEFT(erased)) = pnode;
        LEFT(pnode) = LEFT(erased);
        if (pnode == RIGHT(erased)) {
            fixparent = pnode;
        } else {
            fixparent = PARENT(pnode);
            if (!ISNIL(fixnode))
                PARENT(fixnode) = fixparent;
            LEFT(fixparent) = fixnode;
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
        fn_004019e0(COLOR(pnode), COLOR(erased));
    }
    if (COLOR(erased) == 1) {
        for (; *(int*)fn_005423f0(self, 0) != fixnode && COLOR(fixnode) == 1; fixparent = PARENT(fixnode)) {
            if (fixnode == LEFT(fixparent)) {
                pnode = RIGHT(fixparent);
                if (COLOR(pnode) == 0) {
                    COLOR(pnode) = 1;
                    COLOR(fixparent) = 0;
                    fn_00550900(self, 0, fixparent);
                    pnode = RIGHT(fixparent);
                }
                if (ISNIL(pnode)) {
                    fixnode = fixparent;
                } else if (COLOR(LEFT(pnode)) == 1 && COLOR(RIGHT(pnode)) == 1) {
                    COLOR(pnode) = 0;
                    fixnode = fixparent;
                } else {
                    if (COLOR(RIGHT(pnode)) == 1) {
                        COLOR(LEFT(pnode)) = 1;
                        COLOR(pnode) = 0;
                        fn_00544070(self, 0, pnode);
                        pnode = RIGHT(fixparent);
                    }
                    COLOR(pnode) = COLOR(fixparent);
                    COLOR(fixparent) = 1;
                    COLOR(RIGHT(pnode)) = 1;
                    fn_00550900(self, 0, fixparent);
                    break;
                }
            } else {
                pnode = LEFT(fixparent);
                if (COLOR(pnode) == 0) {
                    COLOR(pnode) = 1;
                    COLOR(fixparent) = 0;
                    fn_00544070(self, 0, fixparent);
                    pnode = LEFT(fixparent);
                }
                if (ISNIL(pnode)) {
                    fixnode = fixparent;
                } else if (COLOR(RIGHT(pnode)) == 1 && COLOR(LEFT(pnode)) == 1) {
                    COLOR(pnode) = 0;
                    fixnode = fixparent;
                } else {
                    if (COLOR(LEFT(pnode)) == 1) {
                        COLOR(RIGHT(pnode)) = 1;
                        COLOR(pnode) = 0;
                        fn_00550900(self, 0, pnode);
                        pnode = LEFT(fixparent);
                    }
                    COLOR(pnode) = COLOR(fixparent);
                    COLOR(fixparent) = 1;
                    COLOR(LEFT(pnode)) = 1;
                    fn_00544070(self, 0, fixparent);
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
    return fn_00544730(self, 0, retPtr, itPtr, itProxy);
}
