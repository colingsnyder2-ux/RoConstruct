// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: every callee is declared as extern "C" fn_<addr>, following the roles in the analog.
// INFERRED: the target is a constructor-like function taking 9 dwords: name, attributes,
//           two 3-dword Triples and flags.
// INFERRED: fn_0059a820 is declared cdecl with a hidden return pointer. The disassembly
//           shows the caller cleaning up 0x1c bytes after the call and no real ecx argument.

struct Triple {
    unsigned long x, y, z;
};

extern "C" void __cdecl fn_00557330(void (__cdecl *)(), long *);   // boost::call_once
extern "C" void __cdecl fn_0059c7e0();                             // call_once init function
extern "C" void *__cdecl fn_0059c780();                            // descriptor getter
extern "C" void *__cdecl fn_0059c7f0();                            // base descriptor getter
extern "C" void __cdecl fn_006a067a(void *);                       // operator delete

// INFERRED: once_flag global used by call_once
extern "C" long g_00976644;
// INFERRED: vtable of the derived property descriptor class
extern "C" void *g_008330cc[];

struct Owner {
    void *p;
    explicit Owner(void *v) : p(v) {}
    Owner(Owner &o) : p(o.release()) {}
    ~Owner() { if (p) fn_006a067a(p); }
    void *release() { void *v = p; p = 0; return v; }
};

// INFERRED: make_property returns Owner through a hidden pointer.
extern "C" Owner __cdecl fn_0059a820(Triple, Triple);

struct S;

extern "C" void __fastcall fn_0056c650(S *self, int unusedEdx, void *baseDesc, void *value,
                                       void *name, unsigned long attributes,
                                       unsigned long flags);

struct S {
    void *vtable;
    char padding[20];
    void *descriptor;
    Owner property;
    void *classDescriptor;
};

static __forceinline void *registered_descriptor()
{
    fn_00557330(fn_0059c7e0, &g_00976644);
    return fn_0059c780();
}

extern "C" S *__fastcall fn_0059d390(S *self, int unusedEdx, void *name,
                                     unsigned long attributes,
                                     unsigned long f0, unsigned long f1, unsigned long f2,
                                     unsigned long s0, unsigned long s1, unsigned long s2,
                                     unsigned long flags)
{
    Triple first;
    first.x = f0; first.y = f1; first.z = f2;
    Triple second;
    second.x = s0; second.y = s1; second.z = s2;

    void *value = registered_descriptor();
    void *baseDescriptor = fn_0059c7f0();
    fn_0056c650(self, 0, baseDescriptor, value, name, attributes, flags);
    self->descriptor = value;
    self->vtable = reinterpret_cast<void *>(g_008330cc);
    self->property.p = fn_0059a820(first, second).release();
    self->classDescriptor = registered_descriptor();
    return self;
}
