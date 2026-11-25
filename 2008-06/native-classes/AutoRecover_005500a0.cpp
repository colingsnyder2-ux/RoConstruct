// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>
#include <algorithm>

// INFERRED: std::_Tree<_Tset_traits<int,...>>::erase(const_iterator) (VC9 <xtree>)
struct TreeNode;

// INFERRED: VC9 const_iterator layout {_Mycont, _Ptr} (8 bytes, passed by value)
struct TreeIter
{
    void* _Mycont;
    TreeNode* _Ptr;
};

struct TreeObj
{
    char _pad0[0x0c];
    char _Alnod[0x10];      // +0x0c
    unsigned int _Mysize;   // +0x1c
};

// iterator members (__thiscall on iterator)
extern "C" TreeNode* __fastcall fn_0054bf70(TreeIter* self, int unusedEdx);   // _Mynode
extern "C" TreeIter* __fastcall fn_005428f0(TreeIter* self, int unusedEdx);   // operator++

// static node accessors (cdecl, caller pops)
extern "C" char& fn_00541d90(TreeNode* a1);          // _Isnil
extern "C" TreeNode*& fn_0054c630(TreeNode* a1);     // _Left
extern "C" TreeNode*& fn_00541da0(TreeNode* a1);     // _Right
extern "C" TreeNode*& fn_0054c640(TreeNode* a1);     // _Parent
extern "C" char& fn_00543630(TreeNode* a1);          // _Color
extern "C" TreeNode* fn_00545510(TreeNode* a1);      // _Min
extern "C" TreeNode* fn_005454d0(TreeNode* a1);      // _Max

// tree members (__thiscall)
extern "C" TreeNode*& __fastcall fn_005423f0(TreeObj* self, int unusedEdx);   // _Root
extern "C" TreeNode*& __fastcall fn_005508e0(TreeObj* self, int unusedEdx);   // _Lmost
extern "C" TreeNode*& __fastcall fn_0054cec0(TreeObj* self, int unusedEdx);   // _Rmost
extern "C" void __fastcall fn_00550900(TreeObj* self, int unusedEdx, TreeNode* a1); // _Lrotate
extern "C" void __fastcall fn_00544070(TreeObj* self, int unusedEdx, TreeNode* a1); // _Rrotate
extern "C" void __fastcall fn_0054f900(void* self, int unusedEdx, TreeNode* a1);    // _Alnod.destroy
extern "C" void __fastcall fn_00543610(void* self, int unusedEdx, TreeNode* a1, unsigned int n); // _Alnod.deallocate
extern "C" TreeIter* __fastcall fn_00544730(TreeObj* self, int unusedEdx, TreeIter* result, TreeIter where); // _Make_iter

