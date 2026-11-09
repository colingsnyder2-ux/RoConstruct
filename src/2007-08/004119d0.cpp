// from server: 100% by colin
extern "C" {
    long (__stdcall *SafeArrayDestroy)(void*);
    long (__stdcall *SafeArrayUnlock)(void*);
}

struct S {
    void* p;
    void f();
};

void S::f() {
    if (p != 0) {
        if (SafeArrayDestroy(p) >= 0) {
            if (SafeArrayUnlock(p) >= 0) {
                p = 0;
            }
        }
    }
}
