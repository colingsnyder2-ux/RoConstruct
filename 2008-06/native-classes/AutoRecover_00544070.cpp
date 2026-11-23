// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::_Tree::_Lrotate (red-black tree left rotation) from the MSVC 2008 STL.
// INFERRED: fn_0054c630 is _Right, fn_00541da0 is _Left, fn_0054c640 is _Parent,
// INFERRED: fn_00541d90 is _Isnil, and fn_005423f0 is _Root.
// INFERRED: the disassembly pushes one stack argument for fn_0054c630 and fn_00541da0, so they
// are declared with one argument each, as static cdecl accessors. This differs from the
// 3-argument and thiscall declarations suggested in the task.

extern "C" int* fn_0054c630(int node);
extern "C" int* fn_00541da0(int node);
extern "C" char* fn_00541d90(int node);
extern "C" int* fn_0054c640(int node);
extern "C" int* __fastcall fn_005423f0(void* self, int unusedEdx);

extern "C" void __fastcall fn_00544070(void* self, int unusedEdx, int wherenode)
{
    int pnode = *fn_0054c630(wherenode);

    *fn_0054c630(wherenode) = *fn_00541da0(pnode);

    if (*fn_00541d90(*fn_00541da0(pnode)) == 0)
        *fn_0054c640(*fn_00541da0(pnode)) = wherenode;

    *fn_0054c640(pnode) = *fn_0054c640(wherenode);

    if (wherenode == *fn_005423f0(self, 0))
        *fn_005423f0(self, 0) = pnode;
    else if (wherenode == *fn_00541da0(*fn_0054c640(wherenode)))
        *fn_00541da0(*fn_0054c640(wherenode)) = pnode;
    else
        *fn_0054c630(*fn_0054c640(wherenode)) = pnode;

    *fn_00541da0(pnode) = wherenode;
    *fn_0054c640(wherenode) = pnode;
}