extern "C" TreeIter* __fastcall fn_005500a0(TreeObj* self, int unusedEdx, TreeIter* result, TreeIter _Where)
{
    if (fn_00541d90(fn_0054bf70(&_Where, 0)))
        throw std::out_of_range(std::string("invalid map/set<T> iterator"));

    TreeNode* _Fixnode;
    TreeNode* _Fixnodeparent;
    TreeNode* _Erasednode = fn_0054bf70(&_Where, 0);
    fn_005428f0(&_Where, 0);

    TreeNode* _Pnode = _Erasednode;
    if (fn_00541d90(fn_0054c630(_Pnode)))
        _Fixnode = fn_00541da0(_Pnode);
    else if (fn_00541d90(fn_00541da0(_Pnode)))
        _Fixnode = fn_0054c630(_Pnode);
    else
    {
        _Pnode = fn_0054bf70(&_Where, 0);
        _Fixnode = fn_00541da0(_Pnode);
    }

    if (_Pnode == _Erasednode)
    {
        _Fixnodeparent = fn_0054c640(_Erasednode);
        if (!fn_00541d90(_Fixnode))
            fn_0054c640(_Fixnode) = _Fixnodeparent;

        if (fn_005423f0(self, 0) == _Erasednode)
            fn_005423f0(self, 0) = _Fixnode;
        else if (fn_0054c630(_Fixnodeparent) == _Erasednode)
            fn_0054c630(_Fixnodeparent) = _Fixnode;
        else
            fn_00541da0(_Fixnodeparent) = _Fixnode;

        if (fn_005508e0(self, 0) == _Erasednode)
            fn_005508e0(self, 0) = fn_00541d90(_Fixnode) ? _Fixnodeparent : fn_00545510(_Fixnode);

        if (fn_0054cec0(self, 0) == _Erasednode)
            fn_0054cec0(self, 0) = fn_00541d90(_Fixnode) ? _Fixnodeparent : fn_005454d0(_Fixnode);
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
            if (!fn_00541d90(_Fixnode))
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
        std::swap(fn_00543630(_Pnode), fn_00543630(_Erasednode));
    }

    if (fn_00543630(_Erasednode) == 1)
    {
        for (; _Fixnode != fn_005423f0(self, 0) && fn_00543630(_Fixnode) == 1;
             _Fixnode = fn_0054c640(_Fixnodeparent))
        {
            if (_Fixnode == fn_0054c630(_Fixnodeparent))
            {
                _Pnode = fn_00541da0(_Fixnodeparent);
                if (fn_00543630(_Pnode) == 0)
                {
                    fn_00543630(_Pnode) = 1;
                    fn_00543630(_Fixnodeparent) = 0;
                    fn_00550900(self, 0, _Fixnodeparent);
                    _Pnode = fn_00541da0(_Fixnodeparent);
                }
                if (fn_00541d90(_Pnode))
                    _Fixnode = _Fixnodeparent;
                else if (fn_00543630(fn_0054c630(_Pnode)) == 1
                      && fn_00543630(fn_00541da0(_Pnode)) == 1)
                {
                    fn_00543630(_Pnode) = 0;
                    _Fixnode = _Fixnodeparent;
                }
                else
                {
                    if (fn_00543630(fn_00541da0(_Pnode)) == 1)
                    {
                        fn_00543630(fn_0054c630(_Pnode)) = 1;
                        fn_00543630(_Pnode) = 0;
                        fn_00544070(self, 0, _Pnode);
                        _Pnode = fn_00541da0(_Fixnodeparent);
                    }
                    fn_00543630(_Pnode) = fn_00543630(_Fixnodeparent);
                    fn_00543630(_Fixnodeparent) = 1;
                    fn_00543630(fn_00541da0(_Pnode)) = 1;
                    fn_00550900(self, 0, _Fixnodeparent);
                    break;
                }
            }
            else
            {
                _Pnode = fn_0054c630(_Fixnodeparent);
                if (fn_00543630(_Pnode) == 0)
                {
                    fn_00543630(_Pnode) = 1;
                    fn_00543630(_Fixnodeparent) = 0;
                    fn_00544070(self, 0, _Fixnodeparent);
                    _Pnode = fn_0054c630(_Fixnodeparent);
                }
                if (fn_00541d90(_Pnode))
                    _Fixnode = _Fixnodeparent;
                else if (fn_00543630(fn_00541da0(_Pnode)) == 1
                      && fn_00543630(fn_0054c630(_Pnode)) == 1)
                {
                    fn_00543630(_Pnode) = 0;
                    _Fixnode = _Fixnodeparent;
                }
                else
                {
                    if (fn_00543630(fn_0054c630(_Pnode)) == 1)
                    {
                        fn_00543630(fn_00541da0(_Pnode)) = 1;
                        fn_00543630(_Pnode) = 0;
                        fn_00550900(self, 0, _Pnode);
                        _Pnode = fn_0054c630(_Fixnodeparent);
                    }
                    fn_00543630(_Pnode) = fn_00543630(_Fixnodeparent);
                    fn_00543630(_Fixnodeparent) = 1;
                    fn_00543630(fn_0054c630(_Pnode)) = 1;
                    fn_00544070(self, 0, _Fixnodeparent);
                    break;
                }
            }
        }
        fn_00543630(_Fixnode) = 1;
    }

    fn_0054f900(&self->_Alnod, 0, _Erasednode);
    fn_00543610(&self->_Alnod, 0, _Erasednode, 1);

    if (0 < self->_Mysize)
        --self->_Mysize;

    fn_00544730(self, 0, result, _Where);
    return result;
}
