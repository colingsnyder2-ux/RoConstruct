// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// Recovers the parameter type of the compiler's existing _CxxThrowException
// declaration, so this file does not redeclare it.
template <class T>
static __forceinline T* ThrowInfoCast(void (__stdcall *)(void*, T*), void* p)
{
    return (T*)p;
}

// INFERRED: this is std::_Tree<set<int>>::_Insert(bool _Addleft, _Nodeptr _Wherenode, const int& _Val),
// returning an iterator through a hidden return pointer.
// INFERRED: the original was built unoptimized (frame pointer, no inlining), so optimization is turned off here.
#pragma optimize("", off)

struct TreeNode;
typedef TreeNode* Nptr;

struct IntSetTree {
    char pad[0x18];
    Nptr head;        // +0x18 _Myhead
    unsigned size;    // +0x1c _Mysize
};

// INFERRED: the node accessors are plain cdecl calls (push arg / add esp,4) in the disassembly.
extern "C" Nptr* __cdecl fn_0054c630(Nptr n);   // _Left
extern "C" Nptr* __cdecl fn_00541da0(Nptr n);   // _Right
extern "C" Nptr* __cdecl fn_0054c640(Nptr n);   // _Parent
extern "C" char* __cdecl fn_0054c5f0(Nptr n);   // _Color

extern "C" unsigned __fastcall fn_0054f980(void* self, int unusedEdx);
extern "C" Nptr __fastcall fn_0054fb80(void* self, int unusedEdx, Nptr a, Nptr b, Nptr c, const int* val, int color);
extern "C" Nptr* __fastcall fn_005423f0(void* self, int unusedEdx);   // _Root
extern "C" Nptr* __fastcall fn_005508e0(void* self, int unusedEdx);   // _Lmost
extern "C" Nptr* __fastcall fn_0054cec0(void* self, int unusedEdx);   // _Rmost
extern "C" void __fastcall fn_0054cd10(void* self, int unusedEdx, Nptr n);
extern "C" void __fastcall fn_0054cee0(void* self, int unusedEdx, Nptr n);
extern "C" void* __fastcall fn_0054e320(void* ret, int unusedEdx, Nptr node, void* tree); // iterator ctor
extern "C" int __fastcall fn_00402480(void* self, int unusedEdx, int a1);   // length_error ctor
extern "C" char g_008d0cc0[];   // INFERRED: throw info for length_error

struct LenErrObj { int a, b, c; };

extern "C" void* __fastcall fn_0054e6b0(IntSetTree* self, int unusedEdx, void* ret, bool addleft, Nptr where, const int* val)
{
    if (fn_0054f980(self, 0) - 1 <= self->size) {
        std::string msg("map/set<T> too long");
        LenErrObj ex;
        fn_00402480(&ex, 0, (int)&msg);
        _CxxThrowException(&ex, ThrowInfoCast(_CxxThrowException, g_008d0cc0));
    }

    Nptr pnode = fn_0054fb80(self, 0, self->head, where, self->head, val, 0);
    ++self->size;

    if (where == self->head) {
        *fn_005423f0(self, 0) = pnode;
        *fn_005508e0(self, 0) = pnode;
        *fn_0054cec0(self, 0) = pnode;
    } else if (addleft) {
        *fn_0054c630(where) = pnode;
        if (where == *fn_005508e0(self, 0))
            *fn_005508e0(self, 0) = pnode;
    } else {
        *fn_00541da0(where) = pnode;
        if (where == *fn_0054cec0(self, 0))
            *fn_0054cec0(self, 0) = pnode;
    }

    Nptr x = pnode;
    while (*fn_0054c5f0(*fn_0054c640(x)) == 0) {
        if (*fn_0054c640(x) == *fn_0054c630(*fn_0054c640(*fn_0054c640(x)))) {
            where = *fn_00541da0(*fn_0054c640(*fn_0054c640(x)));
            if (*fn_0054c5f0(where) == 0) {
                *fn_0054c5f0(*fn_0054c640(x)) = 1;
                *fn_0054c5f0(where) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(x))) = 0;
                x = *fn_0054c640(*fn_0054c640(x));
            } else {
                if (x == *fn_00541da0(*fn_0054c640(x))) {
                    x = *fn_0054c640(x);
                    fn_0054cd10(self, 0, x);
                }
                *fn_0054c5f0(*fn_0054c640(x)) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(x))) = 0;
                fn_0054cee0(self, 0, *fn_0054c640(*fn_0054c640(x)));
            }
        } else {
            where = *fn_0054c630(*fn_0054c640(*fn_0054c640(x)));
            if (*fn_0054c5f0(where) == 0) {
                *fn_0054c5f0(*fn_0054c640(x)) = 1;
                *fn_0054c5f0(where) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(x))) = 0;
                x = *fn_0054c640(*fn_0054c640(x));
            } else {
                if (x == *fn_0054c630(*fn_0054c640(x))) {
                    x = *fn_0054c640(x);
                    fn_0054cee0(self, 0, x);
                }
                *fn_0054c5f0(*fn_0054c640(x)) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(x))) = 0;
                fn_0054cd10(self, 0, *fn_0054c640(*fn_0054c640(x)));
            }
        }
    }

    *fn_0054c5f0(*fn_005423f0(self, 0)) = 1;
    fn_0054e320(ret, 0, pnode, self);
    return ret;
}

#pragma optimize("", on)
