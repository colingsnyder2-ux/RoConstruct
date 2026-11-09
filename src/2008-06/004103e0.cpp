// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_e4aa987a146d5d48.cpp

// Candidate translation unit (score above; library headers required).

struct __RocException { long status; __RocException(const __RocException&); ~__RocException(); void Delete(); };
typedef long HRESULT;

struct Object;

struct ObjectTable {
    HRESULT (__stdcall *query)(Object *, const void *, void **);
    void *reserved[2];
    void *(__thiscall *destroy)(Object *, unsigned int);
};

struct Object {
    ObjectTable *table;
    unsigned char storage[36];
    Object(void *);
};

extern "C" HRESULT __stdcall CreateObject(void *, const void *, void **);

HRESULT __stdcall CreateObject(void *context, const void *iid, void **result)
{
    if (!result)
        return (HRESULT)0x80004003L;

    *result = 0;
    HRESULT status = (HRESULT)0x8007000EL;
    Object *object = 0;

    try {
        object = new Object(context);
    }
    catch (__RocException* __rocException) { __rocException->Delete(); }

    if (object) {
        status = object->table->query(object, iid, result);
        if (status != 0)
            object->table->destroy(object, 1);
    }

    return status;
}
