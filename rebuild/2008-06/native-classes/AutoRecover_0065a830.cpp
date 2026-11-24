// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::_Copy_backward_opt for a vector of 8-byte POD elements, with a cdecl-style signature (first, last, destEnd).
struct E { int v[2]; };

extern "C" E* fn_0065a830(E* first, E* last, E* dest)
{
    E* result = dest - (last - first);
    for (; first != last; )
        *--dest = *--last;
    return result;
}
