// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: returns arg + 4 (pointer to a sub-object at offset 4); target is unnamed so fixed fn_ name is used.
extern "C" char* fn_0054c640(char* self)
{
    return self + 4;
}
