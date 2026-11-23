// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: self-contained minimal declarations; the real headers were not available.
// INFERRED: the function returns the cached controller service as a raw Instance*.

struct Instance;

struct SharedPtrInstance {
    Instance* px;
    void*     pn;   // shared_count (control block pointer)
};

struct InstanceVector {
    int                 pad[3];
    SharedPtrInstance*  first;   // +0x0c relative to the vector base
    SharedPtrInstance*  last;    // +0x10
};

namespace boost { void call_once(void (*func)(), long& flag); }   // 00557330 boost::call_once (boost 1.34 once_flag is a long)
extern "C" int  fn_0045b2b0(void);
extern "C" const void* fn_0045b160(void);
extern "C" void fn_0045b820(void);
extern "C" void fn_0045b6d0(void);
extern long g_96de94;
extern long g_96de88;
extern "C" void __fastcall fn_004124c0(InstanceVector* v, int unusedEdx, unsigned newSize, SharedPtrInstance fill);
extern "C" SharedPtrInstance* __fastcall fn_00572a90(void* self, int unusedEdx, SharedPtrInstance* out, const void* className);
extern "C" void __fastcall fn_004025b0(void** dst, int unusedEdx, void** const* src);
extern "C" void __fastcall fn_00600660(SharedPtrInstance* sp);
extern "C" void __cdecl _invalid_parameter_noinfo(void);

extern "C" int __fastcall fn_0045dce0(void* self, int unusedEdx)
{
    char* base = static_cast<char*>(self);
    boost::call_once(fn_0045b820, g_96de94);
    unsigned idx = static_cast<unsigned>(fn_0045b2b0());

    InstanceVector* vec = reinterpret_cast<InstanceVector*>(base + 0x190);
    unsigned size = static_cast<unsigned>(
        (reinterpret_cast<char*>(*reinterpret_cast<SharedPtrInstance**>(base + 0x1a0)) -
         reinterpret_cast<char*>(*reinterpret_cast<SharedPtrInstance**>(base + 0x19c))) >> 3);

    if (idx + 1 > size) {
        SharedPtrInstance fill = { 0, 0 };
        fn_004124c0(vec, 0, idx + 1, fill);
    } else {
        unsigned sz = static_cast<unsigned>(vec->last - vec->first);
        if (idx >= sz)
            _invalid_parameter_noinfo();
        if (vec->first[idx].px)
            return reinterpret_cast<int>(vec->first[idx].px);
    }

    boost::call_once(fn_0045b6d0, g_96de88);
    SharedPtrInstance svc;
    fn_00572a90(self, 0, &svc, fn_0045b160());

    Instance* p = svc.px;
    if (!p) {
        fn_00600660(&svc);
        return 0;
    }

    unsigned sz = static_cast<unsigned>(vec->last - vec->first);
    if (idx >= sz)
        _invalid_parameter_noinfo();
    SharedPtrInstance* slot = &vec->first[idx];
    slot->px = p;
    // shared_count assignment
    fn_004025b0(&slot->pn, 0, reinterpret_cast<void** const*>(&svc.pn));
    fn_00600660(&svc);
    return reinterpret_cast<int>(p);
}
