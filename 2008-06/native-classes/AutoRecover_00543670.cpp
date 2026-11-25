// native-flags: /O2 /Ob2 /Oy /GF /GS /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>
#include <algorithm>

// INFERRED: this is std::_Tree<set<int>>::erase(const_iterator) from MSVC 9 (set<int>).
// INFERRED: the original was built without optimisation (frame pointer, every helper
// called out of line), so optimisation is switched off for this function.
// INFERRED: node accessors are cdecl (push arg / add esp,4 in the disassembly).

typedef void* NodePtr;

struct TreeIter {
    int   cont;   // INFERRED: checked-iterator container proxy
    void* ptr;    // INFERRED: node pointer
};

struct Local_00543670 {
    TreeIter* erase(TreeIter* ret, int whereCont, void* wherePtr);
};
struct TreeObj;

extern "C" {
    char*     fn_00541d90(NodePtr n);   // _Isnil
    NodePtr*  fn_0054c630(NodePtr n);   // _Left
    NodePtr*  fn_00541da0(NodePtr n);   // _Right
    NodePtr*  fn_0054c640(NodePtr n);   // _Parent
    char*     fn_00543630(NodePtr n);   // _Color
    NodePtr   fn_00545510(NodePtr n);   // _Min
    NodePtr   fn_005454d0(NodePtr n);   // _Max

    NodePtr*  __fastcall fn_005423f0(void* self, int unusedEdx);            // _Root
    NodePtr*  __fastcall fn_005508e0(void* self, int unusedEdx);            // _Lmost
    NodePtr*  __fastcall fn_0054cec0(void* self, int unusedEdx);            // _Rmost
    int       __fastcall fn_00550900(void* self, int unusedEdx, NodePtr n); // _Lrotate
    int       __fastcall fn_00544070(void* self, int unusedEdx, NodePtr n); // _Rrotate
    int       __fastcall fn_005442d0(void* self, int unusedEdx, NodePtr n); // destroy
    int       __fastcall fn_00543610(void* self, int unusedEdx, NodePtr n, int count); // deallocate
    TreeIter* __fastcall fn_00544730(void* self, int unusedEdx, TreeIter* ret, int cont, void* ptr); // _Make_iter

    NodePtr   __fastcall fn_0054bf70(TreeIter* self, int unusedEdx);  // _Mynode
    int       __fastcall fn_005428f0(TreeIter* self, int unusedEdx);  // operator++
}

#pragma optimize("", off)

// INFERRED: 'where' iterator passed by value occupies [ebp+0xc]/[ebp+0x10]
#define WHERE ((TreeIter*)&whereCont)

