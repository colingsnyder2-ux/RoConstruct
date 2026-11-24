// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>

// INFERRED: std::_Tree<...> layout (Dinkumware VC9): _Myhead at +0x18, _Mysize at +0x1c
struct RocTree
{
    char pad[0x18];
    void* _Myhead;
    unsigned int _Mysize;
};

typedef void* NodePtr;

// INFERRED: max_size()
extern "C" unsigned int __fastcall fn_00543650(RocTree* self, int unusedEdx);
// INFERRED: _Buynode(_Larg, _Parg, _Rarg, _Val, _Carg)
extern "C" NodePtr __fastcall fn_00550a30(RocTree* self, int unusedEdx, NodePtr larg, NodePtr parg, NodePtr rarg, const void* val, char carg);
// INFERRED: _Root()
extern "C" NodePtr* __fastcall fn_005423f0(RocTree* self, int unusedEdx);
// INFERRED: _Lmost()
extern "C" NodePtr* __fastcall fn_005508e0(RocTree* self, int unusedEdx);
// INFERRED: _Rmost()
extern "C" NodePtr* __fastcall fn_0054cec0(RocTree* self, int unusedEdx);
// INFERRED: _Lrotate(_Wherenode)
extern "C" void __fastcall fn_00550900(RocTree* self, int unusedEdx, NodePtr wherenode);
// INFERRED: _Rrotate(_Wherenode)
extern "C" void __fastcall fn_00544070(RocTree* self, int unusedEdx, NodePtr wherenode);
// INFERRED: const_iterator(_Nodeptr, const _Tree*) constructor (folded COMDAT)
extern "C" void* __fastcall fn_0054e320(void* self, int unusedEdx, NodePtr node, RocTree* tree);

// INFERRED: static node accessors (cdecl)
extern "C" NodePtr* __cdecl fn_0054c630(NodePtr p); // _Left
extern "C" NodePtr* __cdecl fn_0054c640(NodePtr p); // _Parent
extern "C" NodePtr* __cdecl fn_00541da0(NodePtr p); // _Right
extern "C" char*    __cdecl fn_00543630(NodePtr p); // _Color

// std::_Tree::_Insert(bool _Addleft, _Nodeptr _Wherenode, const value_type& _Val)
extern "C" void* __fastcall fn_0054f3f0(RocTree* self, int unusedEdx, void* result, bool addleft, NodePtr wherenode, const void* val)
{
    if (fn_00543650(self, 0) - 1 <= self->_Mysize)
        throw std::length_error("map/set<T> too long");

    NodePtr newnode = fn_00550a30(self, 0, self->_Myhead, wherenode, self->_Myhead, val, 0);

    ++self->_Mysize;
    if (wherenode == self->_Myhead)
    {
        *fn_005423f0(self, 0) = newnode;
        *fn_005508e0(self, 0) = newnode;
        *fn_0054cec0(self, 0) = newnode;
    }
    else if (addleft)
    {
        *fn_0054c630(wherenode) = newnode;
        if (wherenode == *fn_005508e0(self, 0))
            *fn_005508e0(self, 0) = newnode;
    }
    else
    {
        *fn_00541da0(wherenode) = newnode;
        if (wherenode == *fn_0054cec0(self, 0))
            *fn_0054cec0(self, 0) = newnode;
    }

    for (NodePtr pnode = newnode; *fn_00543630(*fn_0054c640(pnode)) == 0; )
    {
        if (*fn_0054c640(pnode) == *fn_0054c630(*fn_0054c640(*fn_0054c640(pnode))))
        {
            wherenode = *fn_00541da0(*fn_0054c640(*fn_0054c640(pnode)));
            if (*fn_00543630(wherenode) == 0)
            {
                *fn_00543630(*fn_0054c640(pnode)) = 1;
                *fn_00543630(wherenode) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(pnode))) = 0;
                pnode = *fn_0054c640(*fn_0054c640(pnode));
            }
            else
            {
                if (pnode == *fn_00541da0(*fn_0054c640(pnode)))
                {
                    pnode = *fn_0054c640(pnode);
                    fn_00550900(self, 0, pnode);
                }
                *fn_00543630(*fn_0054c640(pnode)) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(pnode))) = 0;
                fn_00544070(self, 0, *fn_0054c640(*fn_0054c640(pnode)));
            }
        }
        else
        {
            wherenode = *fn_0054c630(*fn_0054c640(*fn_0054c640(pnode)));
            if (*fn_00543630(wherenode) == 0)
            {
                *fn_00543630(*fn_0054c640(pnode)) = 1;
                *fn_00543630(wherenode) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(pnode))) = 0;
                pnode = *fn_0054c640(*fn_0054c640(pnode));
            }
            else
            {
                if (pnode == *fn_0054c630(*fn_0054c640(pnode)))
                {
                    pnode = *fn_0054c640(pnode);
                    fn_00544070(self, 0, pnode);
                }
                *fn_00543630(*fn_0054c640(pnode)) = 1;
                *fn_00543630(*fn_0054c640(*fn_0054c640(pnode))) = 0;
                fn_00550900(self, 0, *fn_0054c640(*fn_0054c640(pnode)));
            }
        }
    }

    *fn_00543630(*fn_005423f0(self, 0)) = 1;
    fn_0054e320(result, 0, newnode, self);
    return result;
}
