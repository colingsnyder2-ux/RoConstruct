// from server: 100% by colin
extern "C" void (__stdcall *ReleaseMutex)(void*);
extern "C" void (__stdcall *LeaveCriticalSection)(void*);

struct S {
    void* field0;
    char field4;
    void f();
};

void S::f() {
    if (field4 != 0) {
        ReleaseMutex(field0);
    } else {
        LeaveCriticalSection(field0);
    }
}
