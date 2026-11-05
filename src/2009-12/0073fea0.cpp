// from server: 37% by atomic.potato
extern "C" {
    int __stdcall sub_665740(int);
    void* __stdcall sub_98b6f4(const char*);
    void __stdcall sub_409390(void*, const char*);
    void __stdcall sub_7f4878(void*, void*);
}

struct S {
    void f();
};

void S::f() {
    if (sub_665740(0) == 0) {
        char buf[32];
        sub_98b6f4("The service is not installed");
        sub_409390(buf, "L$Dd");
        sub_7f4878(buf, (void*)0xa904f0);
    }
}
