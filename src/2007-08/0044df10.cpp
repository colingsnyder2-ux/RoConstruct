// from server: 100% by EspClaude
// from server: 78% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: openrbx-client-dll roc_claude_2d98e6e4e1cc2117.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>


#include <intrin.h>

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" __declspec(dllimport) void __stdcall SysFreeString(wchar_t*);

struct Object;
typedef boost::shared_ptr<Object> Shared;

struct Owner;

struct OwnerTable
{
    void* slots[7];
    long (__stdcall *invoke)(Owner*, wchar_t*);
};

struct Owner
{
    virtual void __stdcall s0();
    virtual void __stdcall s1();
    virtual void __stdcall s2();
    virtual void __stdcall s3();
    virtual void __stdcall s4();
    virtual void __stdcall s5();
    virtual void __stdcall s6();
    virtual long __stdcall invoke(wchar_t*);
    Shared get();
};

extern bool __cdecl checkFirst(Object*, int);
extern bool __cdecl checkSecond(Object*, int);

extern wchar_t* __cdecl A2WBSTR(const char*, int);
__declspec(noreturn) void __stdcall AtlThrowImpl(long);

struct String
{
    wchar_t* value;

    String(const char* p)
    {
        if (p != 0)
        {
            value = A2WBSTR(p, -1);
            if (value == 0)
                AtlThrowImpl(0x8007000e);
        }
        else
            value = 0;
    }
    ~String();
};

inline String::~String()
{
    SysFreeString(value);
}

struct CRobloxDoc;

inline bool allowed(const Shared& state)
{
    Object* object = state.get();
    if (checkFirst(object, 1) && !checkSecond(object, 1))
        return false;
    return true;
}

inline long invokeOwner(Owner* o, wchar_t* v)
{
    return o->invoke(v);
}

struct DocumentTable
{
    void* slots[25];
    void (__thiscall *notify)(CRobloxDoc*, int);
};

struct CRobloxDoc
{
    DocumentTable* table;
    char padding[0x74];
    Owner* owner;

    int func_0044f9b0(const char*);
};

int CRobloxDoc::func_0044f9b0(const char* text)
{
    if (!allowed(owner->get()))
        return 0;

    bool failed =
        invokeOwner(owner, String(text).value) != 0;

    if (failed)
        return 0;

    table->notify(this, 0);
    return 1;
}
