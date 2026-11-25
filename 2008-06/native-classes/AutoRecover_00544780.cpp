// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdexcept>
#include <string>

// INFERRED: this is std::_Tree<...>::erase(iterator) from MSVC 2008 <xtree>.
struct Node;
typedef Node* NP;

// INFERRED: an iterator is 8 bytes, passed by value: container proxy plus node pointer.
struct TreeIter
{
    int cont;
    NP ptr;
};

// INFERRED: layout of _Tree: allocator _Alnod at +0xc, _Mysize at +0x1c.
struct TreeObj
{
    char pad0[0xc];
    char alnod[0x10];
    unsigned int mysize;
};

// Iterator members (thiscall on the iterator).
extern "C" NP __fastcall fn_0054bf70(TreeIter* self, int unusedEdx);   // _Mynode
extern "C" TreeIter* __fastcall fn_00542660(TreeIter* self, int unusedEdx);   // operator++

// Static node accessors (caller pops, so cdecl).
extern "C" char& fn_00542e00(NP p);   // _Isnil
extern "C" NP& fn_0054c630(NP p);     // _Left
extern "C" NP& fn_00541da0(NP p);     // _Right
extern "C" NP& fn_0054c640(NP p);     // _Parent
extern "C" char& fn_00544720(NP p);   // _Color
extern "C" NP fn_005450f0(NP p);      // _Min
extern "C" NP fn_00545ae0(NP p);      // _Max
extern "C" void fn_004019e0(char& a, char& b);   // std::swap<char>

// Tree members (thiscall).
extern "C" NP& __fastcall fn_005423f0(TreeObj* self, int unusedEdx);   // _Root
extern "C" NP& __fastcall fn_005508e0(TreeObj* self, int unusedEdx);   // _Lmost
extern "C" NP& __fastcall fn_0054cec0(TreeObj* self, int unusedEdx);   // _Rmost
extern "C" void __fastcall fn_00544fc0(TreeObj* self, int unusedEdx, NP p);   // _Lrotate
extern "C" void __fastcall fn_00545130(TreeObj* self, int unusedEdx, NP p);   // _Rrotate
extern "C" TreeIter* __fastcall fn_00544730(TreeObj* self, int unusedEdx, TreeIter* ret, TreeIter where);   // _Make_iter

// Allocator members (thiscall on this+0xc).
extern "C" void __fastcall fn_00545b70(void* self, int unusedEdx, NP p);   // destroy
extern "C" void __fastcall fn_00543610(void* self, int unusedEdx, NP p, unsigned int n);   // deallocate

