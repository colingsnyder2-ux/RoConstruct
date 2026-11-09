// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_59708ba5c5d7d149.cpp

// Candidate translation unit (score above; library headers required).

struct __RocExc { long status; __RocExc(const __RocExc&); ~__RocExc(); void Delete(); };
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern const unsigned long table0[];
extern const unsigned long table1[];
extern const unsigned long table2[];
extern const unsigned long table4[];
extern const unsigned long table6[];
extern const unsigned long table7[];

struct Module
{
    virtual void unused();
    virtual void lock();
};

extern Module* module;

struct Interface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void destroy(int);
};

struct S
{
    const unsigned long* v0;
    const unsigned long* v1;
    const unsigned long* v2;
    unsigned long field0c;
    const unsigned long* v4;
    unsigned long field14;
    const unsigned long* v6;
    const unsigned long* v7;
    long references;
    unsigned long remaining[4];

    S() throw();
    void initialize();
    long construct();
};

__forceinline S::S() throw()
{
    initialize();
    v0 = table0;
    v1 = table1;
    v2 = table2;
    v4 = table4;
    v6 = table6;
    v7 = table7;
    module->lock();
}

long func_00406da0(S** result)
{
    long status = (long)0x8007000e;
    S* object = 0;

    try
    {
        object = new S;
    }
    catch (__RocExc* __rocExc) { __rocExc->Delete(); }

    if (object != 0)
    {
        ++object->references;
        status = object->construct();
        --object->references;

        if (status != 0)
        {
            reinterpret_cast<Interface*>(&object->v4)->destroy(1);
            object = 0;
        }
    }

    *result = object;
    return status;
}
