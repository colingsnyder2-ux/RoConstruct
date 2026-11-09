// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_d0c15fde0d7c35b7.cpp

// Candidate translation unit (score above; library headers required).

struct __RocException { long status; __RocException(const __RocException&); ~__RocException(); void Delete(); };

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S;

struct VTable
{
    long (__stdcall *query)(S*, const void*, void**);
    void* reserved[2];
    void* (__thiscall *destroy)(S*, unsigned int);
};

struct S
{
    VTable* vtable;
    char storage[152];

    S(void*);
};

long __stdcall sub_00416d20(void* outer, const void* iid, void** result)
{
    if (!result)
        return (long)0x80004003;

    *result = 0;
    S* object = 0;
    long status = (long)0x8007000e;

    try
    {
        object = new S(outer);
    }
    catch (__RocException* __rocException) { __rocException->Delete(); }

    if (object)
    {
        status = object->vtable->query(object, iid, result);
        if (status != 0)
            object->vtable->destroy(object, 1);
    }

    return status;
}
