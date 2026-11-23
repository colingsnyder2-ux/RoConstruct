// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: fn_00541da0 takes one argument and returns a pointer to a node slot
// (the disassembly pushes only one argument, although the supplied prototype lists two).
extern "C" int* fn_00541da0(int a1);

// INFERRED: ecx holds the same value that is pushed as the stack argument, and the
// return value is a char* that is dereferenced.
extern "C" int fn_00541d90(int value);

// INFERRED: argument and return types are plain ints (node handles/pointers).
extern "C" int fn_005454d0(int p)
{
    for (;;)
    {
        int v = *fn_00541da0(p);
        char* c = fn_00541d90((void*)v, 0, v);
        if (*c != 0)
            return p;
        p = *fn_00541da0(p);
    }
}
