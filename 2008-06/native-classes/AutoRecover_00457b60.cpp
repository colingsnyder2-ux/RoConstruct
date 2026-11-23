// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a cached "find service" accessor (ServiceProvider::find<Stats>-like).
// The original headers were not available, so the types below are file-local reconstructions.

struct Instance;

struct SPtr {
    Instance* px;
    void*     pn;
    SPtr() : px(0), pn(0) {}
    ~SPtr();
};

extern "C" {
    void  fn_00456400(void);
    void  fn_004563f0(void);
    extern long g_once_0096dd9c;
    extern long g_once_0096dd98;
    void  __cdecl fn_00557330(void (*fn)(void), long& flag);   // boost::call_once
    int   fn_00455ea0(void);                                    // service index
    const void* fn_00455dc0(void);                              // Name::doDeclare<Stats::sStats>
    void  __fastcall fn_00572a90(void* self, int unusedEdx, SPtr* out, const void* name); // findServiceByClassName
    void  __fastcall fn_004124c0(void* vec, int unusedEdx, unsigned n, SPtr fill);         // vector::resize
    void  __fastcall fn_004025b0(void* dst, int unusedEdx, void* src);                     // shared_count::operator=
    void  __fastcall fn_00600660(void* sp);                                                // ~shared_ptr
}

inline SPtr::~SPtr() { fn_00600660(this); }

// INFERRED: vector<shared_ptr<Instance>> with MSVC9 layout (12 bytes of header before begin/end)
struct ServiceVec {
    char  hdr[0xc];
    SPtr* first;
    SPtr* last;
};

struct ServiceProviderLike {
    char       pad[0x190];
    ServiceVec services;
};

extern "C" void* __fastcall fn_00457b60(void* self, int unusedEdx)
{
    ServiceProviderLike* sp = (ServiceProviderLike*)self;

    fn_00557330(fn_00456400, g_once_0096dd9c);
    unsigned idx = (unsigned)fn_00455ea0();

    ServiceVec* v = &sp->services;
    unsigned size = (unsigned)(v->last - v->first);

    if (idx + 1 > size) {
        SPtr fill;
        fn_004124c0(v, 0, idx + 1, fill);
    } else {
        Instance* cached = v->first[idx].px;
        if (cached)
            return cached;
    }

    fn_00557330(fn_004563f0, g_once_0096dd98);
    SPtr found;
    fn_00572a90(self, 0, &found, fn_00455dc0());

    if (!found.px)
        return 0;

    Instance* result = found.px;
    SPtr* slot = &v->first[idx];
    slot->px = found.px;
    fn_004025b0(&slot->pn, 0, &found.pn);
    return result;
}
