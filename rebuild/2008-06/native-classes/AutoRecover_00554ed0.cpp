// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object type unknown; offsets taken from the disassembly.
struct xtime_t { long long sec; int nsec; };

struct mutex_t;
struct scoped_lock_t;

extern "C" double fn_005f2000(void);                                              // RBX::getRealTime
extern "C" int fn_005a6b40(xtime_t* xt, int type);                                // boost::xtime_get
extern "C" void __fastcall fn_00594ce0(mutex_t* m, int unusedEdx);                // mutex::do_lock
extern "C" void __fastcall fn_00594d00(mutex_t* m, int unusedEdx);                // mutex::do_unlock
extern "C" bool __fastcall fn_00554c30(void* cond, int unusedEdx, scoped_lock_t* lk, xtime_t* xt); // condition::timed_wait

// INFERRED: boost scoped_lock layout (mutex*, locked flag)
struct scoped_lock_t {
    mutex_t* m;
    bool locked;
    explicit scoped_lock_t(mutex_t* mm) : m(mm), locked(false) {
        fn_00594ce0(m, 0);
        locked = true;
    }
    ~scoped_lock_t() {
        fn_00594d00(m, 0);
    }
};

extern "C" bool __fastcall fn_00554ed0(char* self, int unusedEdx)
{
    double start = fn_005f2000();
    xtime_t xt;
    fn_005a6b40(&xt, 1);
    xt.sec += 1;

    bool result = false;
    {
        scoped_lock_t lock((mutex_t*)(self + 0x240));
        if (*(int*)(self + 0x2a8) == 0 ||
            fn_00554c30(self + 0x24c, 0, &lock, &xt))
            result = true;
        *(double*)(self + 0x1d0) = fn_005f2000() - start;
    }
    return result;
}
