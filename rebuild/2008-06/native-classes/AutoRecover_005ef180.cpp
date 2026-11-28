// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Fn005ef180Holder
{
    virtual void __thiscall destroy(unsigned int);
};

// INFERRED: init routine passed to boost::call_once and its once-flag global
extern "C" void fn_005ed690(void);
extern "C" long g_0097b120;
extern "C" void __cdecl fn_00557330(void (*)(void), long&);
extern "C" int* __cdecl fn_005ed630();
extern "C" int fn_006a0920(int a1);
// INFERRED: vtable at 0x83fcf4
extern int g_0083fcf4[];

struct Fn005ef180Slot
{
    int* value;
    void assign(int*& source);
};

struct Fn005ef180Obj
{
    int* field0;
    Fn005ef180Slot field4;
};

__forceinline void Fn005ef180Slot::assign(int*& source)
{
    int* mem = (int*)fn_006a0920(8);
    if (mem)
    {
        mem[0] = (int)g_0083fcf4;
        mem[1] = *source;
    }
    else
    {
        mem = 0;
    }

    int* old = mem;
    if (&source != &value)
    {
        old = value;
        value = mem;
    }

    if (old)
        ((Fn005ef180Holder*)old)->destroy(1);
}

extern "C" Fn005ef180Obj* __fastcall fn_005ef180(Fn005ef180Obj* self, int unusedEdx, int* p)
{
    // INFERRED: constructor body
    fn_00557330(fn_005ed690, g_0097b120);
    self->field0 = fn_005ed630();
    self->field4.assign(p);
    return self;
}
