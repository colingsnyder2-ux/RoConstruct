// from server: 100% by colin
// v5: reference catch; body calls a non-virtual member.
void* __cdecl operator new(unsigned int);

struct Exception {
    long code;
    void Delete();
};

struct S {
    virtual long __stdcall QueryInterface(const void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void Reserved();
    virtual ~S();

    unsigned char padding[20];
    volatile long references;
    unsigned long tail;

    S(void*) throw();

    static long __stdcall CreateInstance(void*, const void*, void**);
};

long __stdcall S::CreateInstance(void* outer, const void* iid, void** result)
{
    if (!result)
        return (long)0x80004003;

    S* object = 0;
    *result = 0;
    long status = (long)0x8007000E;

try {
        object = new S(outer);
    }
    catch (Exception& exception) {
        exception.Delete();
    }

    if (object) {
        ++object->references;
        --object->references;
        status = object->QueryInterface(iid, result);
        if (status != 0)
            delete object;
    }

    return status;
}
