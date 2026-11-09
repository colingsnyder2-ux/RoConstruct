// from server: 100% by auto
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared roc_espeon_workspacecomfactoryfix_556dab054c034434.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <afxwin.h>
#include <intrin.h>
typedef long HRESULT;

void* __cdecl operator new(unsigned int);


struct Stream {
    char storage[0x88];
    __declspec(dllimport) Stream(int, int) throw();
};

struct Service {
    virtual void unused() = 0;
    virtual void notify() = 0;
};

extern Service* service;
extern void* primaryTable[];
extern void* secondaryTable[];

struct AtlException {
    HRESULT result;
};

struct Object {
    void** primary;
    void** secondary;
    long references;
    Stream stream;

    Object() throw() : references(0), stream(3, 1)
    {
        primary = primaryTable;
        secondary = secondaryTable;
        service->notify();
    }

    static HRESULT __stdcall CreateInstance(Object** output);
};

HRESULT __stdcall Object::CreateInstance(Object** output)
{
    if (!output)
        return (HRESULT)0x80004003L;

    *output = 0;
    HRESULT result = (HRESULT)0x8007000EL;
    Object* object = 0;

    try {
        object = new Object();
    }
    catch (CException* exception) {exception->Delete();}

    if (object != 0) {
        _ReadWriteBarrier();
        ++object->references;
        _ReadWriteBarrier();
        result = 0;
        --object->references;
    }

    *output = object;
    return result;
}
