// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0097a630[];

// INFERRED: GettingUp::~GettingUp() (00667ec0). Two polymorphic bases emit the two
// vtable stores before EH state 0, and base dtor unwind calls fn_006435c0.
extern "C" void* __fastcall fn_00793d50(void* self);
extern "C" void __cdecl fn_0056b620();
extern "C" void __cdecl fn_005e1f00();
extern "C" void __fastcall fn_006435c0(void* self);

typedef void* (__thiscall *ThisFn_0056b620)(void*, void*);
typedef void (__thiscall *ThisFn_005e1f00)(void*, char*, int);

struct LocalPrimary { virtual ~LocalPrimary() {} };
struct LocalSecondary { virtual ~LocalSecondary() {} };
struct LocalBase : LocalPrimary, LocalSecondary
{
    int value;
    virtual ~LocalBase() { fn_006435c0(this); }
};
struct LocalGettingUp : LocalBase
{
    __forceinline virtual ~LocalGettingUp()
    {
        void* p = fn_00793d50(this);
        void* key = p ? static_cast<char*>(p) + 20 : 0;
        void* found = ((ThisFn_0056b620)(void*)fn_0056b620)(g_0097a630, key);
        if (found)
        {
            char tag;
            ((ThisFn_005e1f00)(void*)fn_005e1f00)(static_cast<char*>(found) + 16, &tag, 0);
        }
    }
};

extern "C" void __fastcall fn_00667ec0(LocalGettingUp* self, int unusedEdx)
{
    self->LocalGettingUp::~LocalGettingUp();
}