TreeIter* Local_00543670::erase(TreeIter* ret, int whereCont, void* wherePtr)
{
    TreeObj* self = (TreeObj*)this;
    if (*fn_00541d90(fn_0054bf70(WHERE, 0)) != 0)
        throw std::out_of_range("invalid map/set<T> iterator");

    NodePtr _Erasednode = fn_0054bf70(WHERE, 0);
    fn_005428f0(WHERE, 0);

    NodePtr _Fixnode;
    NodePtr _Pnode = _Erasednode;
    NodePtr _Fixnodeparent;

    if (*fn_00541d90(*fn_0054c630(_Pnode)) != 0)
        _Fixnode = *fn_00541da0(_Pnode);
    else if (*fn_00541d90(*fn_00541da0(_Pnode)) != 0)
        _Fixnode = *fn_0054c630(_Pnode);
    else {
        _Pnode = fn_0054bf70(WHERE, 0);
        _Fixnode = *fn_00541da0(_Pnode);
    }

    if (_Pnode == _Erasednode) {
        _Fixnodeparent = *fn_0054c640(_Erasednode);
        if (*fn_00541d90(_Fixnode) == 0)
            *fn_0054c640(_Fixnode) = _Fixnodeparent;

        if (*((NodePtr*(__thiscall*)(void*))fn_005423f0)(self) == _Erasednode)
            *((NodePtr*(__thiscall*)(void*))fn_005423f0)(self) = _Fixnode;
        else if (*fn_0054c630(_Fixnodeparent) == _Erasednode)
            *fn_0054c630(_Fixnodeparent) = _Fixnode;
        else
            *fn_00541da0(_Fixnodeparent) = _Fixnode;

        if (*((NodePtr*(__thiscall*)(void*))fn_005508e0)(self) == _Erasednode)
            *((NodePtr*(__thiscall*)(void*))fn_005508e0)(self) = (*fn_00541d90(_Fixnode) != 0) ? _Fixnodeparent : fn_00545510(_Fixnode);

        if (*((NodePtr*(__thiscall*)(void*))fn_0054cec0)(self) == _Erasednode)
            *((NodePtr*(__thiscall*)(void*))fn_0054cec0)(self) = (*fn_00541d90(_Fixnode) != 0) ? _Fixnodeparent : fn_005454d0(_Fixnode);
    } else {
        *fn_0054c640(*fn_0054c630(_Erasednode)) = _Pnode;
        *fn_0054c630(_Pnode) = *fn_0054c630(_Erasednode);

        if (_Pnode == *fn_00541da0(_Erasednode))
            _Fixnodeparent = _Pnode;
        else {
            _Fixnodeparent = *fn_0054c640(_Pnode);
            if (*fn_00541d90(_Fixnode) == 0)
                *fn_0054c640(_Fixnode) = _Fixnodeparent;
            *fn_0054c630(_Fixnodeparent) = _Fixnode;
            *fn_00541da0(_Pnode) = *fn_00541da0(_Erasednode);
            *fn_0054c640(*fn_00541da0(_Erasednode)) = _Pnode;
        }

        if (*((NodePtr*(__thiscall*)(void*))fn_005423f0)(self) == _Erasednode)
            *((NodePtr*(__thiscall*)(void*))fn_005423f0)(self) = _Pnode;
        else if (*fn_0054c630(*fn_0054c640(_Erasednode)) == _Erasednode)
            *fn_0054c630(*fn_0054c640(_Erasednode)) = _Pnode;
        else
            *fn_00541da0(*fn_0054c640(_Erasednode)) = _Pnode;

        *fn_0054c640(_Pnode) = *fn_0054c640(_Erasednode);
        std::swap(*fn_00543630(_Pnode), *fn_00543630(_Erasednode));
    }

    if (*fn_00543630(_Erasednode) == 1) {
        for (; _Fixnode != *((NodePtr*(__thiscall*)(void*))fn_005423f0)(self) && *fn_00543630(_Fixnode) == 1;
             _Fixnodeparent = *fn_0054c640(_Fixnode))
        {
            if (_Fixnode == *fn_0054c630(_Fixnodeparent)) {
                _Pnode = *fn_00541da0(_Fixnodeparent);
                if (*fn_00543630(_Pnode) == 0) {
                    *fn_00543630(_Pnode) = 1;
                    *fn_00543630(_Fixnodeparent) = 0;
                    ((int(__thiscall*)(void*, NodePtr))fn_00550900)(self, _Fixnodeparent);
                    _Pnode = *fn_00541da0(_Fixnodeparent);
                }
                if (*fn_00541d90(_Pnode) != 0)
                    _Fixnode = _Fixnodeparent;
                else if (*fn_00543630(*fn_0054c630(_Pnode)) == 1
                      && *fn_00543630(*fn_00541da0(_Pnode)) == 1) {
                    *fn_00543630(_Pnode) = 0;
                    _Fixnode = _Fixnodeparent;
                } else {
                    if (*fn_00543630(*fn_00541da0(_Pnode)) == 1) {
                        *fn_00543630(*fn_0054c630(_Pnode)) = 1;
                        *fn_00543630(_Pnode) = 0;
                        ((int(__thiscall*)(void*, NodePtr))fn_00544070)(self, _Pnode);
                        _Pnode = *fn_00541da0(_Fixnodeparent);
                    }
                    *fn_00543630(_Pnode) = *fn_00543630(_Fixnodeparent);
                    *fn_00543630(_Fixnodeparent) = 1;
                    *fn_00543630(*fn_00541da0(_Pnode)) = 1;
                    ((int(__thiscall*)(void*, NodePtr))fn_00550900)(self, _Fixnodeparent);
                    break;
                }
            } else {
                _Pnode = *fn_0054c630(_Fixnodeparent);
                if (*fn_00543630(_Pnode) == 0) {
                    *fn_00543630(_Pnode) = 1;
                    *fn_00543630(_Fixnodeparent) = 0;
                    ((int(__thiscall*)(void*, NodePtr))fn_00544070)(self, _Fixnodeparent);
                    _Pnode = *fn_0054c630(_Fixnodeparent);
                }
                if (*fn_00541d90(_Pnode) != 0)
                    _Fixnode = _Fixnodeparent;
                else if (*fn_00543630(*fn_00541da0(_Pnode)) == 1
                      && *fn_00543630(*fn_0054c630(_Pnode)) == 1) {
                    *fn_00543630(_Pnode) = 0;
                    _Fixnode = _Fixnodeparent;
                } else {
                    if (*fn_00543630(*fn_0054c630(_Pnode)) == 1) {
                        *fn_00543630(*fn_00541da0(_Pnode)) = 1;
                        *fn_00543630(_Pnode) = 0;
                        ((int(__thiscall*)(void*, NodePtr))fn_00550900)(self, _Pnode);
                        _Pnode = *fn_0054c630(_Fixnodeparent);
                    }
                    *fn_00543630(_Pnode) = *fn_00543630(_Fixnodeparent);
                    *fn_00543630(_Fixnodeparent) = 1;
                    *fn_00543630(*fn_0054c630(_Pnode)) = 1;
                    ((int(__thiscall*)(void*, NodePtr))fn_00544070)(self, _Fixnodeparent);
                    break;
                }
            }
        }
        *fn_00543630(_Fixnode) = 1;
    }

    fn_005442d0((char*)self + 0xc, 0, _Erasednode);
    fn_00543610((char*)self + 0xc, 0, _Erasednode, 1);

    if (*(unsigned int*)((char*)self + 0x1c) > 0)
        *(unsigned int*)((char*)self + 0x1c) = *(unsigned int*)((char*)self + 0x1c) - 1;

    ((TreeIter*(__thiscall*)(void*, TreeIter*, int, void*))fn_00544730)(self, ret, whereCont, wherePtr);
    return ret;
}

#undef WHERE

#pragma optimize("", on)
