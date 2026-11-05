// from server: 37% by atomic.potato
extern "C" {
    int __stdcall sub_5cc3f0(int);
    void __stdcall sub_4093b0(void*, const char*);
    void __stdcall sub_7a89b2(void*, void*);
    void* __stdcall sub_9ea410(const char*);
}

struct S {
    void f();
};

void S::f()
{
    if (sub_5cc3f0(0) == 0) {
        char buf[32];
        sub_9ea410("The service is not installed");
        sub_4093b0(buf, "The service is not installed");
        sub_7a89b2(buf, (void*)0xb03074);
    }
}
