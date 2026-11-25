// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>

// INFERRED: this is std::_Tree<set<int>>::_Insert(bool addleft, _Nodeptr where, const int& val)
// returning an iterator through a hidden pointer (first stack arg).
// Node accessors at 0x54c630/0x54c640/0x541da0/0x543630 are cdecl (caller does add esp,4).
extern "C" int* fn_0054c630(int node);   // _Left
extern "C" int* fn_0054c640(int node);   // _Parent
extern "C" int* fn_00541da0(int node);   // _Right
extern "C" char* fn_00543630(int node);  // _Color

extern "C" int __fastcall fn_00550a30(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
extern "C" int* __fastcall fn_005423f0(void* self, int unusedEdx);   // _Root
extern "C" int* __fastcall fn_0054cec0(void* self, int unusedEdx);   // _Rmost
extern "C" int* __fastcall fn_005508e0(void* self, int unusedEdx);   // _Lmost
extern "C" int __fastcall fn_00550900(void* self, int unusedEdx, int node); // _Lrotate
extern "C" int __fastcall fn_00544070(void* self, int unusedEdx, int node); // _Rrotate
extern "C" int __fastcall fn_00543650(Unknown543650* self, int unusedEdx);
extern "C" void* __fastcall fn_0054e320(void* self, int unusedEdx, int node, void* tree); // iterator ctor

struct TreeHdr {
    char pad[0x18];
    int head;
    unsigned size;
};

extern "C" void* __fastcall fn_0054f3f0(TreeHdr* self, int unusedEdx, void* retIter, int addLeft, int where, int val)
{
    // max_size() check; INFERRED: original max_size is func_00543650
    if ((unsigned)fn_00543650(self, 0, 0, 0, 0, 0, 0, 0) - 1 <= self->size) {
        // INFERRED: _Xlen
        throw std::length_error(std::string("map/set<T> too long"));
    }

    int newnode = fn_00550a30(self, 0, self->head, where, self->head, val, 0);
    ++self->size;

    if (where == self->head) {
        *fn_005423f0(self, 0) = newnode;
        *fn_005508e0(self, 0) = newnode;
        *fn_0054cec0(self, 0) = newnode;
    } else if ((unsigned char)addLeft) {
        *fn_0054c630(where) = newnode;
        if (where == *fn_005508e0(self, 0))
            *fn_005508e0(self, 0) = newnode;
    } else {
        *fn_00541da0(where) = newnode;
        if (where == *fn_0054cec0(self, 0))
            *fn_0054cec0(self, 0) = newnode;
    }

    int p = newnode;
    while (*fn_00543630(*fn_0054c640(p)) == 0) {
        if (*fn_0054c640(p) == *fn_0054c630(*fn_0054c640(*fn_0054c640(p)))) {
            int w = *fn_00541da0(*fn_0054c640(*fn_0054c640(p)));
            if (*fn_00543630(w) == 0) {
                *fn_00543630(*fn_0054c640(p)) = 1;
                *fn_00543630(w) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(p))) = 0;
                p = *fn_0054c640(*fn_0054c640(p));
            } else {
                if (p == *fn_00541da0(*fn_0054c640(p))) {
                    p = *fn_0054c640(p);
                    fn_00550900(self, 0, p);
                }
                *fn_00543630(*fn_0054c640(p)) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(p))) = 0;
                fn_00544070(self, 0, *fn_0054c640(*fn_0054c640(p)));
            }
        } else {
            int w = *fn_0054c630(*fn_0054c640(*fn_0054c640(p)));
            if (*fn_00543630(w) == 0) {
                *fn_00543630(*fn_0054c640(p)) = 1;
                *fn_00543630(w) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(p))) = 0;
                p = *fn_0054c640(*fn_0054c640(p));
            } else {
                if (p == *fn_0054c630(*fn_0054c640(p))) {
                    p = *fn_0054c640(p);
                    fn_00544070(self, 0, p);
                }
                *fn_00543630(*fn_0054c640(p)) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(p))) = 0;
                fn_00550900(self, 0, *fn_0054c640(*fn_0054c640(p)));
            }
        }
    }

    *fn_00543630(*fn_005423f0(self, 0)) = 1;
    return fn_0054e320(retIter, 0, newnode, self);
}
