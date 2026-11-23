// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::_Tree<...>::equal_range(const key_type&), the MSVC 2008 form,
// returning pair<iterator, iterator> through a hidden return pointer (arg 1).
// The names of the callees are guesses from how they are used.

// _Root(): ecx = tree, returns pointer to the node pointer (head->_Parent)
extern "C" int* __fastcall fn_005423f0(void* self, int unusedEdx);
// _Isnil(node), _Key(node), _Right(node), _Left(node): plain cdecl, one argument
extern "C" char* __cdecl fn_00541d90(int node);
extern "C" int   __cdecl fn_0054c610(int node);
extern "C" int*  __cdecl fn_00541da0(int node);
extern "C" int*  __cdecl fn_0054c630(int node);
// comparator at this+8: bool compare(a, b), thiscall with two stack args
extern "C" unsigned char __fastcall fn_005424e0(void* self, int unusedEdx, int a, int b);
// iterator(node, container)
extern "C" void __fastcall fn_0054e320(void* self, int unusedEdx, int node, int container);
// pair(const iterator&, const iterator&)
extern "C" void __fastcall fn_005459d0(void* self, int unusedEdx, void* first, void* second);

extern "C" void* __fastcall fn_00543e50(void* self, int unusedEdx, void* retPair, int keyval)
{
    char* tree = (char*)self;
    int pnode = *fn_005423f0(self, 0);
    int lbound = *(int*)(tree + 0x18);
    int ubound = *(int*)(tree + 0x18);

    while (*fn_00541d90(pnode) == 0)
    {
        if (fn_005424e0(tree + 8, 0, fn_0054c610(pnode), keyval))
        {
            pnode = *fn_00541da0(pnode);
        }
        else
        {
            if (*fn_00541d90(ubound) != 0)
            {
                if (fn_005424e0(tree + 8, 0, keyval, fn_0054c610(pnode)))
                    ubound = pnode;
            }
            lbound = pnode;
            pnode = *fn_0054c630(pnode);
        }
    }

    if (*fn_00541d90(ubound) != 0)
        pnode = *fn_005423f0(self, 0);
    else
        pnode = *fn_0054c630(ubound);

    while (*fn_00541d90(pnode) == 0)
    {
        if (fn_005424e0(tree + 8, 0, keyval, fn_0054c610(pnode)))
        {
            ubound = pnode;
            pnode = *fn_0054c630(pnode);
        }
        else
        {
            pnode = *fn_00541da0(pnode);
        }
    }

    int itLower[2];
    int itUpper[2];
    fn_0054e320(itLower, 0, lbound, (int)self);
    fn_0054e320(itUpper, 0, ubound, (int)self);
    fn_005459d0(retPair, 0, itLower, itUpper);
    return retPair;
}
