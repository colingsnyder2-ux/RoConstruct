// from server: 100% by auto
// from server: 100% by EspClaude
// from server: 89% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_comfactoryexception585c8dc907e34c73.cpp

// Candidate translation unit (score above; library headers required).
class CException { public: void Delete(); };
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct State {
    char reserved[52];
    long initialize();
};

struct Object {
    virtual long __stdcall query(const void*, void**);
    virtual unsigned long __stdcall addRef();
    virtual unsigned long __stdcall release();
    virtual ~Object();

    char reserved[4];
    State state;

    Object(void*);
};

long __stdcall createObject(void* context, const void* iid, void** result)
{
    if (!result)
        return (long)0x80004003UL;

    *result = 0;
    long status = (long)0x8007000EUL;
    Object* object = 0;

    try {
        object = new Object(context);
    }
    catch (CException* error) {
        error->Delete();
    }

    if (object) {
        status = object->state.initialize();
        if (status >= 0)
            status = object->query(iid, result);
        if (status != 0)
            delete object;
    }

    return status;
}
