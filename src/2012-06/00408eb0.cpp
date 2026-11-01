// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_51cfa5c43423c602.cpp

// Candidate translation unit (score above; library headers required).

struct Exception {
    long status;
    Exception(const Exception&);
    ~Exception(); void Delete();
};

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct S
{
    S(void*);
    virtual long __stdcall QueryInterface(const void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual ~S();

    unsigned char data[32];

    static long __stdcall CreateInstance(void*, const void*, void**);
};

long __stdcall S::CreateInstance(void* outer, const void* iid, void** result)
{
    if (!result)
        return (long)0x80004003;

    *result = 0;
    long status = (long)0x8007000E;
    S* object = 0;

    try
    {
        object = new S(outer);
    }
    catch (Exception* exception) { exception->Delete(); }

    if (object)
    {
        status = object->QueryInterface(iid, result);
        if (status != 0)
            delete object;
    }

    return status;
}
