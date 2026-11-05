// from server: 72% by atomic.potato
extern "C" void __stdcall sub_a404c8(void*, void*, void*);

struct S_func_005ff660 {
    char pad[136];
    void* f(void* arg);
};

void* S_func_005ff660::f(void* arg)
{
    char* self = (char*)this - 136;
    void* tmp = 0;
    sub_a404c8(arg, &tmp, self);
    return arg;
}
