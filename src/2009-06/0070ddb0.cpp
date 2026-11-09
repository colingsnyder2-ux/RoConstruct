// from server: 100% by why2
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);

struct S {
    void* field0;
    void f();
};

void S::f() {
    void* h = field0;
    if (SetEvent(h) == 0) {
        extern void g();
        g();
    }
}
