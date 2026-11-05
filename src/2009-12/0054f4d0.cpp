// from server: 55% by atomic.potato
struct S {
    char pad[8];
    S* f(char* a, char* b);
};

extern "C" void __stdcall sub_54f2f0(char* out, char* in);
extern "C" void* __stdcall sub_98b6f4(char* in);

S* S::f(char* a, char* b) {
    char buf[8];
    *(int*)buf = 0;
    sub_54f2f0(buf, a);
    sub_98b6f4(buf);
    return this;
}
