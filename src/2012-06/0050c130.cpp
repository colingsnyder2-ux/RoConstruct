// from server: 45% by atomic.potato
struct S_func_0050c130 {
    char pad0[4];
    void* field4;
    void f(void* arg);
};

extern "C" void __stdcall sub_0050bff0(void* dst, void* src);

void S_func_0050c130::f(void* arg)
{
    void* local;
    char flag;
    void* p;
    void* q;

    local = arg;
    flag = 0;
    p = (char*)this + 4;
    if (p != 0) {
        q = (char*)p - 4;
    } else {
        q = 0;
    }
    sub_0050bff0(&local, q);

    p = (char*)this + 4;
    void* node = *(void**)p;
    p = (char*)p - 4;
    while (node != p) {
        sub_0050bff0(&local, node);
        node = *(void**)((char*)node + 4);
    }
}
