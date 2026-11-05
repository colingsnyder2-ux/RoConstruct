// from server: 100% by colin
// roc-flags: /O2 /GS /MD
typedef void (__thiscall *CopyFunction)(void *, const void *);
typedef void (__thiscall *Destructor)(void *);
extern "C" void __stdcall array_unwind(void *, unsigned int, int, Destructor);
#pragma optimize("s", on)
extern "C" void __stdcall vector_copy_constructor(void *ptr, const void *src, unsigned int size, int count, CopyFunction copy, Destructor destructor)
{
    int success = 0;
    int i;
    __try {
        for (i = 0; i < count; ++i) {
            copy(ptr, src);
            ptr = (char *)ptr + size;
            src = (const char *)src + size;
        }
        success = 1;
    }
    __finally {
        if (!success)
            array_unwind(ptr, size, i, destructor);
    }
}
