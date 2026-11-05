// from server: 66% by colin
// roc-cl: 21022
// roc-flags: /O1 /GS- /EHsc /MD
extern "C" unsigned long (__stdcall *GetLastError)();
extern "C" void (__stdcall *SetLastError)(unsigned long);
extern "C" void __stdcall Cleanup(int, void *);

void __fastcall cleanup_fragment(int state, int status, void *resource)
{
    if (state != 2)
    {
        int preserveError = (status == 0);
        unsigned long error;

        if (preserveError)
            error = GetLastError();
        else
            error = 0;

        Cleanup(0, resource);

        if (preserveError)
            SetLastError(error);
    }
}
