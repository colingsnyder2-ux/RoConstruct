// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_8d97a33f1600ac0a.cpp

// Candidate translation unit (score above; library headers required).

struct __RocException { long status; __RocException(const __RocException&); ~__RocException(); void Delete(); };
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Object {
    virtual long __stdcall QueryInterface(const void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual ~Object();

    unsigned char storage[64];

    Object(void*);
};

struct Creator {
    static long __stdcall Create(void*, const void*, void**);
};

long __stdcall Creator::Create(void* context, const void* iid, void** result)
{
    if (result == 0)
        return (long)0x80004003;

    *result = 0;
    long status = (long)0x8007000e;
    Object* object = 0;

    try {
        object = new Object(context);
    }
    catch (__RocException* __rocException) { __rocException->Delete(); }

    if (object != 0) {
        status = object->QueryInterface(iid, result);
        if (status != 0)
            delete object;
    }

    return status;
}
