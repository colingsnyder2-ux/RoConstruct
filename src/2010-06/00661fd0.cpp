// from server: 34% by atomic.potato
extern "C" void __stdcall func_004ab810(void*);
extern "C" void __stdcall func_004ab4b0(void*);

struct S {
    void f(void*);
};

void S::f(void* arg)
{
    char buf[8];
    func_004ab810(buf);
    void** vtbl = *(void***)arg;
    void (*fn)(void*, void*) = (void (*)(void*, void*))vtbl[1];
    fn(arg, buf);
    func_004ab4b0(buf);
}