extern "C" TreeIter* __fastcall fn_00544780(TreeObj* self, int unusedEdx, TreeIter* result, TreeIter _Where)
{
    if (fn_00542e00(fn_0054bf70(&_Where, 0)))
        throw std::out_of_range(std::string("invalid map/set<T> iterator"));

    NP _Fixnode;
    NP _Fixnodeparent;
    NP _Erasednode = fn_0054bf70(&_Where, 0);
    fn_00542660(&_Where, 0);

    NP _Pnode = _Erasednode;
    if (fn_00542e00(fn_0054c630(_Pnode)))
        _Fixnode = fn_00541da0(_Pnode);
    else if (fn_00542e00(fn_00541da0(_Pnode)))
        _Fixnode = fn_0054c630(_Pnode);
    else
    {
        _Pnode = fn_0054bf70(&_Where, 0);
        _Fixnode = fn_00541da0(_Pnode);
    }

    if (_Pnode == _Erasednode)
    {
        _Fixnodeparent = fn_0054c640(_Erasednode);
        if (!fn_00542e00(_Fixnode))
            fn_0054c640(_Fixnode) = _Fixnodeparent;

        if (fn_005423f0(self, 0) == _Erasednode)
            fn_005423f0(self, 0) = _Fixnode;
        else if (fn_0054c630(_Fixnodeparent) == _Erasednode)
            fn_0054c630(_Fixnodeparent) = _Fixnode;
        else
            fn_00541da0(_Fixnodeparent) = _Fixnode;

        if (fn_005508e0(self, 0) == _Erasednode)
            fn_005508e0(self, 0) = fn_00542e00(_Fixnode) ? _Fixnodeparent : fn_005450f0(_Fixnode);

        if (fn_0054cec0(self, 0) == _Erasednode)
            fn_0054cec0(self, 0) = fn_00542e00(_Fixnode) ? _Fixnodeparent : fn_00545ae0(_Fixnode);
    }
    else
    {
        fn_0054c640(fn_0054c630(_Erasednode)) = _Pnode;
        fn_0054c630(_Pnode) = fn_0054c630(_Erasednode);

        if (_Pnode == fn_00541da0(_Erasednode))
            _Fixnodeparent = _Pnode;
        else
        {
            _Fixnodeparent = fn_0054c640(_Pnode);
            if (!fn_00542e00(_Fixnode))
                fn_0054c640(_Fixnode) = _Fixnodeparent;
            fn_0054c630(_Fixnodeparent) = _Fixnode;
            fn_00541da0(_Pnode) = fn_00541da0(_Erasednode);
            fn_0054c640(fn_00541da0(_Erasednode)) = _Pnode;
        }

        if (fn_005423f0(self, 0) == _Erasednode)
            fn_005423f0(self, 0) = _Pnode;
        else if (fn_0054c630(fn_0054c640(_Erasednode)) == _Erasednode)
            fn_0054c630(fn_0054c640(_Erasednode)) = _Pnode;
        else
            fn_00541da0(fn_0054c640(_Erasednode)) = _Pnode;

        fn_0054c640(_Pnode) = fn_0054c640(_Erasednode);
        fn_004019e0(fn_00544720(_Pnode), fn_00544720(_Erasednode));
    }

    if (fn_00544720(_Erasednode) == 1)
    {
        for (; _Fixnode != fn_005423f0(self, 0) && fn_00544720(_Fixnode) == 1;
             _Fixnodeparent = fn_0054c640(_Fixnode))
        {
            if (_Fixnode == fn_0054c630(_Fixnodeparent))
            {
                _Pnode = fn_00541da0(_Fixnodeparent);
                if (fn_00544720(_Pnode) == 0)
                {
                    fn_00544720(_Pnode) = 1;
                    fn_00544720(_Fixnodeparent) = 0;
                    fn_00544fc0(self, 0, _Fixnodeparent);
                    _Pnode = fn_00541da0(_Fixnodeparent);
                }

                if (fn_00542e00(_Pnode))
                    _Fixnode = _Fixnodeparent;
                else if (fn_00544720(fn_0054c630(_Pnode)) == 1
                         && fn_00544720(fn_00541da0(_Pnode)) == 1)
                {
                    fn_00544720(_Pnode) = 0;
                    _Fixnode = _Fixnodeparent;
                }
                else
                {
                    if (fn_00544720(fn_00541da0(_Pnode)) == 1)
                    {
                        fn_00544720(fn_0054c630(_Pnode)) = 1;
                        fn_00544720(_Pnode) = 0;
                        fn_00545130(self, 0, _Pnode);
                        _Pnode = fn_00541da0(_Fixnodeparent);
                    }
                    fn_00544720(_Pnode) = fn_00544720(_Fixnodeparent);
                    fn_00544720(_Fixnodeparent) = 1;
                    fn_00544720(fn_00541da0(_Pnode)) = 1;
                    fn_00544fc0(self, 0, _Fixnodeparent);
                    break;
                }
            }
            else
            {
                _Pnode = fn_0054c630(_Fixnodeparent);
                if (fn_00544720(_Pnode) == 0)
                {
                    fn_00544720(_Pnode) = 1;
                    fn_00544720(_Fixnodeparent) = 0;
                    fn_00545130(self, 0, _Fixnodeparent);
                    _Pnode = fn_0054c630(_Fixnodeparent);
                }

                if (fn_00542e00(_Pnode))
                    _Fixnode = _Fixnodeparent;
                else if (fn_00544720(fn_00541da0(_Pnode)) == 1
                         && fn_00544720(fn_0054c630(_Pnode)) == 1)
                {
                    fn_00544720(_Pnode) = 0;
                    _Fixnode = _Fixnodeparent;
                }
                else
                {
                    if (fn_00544720(fn_0054c630(_Pnode)) == 1)
                    {
                        fn_00544720(fn_00541da0(_Pnode)) = 1;
                        fn_00544720(_Pnode) = 0;
                        fn_00544fc0(self, 0, _Pnode);
                        _Pnode = fn_0054c630(_Fixnodeparent);
                    }
                    fn_00544720(_Pnode) = fn_00544720(_Fixnodeparent);
                    fn_00544720(_Fixnodeparent) = 1;
                    fn_00544720(fn_0054c630(_Pnode)) = 1;
                    fn_00545130(self, 0, _Fixnodeparent);
                    break;
                }
            }
        }
        fn_00544720(_Fixnode) = 1;
    }

    fn_00545b70(self->alnod, 0, _Erasednode);
    fn_00543610(self->alnod, 0, _Erasednode, 1);

    if (0 < self->mysize)
        --self->mysize;

    fn_00544730(self, 0, result, _Where);
    return result;
}
