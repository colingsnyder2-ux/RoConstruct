// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void fn_004e63a0(void* in, void* out, int op);

// INFERRED: 0x941678 is a static table/vtable in the exe; unknown global, declared by name.
extern "C" char g_00941678[];

// INFERRED: a1 passed through, a2 is an out slot receiving the table pointer for kind 3,
// the 4th arg is a3 with its low byte cleared (ecx at the call is that same value).
extern "C" int fn_004e70c0(int a1, void** a2, int a3)
{
    if (a3 == 3) {
        *a2 = g_00941678;
        return a3;
    }
    int masked = a3;
    *(unsigned char*)&masked = 0;
    return fn_004e63a0((void*)masked, 0, a1, (int)a2, a3, masked);
}
