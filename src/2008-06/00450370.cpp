// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_25136762e631126d.cpp

// Candidate translation unit (score above; library headers required).

struct __RocException { long status; __RocException(const __RocException&); ~__RocException(); void Delete(); };

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Interface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void destroy(unsigned int);
};

struct Object
{
    unsigned char padding0[16];
    Interface interfacePart;
    unsigned char padding1[12];
    long references;
    unsigned char padding2[16];

    Object(int) throw();
    long initialize();
};

long __stdcall func_00450370(Object** result)
{
    if (!result)
        return (long)0x80004003;

    *result = 0;
    long status = (long)0x8007000e;
    Object* object = 0;

    try
    {
        object = new Object(0);
    }
    catch (__RocException* __rocException) { __rocException->Delete(); }

    if (object)
    {
        ++object->references;
        status = object->initialize();
        if (status >= 0)
            status = 0;
        --object->references;

        if (status != 0)
        {
            object->interfacePart.destroy(1);
            object = 0;
        }
    }

    *result = object;
    return status;
}
