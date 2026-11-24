// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: both callees pop one stack arg at the call site (add esp,4), so they are declared with one cdecl arg.
extern "C" int* fn_0054c630(int a1);
extern "C" char* fn_00542e00(int a1);

// INFERRED: node is a pointer-sized handle. fn_0054c630 returns a pointer to its next link.
extern "C" int fn_005450f0(int node)
{
    while (*fn_00542e00(*fn_0054c630(node)) == 0)
        node = *fn_0054c630(node);
    return node;
}
