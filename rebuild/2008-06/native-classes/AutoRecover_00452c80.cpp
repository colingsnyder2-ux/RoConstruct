// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: self-contained layout; ServiceProvider service vector at +0x190 (checked-iterator build).
struct RunService;
struct Name;

struct SharedCount { int* pi; };

struct SharedInstance {
    void* px;
    SharedCount pn;
    ~SharedInstance();
};

struct ServiceVector {
    int proxy[3];
    SharedInstance* first;
    SharedInstance* last;
};

struct ServiceProvider {
    char pad[0x190];
    ServiceVector services;
};

extern "C" void __cdecl fn_00557330(void (*once)(void), long* flag);
extern "C" unsigned __cdecl fn_0044f3c0(void);
extern "C" void __cdecl fn_00450860(void);
extern "C" void __cdecl fn_004029f0(void);
extern "C" const Name* __cdecl fn_00401a00(void);
extern "C" void __fastcall fn_004124c0(ServiceVector* v, int unusedEdx, unsigned n, SharedInstance val);
extern "C" SharedInstance* __fastcall fn_00572a90(ServiceProvider* self, int unusedEdx, SharedInstance* ret, const Name* name);
extern "C" void __fastcall fn_004025b0(SharedCount* dst, int unusedEdx, const SharedCount* src);

extern long g_flag_96dd70;
extern long g_flag_96c2b0;

extern "C" void* __fastcall fn_00452c80(ServiceProvider* self, int unusedEdx)
{
    fn_00557330(fn_00450860, &g_flag_96dd70);
    unsigned index = fn_0044f3c0();
    ServiceVector& v = self->services;

    if (index + 1 > (unsigned)(v.last - v.first)) {
        SharedInstance empty = { 0, { 0 } };
        fn_004124c0(&v, 0, index + 1, empty);
    } else if (v.first[index].px) {
        return v.first[index].px;
    }

    fn_00557330(fn_004029f0, &g_flag_96c2b0);
    SharedInstance found;
    fn_00572a90(self, 0, &found, fn_00401a00());
    if (!found.px)
        return 0;

    void* p = found.px;
    SharedInstance& slot = v.first[index];
    slot.px = found.px;
    fn_004025b0(&slot.pn, 0, &found.pn);
    return p;
}
