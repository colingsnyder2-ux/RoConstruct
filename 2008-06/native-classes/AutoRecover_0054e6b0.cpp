// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>

// INFERRED: std::_Tree (VC9) layout: _Myhead at +0x18, _Mysize at +0x1c
struct Local_0054e6b0
{
    char pad[0x18];
    void* _Myhead;
    unsigned int _Mysize;
};

// INFERRED: max_size()
extern "C" unsigned int __fastcall fn_0054f980(Local_0054e6b0* self, int unusedEdx);
// INFERRED: _Buynode(_Larg, _Parg, _Rarg, _Val, _Carg)
extern "C" void* __fastcall fn_0054fb80(Local_0054e6b0* self, int unusedEdx, void* larg, void* parg, void* rarg, const void* val, char carg);
// INFERRED: _Root()
extern "C" void** __fastcall fn_005423f0(Local_0054e6b0* self, int unusedEdx);
// INFERRED: _Lmost() (ICF-folded with set<int> _Lmost)
extern "C" void** __fastcall fn_005508e0(Local_0054e6b0* self, int unusedEdx);
// INFERRED: _Rmost()
extern "C" void** __fastcall fn_0054cec0(Local_0054e6b0* self, int unusedEdx);
// INFERRED: static _Left / _Right / _Parent / _Color (cdecl, caller cleans)
extern "C" void** __cdecl fn_0054c630(void* node);
extern "C" void** __cdecl fn_00541da0(void* node);
extern "C" void** __cdecl fn_0054c640(void* node);
extern "C" char* __cdecl fn_0054c5f0(void* node);
// INFERRED: _Lrotate / _Rrotate
extern "C" void __fastcall fn_0054cd10(Local_0054e6b0* self, int unusedEdx, void* node);
extern "C" void __fastcall fn_0054cee0(Local_0054e6b0* self, int unusedEdx, void* node);
// INFERRED: iterator(_Nodeptr, const _Myt*) constructor (ICF-folded)
extern "C" void* __fastcall fn_0054e320(void* it, int unusedEdx, void* node, Local_0054e6b0* tree);

// INFERRED: original vendor TU was built /Od; keep this function unoptimized
#pragma optimize("", off)

// INFERRED: std::_Tree<...>::_Insert(bool _Addleft, _Nodeptr _Wherenode, const value_type& _Val)
extern "C" void* __fastcall fn_0054e6b0(Local_0054e6b0* self, int unusedEdx, void* result,
                                       bool _Addleft, void* _Wherenode, const void* _Val)
{
    if (fn_0054f980(self, 0) - 1 <= self->_Mysize)
        throw std::length_error("map/set<T> too long");

    void* _Newnode = fn_0054fb80(self, 0, self->_Myhead, _Wherenode, self->_Myhead, _Val, 0);

    ++self->_Mysize;
    if (_Wherenode == self->_Myhead)
    {
        *fn_005423f0(self, 0) = _Newnode;
        *fn_005508e0(self, 0) = _Newnode;
        *fn_0054cec0(self, 0) = _Newnode;
    }
    else if (_Addleft)
    {
        *fn_0054c630(_Wherenode) = _Newnode;
        if (_Wherenode == *fn_005508e0(self, 0))
            *fn_005508e0(self, 0) = _Newnode;
    }
    else
    {
        *fn_00541da0(_Wherenode) = _Newnode;
        if (_Wherenode == *fn_0054cec0(self, 0))
            *fn_0054cec0(self, 0) = _Newnode;
    }

    for (void* _Pnode = _Newnode; *fn_0054c5f0(*fn_0054c640(_Pnode)) == 0; )
    {
        if (*fn_0054c640(_Pnode) == *fn_0054c630(*fn_0054c640(*fn_0054c640(_Pnode))))
        {
            _Wherenode = *fn_00541da0(*fn_0054c640(*fn_0054c640(_Pnode)));
            if (*fn_0054c5f0(_Wherenode) == 0)
            {
                *fn_0054c5f0(*fn_0054c640(_Pnode)) = 1;
                *fn_0054c5f0(_Wherenode) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(_Pnode))) = 0;
                _Pnode = *fn_0054c640(*fn_0054c640(_Pnode));
            }
            else
            {
                if (_Pnode == *fn_00541da0(*fn_0054c640(_Pnode)))
                {
                    _Pnode = *fn_0054c640(_Pnode);
                    fn_0054cd10(self, 0, _Pnode);
                }
                *fn_0054c5f0(*fn_0054c640(_Pnode)) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(_Pnode))) = 0;
                fn_0054cee0(self, 0, *fn_0054c640(*fn_0054c640(_Pnode)));
            }
        }
        else
        {
            _Wherenode = *fn_0054c630(*fn_0054c640(*fn_0054c640(_Pnode)));
            if (*fn_0054c5f0(_Wherenode) == 0)
            {
                *fn_0054c5f0(*fn_0054c640(_Pnode)) = 1;
                *fn_0054c5f0(_Wherenode) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(_Pnode))) = 0;
                _Pnode = *fn_0054c640(*fn_0054c640(_Pnode));
            }
            else
            {
                if (_Pnode == *fn_0054c630(*fn_0054c640(_Pnode)))
                {
                    _Pnode = *fn_0054c640(_Pnode);
                    fn_0054cee0(self, 0, _Pnode);
                }
                *fn_0054c5f0(*fn_0054c640(_Pnode)) = 1;
                *fn_0054c5f0(*fn_0054c640(*fn_0054c640(_Pnode))) = 0;
                fn_0054cd10(self, 0, *fn_0054c640(*fn_0054c640(_Pnode)));
            }
        }
    }

    *fn_0054c5f0(*fn_005423f0(self, 0)) = 1;
    fn_0054e320(result, 0, _Newnode, self);
    return result;
}

#pragma optimize("", on)
