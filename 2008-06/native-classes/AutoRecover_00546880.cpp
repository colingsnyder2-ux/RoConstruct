// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callee is std::_Iterator_base_aux::_Same_container (thiscall, 1 stack arg, bool return);
// declared with the fn_ convention. The element pointer is passed as "this" and the third
// argument is passed as the single stack argument.
extern "C" bool __fastcall fn_004d71d0(void* self, int unusedEdx, int arg);

// INFERRED: a find-if style loop over 4-byte elements; returns the first element for which the
// callee returns true, or `last`.
extern "C" int* fn_00546880(int* first, int* last, int val)
{
    while (first != last)
    {
        if (fn_004d71d0(first, 0, val))
            break;
        ++first;
    }
    return first;
}
