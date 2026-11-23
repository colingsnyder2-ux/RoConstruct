// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// INFERRED: local stand-ins; layout from the disassembly and the server 100% analog.
struct S;

struct Ref {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release()
    {
        if (_InterlockedDecrement(&strong) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

struct RefSlot {
    Ref* value;
    RefSlot& operator=(const RefSlot&); // shared_count::operator=
};

struct Pair {
    Ref* value;
    RefSlot owner;
    ~Pair()
    {
        if (owner.value)
            owner.value->release();
    }
};

struct Entry {
    Ref* value;
    RefSlot owner;
};

struct S {
    char padding[0x19c];
    Entry* first;
    Entry* last;

    Ref* existing(); // fn_0045dce0 (thiscall)
};

// C++ linkage on purpose: extern "C" callees are nothrow under /EHsc and the
// original has an EH frame (state 0 while the shared_ptr temp lives).
Pair __cdecl create_ff();                  // Creatable<Instance>::create<ForceField>
void __cdecl setParent(Ref*, S*);          // placeholder, replaced below
namespace boost {
void call_once(void (*)(), long&);
}
extern "C" void fn_0045b820(void);
extern "C" long g_0096de94;
void* __cdecl slot_index_fn();             // fn_0045b2b0
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct RefAttach : Ref {
    void attach(S*); // Instance::setParent (thiscall)
};

extern "C" Ref* __fastcall fn_0045de20(S* self, int unusedEdx)
{
    Ref* result = self->existing();
    if (!result) {
        Pair p = create_ff();
        result = p.value;
        boost::call_once(fn_0045b820, g_0096de94);
        unsigned index = (unsigned)slot_index_fn();
        if (index >= (unsigned)(self->last - self->first))
            invalid_parameter_noinfo();
        Entry& entry = self->first[index];
        entry.value = p.value;
        entry.owner = p.owner;
        ((RefAttach*)result)->attach(self);
    }
    return result;
}
