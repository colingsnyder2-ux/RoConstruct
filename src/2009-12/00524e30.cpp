// from server: 25% by atomic.potato
struct S_func_00422b70 {
    void* f();
};

struct S {
    char pad0[4];
    void* field4;
    void run();
};

void S::run()
{
    S_func_00422b70 local;
    local.f();
    char b = 0;
    char c = b;
    void* p = this->field4;
    void (*fn)() = *(void (**)())this;
    fn();
}
