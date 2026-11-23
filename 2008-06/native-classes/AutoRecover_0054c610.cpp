// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes only one argument to fn_00543640, so it is declared
// with one parameter here instead of the two in the supplied declaration.
extern "C" int fn_00543640(int a1);
extern "C" int fn_0054c630(int a1);

extern "C" int fn_0054c610(int a1)
{
    return fn_0054c630(fn_00543640(a1));
}
