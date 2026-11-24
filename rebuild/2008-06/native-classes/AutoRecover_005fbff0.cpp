// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" long _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

// INFERRED: minimal local boost::shared_ptr layout; real headers not shown.
struct CountBase {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};

struct SharedCount {
    CountBase* pi;
    SharedCount() : pi(0) {}
    ~SharedCount() {
        if (pi)
            pi->release();
    }
};

struct SharedPartPtr {
    void* px;
    SharedCount pn;
};

struct PartInstance;
struct PartHolder {
    char pad0[0x1a0];
    void* part;
    SharedCount partCount;
};
struct PartArg {
    char pad0[0x148];
    PartInstance* part;
};

// INFERRED: callees may throw, so the temp gets an EH frame (extern "C" is nothrow under /EHsc otherwise).
extern "C" SharedPartPtr* fn_00618a40(SharedPartPtr* ret, PartInstance* p) throw(...);
extern "C" SharedCount* __fastcall fn_004025b0(SharedCount* self, int unusedEdx, SharedCount* other) throw(...);

extern "C" void __fastcall fn_005fbff0(PartHolder* self, int unusedEdx, PartArg* arg)
{
    SharedPartPtr tmp;
    SharedPartPtr* r = fn_00618a40(&tmp, arg->part);
    self->part = r->px;
    fn_004025b0(&self->partCount, 0, &r->pn);
}
