// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost::shared_ptr<Instance> modelled by a local two-word struct. The real
// types come from boost and RBX headers, and the callees are the unnamed fn_ helpers.
// INFERRED: the target takes no stack args (plain ret). The prompt's 4-arg
// declaration looks like a mis-inference from the caller's stack.
struct SpInstance {
    void* px;
    void* pn;
};

extern "C" int fn_0045b2b0(void);
extern "C" void fn_00557330(void (*f)(void), long* flag);
extern "C" void fn_0045b820(void);
extern "C" void fn_0045b6d0(void);
extern "C" const void* fn_0045b160(void);
extern "C" void __fastcall fn_004124c0(void* vec, int unusedEdx, unsigned n, SpInstance* fill);
extern "C" void __fastcall fn_00572a90(void* self, int unusedEdx, SpInstance* out, const void* name);
extern "C" void __fastcall fn_004025b0(void* dstCount, int unusedEdx, void* srcCount);
extern "C" void __fastcall fn_00600660(SpInstance* sp);

extern long g_once96de94;
extern long g_once96de88;

struct ServiceProviderLike {
    char pad[0x190];
    SpInstance* begin_;  // INFERRED: vector<shared_ptr<Instance>> at +0x190, begin at +0x19c
};

extern "C" int __fastcall fn_0045dce0(void* self, int unusedEdx)
{
    char* base = (char*)self;
    fn_00557330(fn_0045b820, &g_once96de94);
    unsigned idx = (unsigned)fn_0045b2b0();
    SpInstance*& begin = *(SpInstance**)(base + 0x19c);
    SpInstance* end = *(SpInstance**)(base + 0x1a0);
    if (idx + 1 > (unsigned)(end - begin)) {
        SpInstance fill = {0, 0};
        fn_004124c0(base + 0x190, 0, idx + 1, &fill);
    } else if (begin[idx].px) {
        return (int)begin[idx].px;
    }
    fn_00557330(fn_0045b6d0, &g_once96de88);
    SpInstance found;
    fn_00572a90(self, 0, &found, fn_0045b160());
    if (!found.px) {
        fn_00600660(&found);
        return 0;
    }
    SpInstance* slot = &begin[idx];
    slot->px = found.px;
    fn_004025b0(&slot->pn, 0, &found.pn);
    void* r = found.px;
    fn_00600660(&found);
    return (int)r;
}
