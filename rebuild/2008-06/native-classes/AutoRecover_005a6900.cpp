// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void __fastcall fn_005f1dd0(SemaphoreGuard* self, int unusedEdx);
extern "C" void __fastcall fn_00594d40(ScopedLockHolder* self, int unusedEdx);
extern "C" int __fastcall fn_005f1df0(void* self, int unusedEdx);
extern "C" void __fastcall fn_00594ce0(void* self, int unusedEdx);
extern "C" void __fastcall fn_00594d00(void* self, int unusedEdx);
extern "C" void __fastcall fn_00594d20(void* self, int unusedEdx, void** state);

// INFERRED: boost 1.3x scoped_lock + condition wait loop; flag at +0x24, condition at +8
struct ScopedLockInferred {
    void* m;
    bool locked;
    explicit ScopedLockInferred(void* mx) : m(mx), locked(false) {
        fn_00594ce0(m, 0);
        locked = true;
    }
    ~ScopedLockInferred() {
        if (locked) fn_00594d00(m, 0);
    }
};

extern "C" void __fastcall fn_005a6900(char* self, int unusedEdx) {
    ScopedLockInferred lock(self);
    while (!self[0x24]) {
        fn_005f1dd0(self + 8, 0, 0);
        fn_00594d40(self, 0, (int)&lock.m, 0);
        fn_005f1df0(self + 8, 0);
        fn_00594d20(self, 0, &lock.m);
    }
}
