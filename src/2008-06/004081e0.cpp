// from server: 100% by colin
// b.cpp: king's fn-pointer QI shape + MFC-style catch (isolates funclet fix).
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct CException {
    void* vfptr;
    void Delete();   // mfc90.dll!#2084 - non-virtual, direct __thiscall import call
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Subobject {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void destroy(unsigned int);
};

struct S;
struct Table {
    long (__stdcall* query)(S*, const void*, void**);
};

struct S {
    Table* table;
    unsigned long reserved[2];
    Subobject subobject;
    unsigned long reserved2[2];
    volatile long references;

    S(void*) throw();
    static long __stdcall create(void*, const void*, void**);
};

long __stdcall S::create(void* context, const void* iid, void** result)
{
    if (!result)
        return (long)0x80004003;

    S* object = 0;
    *result = 0;
    long status = (long)0x8007000e;

    try {
        object = new S(context);
    }
    catch (CException* e) {
        e->Delete();
    }

    if (object) {
        ++object->references;
        --object->references;
        status = object->table->query(object, iid, result);
        if (status != 0)
            object->subobject.destroy(1);
    }

    return status;
}
